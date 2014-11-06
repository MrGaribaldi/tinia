// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TiniaProtoBuf.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "../include/tinia/protobuf/TiniaProtoBuf.pb.h"

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

namespace tinia {
namespace protobuf {

namespace {

const ::google::protobuf::Descriptor* TiniaProtoBuf_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TiniaProtoBuf_reflection_ = NULL;
const ::google::protobuf::Descriptor* TiniaProtoBuf_Viewer_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TiniaProtoBuf_Viewer_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_TiniaProtoBuf_2eproto() {
  protobuf_AddDesc_TiniaProtoBuf_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "TiniaProtoBuf.proto");
  GOOGLE_CHECK(file != NULL);
  TiniaProtoBuf_descriptor_ = file->message_type(0);
  static const int TiniaProtoBuf_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TiniaProtoBuf, viewer_),
  };
  TiniaProtoBuf_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TiniaProtoBuf_descriptor_,
      TiniaProtoBuf::default_instance_,
      TiniaProtoBuf_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TiniaProtoBuf, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TiniaProtoBuf, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(TiniaProtoBuf));
  TiniaProtoBuf_Viewer_descriptor_ = TiniaProtoBuf_descriptor_->nested_type(0);
  static const int TiniaProtoBuf_Viewer_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TiniaProtoBuf_Viewer, viewer_key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TiniaProtoBuf_Viewer, rgb_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TiniaProtoBuf_Viewer, depth_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TiniaProtoBuf_Viewer, view_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TiniaProtoBuf_Viewer, proj_),
  };
  TiniaProtoBuf_Viewer_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TiniaProtoBuf_Viewer_descriptor_,
      TiniaProtoBuf_Viewer::default_instance_,
      TiniaProtoBuf_Viewer_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TiniaProtoBuf_Viewer, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TiniaProtoBuf_Viewer, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(TiniaProtoBuf_Viewer));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_TiniaProtoBuf_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TiniaProtoBuf_descriptor_, &TiniaProtoBuf::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TiniaProtoBuf_Viewer_descriptor_, &TiniaProtoBuf_Viewer::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_TiniaProtoBuf_2eproto() {
  delete TiniaProtoBuf::default_instance_;
  delete TiniaProtoBuf_reflection_;
  delete TiniaProtoBuf_Viewer::default_instance_;
  delete TiniaProtoBuf_Viewer_reflection_;
}

void protobuf_AddDesc_TiniaProtoBuf_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023TiniaProtoBuf.proto\022\016tinia.protobuf\"\233\001"
    "\n\rTiniaProtoBuf\0224\n\006viewer\030\001 \003(\n2$.tinia."
    "protobuf.TiniaProtoBuf.Viewer\032T\n\006Viewer\022"
    "\022\n\nviewer_key\030\001 \002(\t\022\013\n\003rgb\030\002 \002(\014\022\r\n\005dept"
    "h\030\003 \001(\014\022\014\n\004view\030\004 \001(\t\022\014\n\004proj\030\005 \001(\t", 195);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "TiniaProtoBuf.proto", &protobuf_RegisterTypes);
  TiniaProtoBuf::default_instance_ = new TiniaProtoBuf();
  TiniaProtoBuf_Viewer::default_instance_ = new TiniaProtoBuf_Viewer();
  TiniaProtoBuf::default_instance_->InitAsDefaultInstance();
  TiniaProtoBuf_Viewer::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_TiniaProtoBuf_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_TiniaProtoBuf_2eproto {
  StaticDescriptorInitializer_TiniaProtoBuf_2eproto() {
    protobuf_AddDesc_TiniaProtoBuf_2eproto();
  }
} static_descriptor_initializer_TiniaProtoBuf_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int TiniaProtoBuf_Viewer::kViewerKeyFieldNumber;
const int TiniaProtoBuf_Viewer::kRgbFieldNumber;
const int TiniaProtoBuf_Viewer::kDepthFieldNumber;
const int TiniaProtoBuf_Viewer::kViewFieldNumber;
const int TiniaProtoBuf_Viewer::kProjFieldNumber;
#endif  // !_MSC_VER

TiniaProtoBuf_Viewer::TiniaProtoBuf_Viewer()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void TiniaProtoBuf_Viewer::InitAsDefaultInstance() {
}

