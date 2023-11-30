// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cpp_pubsub:srv/Speak.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB__SRV__DETAIL__SPEAK__STRUCT_H_
#define CPP_PUBSUB__SRV__DETAIL__SPEAK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'date'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/Speak in the package cpp_pubsub.
typedef struct cpp_pubsub__srv__Speak_Request
{
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String date;
} cpp_pubsub__srv__Speak_Request;

// Struct for a sequence of cpp_pubsub__srv__Speak_Request.
typedef struct cpp_pubsub__srv__Speak_Request__Sequence
{
  cpp_pubsub__srv__Speak_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_pubsub__srv__Speak_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'output'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/Speak in the package cpp_pubsub.
typedef struct cpp_pubsub__srv__Speak_Response
{
  rosidl_runtime_c__String output;
} cpp_pubsub__srv__Speak_Response;

// Struct for a sequence of cpp_pubsub__srv__Speak_Response.
typedef struct cpp_pubsub__srv__Speak_Response__Sequence
{
  cpp_pubsub__srv__Speak_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_pubsub__srv__Speak_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CPP_PUBSUB__SRV__DETAIL__SPEAK__STRUCT_H_
