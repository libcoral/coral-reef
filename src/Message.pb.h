// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Message.proto

#ifndef PROTOBUF_Message_2eproto__INCLUDED
#define PROTOBUF_Message_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace reef {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Message_2eproto();
void protobuf_AssignDesc_Message_2eproto();
void protobuf_ShutdownFile_Message_2eproto();

class DataContainer;
class Argument;
class VirtualAddress;
class Message_Member;
class Message_New;
class Message;

enum Message_Type {
  Message_Type_TYPE_NEW = 0,
  Message_Type_TYPE_FIELD = 1,
  Message_Type_TYPE_CALL = 2,
  Message_Type_TYPE_RETURN = 3,
  Message_Type_TYPE_OTHER = 4
};
bool Message_Type_IsValid(int value);
const Message_Type Message_Type_Type_MIN = Message_Type_TYPE_NEW;
const Message_Type Message_Type_Type_MAX = Message_Type_TYPE_OTHER;
const int Message_Type_Type_ARRAYSIZE = Message_Type_Type_MAX + 1;

const ::google::protobuf::EnumDescriptor* Message_Type_descriptor();
inline const ::std::string& Message_Type_Name(Message_Type value) {
  return ::google::protobuf::internal::NameOfEnum(
    Message_Type_descriptor(), value);
}
inline bool Message_Type_Parse(
    const ::std::string& name, Message_Type* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Message_Type>(
    Message_Type_descriptor(), name, value);
}
// ===================================================================

class DataContainer : public ::google::protobuf::Message {
 public:
  DataContainer();
  virtual ~DataContainer();
  
  DataContainer(const DataContainer& from);
  
  inline DataContainer& operator=(const DataContainer& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const DataContainer& default_instance();
  
  void Swap(DataContainer* other);
  
  // implements Message ----------------------------------------------
  
  DataContainer* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DataContainer& from);
  void MergeFrom(const DataContainer& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // optional bool boolean = 1;
  inline bool has_boolean() const;
  inline void clear_boolean();
  static const int kBooleanFieldNumber = 1;
  inline bool boolean() const;
  inline void set_boolean(bool value);
  
  // optional string str = 2;
  inline bool has_str() const;
  inline void clear_str();
  static const int kStrFieldNumber = 2;
  inline const ::std::string& str() const;
  inline void set_str(const ::std::string& value);
  inline void set_str(const char* value);
  inline void set_str(const char* value, size_t size);
  inline ::std::string* mutable_str();
  inline ::std::string* release_str();
  
  // optional double numeric = 3;
  inline bool has_numeric() const;
  inline void clear_numeric();
  static const int kNumericFieldNumber = 3;
  inline double numeric() const;
  inline void set_numeric(double value);
  
  // @@protoc_insertion_point(class_scope:reef.DataContainer)
 private:
  inline void set_has_boolean();
  inline void clear_has_boolean();
  inline void set_has_str();
  inline void clear_has_str();
  inline void set_has_numeric();
  inline void clear_has_numeric();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* str_;
  double numeric_;
  bool boolean_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  friend void  protobuf_AddDesc_Message_2eproto();
  friend void protobuf_AssignDesc_Message_2eproto();
  friend void protobuf_ShutdownFile_Message_2eproto();
  
  void InitAsDefaultInstance();
  static DataContainer* default_instance_;
};
// -------------------------------------------------------------------

class Argument : public ::google::protobuf::Message {
 public:
  Argument();
  virtual ~Argument();
  
  Argument(const Argument& from);
  
