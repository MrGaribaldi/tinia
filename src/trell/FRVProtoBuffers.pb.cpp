// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FRVProtoBuffers.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "tinia/trell/FRVProtoBuffers.pb.hpp"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace frv {

namespace {

const ::google::protobuf::Descriptor* imageRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  imageRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* imageResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  imageResponse_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_FRVProtoBuffers_2eproto() {
  protobuf_AddDesc_FRVProtoBuffers_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "FRVProtoBuffers.proto");
  GOOGLE_CHECK(file != NULL);
  imageRequest_descriptor_ = file->message_type(0);
  static const int imageRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(imageRequest, modelview_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(imageRequest, projection_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(imageRequest, zscale_),
  };
  imageRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      imageRequest_descriptor_,
      imageRequest::default_instance_,
      imageRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(imageRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(imageRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(imageRequest));
  imageResponse_descriptor_ = file->message_type(1);
  static const int imageResponse_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(imageResponse, image_bytes_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(imageResponse, image_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(imageResponse, zscale_),
  };
  imageResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      imageResponse_descriptor_,
      imageResponse::default_instance_,
      imageResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(imageResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(imageResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(imageResponse));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_FRVProtoBuffers_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    imageRequest_descriptor_, &imageRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    imageResponse_descriptor_, &imageResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_FRVProtoBuffers_2eproto() {
  delete imageRequest::default_instance_;
  delete imageRequest_reflection_;
  delete imageResponse::default_instance_;
  delete imageResponse_reflection_;
}

void protobuf_AddDesc_FRVProtoBuffers_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025FRVProtoBuffers.proto\022\003frv\"M\n\014imageReq"
    "uest\022\025\n\tmodelView\030\001 \003(\002B\002\020\001\022\026\n\nprojectio"
    "n\030\002 \003(\002B\002\020\001\022\016\n\006zScale\030\003 \001(\002\"H\n\rimageResp"
    "onse\022\023\n\013image_bytes\030\001 \002(\014\022\022\n\nimage_type\030"
    "\002 \002(\t\022\016\n\006zScale\030\003 \001(\002", 181);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "FRVProtoBuffers.proto", &protobuf_RegisterTypes);
  imageRequest::default_instance_ = new imageRequest();
  imageResponse::default_instance_ = new imageResponse();
  imageRequest::default_instance_->InitAsDefaultInstance();
  imageResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_FRVProtoBuffers_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_FRVProtoBuffers_2eproto {
  StaticDescriptorInitializer_FRVProtoBuffers_2eproto() {
    protobuf_AddDesc_FRVProtoBuffers_2eproto();
  }
} static_descriptor_initializer_FRVProtoBuffers_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int imageRequest::kModelViewFieldNumber;
const int imageRequest::kProjectionFieldNumber;
const int imageRequest::kZScaleFieldNumber;
#endif  // !_MSC_VER

imageRequest::imageRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:frv.imageRequest)
}

void imageRequest::InitAsDefaultInstance() {
}

imageRequest::imageRequest(const imageRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:frv.imageRequest)
}

void imageRequest::SharedCtor() {
  _cached_size_ = 0;
  zscale_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

imageRequest::~imageRequest() {
  // @@protoc_insertion_point(destructor:frv.imageRequest)
  SharedDtor();
}

void imageRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void imageRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* imageRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return imageRequest_descriptor_;
}

const imageRequest& imageRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FRVProtoBuffers_2eproto();
  return *default_instance_;
}

imageRequest* imageRequest::default_instance_ = NULL;

imageRequest* imageRequest::New() const {
  return new imageRequest;
}

void imageRequest::Clear() {
  zscale_ = 0;
  modelview_.Clear();
  projection_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool imageRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:frv.imageRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated float modelView = 1 [packed = true];
      case 1: {
        if (tag == 10) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, this->mutable_modelview())));
        } else if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 1, 10, input, this->mutable_modelview())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_projection;
        break;
      }

      // repeated float projection = 2 [packed = true];
      case 2: {
        if (tag == 18) {
         parse_projection:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, this->mutable_projection())));
        } else if (tag == 21) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 1, 18, input, this->mutable_projection())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(29)) goto parse_zScale;
        break;
      }

      // optional float zScale = 3;
      case 3: {
        if (tag == 29) {
         parse_zScale:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &zscale_)));
          set_has_zscale();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:frv.imageRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:frv.imageRequest)
  return false;
#undef DO_
}

void imageRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:frv.imageRequest)
  // repeated float modelView = 1 [packed = true];
  if (this->modelview_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(1, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_modelview_cached_byte_size_);
  }
  for (int i = 0; i < this->modelview_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFloatNoTag(
      this->modelview(i), output);
  }

  // repeated float projection = 2 [packed = true];
  if (this->projection_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(2, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_projection_cached_byte_size_);
  }
  for (int i = 0; i < this->projection_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFloatNoTag(
      this->projection(i), output);
  }

  // optional float zScale = 3;
  if (has_zscale()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(3, this->zscale(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:frv.imageRequest)
}

::google::protobuf::uint8* imageRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:frv.imageRequest)
  // repeated float modelView = 1 [packed = true];
  if (this->modelview_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      1,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _modelview_cached_byte_size_, target);
  }
  for (int i = 0; i < this->modelview_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteFloatNoTagToArray(this->modelview(i), target);
  }

  // repeated float projection = 2 [packed = true];
  if (this->projection_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      2,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _projection_cached_byte_size_, target);
  }
  for (int i = 0; i < this->projection_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteFloatNoTagToArray(this->projection(i), target);
  }

  // optional float zScale = 3;
  if (has_zscale()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(3, this->zscale(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:frv.imageRequest)
  return target;
}

int imageRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[2 / 32] & (0xffu << (2 % 32))) {
    // optional float zScale = 3;
    if (has_zscale()) {
      total_size += 1 + 4;
    }

  }
  // repeated float modelView = 1 [packed = true];
  {
    int data_size = 0;
    data_size = 4 * this->modelview_size();
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _modelview_cached_byte_size_ = data_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated float projection = 2 [packed = true];
  {
    int data_size = 0;
    data_size = 4 * this->projection_size();
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _projection_cached_byte_size_ = data_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void imageRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const imageRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const imageRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void imageRequest::MergeFrom(const imageRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  modelview_.MergeFrom(from.modelview_);
  projection_.MergeFrom(from.projection_);
  if (from._has_bits_[2 / 32] & (0xffu << (2 % 32))) {
    if (from.has_zscale()) {
      set_zscale(from.zscale());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void imageRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void imageRequest::CopyFrom(const imageRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool imageRequest::IsInitialized() const {

  return true;
}

void imageRequest::Swap(imageRequest* other) {
  if (other != this) {
    modelview_.Swap(&other->modelview_);
    projection_.Swap(&other->projection_);
    std::swap(zscale_, other->zscale_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata imageRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = imageRequest_descriptor_;
  metadata.reflection = imageRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int imageResponse::kImageBytesFieldNumber;
const int imageResponse::kImageTypeFieldNumber;
const int imageResponse::kZScaleFieldNumber;
#endif  // !_MSC_VER

imageResponse::imageResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:frv.imageResponse)
}

void imageResponse::InitAsDefaultInstance() {
}

imageResponse::imageResponse(const imageResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:frv.imageResponse)
}

void imageResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  image_bytes_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  image_type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  zscale_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

imageResponse::~imageResponse() {
  // @@protoc_insertion_point(destructor:frv.imageResponse)
  SharedDtor();
}

void imageResponse::SharedDtor() {
  if (image_bytes_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete image_bytes_;
  }
  if (image_type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete image_type_;
  }
  if (this != default_instance_) {
  }
}

void imageResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* imageResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return imageResponse_descriptor_;
}

const imageResponse& imageResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FRVProtoBuffers_2eproto();
  return *default_instance_;
}

imageResponse* imageResponse::default_instance_ = NULL;

imageResponse* imageResponse::New() const {
  return new imageResponse;
}

void imageResponse::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_image_bytes()) {
      if (image_bytes_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        image_bytes_->clear();
      }
    }
    if (has_image_type()) {
      if (image_type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        image_type_->clear();
      }
    }
    zscale_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool imageResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:frv.imageResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes image_bytes = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_image_bytes()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_image_type;
        break;
      }

      // required string image_type = 2;
      case 2: {
        if (tag == 18) {
         parse_image_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_image_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->image_type().data(), this->image_type().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "image_type");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(29)) goto parse_zScale;
        break;
      }

      // optional float zScale = 3;
      case 3: {
        if (tag == 29) {
         parse_zScale:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &zscale_)));
          set_has_zscale();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:frv.imageResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:frv.imageResponse)
  return false;
#undef DO_
}

void imageResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:frv.imageResponse)
  // required bytes image_bytes = 1;
  if (has_image_bytes()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->image_bytes(), output);
  }

  // required string image_type = 2;
  if (has_image_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->image_type().data(), this->image_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "image_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->image_type(), output);
  }

  // optional float zScale = 3;
  if (has_zscale()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(3, this->zscale(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:frv.imageResponse)
}

::google::protobuf::uint8* imageResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:frv.imageResponse)
  // required bytes image_bytes = 1;
  if (has_image_bytes()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->image_bytes(), target);
  }

  // required string image_type = 2;
  if (has_image_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->image_type().data(), this->image_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "image_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->image_type(), target);
  }

  // optional float zScale = 3;
  if (has_zscale()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(3, this->zscale(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:frv.imageResponse)
  return target;
}

int imageResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required bytes image_bytes = 1;
    if (has_image_bytes()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->image_bytes());
    }

    // required string image_type = 2;
    if (has_image_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->image_type());
    }

    // optional float zScale = 3;
    if (has_zscale()) {
      total_size += 1 + 4;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void imageResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const imageResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const imageResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void imageResponse::MergeFrom(const imageResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_image_bytes()) {
      set_image_bytes(from.image_bytes());
    }
    if (from.has_image_type()) {
      set_image_type(from.image_type());
    }
    if (from.has_zscale()) {
      set_zscale(from.zscale());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void imageResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void imageResponse::CopyFrom(const imageResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool imageResponse::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void imageResponse::Swap(imageResponse* other) {
  if (other != this) {
    std::swap(image_bytes_, other->image_bytes_);
    std::swap(image_type_, other->image_type_);
    std::swap(zscale_, other->zscale_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata imageResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = imageResponse_descriptor_;
  metadata.reflection = imageResponse_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace frv

// @@protoc_insertion_point(global_scope)
