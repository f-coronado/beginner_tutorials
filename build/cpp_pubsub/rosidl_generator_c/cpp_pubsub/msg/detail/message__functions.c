// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cpp_pubsub:msg/Message.idl
// generated code does not contain a copyright notice
#include "cpp_pubsub/msg/detail/message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `response`
#include "rosidl_runtime_c/string_functions.h"

bool
cpp_pubsub__msg__Message__init(cpp_pubsub__msg__Message * msg)
{
  if (!msg) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__init(&msg->response)) {
    cpp_pubsub__msg__Message__fini(msg);
    return false;
  }
  return true;
}

void
cpp_pubsub__msg__Message__fini(cpp_pubsub__msg__Message * msg)
{
  if (!msg) {
    return;
  }
  // response
  rosidl_runtime_c__String__fini(&msg->response);
}

bool
cpp_pubsub__msg__Message__are_equal(const cpp_pubsub__msg__Message * lhs, const cpp_pubsub__msg__Message * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
cpp_pubsub__msg__Message__copy(
  const cpp_pubsub__msg__Message * input,
  cpp_pubsub__msg__Message * output)
{
  if (!input || !output) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

cpp_pubsub__msg__Message *
cpp_pubsub__msg__Message__create()
{
  cpp_pubsub__msg__Message * msg = (cpp_pubsub__msg__Message *)malloc(sizeof(cpp_pubsub__msg__Message));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_pubsub__msg__Message));
  bool success = cpp_pubsub__msg__Message__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
cpp_pubsub__msg__Message__destroy(cpp_pubsub__msg__Message * msg)
{
  if (msg) {
    cpp_pubsub__msg__Message__fini(msg);
  }
  free(msg);
}


bool
cpp_pubsub__msg__Message__Sequence__init(cpp_pubsub__msg__Message__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  cpp_pubsub__msg__Message * data = NULL;
  if (size) {
    data = (cpp_pubsub__msg__Message *)calloc(size, sizeof(cpp_pubsub__msg__Message));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_pubsub__msg__Message__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_pubsub__msg__Message__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cpp_pubsub__msg__Message__Sequence__fini(cpp_pubsub__msg__Message__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cpp_pubsub__msg__Message__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cpp_pubsub__msg__Message__Sequence *
cpp_pubsub__msg__Message__Sequence__create(size_t size)
{
  cpp_pubsub__msg__Message__Sequence * array = (cpp_pubsub__msg__Message__Sequence *)malloc(sizeof(cpp_pubsub__msg__Message__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = cpp_pubsub__msg__Message__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
cpp_pubsub__msg__Message__Sequence__destroy(cpp_pubsub__msg__Message__Sequence * array)
{
  if (array) {
    cpp_pubsub__msg__Message__Sequence__fini(array);
  }
  free(array);
}

bool
cpp_pubsub__msg__Message__Sequence__are_equal(const cpp_pubsub__msg__Message__Sequence * lhs, const cpp_pubsub__msg__Message__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_pubsub__msg__Message__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_pubsub__msg__Message__Sequence__copy(
  const cpp_pubsub__msg__Message__Sequence * input,
  cpp_pubsub__msg__Message__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cpp_pubsub__msg__Message);
    cpp_pubsub__msg__Message * data =
      (cpp_pubsub__msg__Message *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_pubsub__msg__Message__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          cpp_pubsub__msg__Message__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_pubsub__msg__Message__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