  inline Argument& operator=(const Argument& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Argument& default_instance();
  
  void Swap(Argument* other);
  
  // implements Message ----------------------------------------------
  
  Argument* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Argument& from);
  void MergeFrom(const Argument& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // repeated .reef.DataContainer data = 1;
  inline int data_size() const;
  inline void clear_data();
  static const int kDataFieldNumber = 1;
  inline const ::reef::DataContainer& data(int index) const;
  inline ::reef::DataContainer* mutable_data(int index);
  inline ::reef::DataContainer* add_data();
  inline const ::google::protobuf::RepeatedPtrField< ::reef::DataContainer >&
      data() const;
  inline ::google::protobuf::RepeatedPtrField< ::reef::DataContainer >*
      mutable_data();
  
  // @@protoc_insertion_point(class_scope:reef.Argument)
 private:
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::RepeatedPtrField< ::reef::DataContainer > data_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_Message_2eproto();
  friend void protobuf_AssignDesc_Message_2eproto();
  friend void protobuf_ShutdownFile_Message_2eproto();
  
  void InitAsDefaultInstance();
  static Argument* default_instance_;
};
// -------------------------------------------------------------------

class VirtualAddress : public ::google::protobuf::Message {
 public:
  VirtualAddress();
  virtual ~VirtualAddress();
  
  VirtualAddress(const VirtualAddress& from);
  
  inline VirtualAddress& operator=(const VirtualAddress& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const VirtualAddress& default_instance();
  
  void Swap(VirtualAddress* other);
  
  // implements Message ----------------------------------------------
  
  VirtualAddress* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const VirtualAddress& from);
  void MergeFrom(const VirtualAddress& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 address = 1;
  inline bool has_address() const;
  inline void clear_address();
  static const int kAddressFieldNumber = 1;
  inline ::google::protobuf::int32 address() const;
  inline void set_address(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:reef.VirtualAddress)
 private:
  inline void set_has_address();
  inline void clear_has_address();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int32 address_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_Message_2eproto();
  friend void protobuf_AssignDesc_Message_2eproto();
  friend void protobuf_ShutdownFile_Message_2eproto();
  
  void InitAsDefaultInstance();
  static VirtualAddress* default_instance_;
};
// -------------------------------------------------------------------

class Message_Member : public ::google::protobuf::Message {
 public:
  Message_Member();
  virtual ~Message_Member();
  
  Message_Member(const Message_Member& from);
  
  inline Message_Member& operator=(const Message_Member& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Message_Member& default_instance();
  
  void Swap(Message_Member* other);
  
  // implements Message ----------------------------------------------
  
  Message_Member* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Message_Member& from);
  void MergeFrom(const Message_Member& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required bool hasReturn = 1;
  inline bool has_hasreturn() const;
  inline void clear_hasreturn();
  static const int kHasReturnFieldNumber = 1;
  inline bool hasreturn() const;
  inline void set_hasreturn(bool value);
  
  // required uint32 serviceIndex = 2;
  inline bool has_serviceindex() const;
  inline void clear_serviceindex();
  static const int kServiceIndexFieldNumber = 2;
  inline ::google::protobuf::uint32 serviceindex() const;
  inline void set_serviceindex(::google::protobuf::uint32 value);
  
  // required uint32 memberIndex = 3;
  inline bool has_memberindex() const;
  inline void clear_memberindex();
  static const int kMemberIndexFieldNumber = 3;
  inline ::google::protobuf::uint32 memberindex() const;
  inline void set_memberindex(::google::protobuf::uint32 value);
  
  // repeated .reef.Argument arguments = 4;
  inline int arguments_size() const;
  inline void clear_arguments();
  static const int kArgumentsFieldNumber = 4;
  inline const ::reef::Argument& arguments(int index) const;
  inline ::reef::Argument* mutable_arguments(int index);
  inline ::reef::Argument* add_arguments();
  inline const ::google::protobuf::RepeatedPtrField< ::reef::Argument >&
      arguments() const;
  inline ::google::protobuf::RepeatedPtrField< ::reef::Argument >*
      mutable_arguments();
  
  // @@protoc_insertion_point(class_scope:reef.Message_Member)
 private:
  inline void set_has_hasreturn();
  inline void clear_has_hasreturn();
  inline void set_has_serviceindex();
  inline void clear_has_serviceindex();
  inline void set_has_memberindex();
  inline void clear_has_memberindex();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  bool hasreturn_;
  ::google::protobuf::uint32 serviceindex_;
  ::google::protobuf::RepeatedPtrField< ::reef::Argument > arguments_;
  ::google::protobuf::uint32 memberindex_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];
  
