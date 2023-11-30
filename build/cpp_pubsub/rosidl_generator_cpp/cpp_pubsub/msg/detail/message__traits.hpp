// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cpp_pubsub:msg/Message.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB__MSG__DETAIL__MESSAGE__TRAITS_HPP_
#define CPP_PUBSUB__MSG__DETAIL__MESSAGE__TRAITS_HPP_

#include "cpp_pubsub/msg/detail/message__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const cpp_pubsub::msg::Message & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    value_to_yaml(msg.response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const cpp_pubsub::msg::Message & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<cpp_pubsub::msg::Message>()
{
  return "cpp_pubsub::msg::Message";
}

template<>
inline const char * name<cpp_pubsub::msg::Message>()
{
  return "cpp_pubsub/msg/Message";
}

template<>
struct has_fixed_size<cpp_pubsub::msg::Message>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cpp_pubsub::msg::Message>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cpp_pubsub::msg::Message>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CPP_PUBSUB__MSG__DETAIL__MESSAGE__TRAITS_HPP_
