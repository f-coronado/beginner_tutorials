#include "rclcpp/rclcpp.hpp"
// #include "example_interfaces/srv/add_two_ints.hpp"
#include "string_msgs/srv/Speak.hpp"
#include <string>
#include <memory>


/**
 * @brief Returns the response based on request
 *
 * @param request Two strings: name, date
 * @param response String: output
 */
void speak(const std::shared_ptr<string_msgs::srv::Speak::Request> request,
          std::shared_ptr<string_msgs::srv::Speak::Response>      response)
{


  response->output = "Hi, my name is " << request->name << "And today is " << request->date;

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request by:\n" request->name << "Timestamp is" << request->date);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending back the generated response: " << response->output);


}

int main(int argc, char **argv)
{

  /**
  * @brief Initialize the ROS2 CPP client library
  */
  rclcpp::init(argc, argv);


  /**
  * @brief Initialize the server node
  */
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("reply_server");


  /**
  * @brief Designate the speak service as the service for the server node
  */
  rclcpp::Service<string_msgs::srv::Speak>::SharedPtr service =
    node->create_service<string_msgs::src::Speak>("speak", &speak);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready hear a reply.");


  /**
  * @brief Spin the server node
  */
  rclcpp::spin(node);
  rclcpp::shutdown();
}