  friend void  protobuf_AddDesc_Message_2eproto();
  friend void protobuf_AssignDesc_Message_2eproto();
  friend void protobuf_ShutdownFile_Message_2eproto();
  
  void InitAsDefaultInstance();
  static Message_Member* default_instance_;
};
// -------------------------------------------------------------------

class Message_New : public ::google::protobuf::Message {
 public:
  Message_New();
  virtual ~Message_New();
  
  Message_New(const Message_New& from);
  
  inline Message_New& operator=(const Message_New& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Message_New& default_instance();
  
  void Swap(Message_New* other);
  
  // implements Message ----------------------------------------------
  
  Message_New* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Message_New& from);
  void MergeFrom(const Message_New& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string componentTypeName = 1;
  inline bool has_componenttypename() const;
  inline void clear_componenttypename();
  static const int kComponentTypeNameFieldNumber = 1;
  inline const ::std::string& componenttypename() const;
  inline void set_componenttypename(const ::std::string& value);
  inline void set_componenttypename(const char* value);
  inline void set_componenttypename(const char* value, size_t size);
  inline ::std::string* mutable_componenttypename();
  inline ::std::string* release_componenttypename();
  
  // @@protoc_insertion_point(class_scope:reef.Message_New)
 private:
  inline void set_has_componenttypename();
  inline void clear_has_componenttypename();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* componenttypename_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_Message_2eproto();
  friend void protobuf_AssignDesc_Message_2eproto();
  friend void protobuf_ShutdownFile_Message_2eproto();
  
  void InitAsDefaultInstance();
  static Message_New* default_instance_;
};
// -------------------------------------------------------------------

class Message : public ::google::protobuf::Message {
 public:
  Message();
  virtual ~Message();
  
  Message(const Message& from);
  
  inline Message& operator=(const Message& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Message& default_instance();
  
  void Swap(Message* other);
  
  // implements Message ----------------------------------------------
  
  Message* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Message& from);
  void MergeFrom(const Message& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  typedef Message_Type Type;
  static const Type TYPE_NEW = Message_Type_TYPE_NEW;
  static const Type TYPE_FIELD = Message_Type_TYPE_FIELD;
  static const Type TYPE_CALL = Message_Type_TYPE_CALL;
  static const Type TYPE_RETURN = Message_Type_TYPE_RETURN;
  static const Type TYPE_OTHER = Message_Type_TYPE_OTHER;
  static inline bool Type_IsValid(int value) {
    return Message_Type_IsValid(value);
  }
  static const Type Type_MIN =
    Message_Type_Type_MIN;
  static const Type Type_MAX =
    Message_Type_Type_MAX;
  static const int Type_ARRAYSIZE =
    Message_Type_Type_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Type_descriptor() {
    return Message_Type_descriptor();
  }
  static inline const ::std::string& Type_Name(Type value) {
    return Message_Type_Name(value);
  }
  static inline bool Type_Parse(const ::std::string& name,
      Type* value) {
    return Message_Type_Parse(name, value);
  }
  
  // accessors -------------------------------------------------------
  
  // required .reef.Message.Type type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::reef::Message_Type type() const;
  inline void set_type(::reef::Message_Type value);
  
  // required uint32 destination = 2;
  inline bool has_destination() const;
  inline void clear_destination();
  static const int kDestinationFieldNumber = 2;
  inline ::google::protobuf::uint32 destination() const;
  inline void set_destination(::google::protobuf::uint32 value);
  
  // optional .reef.Message_New msgNew = 3;
  inline bool has_msgnew() const;
  inline void clear_msgnew();
  static const int kMsgNewFieldNumber = 3;
  inline const ::reef::Message_New& msgnew() const;
  inline ::reef::Message_New* mutable_msgnew();
  inline ::reef::Message_New* release_msgnew();
  
  // optional .reef.Message_Member msgMember = 4;
  inline bool has_msgmember() const;
  inline void clear_msgmember();
  static const int kMsgMemberFieldNumber = 4;
  inline const ::reef::Message_Member& msgmember() const;
  inline ::reef::Message_Member* mutable_msgmember();
  inline ::reef::Message_Member* release_msgmember();
  
  // @@protoc_insertion_point(class_scope:reef.Message)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_destination();
  inline void clear_has_destination();
  inline void set_has_msgnew();
  inline void clear_has_msgnew();
  inline void set_has_msgmember();
  inline void clear_has_msgmember();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  int type_;
  ::google::protobuf::uint32 destination_;
  ::reef::Message_New* msgnew_;
  ::reef::Message_Member* msgmember_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];
  
