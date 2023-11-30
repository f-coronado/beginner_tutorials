// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cpp_pubsub:srv/Speak.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB__SRV__DETAIL__SPEAK__BUILDER_HPP_
#define CPP_PUBSUB__SRV__DETAIL__SPEAK__BUILDER_HPP_

#include "cpp_pubsub/srv/detail/speak__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace cpp_pubsub
{

namespace srv
{

namespace builder
{

class Init_Speak_Request_date
{
public:
  explicit Init_Speak_Request_date(::cpp_pubsub::srv::Speak_Request & msg)
  : msg_(msg)
  {}
  ::cpp_pubsub::srv::Speak_Request date(::cpp_pubsub::srv::Speak_Request::_date_type arg)
  {
    msg_.date = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_pubsub::srv::Speak_Request msg_;
};

class Init_Speak_Request_name
{
public:
  Init_Speak_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Speak_Request_date name(::cpp_pubsub::srv::Speak_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Speak_Request_date(msg_);
  }

private:
  ::cpp_pubsub::srv::Speak_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_pubsub::srv::Speak_Request>()
{
  return cpp_pubsub::srv::builder::Init_Speak_Request_name();
}

}  // namespace cpp_pubsub


namespace cpp_pubsub
{

namespace srv
{

namespace builder
{

class Init_Speak_Response_output
{
public:
  Init_Speak_Response_output()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cpp_pubsub::srv::Speak_Response output(::cpp_pubsub::srv::Speak_Response::_output_type arg)
  {
    msg_.output = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_pubsub::srv::Speak_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_pubsub::srv::Speak_Response>()
{
  return cpp_pubsub::srv::builder::Init_Speak_Response_output();
}

}  // namespace cpp_pubsub

#endif  // CPP_PUBSUB__SRV__DETAIL__SPEAK__BUILDER_HPP_
