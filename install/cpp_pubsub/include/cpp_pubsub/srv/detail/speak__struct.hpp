// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cpp_pubsub:srv/Speak.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB__SRV__DETAIL__SPEAK__STRUCT_HPP_
#define CPP_PUBSUB__SRV__DETAIL__SPEAK__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__cpp_pubsub__srv__Speak_Request __attribute__((deprecated))
#else
# define DEPRECATED__cpp_pubsub__srv__Speak_Request __declspec(deprecated)
#endif

namespace cpp_pubsub
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Speak_Request_
{
  using Type = Speak_Request_<ContainerAllocator>;

  explicit Speak_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->date = "";
    }
  }

  explicit Speak_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    date(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->date = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _date_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _date_type date;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__date(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->date = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cpp_pubsub::srv::Speak_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cpp_pubsub::srv::Speak_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cpp_pubsub::srv::Speak_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cpp_pubsub::srv::Speak_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cpp_pubsub::srv::Speak_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cpp_pubsub::srv::Speak_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cpp_pubsub::srv::Speak_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cpp_pubsub::srv::Speak_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cpp_pubsub::srv::Speak_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cpp_pubsub::srv::Speak_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cpp_pubsub__srv__Speak_Request
    std::shared_ptr<cpp_pubsub::srv::Speak_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cpp_pubsub__srv__Speak_Request
    std::shared_ptr<cpp_pubsub::srv::Speak_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Speak_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->date != other.date) {
      return false;
    }
    return true;
  }
  bool operator!=(const Speak_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Speak_Request_

// alias to use template instance with default allocator
using Speak_Request =
  cpp_pubsub::srv::Speak_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cpp_pubsub


#ifndef _WIN32
# define DEPRECATED__cpp_pubsub__srv__Speak_Response __attribute__((deprecated))
#else
# define DEPRECATED__cpp_pubsub__srv__Speak_Response __declspec(deprecated)
#endif

namespace cpp_pubsub
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Speak_Response_
{
  using Type = Speak_Response_<ContainerAllocator>;

  explicit Speak_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output = "";
    }
  }

  explicit Speak_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : output(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output = "";
    }
  }

  // field types and members
  using _output_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _output_type output;

  // setters for named parameter idiom
  Type & set__output(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->output = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cpp_pubsub::srv::Speak_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cpp_pubsub::srv::Speak_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cpp_pubsub::srv::Speak_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cpp_pubsub::srv::Speak_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cpp_pubsub::srv::Speak_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cpp_pubsub::srv::Speak_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cpp_pubsub::srv::Speak_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cpp_pubsub::srv::Speak_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cpp_pubsub::srv::Speak_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cpp_pubsub::srv::Speak_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cpp_pubsub__srv__Speak_Response
    std::shared_ptr<cpp_pubsub::srv::Speak_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cpp_pubsub__srv__Speak_Response
    std::shared_ptr<cpp_pubsub::srv::Speak_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Speak_Response_ & other) const
  {
    if (this->output != other.output) {
      return false;
    }
    return true;
  }
  bool operator!=(const Speak_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Speak_Response_

// alias to use template instance with default allocator
using Speak_Response =
  cpp_pubsub::srv::Speak_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cpp_pubsub

namespace cpp_pubsub
{

namespace srv
{

struct Speak
{
  using Request = cpp_pubsub::srv::Speak_Request;
  using Response = cpp_pubsub::srv::Speak_Response;
};

}  // namespace srv

}  // namespace cpp_pubsub

#endif  // CPP_PUBSUB__SRV__DETAIL__SPEAK__STRUCT_HPP_