  friend void  protobuf_AddDesc_Message_2eproto();
  friend void protobuf_AssignDesc_Message_2eproto();
  friend void protobuf_ShutdownFile_Message_2eproto();
  
  void InitAsDefaultInstance();
  static Message* default_instance_;
};
// ===================================================================


// ===================================================================

// DataContainer

// optional bool boolean = 1;
inline bool DataContainer::has_boolean() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DataContainer::set_has_boolean() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DataContainer::clear_has_boolean() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DataContainer::clear_boolean() {
  boolean_ = false;
  clear_has_boolean();
}
inline bool DataContainer::boolean() const {
  return boolean_;
}
inline void DataContainer::set_boolean(bool value) {
  set_has_boolean();
  boolean_ = value;
}

// optional string str = 2;
inline bool DataContainer::has_str() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void DataContainer::set_has_str() {
  _has_bits_[0] |= 0x00000002u;
}
inline void DataContainer::clear_has_str() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void DataContainer::clear_str() {
  if (str_ != &::google::protobuf::internal::kEmptyString) {
    str_->clear();
  }
  clear_has_str();
}
inline const ::std::string& DataContainer::str() const {
  return *str_;
}
inline void DataContainer::set_str(const ::std::string& value) {
  set_has_str();
  if (str_ == &::google::protobuf::internal::kEmptyString) {
    str_ = new ::std::string;
  }
  str_->assign(value);
}
inline void DataContainer::set_str(const char* value) {
  set_has_str();
  if (str_ == &::google::protobuf::internal::kEmptyString) {
    str_ = new ::std::string;
  }
  str_->assign(value);
}
inline void DataContainer::set_str(const char* value, size_t size) {
  set_has_str();
  if (str_ == &::google::protobuf::internal::kEmptyString) {
    str_ = new ::std::string;
  }
  str_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* DataContainer::mutable_str() {
  set_has_str();
  if (str_ == &::google::protobuf::internal::kEmptyString) {
    str_ = new ::std::string;
  }
  return str_;
}
inline ::std::string* DataContainer::release_str() {
  clear_has_str();
  if (str_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = str_;
    str_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional double numeric = 3;
inline bool DataContainer::has_numeric() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void DataContainer::set_has_numeric() {
  _has_bits_[0] |= 0x00000004u;
}
inline void DataContainer::clear_has_numeric() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void DataContainer::clear_numeric() {
  numeric_ = 0;
  clear_has_numeric();
}
inline double DataContainer::numeric() const {
  return numeric_;
}
inline void DataContainer::set_numeric(double value) {
  set_has_numeric();
  numeric_ = value;
}

// -------------------------------------------------------------------

// Argument

// repeated .reef.DataContainer data = 1;
inline int Argument::data_size() const {
  return data_.size();
}
inline void Argument::clear_data() {
  data_.Clear();
}
inline const ::reef::DataContainer& Argument::data(int index) const {
  return data_.Get(index);
}
inline ::reef::DataContainer* Argument::mutable_data(int index) {
  return data_.Mutable(index);
}
inline ::reef::DataContainer* Argument::add_data() {
  return data_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::reef::DataContainer >&
Argument::data() const {
  return data_;
}
inline ::google::protobuf::RepeatedPtrField< ::reef::DataContainer >*
Argument::mutable_data() {
  return &data_;
}

// -------------------------------------------------------------------

// VirtualAddress

// required int32 address = 1;
inline bool VirtualAddress::has_address() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void VirtualAddress::set_has_address() {
  _has_bits_[0] |= 0x00000001u;
}
inline void VirtualAddress::clear_has_address() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void VirtualAddress::clear_address() {
  address_ = 0;
  clear_has_address();
}
inline ::google::protobuf::int32 VirtualAddress::address() const {
  return address_;
}
inline void VirtualAddress::set_address(::google::protobuf::int32 value) {
  set_has_address();
  address_ = value;
}

// -------------------------------------------------------------------

// Message_Member

// required bool hasReturn = 1;
inline bool Message_Member::has_hasreturn() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Message_Member::set_has_hasreturn() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Message_Member::clear_has_hasreturn() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Message_Member::clear_hasreturn() {
  hasreturn_ = false;
  clear_has_hasreturn();
}
inline bool Message_Member::hasreturn() const {
  return hasreturn_;
}
inline void Message_Member::set_hasreturn(bool value) {
  set_has_hasreturn();
  hasreturn_ = value;
}

// required uint32 serviceIndex = 2;
inline bool Message_Member::has_serviceindex() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Message_Member::set_has_serviceindex() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Message_Member::clear_has_serviceindex() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Message_Member::clear_serviceindex() {
  serviceindex_ = 0u;
  clear_has_serviceindex();
}
inline ::google::protobuf::uint32 Message_Member::serviceindex() const {
  return serviceindex_;
}
inline void Message_Member::set_serviceindex(::google::protobuf::uint32 value) {
  set_has_serviceindex();
  serviceindex_ = value;
}

// required uint32 memberIndex = 3;
inline bool Message_Member::has_memberindex() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Message_Member::set_has_memberindex() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Message_Member::clear_has_memberindex() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Message_Member::clear_memberindex() {
  memberindex_ = 0u;
  clear_has_memberindex();
}
inline ::google::protobuf::uint32 Message_Member::memberindex() const {
  return memberindex_;
}
inline void Message_Member::set_memberindex(::google::protobuf::uint32 value) {
  set_has_memberindex();
  memberindex_ = value;
}

// repeated .reef.Argument arguments = 4;
inline int Message_Member::arguments_size() const {
  return arguments_.size();
}
inline void Message_Member::clear_arguments() {
  arguments_.Clear();
}
inline const ::reef::Argument& Message_Member::arguments(int index) const {
  return arguments_.Get(index);
}
inline ::reef::Argument* Message_Member::mutable_arguments(int index) {
  return arguments_.Mutable(index);
}
inline ::reef::Argument* Message_Member::add_arguments() {
  return arguments_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::reef::Argument >&
Message_Member::arguments() const {
  return arguments_;
}
inline ::google::protobuf::RepeatedPtrField< ::reef::Argument >*
Message_Member::mutable_arguments() {
  return &arguments_;
}

// -------------------------------------------------------------------

// Message_New

// required string componentTypeName = 1;
inline bool Message_New::has_componenttypename() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Message_New::set_has_componenttypename() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Message_New::clear_has_componenttypename() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Message_New::clear_componenttypename() {
  if (componenttypename_ != &::google::protobuf::internal::kEmptyString) {
    componenttypename_->clear();
  }
  clear_has_componenttypename();
}
inline const ::std::string& Message_New::componenttypename() const {
  return *componenttypename_;
}
inline void Message_New::set_componenttypename(const ::std::string& value) {
  set_has_componenttypename();
  if (componenttypename_ == &::google::protobuf::internal::kEmptyString) {
    componenttypename_ = new ::std::string;
  }
  componenttypename_->assign(value);
}
inline void Message_New::set_componenttypename(const char* value) {
  set_has_componenttypename();
  if (componenttypename_ == &::google::protobuf::internal::kEmptyString) {
    componenttypename_ = new ::std::string;
  }
  componenttypename_->assign(value);
}
inline void Message_New::set_componenttypename(const char* value, size_t size) {
  set_has_componenttypename();
  if (componenttypename_ == &::google::protobuf::internal::kEmptyString) {
    componenttypename_ = new ::std::string;
  }
  componenttypename_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Message_New::mutable_componenttypename() {
  set_has_componenttypename();
  if (componenttypename_ == &::google::protobuf::internal::kEmptyString) {
    componenttypename_ = new ::std::string;
  }
  return componenttypename_;
}
inline ::std::string* Message_New::release_componenttypename() {
  clear_has_componenttypename();
  if (componenttypename_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = componenttypename_;
    componenttypename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// -------------------------------------------------------------------

// Message

// required .reef.Message.Type type = 1;
inline bool Message::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Message::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Message::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Message::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::reef::Message_Type Message::type() const {
  return static_cast< ::reef::Message_Type >(type_);
}
inline void Message::set_type(::reef::Message_Type value) {
  GOOGLE_DCHECK(::reef::Message_Type_IsValid(value));
  set_has_type();
  type_ = value;
}

// required uint32 destination = 2;
inline bool Message::has_destination() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Message::set_has_destination() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Message::clear_has_destination() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Message::clear_destination() {
  destination_ = 0u;
  clear_has_destination();
}
inline ::google::protobuf::uint32 Message::destination() const {
  return destination_;
}
inline void Message::set_destination(::google::protobuf::uint32 value) {
  set_has_destination();
  destination_ = value;
}

// optional .reef.Message_New msgNew = 3;
inline bool Message::has_msgnew() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Message::set_has_msgnew() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Message::clear_has_msgnew() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Message::clear_msgnew() {
  if (msgnew_ != NULL) msgnew_->::reef::Message_New::Clear();
  clear_has_msgnew();
}
inline const ::reef::Message_New& Message::msgnew() const {
  return msgnew_ != NULL ? *msgnew_ : *default_instance_->msgnew_;
}
inline ::reef::Message_New* Message::mutable_msgnew() {
  set_has_msgnew();
  if (msgnew_ == NULL) msgnew_ = new ::reef::Message_New;
  return msgnew_;
}
inline ::reef::Message_New* Message::release_msgnew() {
  clear_has_msgnew();
  ::reef::Message_New* temp = msgnew_;
  msgnew_ = NULL;
  return temp;
}

// optional .reef.Message_Member msgMember = 4;
inline bool Message::has_msgmember() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Message::set_has_msgmember() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Message::clear_has_msgmember() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Message::clear_msgmember() {
  if (msgmember_ != NULL) msgmember_->::reef::Message_Member::Clear();
  clear_has_msgmember();
}
inline const ::reef::Message_Member& Message::msgmember() const {
  return msgmember_ != NULL ? *msgmember_ : *default_instance_->msgmember_;
}
inline ::reef::Message_Member* Message::mutable_msgmember() {
  set_has_msgmember();
  if (msgmember_ == NULL) msgmember_ = new ::reef::Message_Member;
  return msgmember_;
}
inline ::reef::Message_Member* Message::release_msgmember() {
  clear_has_msgmember();
  ::reef::Message_Member* temp = msgmember_;
  msgmember_ = NULL;
  return temp;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace reef

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::reef::Message_Type>() {
  return ::reef::Message_Type_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Message_2eproto__INCLUDED
