// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
/**
 * @file server_speaker.cpp
 * @author f-coronado
 * @brief Server script
 * @date 11/20/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <memory>
#include <string>
#include <cpp_pubsub/srv/speak.hpp>
#include <rclcpp/rclcpp.hpp>

/**
 * @brief Returns the response based on request
 *
 * @param request Two strings: name, date
 * @param response String: output
 */
void speak(
  const std::shared_ptr<cpp_pubsub::srv::Speak::Request> request,
  std::shared_ptr<cpp_pubsub::srv::Speak::Response> response) {
  response->output =
    "Hi, my name is " + request->name + " and today is " + request->date;

  RCLCPP_INFO(
    rclcpp::get_logger("rclcpp"),
    "Request received by speak server",
    request->name.c_str(), request->date.c_str());
  RCLCPP_INFO(
    rclcpp::get_logger("rclcpp"),
    "Sending back the generated response: %s",
    response->output.c_str());
}

/**
 * @brief initialize RCLCPP and spin the minimalPublisher node
 *
 * @param argc
 * @param argv
 *
 */
int main(int argc, char ** argv) {
  /**
   * @brief Initialize the ROS2 CPP client library
   */
  rclcpp::init(argc, argv);

  /**
   * @brief Initialize the server node
   */
  std::shared_ptr<rclcpp::Node> node =
    rclcpp::Node::make_shared("reply_server");

  /**
   * @brief Designate the speak service as the service for the server node
   */
  rclcpp::Service<cpp_pubsub::srv::Speak>::SharedPtr service =
    node->create_service<cpp_pubsub::srv::Speak>("speak", &speak);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready hear a name and date:.");

  /**
   * @brief Spin the server node
   */
  rclcpp::spin(node);
  rclcpp::shutdown();
}
