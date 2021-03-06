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

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <siut2/dsrv/FreeglutWindow.h>
#include <renderlist/gl/Renderer.hpp>
#include <renderlist/DataBase.hpp>
#include <renderlist/XMLWriter.hpp>
#include <renderlist/Buffer.hpp>
#include <renderlist/Draw.hpp>
#include <renderlist/SetViewCoordSys.hpp>
#include <renderlist/Shader.hpp>
#include <renderlist/SetShader.hpp>
#include <renderlist/SetInputs.hpp>
#include <renderlist/SetUniforms.hpp>
#include <renderlist/SetLight.hpp>
#include <renderlist/SetLocalCoordSys.hpp>
#include <renderlist/SetFramebuffer.hpp>
#include <renderlist/SetFramebufferState.hpp>
#include <renderlist/SetPixelState.hpp>
#include <renderlist/SetRasterState.hpp>

class RenderListViewer : public siut2::dsrv::FreeglutWindow
{
public:
    RenderListViewer( int* argc, char** argv )
        : FreeglutWindow(),
          m_renderer( m_db ),
          m_has_dumped( 0 ),
          m_shape0_visible( true ),
          m_shape1_visible( true ),
          m_shape2_visible( true ),
          m_shape0_position( glm::vec3( 0.8f, 0.8f, 0.8f ) ),
          m_shape1_position( glm::vec3( 0.3f, 0.3f, 0.3f ) ),
          m_shape2_position( glm::vec3( 0.0f, 0.0f, 0.0f ) )
    {
        setUpMixedModeContext( argc, argv, "RenderListViewer", GLUT_DOUBLE | GLUT_RGBA );
        glm::vec3 bb_min( -1.1f );
        glm::vec3 bb_max(  2.1f );
        init( bb_min, bb_max );

        float P[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1.0202, -1, 0, 0, -0.121333, 0 };
        float Pi[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -8.24176, 0, 0, -1, 8.40826 };
        float cfw[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, -3, 1};
        float ctw[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 3, 1 };
        float lfw[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
        float ltw[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

        float c0fw[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
        float c0tw[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};


        // --- line geometry
        float lines[3*3] = {
            0.f, 0.f, 0.5f,
            0.5f, 1.0f, 0.5f,
            1.f, 0.f, 0.f
        };
        m_db.createBuffer( "line_triangle_pos" )->set( lines, 3*3 );
        m_db.createAction<renderlist::Draw>( "line_triangle_draw" )
            ->setNonIndexed( renderlist::PRIMITIVE_LINE_LOOP, 0, 3 );

        // --- cube geometry
        float cube_pos[36*3] = { 0.f,  1.f, 0.f,  1.f,  1.f, 0.f,  1.f, 0.f, 0.f,  1.f, 0.f, 0.f,
                                 0.f, 0.f, 0.f, 0.f,  1.f, 0.f, 0.f,  1.f,  1.f,  1.f, 0.f,  1.f,
                                 1.f,  1.f,  1.f,  1.f, 0.f,  1.f, 0.f,  1.f,  1.f, 0.f, 0.f,  1.f,
                                 1.f,  1.f, 0.f,  1.f,  1.f,  1.f,  1.f, 0.f,  1.f,  1.f, 0.f,  1.f,
                                 1.f, 0.f, 0.f,  1.f,  1.f, 0.f, 0.f,  1.f, 0.f, 0.f, 0.f,  1.f,
                                 0.f,  1.f,  1.f, 0.f, 0.f,  1.f, 0.f,  1.f, 0.f, 0.f, 0.f, 0.f,
                                 0.f,  1.f, 0.f, 0.f,  1.f,  1.f,  1.f,  1.f,  1.f,  1.f,  1.f,  1.f,
                                 1.f,  1.f, 0.f, 0.f,  1.f, 0.f, 0.f, 0.f, 0.f,  1.f, 0.f,  1.f,
                                 0.f, 0.f,  1.f,  1.f, 0.f,  1.f, 0.f, 0.f, 0.f,  1.f, 0.f, 0.f };
        float cube_nrm[36*3] = { 0.f, 0.f, -1.f,  0.f,  0.f, -1.f,  0.f,  0.f, -1.f,  0.f,  0.f, -1.f,
                                 0.f, 0.f, -1.f,  0.f,  0.f, -1.f,  0.f,  0.f,  1.f,  0.f,  0.f,  1.f,
                                 0.f, 0.f,  1.f,  0.f,  0.f,  1.f,  0.f,  0.f,  1.f,  0.f,  0.f,  1.f,
                                 1.f, 0.f,  0.f,  1.f,  0.f,  0.f,  1.f,  0.f,  0.f,  1.f,  0.f,  0.f,
                                 1.f, 0.f,  0.f,  1.f,  0.f,  0.f, -1.f,  0.f,  0.f, -1.f,  0.f,  0.f,
                                 -1.f, 0.f,  0.f, -1.f,  0.f,  0.f, -1.f,  0.f,  0.f, -1.f,  0.f,  0.f,
                                 0.f, 1.f,  0.f,  0.f,  1.f,  0.f,  0.f,  1.f,  0.f,  0.f,  1.f,  0.f,
                                 0.f, 1.f,  0.f,  0.f,  1.f,  0.f,  0.f, -1.f,  0.f,  0.f, -1.f,  0.f,
                                 0.f, -1.f, 0.f,  0.f, -1.f,  0.f,  0.f, -1.f,  0.f,  0.f, -1.f,  0.f };

        m_db.createBuffer( "cube_pos" )->set( cube_pos, 3*36 );
        m_db.createBuffer( "cube_nrm" )->set( cube_nrm, 3*36 );
        m_db.createAction<renderlist::Draw>( "cube_draw")
                ->setNonIndexed( renderlist::PRIMITIVE_TRIANGLES, 0, 36 );


        // --- set up solid shader
        m_db.createShader( "solid" )
            ->setVertexStage( "uniform mat4 MVP;\n"
                              "attribute vec3 position;\n"
                              "void\n"
                              "main()\n"
                              "{\n"
                              "    gl_Position = MVP * vec4( position, 1.0 );\n"
                              "}\n" )
            ->setFragmentStage( "#ifdef GL_ES\n"
                                "precision highp float;\n"
                                "#endif\n"
                                "uniform vec3 color;\n"
                                "void\n"
                                "main()\n"
                                "{\n"
                                "    gl_FragColor = vec4( color, 1.0 );\n"
                                "}\n" );
        m_db.createAction<renderlist::SetShader>( "use_solid")
            ->setShader( "solid" );
        m_db.createAction<renderlist::SetUniforms>( "solid_matrices" )
            ->setShader( "solid" )
            ->setSemantic( "MVP", renderlist::SEMANTIC_MODELVIEW_PROJECTION_MATRIX );
        m_db.createAction<renderlist::SetUniforms>( "solid_green" )
            ->setShader( "solid" )
            ->setFloat3( "color", 0.5f, 1.0f, 0.6f );

        // --- set up line triangle input for solid rendering
        m_db.createAction<renderlist::SetInputs>( "solid_line_inputs" )
                ->setShader( "solid" )
                ->setInput( "position", "line_triangle_pos", 3 );


        // --- set up phong shader
        m_db.createShader( "phong" )
                ->setVertexStage( "uniform mat4 MVP;\n"
                                  "uniform mat3 NM;\n"
                                  "attribute vec3 position;\n"
                                  "attribute vec3 normal;\n"
                                  "varying vec3 es_normal;\n"
                                  "void\n"
                                  "main()\n"
                                  "{\n"
                                  "    es_normal = NM * normal;\n"
                                  "    gl_Position = MVP * vec4( position, 1.0 );\n"
                                  "}\n" )
                ->setFragmentStage( "#ifdef GL_ES\n"
                                    "precision highp float;\n"
                                    "#endif\n"
                                    "varying vec3 es_normal;\n"
                                    "uniform vec3 color;\n"
                                    "void\n"
                                    "main()\n"
                                    "{\n"
                                    "    vec3 light_z = normalize( vec3(1,1,1) );\n"
                                    "    gl_FragColor = vec4( color*max(0.1, dot( normalize(es_normal), light_z ) ), 1.0 );\n"
                                    "}\n" );
        m_db.createAction<renderlist::SetShader>( "use_phong" )
            ->setShader( "phong" );
        m_db.createAction<renderlist::SetUniforms>( "phong_matrices" )
            ->setShader( "phong" )
            ->setSemantic( "MVP", renderlist::SEMANTIC_MODELVIEW_PROJECTION_MATRIX )
            ->setSemantic( "NM", renderlist::SEMANTIC_NORMAL_MATRIX );
        m_db.createAction<renderlist::SetUniforms>( "phong_blue" )
            ->setShader( "phong" )
            ->setFloat3( "color", 0.8f, 0.9f, 1.f );
        m_db.createAction<renderlist::SetUniforms>( "phong_red" )
            ->setShader( "phong" )
            ->setFloat3( "color", 1.0f, 0.5f, 0.4f );

        // --- set up cube input for phong rendering
        m_db.createAction<renderlist::SetInputs>( "phong_cube_inputs" )
            ->setShader( "phong" )
            ->setInput( "position", "cube_pos", 3 )
            ->setInput( "normal", "cube_nrm", 3 );





        // --- set up shape orientations
        m_db.createAction<renderlist::SetLocalCoordSys>( "shape0_orient" );
        m_db.createAction<renderlist::SetLocalCoordSys>( "shape1_orient" );
        m_db.createAction<renderlist::SetLocalCoordSys>( "shape2_orient" );



        m_db.createAction<renderlist::SetViewCoordSys>( "cam" )
                ->setProjection( P, Pi )
                ->setOrientation( cfw, ctw );

        m_db.createAction<renderlist::SetLight>( "light" )
            ->setType( renderlist::LIGHT_POINT )
            ->setIndex( 0 )
            ->setColor( 0.8f, 1.f, 1.f )
            ->setAttenuation( 1.f, 0.f, 0.f )
            ->setFalloff( 3.14159f, 0.f )
            ->setOrientation( lfw, ltw );


        m_db.createAction<renderlist::SetFramebuffer>( "default_fbo" )
            ->setDefault();

        m_db.createAction<renderlist::SetPixelState>( "px_state" )
            ->enableDepthTest()
            ->disableBlending();

        m_db.createAction<renderlist::SetFramebufferState>( "fb_state" )
            ->setColorWritemask( true, true, true )
            ->setDepthWritemask( true );

        m_db.createAction<renderlist::SetRasterState>( "rs_state" );



        updateShapePositions();
        updateDrawOrder();

        std::cout << renderlist::getUpdateXML( &m_db, renderlist::ENCODING_JSON, 0 );
     }

protected:
    renderlist::DataBase     m_db;
    renderlist::gl::Renderer m_renderer;
    renderlist::Revision     m_has_dumped;
    bool                        m_shape0_visible;
    bool                        m_shape1_visible;
    bool                        m_shape2_visible;
    glm::vec3                   m_shape0_position;
    glm::vec3                   m_shape1_position;
    glm::vec3                   m_shape2_position;

    void keyboard(unsigned char key)
    {
        switch(key) {
        case '1':
            m_shape0_visible = !m_shape0_visible;
            updateDrawOrder();
            break;
        case '2':
            m_shape1_visible = !m_shape1_visible;
            updateDrawOrder();
            break;
        case '3':
            m_shape2_visible = !m_shape2_visible;
            updateDrawOrder();
            break;
        case 'd':
            m_shape0_position.x += 0.1f;
            updateShapePositions();
            break;
        case 'a':
            m_shape0_position.x -= 0.1f;
            updateShapePositions();
            break;
        default:
            break;
        }
    }


    void
    updateShapePositions()
    {
        glm::mat4 LTW0;
        LTW0 = glm::translate( LTW0, m_shape0_position );
        LTW0 = glm::scale( LTW0, glm::vec3( 0.7f, 0.7f, 0.7f) );
        glm::mat4 LFW0 = glm::inverse( LTW0 );

        m_db.castedItemByName<renderlist::SetLocalCoordSys*>( "shape0_orient" )
            ->setOrientation( glm::value_ptr( LFW0),
                              glm::value_ptr( LTW0 ) );

        glm::mat4 LTW1;
        LTW1 = glm::translate( LTW1, m_shape1_position );
        LTW1 = glm::scale( LTW1, glm::vec3( 0.7f, 0.7f, 0.7f) );
        glm::mat4 LFW1 = glm::inverse( LTW1 );
        m_db.castedItemByName<renderlist::SetLocalCoordSys*>( "shape1_orient" )
            ->setOrientation( glm::value_ptr( LFW1),
                              glm::value_ptr( LTW1 ) );

        glm::mat4 LTW2;
        LTW2 = glm::translate( LTW2, m_shape2_position );
        glm::mat4 LFW2 = glm::inverse( LTW2 );
        m_db.castedItemByName<renderlist::SetLocalCoordSys*>( "shape2_orient" )
            ->setOrientation( glm::value_ptr( LFW2),
                              glm::value_ptr( LTW2 ) );

        m_db.process();
    }

    void
    updateDrawOrder()
    {
        m_db.drawOrderClear()
            ->drawOrderAdd( "cam" )
            ->drawOrderAdd( "default_fbo" )
            ->drawOrderAdd( "rs_state" )
            ->drawOrderAdd( "px_state" )
            ->drawOrderAdd( "fb_state" );

        // --- cube 0
        if( m_shape0_visible ) {
            m_db.drawOrderAdd( "use_phong" )
                    ->drawOrderAdd( "phong_cube_inputs" )
                    ->drawOrderAdd( "shape0_orient" )
                    ->drawOrderAdd( "phong_matrices" )
                    ->drawOrderAdd( "phong_blue" )
                    ->drawOrderAdd( "cube_draw" );
        }

        // --- cube 1
        if( m_shape1_visible ) {
            m_db.drawOrderAdd( "use_phong" )
                    ->drawOrderAdd( "phong_cube_inputs" )
                    ->drawOrderAdd( "shape1_orient" )
                    ->drawOrderAdd( "phong_matrices" )
                    ->drawOrderAdd( "phong_red" )
                    ->drawOrderAdd( "cube_draw" );
        }

        // --- line triangle
        if( m_shape2_visible ) {
            m_db.drawOrderAdd( "use_solid" )
                    ->drawOrderAdd( "shape2_orient" )
                    ->drawOrderAdd( "solid_matrices" )
                    ->drawOrderAdd( "solid_green" )
                    ->drawOrderAdd( "solid_line_inputs" )
                    ->drawOrderAdd( "line_triangle_draw" );
        }
        m_db.process();
    }


    void render()
    {
        if( m_has_dumped != m_db.latest() ) {
            std::cerr << "--- update --- \n";
            std::cerr << renderlist::getUpdateXML( &m_db, renderlist::ENCODING_JSON, m_has_dumped );
            std::cerr << "--- update --- \n";
            m_has_dumped = m_db.latest();
        }

        glm::vec2 size = m_viewer->getWindowSize();
        m_renderer.pull();
        m_renderer.render( 0,
                           glm::value_ptr( m_viewer->getProjectionMatrix() ),
                           glm::value_ptr( m_viewer->getProjectionInverseMatrix() ),
                           glm::value_ptr( m_viewer->getModelviewMatrix() ),
                           glm::value_ptr( m_viewer->getModelviewInverseMatrix() ),
                           size.x,
                           size.y );
    }

};


int
main( int argc, char** argv )
{
    RenderListViewer app( &argc, argv );
    app.run();
    return EXIT_SUCCESS;
}
