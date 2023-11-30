// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cpp_pubsub:srv/Speak.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB__SRV__DETAIL__SPEAK__TRAITS_HPP_
#define CPP_PUBSUB__SRV__DETAIL__SPEAK__TRAITS_HPP_

#include "cpp_pubsub/srv/detail/speak__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const cpp_pubsub::srv::Speak_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: date
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "date: ";
    value_to_yaml(msg.date, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const cpp_pubsub::srv::Speak_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<cpp_pubsub::srv::Speak_Request>()
{
  return "cpp_pubsub::srv::Speak_Request";
}

template<>
inline const char * name<cpp_pubsub::srv::Speak_Request>()
{
  return "cpp_pubsub/srv/Speak_Request";
}

template<>
struct has_fixed_size<cpp_pubsub::srv::Speak_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cpp_pubsub::srv::Speak_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cpp_pubsub::srv::Speak_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const cpp_pubsub::srv::Speak_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: output
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "output: ";
    value_to_yaml(msg.output, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const cpp_pubsub::srv::Speak_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<cpp_pubsub::srv::Speak_Response>()
{
  return "cpp_pubsub::srv::Speak_Response";
}

template<>
inline const char * name<cpp_pubsub::srv::Speak_Response>()
{
  return "cpp_pubsub/srv/Speak_Response";
}

template<>
struct has_fixed_size<cpp_pubsub::srv::Speak_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cpp_pubsub::srv::Speak_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cpp_pubsub::srv::Speak_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cpp_pubsub::srv::Speak>()
{
  return "cpp_pubsub::srv::Speak";
}

template<>
inline const char * name<cpp_pubsub::srv::Speak>()
{
  return "cpp_pubsub/srv/Speak";
}

template<>
struct has_fixed_size<cpp_pubsub::srv::Speak>
  : std::integral_constant<
    bool,
    has_fixed_size<cpp_pubsub::srv::Speak_Request>::value &&
    has_fixed_size<cpp_pubsub::srv::Speak_Response>::value
  >
{
};

template<>
struct has_bounded_size<cpp_pubsub::srv::Speak>
  : std::integral_constant<
    bool,
    has_bounded_size<cpp_pubsub::srv::Speak_Request>::value &&
    has_bounded_size<cpp_pubsub::srv::Speak_Response>::value
  >
{
};

template<>
struct is_service<cpp_pubsub::srv::Speak>
  : std::true_type
{
};

template<>
struct is_service_request<cpp_pubsub::srv::Speak_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cpp_pubsub::srv::Speak_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CPP_PUBSUB__SRV__DETAIL__SPEAK__TRAITS_HPP_
