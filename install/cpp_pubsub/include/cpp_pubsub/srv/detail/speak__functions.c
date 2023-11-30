// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cpp_pubsub:srv/Speak.idl
// generated code does not contain a copyright notice
#include "cpp_pubsub/srv/detail/speak__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include directives for member types
// Member `name`
// Member `date`
#include "rosidl_runtime_c/string_functions.h"

bool
cpp_pubsub__srv__Speak_Request__init(cpp_pubsub__srv__Speak_Request * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    cpp_pubsub__srv__Speak_Request__fini(msg);
    return false;
  }
  // date
  if (!rosidl_runtime_c__String__init(&msg->date)) {
    cpp_pubsub__srv__Speak_Request__fini(msg);
    return false;
  }
  return true;
}

void
cpp_pubsub__srv__Speak_Request__fini(cpp_pubsub__srv__Speak_Request * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // date
  rosidl_runtime_c__String__fini(&msg->date);
}

bool
cpp_pubsub__srv__Speak_Request__are_equal(const cpp_pubsub__srv__Speak_Request * lhs, const cpp_pubsub__srv__Speak_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // date
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->date), &(rhs->date)))
  {
    return false;
  }
  return true;
}

bool
cpp_pubsub__srv__Speak_Request__copy(
  const cpp_pubsub__srv__Speak_Request * input,
  cpp_pubsub__srv__Speak_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // date
  if (!rosidl_runtime_c__String__copy(
      &(input->date), &(output->date)))
  {
    return false;
  }
  return true;
}

