// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cpp_pubsub:msg/Message.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB__MSG__DETAIL__MESSAGE__BUILDER_HPP_
#define CPP_PUBSUB__MSG__DETAIL__MESSAGE__BUILDER_HPP_

#include "cpp_pubsub/msg/detail/message__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace cpp_pubsub
{

namespace msg
{

namespace builder
{

class Init_Message_response
{
public:
  Init_Message_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cpp_pubsub::msg::Message response(::cpp_pubsub::msg::Message::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_pubsub::msg::Message msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_pubsub::msg::Message>()
{
  return cpp_pubsub::msg::builder::Init_Message_response();
}

}  // namespace cpp_pubsub

#endif  // CPP_PUBSUB__MSG__DETAIL__MESSAGE__BUILDER_HPP_
