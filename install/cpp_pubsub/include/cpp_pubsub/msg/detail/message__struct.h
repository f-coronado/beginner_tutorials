// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cpp_pubsub:msg/Message.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB__MSG__DETAIL__MESSAGE__STRUCT_H_
#define CPP_PUBSUB__MSG__DETAIL__MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'response'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Message in the package cpp_pubsub.
typedef struct cpp_pubsub__msg__Message
{
  rosidl_runtime_c__String response;
} cpp_pubsub__msg__Message;

// Struct for a sequence of cpp_pubsub__msg__Message.
typedef struct cpp_pubsub__msg__Message__Sequence
{
  cpp_pubsub__msg__Message * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_pubsub__msg__Message__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CPP_PUBSUB__MSG__DETAIL__MESSAGE__STRUCT_H_
