// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from cpp_pubsub:srv/Speak.idl
// generated code does not contain a copyright notice
#include "cpp_pubsub/srv/detail/speak__rosidl_typesupport_fastrtps_cpp.hpp"
#include "cpp_pubsub/srv/detail/speak__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace cpp_pubsub
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cpp_pubsub
cdr_serialize(
  const cpp_pubsub::srv::Speak_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;
  // Member: date
  cdr << ros_message.date;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cpp_pubsub
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  cpp_pubsub::srv::Speak_Request & ros_message)
{
  // Member: name
  cdr >> ros_message.name;

  // Member: date
  cdr >> ros_message.date;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cpp_pubsub
get_serialized_size(
  const cpp_pubsub::srv::Speak_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.name.size() + 1);
  // Member: date
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.date.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cpp_pubsub
max_serialized_size_Speak_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: date
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _Speak_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const cpp_pubsub::srv::Speak_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Speak_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<cpp_pubsub::srv::Speak_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Speak_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const cpp_pubsub::srv::Speak_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Speak_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Speak_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _Speak_Request__callbacks = {
  "cpp_pubsub::srv",
  "Speak_Request",
  _Speak_Request__cdr_serialize,
  _Speak_Request__cdr_deserialize,
  _Speak_Request__get_serialized_size,
  _Speak_Request__max_serialized_size
};

static rosidl_message_type_support_t _Speak_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Speak_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace cpp_pubsub

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_cpp_pubsub
const rosidl_message_type_support_t *
get_message_type_support_handle<cpp_pubsub::srv::Speak_Request>()
{
  return &cpp_pubsub::srv::typesupport_fastrtps_cpp::_Speak_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cpp_pubsub, srv, Speak_Request)() {
  return &cpp_pubsub::srv::typesupport_fastrtps_cpp::_Speak_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace cpp_pubsub
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cpp_pubsub
cdr_serialize(
  const cpp_pubsub::srv::Speak_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: output
  cdr << ros_message.output;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cpp_pubsub
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  cpp_pubsub::srv::Speak_Response & ros_message)
{
  // Member: output
  cdr >> ros_message.output;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cpp_pubsub
get_serialized_size(
  const cpp_pubsub::srv::Speak_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: output
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.output.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cpp_pubsub
max_serialized_size_Speak_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: output
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _Speak_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const cpp_pubsub::srv::Speak_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Speak_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<cpp_pubsub::srv::Speak_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Speak_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const cpp_pubsub::srv::Speak_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Speak_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Speak_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _Speak_Response__callbacks = {
  "cpp_pubsub::srv",
  "Speak_Response",
  _Speak_Response__cdr_serialize,
  _Speak_Response__cdr_deserialize,
  _Speak_Response__get_serialized_size,
  _Speak_Response__max_serialized_size
};

static rosidl_message_type_support_t _Speak_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Speak_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace cpp_pubsub

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_cpp_pubsub
const rosidl_message_type_support_t *
get_message_type_support_handle<cpp_pubsub::srv::Speak_Response>()
{
  return &cpp_pubsub::srv::typesupport_fastrtps_cpp::_Speak_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cpp_pubsub, srv, Speak_Response)() {
  return &cpp_pubsub::srv::typesupport_fastrtps_cpp::_Speak_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace cpp_pubsub
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _Speak__callbacks = {
  "cpp_pubsub::srv",
  "Speak",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cpp_pubsub, srv, Speak_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cpp_pubsub, srv, Speak_Response)(),
};

static rosidl_service_type_support_t _Speak__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Speak__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace cpp_pubsub

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_cpp_pubsub
const rosidl_service_type_support_t *
get_service_type_support_handle<cpp_pubsub::srv::Speak>()
{
  return &cpp_pubsub::srv::typesupport_fastrtps_cpp::_Speak__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cpp_pubsub, srv, Speak)() {
  return &cpp_pubsub::srv::typesupport_fastrtps_cpp::_Speak__handle;
}

#ifdef __cplusplus
}
#endif
