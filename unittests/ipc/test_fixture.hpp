/* Copyright STIFTELSEN SINTEF 2012
 * 
 * This file is part of the Tinia Framework.
 * 
 * The Tinia Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * The Tinia Framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with the Tinia Framework.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <cassert>
#include <ctime>
#include <cstdarg>
#include <iostream>
#include <sstream>
#include <boost/test/unit_test.hpp>
#include <tinia/ipc/ipc_msg.h>
#include "../../src/ipc/ipc_msg_internal.h"


#define NOT_MAIN_THREAD_REQUIRE( obj, a ) do { if(!(a)){                    \
    std::stringstream o;                                                    \
    o << (#a) << " failed at " << __FILE__ << '@' << __LINE__;              \
    obj->setErrorFromThread( o.str() );                                     \
    } } while(0)

#define FAIL_MISERABLY_UNLESS( a ) do { if(!(a) ) {                             \
    fprintf( stderr, "Failed misrably at %s@%d: %s\n", __FILE__, __LINE__, #a );\
    *((int*)0xDEADBEEF) = 42;                                                   \
    } } while(0)


struct SendRecvFixtureBase
{

    // RAII-locker for fixture
    class Locker
    {
    public:
        explicit Locker( SendRecvFixtureBase* that )
            : m_that( that ),
              m_locked( false )
        {
            lock();
        }

        ~Locker()
        {
            if( m_locked ) {
                unlock();
            }
        }

        void
        lock()
        {
            if( m_locked ) {
                fprintf( stderr, "Locker::lock: Locker already locked\n" );
                *((int*)0xDEADBEEF) = 42;   // Serious error, force segfault & termination.
            }

            int rv = pthread_mutex_lock( &m_that->lock );
            if( rv != 0 ) {
                fprintf( stderr, "Locker::lock: %s\n", strerror( rv ) );
            }
            m_locked = true;
        }

        void
        unlock()
        {
            if( !m_locked ) {
                fprintf( stderr, "Locker::lock: Locker not locked\n" );
                *((int*)0xDEADBEEF) = 42;   // Serious error, force segfault & termination.
            }

            int rv = pthread_mutex_unlock( &m_that->lock );
            if( rv != 0 ) {
                fprintf( stderr, "Locker::lock: %s\n", strerror( rv ) );
            }
            m_locked = false;
        }

    protected:
        SendRecvFixtureBase*    m_that;
        bool                    m_locked;
    };


    SendRecvFixtureBase()
        : m_server( NULL ),
          m_server_runs_flag( 0 ),
          m_failure_is_an_option( 0 ),
          m_clients( 1 ),
          m_clients_should_longpoll( 0 ),
          m_clients_initialized( 0 ),
          m_clients_exited( 0 )
    {}
    
    std::vector<pthread_t>  m_threads;
    pthread_mutex_t         lock;
    tinia_ipc_msg_server_t*               m_server;
    int                     m_server_runs_flag;
    pthread_cond_t          m_server_runs_cond;
    int                     m_failure_is_an_option;
    int                     m_clients;
    int                     m_clients_should_longpoll;
    int                     m_clients_initialized;
    pthread_cond_t          m_clients_initialized_cond;
    int                     m_clients_exited;
    pthread_cond_t          m_clients_exited_cond;
    std::string             m_error_from_thread;
    
    void
    setErrorFromThread( const std::string& error )
    {
        Locker locker( this );
        m_error_from_thread = error;
    }

    virtual
    int
    clientProducer( int* more,
                    char* buffer,
                    size_t* buffer_bytes,
                    const size_t buffer_size,
                    const int part ) = 0;
    
    virtual
    int
    clientConsumer( const char* buffer,
                    const size_t buffer_bytes,
                    const int part,
                    const int more ) = 0;
    virtual
    int
    serverConsumer( const char* buffer,
                    const size_t buffer_bytes,
                    const int part,
                    const int more ) = 0;
    
    virtual
    int
    serverProducer( int* more,
                    char* buffer,
                    size_t* buffer_bytes,
                    const size_t buffer_size,
                    const int part ) = 0;

    virtual
    int
    inner()
    { return 0; }
    
    virtual
    void
    run()
    {
        fprintf( stderr, "test begin.\n" );
        m_clients_initialized = 0;
        m_clients_exited = 0;

        int rc;
        // Note boost::test is not thread safe. Thus, we use a lock around
        // all test macros when we go multi-threaded. Actually obtaining this
        // lock is wrappend in assert, as the lock must be held to use the
        // test macros.
        
        // test timeout
        struct timespec timeout;
        clock_gettime( CLOCK_REALTIME, &timeout );
        timeout.tv_sec += 1;

        
        pthread_mutexattr_t mutex_attr;
        
        BOOST_REQUIRE( pthread_mutexattr_init( &mutex_attr) == 0 );
        BOOST_REQUIRE( pthread_mutexattr_settype( &mutex_attr, PTHREAD_MUTEX_ERRORCHECK ) == 0 );
        BOOST_REQUIRE( pthread_mutexattr_settype( &mutex_attr, PTHREAD_MUTEX_RECURSIVE ) == 0 );
        
        BOOST_REQUIRE( pthread_mutex_init( &lock, &mutex_attr ) == 0 );

        BOOST_REQUIRE( pthread_cond_init( &m_server_runs_cond, NULL ) == 0 );
        BOOST_REQUIRE( pthread_cond_init( &m_clients_initialized_cond, NULL ) == 0 );
        BOOST_REQUIRE( pthread_cond_init( &m_clients_exited_cond, NULL ) == 0 );
        
        BOOST_REQUIRE( pthread_mutexattr_destroy( &mutex_attr) == 0 );

        // wait for server to be up and running.
        Locker locker( this );
        m_server = NULL;
        m_threads.resize( m_threads.size()+1 );

        BOOST_REQUIRE( pthread_create( &m_threads.back(),
                                       NULL,
                                       server_thread_func,
                                       this ) == 0 );
        m_server_runs_flag = 0;
        do {
            int rc = pthread_cond_timedwait( &m_server_runs_cond,
                                             &lock,
                                             &timeout );
            BOOST_REQUIRE( (rc == 0) || (rc==ETIMEDOUT) );
            if( rc == ETIMEDOUT ) {
                BOOST_CHECK( false && "timed out while waiting for server to be created."  );
                goto hung;
            }
        }
        while( m_server_runs_flag == 0 );

        BOOST_REQUIRE( m_server != NULL );
        BOOST_REQUIRE( m_server->shmem_header_ptr != NULL );
            
        // create clients
        BOOST_REQUIRE( (m_clients >= 0) && (m_clients < 10) ); // sanity check
        for(int i=0; i<m_clients; i++ ) {
            m_threads.resize( m_threads.size()+1 );
            BOOST_REQUIRE( pthread_create( &m_threads.back(),
                                           NULL,
                                           client_thread_func,
                                           this ) == 0 );
        }

        
        // wait for clients to run
        while( m_clients_initialized != m_clients ) {
            int rc = pthread_cond_timedwait( &m_clients_initialized_cond,
                                             &lock,
                                             &timeout );
            BOOST_REQUIRE( (rc == 0) || (rc==ETIMEDOUT) );
            if( rc == ETIMEDOUT ) {
                BOOST_CHECK( false && "timed out while waiting for clients to initialize."  );
                goto hung;
            }
        }
        
        if( inner() != 0 ) {
            goto hung;
        }

        // wait for clients to finish
        while( m_clients_exited != m_clients ) {
            int rc = pthread_cond_timedwait( &m_clients_exited_cond,
                                             &lock,
                                             &timeout );
            BOOST_REQUIRE( (rc == 0) || (rc==ETIMEDOUT) );
            if( rc == ETIMEDOUT ) {
                BOOST_CHECK( false && "timed out while waiting for clients to finish."  );
                goto hung;
            }
        }
        fprintf( stderr, "%s@%d: %d clients have exited.\n", __FILE__, __LINE__, m_clients_exited );
        // kill server
        BOOST_REQUIRE( m_server != NULL );

        locker.unlock();
        rc = ipc_msg_server_mainloop_break( m_server );
        BOOST_REQUIRE( rc == 0 );

        locker.lock();
        
        // wait for server thread to finsh
        while( m_server != NULL ) {
            int rc = pthread_cond_timedwait( &m_server_runs_cond,
                                             &lock,
                                             &timeout );
            BOOST_REQUIRE( (rc == 0) || (rc==ETIMEDOUT) );
            if( rc == ETIMEDOUT ) {
                BOOST_CHECK( false && "timed out while waiting for server to finish."  );
                goto hung;
            }
        }
        locker.unlock();
        goto cleanup;
hung:
        ipc_msg_server_mainloop_break( m_server );
        sleep(1);

        // invariants:
        // - m_shared_lock locked.
        for( auto it=m_threads.begin(); it!=m_threads.end(); ++it ) {
            pthread_cancel( *it );
        }
        locker.unlock();

cleanup:
        for( size_t i=0; i<m_threads.size(); i++ ) {
            void* tmp;
            if( pthread_tryjoin_np( m_threads[i], &tmp ) == 0 ) {
                //std::cerr << "joined thread "<< i<< ".\n";
            }
            else {
                //std::cerr << "thread "<< i<< " is still busy.\n";
            }
        }
        //std::cerr << "done.\n";
        BOOST_REQUIRE( pthread_cond_destroy( &m_server_runs_cond ) == 0 );
        BOOST_REQUIRE( pthread_cond_destroy( &m_clients_initialized_cond ) == 0 );
        BOOST_REQUIRE( pthread_cond_destroy( &m_clients_exited_cond) == 0 );
        FAIL_MISERABLY_UNLESS( pthread_mutex_destroy( &lock ) == 0 );
        //ipc_msg_server_wipe( "unittest" );
        if( !m_error_from_thread.empty() ) {
            fprintf( stderr, "Error from thread: %s\n", m_error_from_thread.c_str() );
            BOOST_REQUIRE( m_error_from_thread.empty() );
        }

        fprintf( stderr, "test end.\n" );
    }

    static
    void
    logger( void* data,
            int level,
            const char* who,
            const char* msg, ... )
    {
        SendRecvFixtureBase* that = (SendRecvFixtureBase*)data;
        Locker locker( that );
        char buf[1024];
        va_list args;
        va_start( args, msg );
        vsnprintf( buf, sizeof(buf), msg, args );
        va_end( args );
        switch( level ) {
        case 0: std::cerr << "[E] "; break;
        case 1: std::cerr << "[W] "; break;
        default:  std::cerr << "[I] "; break;
        }
        if( who != NULL ) {
            std::cerr << '[' << who << "]";
        }
        for( int i = strlen(who); i<40; i++ ) {
            std::cerr << ' ';
        }
        std::cerr << buf << std::endl;
    }
    
    
    static
    int
    server_consumer( void* data,
                     const char* buffer,
                     const size_t buffer_bytes,
                     const int part,
                     const int more )
    {
        return ((SendRecvFixtureBase*)data)->serverConsumer( buffer,
                                                             buffer_bytes,
                                                             part,
                                                             more );
    }

    static
    int
    server_producer( void* data,
              int* more,
              char* buffer,
              size_t* buffer_bytes,
              const size_t buffer_size,
              const int part )
    {
        return ((SendRecvFixtureBase*)data)->serverProducer( more,
                                                             buffer,
                                                             buffer_bytes,
                                                             buffer_size,
                                                             part );
    }
    
    static
    int
    server_input_handler( tinia_ipc_msg_consumer_func_t* consumer_, void** consumer_data,
                          void* handler_data,
                          const char* buffer,
                          const size_t buffer_bytes )
    {
        *consumer_ = server_consumer;
        *consumer_data = handler_data;
        return 0;
    }

    static
    int
    server_output_handler( tinia_ipc_msg_producer_func_t* producer,
                           void** producer_data,
                           void* handler_data)
    {
        *producer = server_producer;
        *producer_data = handler_data;
        return 0;
    }

    static
    int
    server_handler_finished( void* data, int success )
    {
        return 0;
    }

    
    static
    int
    server_periodic( void* arg )
    {
        SendRecvFixtureBase* that = (SendRecvFixtureBase*)arg;

        Locker locker( that );
        if( that->m_server_runs_flag == 0 ) {
            that->m_server_runs_flag = 1;
            NOT_MAIN_THREAD_REQUIRE( that, pthread_cond_signal( &that->m_server_runs_cond ) == 0 );
        }
        return 0;
    }
    
    static
    void*
    server_thread_func( void* arg )
    {
        SendRecvFixtureBase* that = (SendRecvFixtureBase*)arg;

        // setup server
        tinia_ipc_msg_server_t* server = ipc_msg_server_create( "unittest",
                                                  logger,
                                                  arg );
        {
            Locker locker( that );
            NOT_MAIN_THREAD_REQUIRE( that, server != NULL );
            NOT_MAIN_THREAD_REQUIRE( that, server->shmem_base != NULL );
            NOT_MAIN_THREAD_REQUIRE( that, server->shmem_header_ptr != NULL );
            that->m_server = server;
        }
        // run server mainloop
        //std::cerr << __LINE__ << ": A\n";
        int rc = ipc_msg_server_mainloop( server,
                                          server_periodic, that,
                                          server_input_handler, that,
                                          server_output_handler, that );
        if( rc < -1 ) { // Serious error.
            fprintf( stderr, "Return code from ipc_msg_server_main = %d\n", rc );
            NOT_MAIN_THREAD_REQUIRE( that, rc >= -1 );
        }
        {
            Locker locker( that );
            that->m_server = NULL;
        }

        rc = ipc_msg_server_delete( server );
        NOT_MAIN_THREAD_REQUIRE( that, rc == 0 );

        {
            Locker locker( that );
            NOT_MAIN_THREAD_REQUIRE( that, pthread_cond_signal( &that->m_server_runs_cond ) == 0 );
        }
        return NULL;
    }
    
 
    
    static
    int
    client_producer( void* data,
                     int* more,
                     char* buffer,
                     size_t* buffer_bytes,
                     const size_t buffer_size,
                     const int part )
    {
        return ((SendRecvFixtureBase*)data)->clientProducer( more,
                                                             buffer,
                                                             buffer_bytes,
                                                             buffer_size,
                                                             part );
    }

    
    
    static
    int
    client_consumer( void* data,
                     const char* buffer,
                     const size_t buffer_bytes,
                     const int part,
                     const int more )
    {
        return ((SendRecvFixtureBase*)data)->clientConsumer( buffer,
                                                             buffer_bytes,
                                                             part,
                                                             more );
    }

    static
    int
    client_input_handler( tinia_ipc_msg_consumer_func_t* consumer_, void** consumer_data,
                          void* handler_data,
                          const char* buffer,
                          const size_t buffer_bytes )
    {
        *consumer_ = client_consumer;
        *consumer_data = handler_data;
        return 0;
    }

    
    static
    void*
    client_thread_func( void* arg )
    {
        int rc;
        SendRecvFixtureBase* that = (SendRecvFixtureBase*)arg;
        
        {
            Locker locker( that );
            that->m_clients_initialized++;
            if( that->m_clients_initialized == that->m_clients ) {
                // last client to finish init
                NOT_MAIN_THREAD_REQUIRE( that, pthread_cond_signal( &that->m_clients_initialized_cond ) == 0 );
            }
        }

        tinia_ipc_msg_client_t* client = (tinia_ipc_msg_client_t*)malloc( tinia_ipc_msg_client_t_sizeof );
        rc = tinia_ipc_msg_client_init( client, "unittest", logger, arg );
        NOT_MAIN_THREAD_REQUIRE( that, rc == 0 );

        do {
            int timeout;
            bool failure_is_an_option;
            {
                Locker locker( that );
                timeout = that->m_clients_should_longpoll ? 2 : 0;
                failure_is_an_option = that->m_failure_is_an_option;
            }

            rc = tinia_ipc_msg_client_sendrecv( client,
                                          client_producer, that,
                                          client_consumer, that,
                                          timeout );
            
            if( failure_is_an_option ) {
                NOT_MAIN_THREAD_REQUIRE( that, rc >= -1 );
            }
            else {
                NOT_MAIN_THREAD_REQUIRE( that, rc == 0 );
            }

        } while(0);

        rc = tinia_ipc_msg_client_release( client );
        NOT_MAIN_THREAD_REQUIRE( that, rc == 0 );
        free( client );
        
        // notify that we have finished
        {
            Locker locker( that );
            that->m_clients_exited++;
            if( that->m_clients_exited == that->m_clients ) {
                // last client to finish init
                NOT_MAIN_THREAD_REQUIRE( that, pthread_cond_signal( &that->m_clients_exited_cond ) == 0 );
            }
        }

        return NULL;
    }


    
};