cpp_pubsub__srv__Speak_Request *
cpp_pubsub__srv__Speak_Request__create()
{
  cpp_pubsub__srv__Speak_Request * msg = (cpp_pubsub__srv__Speak_Request *)malloc(sizeof(cpp_pubsub__srv__Speak_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_pubsub__srv__Speak_Request));
  bool success = cpp_pubsub__srv__Speak_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
cpp_pubsub__srv__Speak_Request__destroy(cpp_pubsub__srv__Speak_Request * msg)
{
  if (msg) {
    cpp_pubsub__srv__Speak_Request__fini(msg);
  }
  free(msg);
}


bool
cpp_pubsub__srv__Speak_Request__Sequence__init(cpp_pubsub__srv__Speak_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  cpp_pubsub__srv__Speak_Request * data = NULL;
  if (size) {
    data = (cpp_pubsub__srv__Speak_Request *)calloc(size, sizeof(cpp_pubsub__srv__Speak_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_pubsub__srv__Speak_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_pubsub__srv__Speak_Request__fini(&data[i - 1]);
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
cpp_pubsub__srv__Speak_Request__Sequence__fini(cpp_pubsub__srv__Speak_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cpp_pubsub__srv__Speak_Request__fini(&array->data[i]);
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

cpp_pubsub__srv__Speak_Request__Sequence *
cpp_pubsub__srv__Speak_Request__Sequence__create(size_t size)
{
  cpp_pubsub__srv__Speak_Request__Sequence * array = (cpp_pubsub__srv__Speak_Request__Sequence *)malloc(sizeof(cpp_pubsub__srv__Speak_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = cpp_pubsub__srv__Speak_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
cpp_pubsub__srv__Speak_Request__Sequence__destroy(cpp_pubsub__srv__Speak_Request__Sequence * array)
{
  if (array) {
    cpp_pubsub__srv__Speak_Request__Sequence__fini(array);
  }
  free(array);
}

bool
cpp_pubsub__srv__Speak_Request__Sequence__are_equal(const cpp_pubsub__srv__Speak_Request__Sequence * lhs, const cpp_pubsub__srv__Speak_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_pubsub__srv__Speak_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_pubsub__srv__Speak_Request__Sequence__copy(
  const cpp_pubsub__srv__Speak_Request__Sequence * input,
  cpp_pubsub__srv__Speak_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cpp_pubsub__srv__Speak_Request);
    cpp_pubsub__srv__Speak_Request * data =
      (cpp_pubsub__srv__Speak_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_pubsub__srv__Speak_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          cpp_pubsub__srv__Speak_Request__fini(&data[i]);
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
    if (!cpp_pubsub__srv__Speak_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `output`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
cpp_pubsub__srv__Speak_Response__init(cpp_pubsub__srv__Speak_Response * msg)
{
  if (!msg) {
    return false;
  }
  // output
  if (!rosidl_runtime_c__String__init(&msg->output)) {
    cpp_pubsub__srv__Speak_Response__fini(msg);
    return false;
  }
  return true;
}

void
cpp_pubsub__srv__Speak_Response__fini(cpp_pubsub__srv__Speak_Response * msg)
{
  if (!msg) {
    return;
  }
  // output
  rosidl_runtime_c__String__fini(&msg->output);
}

bool
cpp_pubsub__srv__Speak_Response__are_equal(const cpp_pubsub__srv__Speak_Response * lhs, const cpp_pubsub__srv__Speak_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // output
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->output), &(rhs->output)))
  {
    return false;
  }
  return true;
}

bool
cpp_pubsub__srv__Speak_Response__copy(
  const cpp_pubsub__srv__Speak_Response * input,
  cpp_pubsub__srv__Speak_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // output
  if (!rosidl_runtime_c__String__copy(
      &(input->output), &(output->output)))
  {
    return false;
  }
  return true;
}

cpp_pubsub__srv__Speak_Response *
cpp_pubsub__srv__Speak_Response__create()
{
  cpp_pubsub__srv__Speak_Response * msg = (cpp_pubsub__srv__Speak_Response *)malloc(sizeof(cpp_pubsub__srv__Speak_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_pubsub__srv__Speak_Response));
  bool success = cpp_pubsub__srv__Speak_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
cpp_pubsub__srv__Speak_Response__destroy(cpp_pubsub__srv__Speak_Response * msg)
{
  if (msg) {
    cpp_pubsub__srv__Speak_Response__fini(msg);
  }
  free(msg);
}


bool
cpp_pubsub__srv__Speak_Response__Sequence__init(cpp_pubsub__srv__Speak_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  cpp_pubsub__srv__Speak_Response * data = NULL;
  if (size) {
    data = (cpp_pubsub__srv__Speak_Response *)calloc(size, sizeof(cpp_pubsub__srv__Speak_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_pubsub__srv__Speak_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_pubsub__srv__Speak_Response__fini(&data[i - 1]);
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
cpp_pubsub__srv__Speak_Response__Sequence__fini(cpp_pubsub__srv__Speak_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cpp_pubsub__srv__Speak_Response__fini(&array->data[i]);
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

cpp_pubsub__srv__Speak_Response__Sequence *
cpp_pubsub__srv__Speak_Response__Sequence__create(size_t size)
{
  cpp_pubsub__srv__Speak_Response__Sequence * array = (cpp_pubsub__srv__Speak_Response__Sequence *)malloc(sizeof(cpp_pubsub__srv__Speak_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = cpp_pubsub__srv__Speak_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
cpp_pubsub__srv__Speak_Response__Sequence__destroy(cpp_pubsub__srv__Speak_Response__Sequence * array)
{
  if (array) {
    cpp_pubsub__srv__Speak_Response__Sequence__fini(array);
  }
  free(array);
}

bool
cpp_pubsub__srv__Speak_Response__Sequence__are_equal(const cpp_pubsub__srv__Speak_Response__Sequence * lhs, const cpp_pubsub__srv__Speak_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_pubsub__srv__Speak_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_pubsub__srv__Speak_Response__Sequence__copy(
  const cpp_pubsub__srv__Speak_Response__Sequence * input,
  cpp_pubsub__srv__Speak_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cpp_pubsub__srv__Speak_Response);
    cpp_pubsub__srv__Speak_Response * data =
      (cpp_pubsub__srv__Speak_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_pubsub__srv__Speak_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          cpp_pubsub__srv__Speak_Response__fini(&data[i]);
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
    if (!cpp_pubsub__srv__Speak_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