TiniaProtoBuf_Viewer::TiniaProtoBuf_Viewer(const TiniaProtoBuf_Viewer& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void TiniaProtoBuf_Viewer::SharedCtor() {
  _cached_size_ = 0;
  viewer_key_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  rgb_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  depth_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  view_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  proj_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

TiniaProtoBuf_Viewer::~TiniaProtoBuf_Viewer() {
  SharedDtor();
}

void TiniaProtoBuf_Viewer::SharedDtor() {
  if (viewer_key_ != &::google::protobuf::internal::kEmptyString) {
    delete viewer_key_;
  }
  if (rgb_ != &::google::protobuf::internal::kEmptyString) {
    delete rgb_;
  }
  if (depth_ != &::google::protobuf::internal::kEmptyString) {
    delete depth_;
  }
  if (view_ != &::google::protobuf::internal::kEmptyString) {
    delete view_;
  }
  if (proj_ != &::google::protobuf::internal::kEmptyString) {
    delete proj_;
  }
  if (this != default_instance_) {
  }
}

void TiniaProtoBuf_Viewer::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TiniaProtoBuf_Viewer::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TiniaProtoBuf_Viewer_descriptor_;
}

const TiniaProtoBuf_Viewer& TiniaProtoBuf_Viewer::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_TiniaProtoBuf_2eproto();
  return *default_instance_;
}

TiniaProtoBuf_Viewer* TiniaProtoBuf_Viewer::default_instance_ = NULL;

TiniaProtoBuf_Viewer* TiniaProtoBuf_Viewer::New() const {
  return new TiniaProtoBuf_Viewer;
}

void TiniaProtoBuf_Viewer::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_viewer_key()) {
      if (viewer_key_ != &::google::protobuf::internal::kEmptyString) {
        viewer_key_->clear();
      }
    }
    if (has_rgb()) {
      if (rgb_ != &::google::protobuf::internal::kEmptyString) {
        rgb_->clear();
      }
    }
    if (has_depth()) {
      if (depth_ != &::google::protobuf::internal::kEmptyString) {
        depth_->clear();
      }
    }
    if (has_view()) {
      if (view_ != &::google::protobuf::internal::kEmptyString) {
        view_->clear();
      }
    }
    if (has_proj()) {
      if (proj_ != &::google::protobuf::internal::kEmptyString) {
        proj_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool TiniaProtoBuf_Viewer::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string viewer_key = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_viewer_key()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->viewer_key().data(), this->viewer_key().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_rgb;
        break;
      }

      // required bytes rgb = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_rgb:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_rgb()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_depth;
        break;
      }

      // optional bytes depth = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_depth:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_depth()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_view;
        break;
      }

      // optional string view = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_view:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_view()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->view().data(), this->view().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_proj;
        break;
      }

      // optional string proj = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_proj:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_proj()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->proj().data(), this->proj().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void TiniaProtoBuf_Viewer::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string viewer_key = 1;
  if (has_viewer_key()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->viewer_key().data(), this->viewer_key().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->viewer_key(), output);
  }

  // required bytes rgb = 2;
  if (has_rgb()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->rgb(), output);
  }

  // optional bytes depth = 3;
  if (has_depth()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->depth(), output);
  }

  // optional string view = 4;
  if (has_view()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->view().data(), this->view().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->view(), output);
  }

  // optional string proj = 5;
  if (has_proj()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->proj().data(), this->proj().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->proj(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* TiniaProtoBuf_Viewer::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string viewer_key = 1;
  if (has_viewer_key()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->viewer_key().data(), this->viewer_key().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->viewer_key(), target);
  }

  // required bytes rgb = 2;
  if (has_rgb()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->rgb(), target);
  }

  // optional bytes depth = 3;
  if (has_depth()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->depth(), target);
  }

  // optional string view = 4;
  if (has_view()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->view().data(), this->view().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->view(), target);
  }

  // optional string proj = 5;
  if (has_proj()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->proj().data(), this->proj().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->proj(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int TiniaProtoBuf_Viewer::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string viewer_key = 1;
    if (has_viewer_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->viewer_key());
    }

    // required bytes rgb = 2;
    if (has_rgb()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->rgb());
    }

    // optional bytes depth = 3;
    if (has_depth()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->depth());
    }

    // optional string view = 4;
    if (has_view()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->view());
    }

    // optional string proj = 5;
    if (has_proj()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->proj());
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

