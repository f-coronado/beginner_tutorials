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
* @file client_response.cpp
* @author f-coronado
* @brief Client script
* @date 11/20/2023
*
* @copyright Copyright (c) 2023
*
*/

#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include <cpp_pubsub/srv/speak.hpp>

using std::chrono_literals::operator""ms;

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);

  if (argc != 3) {
    RCLCPP_INFO(
      rclcpp::get_logger("rclcpp"),
      "usage: client_response name date");
    return 1;
  }
  /**
   * @brief Create client node
   */
  std::shared_ptr<rclcpp::Node> node =
    rclcpp::Node::make_shared("client_response");
  rclcpp::Client<cpp_pubsub::srv::Speak>::SharedPtr client =
    node->create_client<cpp_pubsub::srv::Speak>("/talker");

  /**
   * @brief Create request, structure is defined by .srv file
   */
  auto request = std::make_shared<cpp_pubsub::srv::Speak::Request>();
  request->name = argv[1];
  request->date = argv[2];

  /**
   * @brief Log how long it takes for the client to find the service node
   */
  while (!client->wait_for_service(1000ms)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(
        rclcpp::get_logger("rclcpp"),
        "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(
      rclcpp::get_logger("rclcpp"),
      "service not available, waiting again...");
  }

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::FutureReturnCode::SUCCESS) {
    RCLCPP_INFO(
      rclcpp::get_logger("rclcpp"), "Response: %s",
      result.get()->output.c_str());
  } else {
    RCLCPP_ERROR(
      rclcpp::get_logger("rclcpp"),
      "Failed to call service reply_server");
  }

  rclcpp::shutdown();
  return 0;
}