void TiniaProtoBuf_Viewer::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const TiniaProtoBuf_Viewer* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const TiniaProtoBuf_Viewer*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void TiniaProtoBuf_Viewer::MergeFrom(const TiniaProtoBuf_Viewer& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_viewer_key()) {
      set_viewer_key(from.viewer_key());
    }
    if (from.has_rgb()) {
      set_rgb(from.rgb());
    }
    if (from.has_depth()) {
      set_depth(from.depth());
    }
    if (from.has_view()) {
      set_view(from.view());
    }
    if (from.has_proj()) {
      set_proj(from.proj());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void TiniaProtoBuf_Viewer::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TiniaProtoBuf_Viewer::CopyFrom(const TiniaProtoBuf_Viewer& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TiniaProtoBuf_Viewer::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void TiniaProtoBuf_Viewer::Swap(TiniaProtoBuf_Viewer* other) {
  if (other != this) {
    std::swap(viewer_key_, other->viewer_key_);
    std::swap(rgb_, other->rgb_);
    std::swap(depth_, other->depth_);
    std::swap(view_, other->view_);
    std::swap(proj_, other->proj_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata TiniaProtoBuf_Viewer::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TiniaProtoBuf_Viewer_descriptor_;
  metadata.reflection = TiniaProtoBuf_Viewer_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int TiniaProtoBuf::kViewerFieldNumber;
#endif  // !_MSC_VER

TiniaProtoBuf::TiniaProtoBuf()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void TiniaProtoBuf::InitAsDefaultInstance() {
}

TiniaProtoBuf::TiniaProtoBuf(const TiniaProtoBuf& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void TiniaProtoBuf::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

TiniaProtoBuf::~TiniaProtoBuf() {
  SharedDtor();
}

void TiniaProtoBuf::SharedDtor() {
  if (this != default_instance_) {
  }
}

void TiniaProtoBuf::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TiniaProtoBuf::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TiniaProtoBuf_descriptor_;
}

const TiniaProtoBuf& TiniaProtoBuf::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_TiniaProtoBuf_2eproto();
  return *default_instance_;
}

TiniaProtoBuf* TiniaProtoBuf::default_instance_ = NULL;

TiniaProtoBuf* TiniaProtoBuf::New() const {
  return new TiniaProtoBuf;
}

void TiniaProtoBuf::Clear() {
  viewer_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool TiniaProtoBuf::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated group Viewer = 1 {
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_START_GROUP) {
         parse_viewer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadGroupNoVirtual(
                1, input, add_viewer()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(11)) goto parse_viewer;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void TiniaProtoBuf::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated group Viewer = 1 {
  for (int i = 0; i < this->viewer_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteGroupMaybeToArray(
      1, this->viewer(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* TiniaProtoBuf::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated group Viewer = 1 {
  for (int i = 0; i < this->viewer_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteGroupNoVirtualToArray(
        1, this->viewer(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int TiniaProtoBuf::ByteSize() const {
  int total_size = 0;

  // repeated group Viewer = 1 {
  total_size += 2 * this->viewer_size();
  for (int i = 0; i < this->viewer_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::GroupSizeNoVirtual(
        this->viewer(i));
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

void TiniaProtoBuf::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const TiniaProtoBuf* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const TiniaProtoBuf*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void TiniaProtoBuf::MergeFrom(const TiniaProtoBuf& from) {
  GOOGLE_CHECK_NE(&from, this);
  viewer_.MergeFrom(from.viewer_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void TiniaProtoBuf::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TiniaProtoBuf::CopyFrom(const TiniaProtoBuf& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TiniaProtoBuf::IsInitialized() const {

  for (int i = 0; i < viewer_size(); i++) {
    if (!this->viewer(i).IsInitialized()) return false;
  }
  return true;
}

void TiniaProtoBuf::Swap(TiniaProtoBuf* other) {
  if (other != this) {
    viewer_.Swap(&other->viewer_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata TiniaProtoBuf::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TiniaProtoBuf_descriptor_;
  metadata.reflection = TiniaProtoBuf_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace tinia

// @@protoc_insertion_point(global_scope)