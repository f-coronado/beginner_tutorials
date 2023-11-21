// MIT License

// Copyright (c) 2023 f-coronado

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
#include <cpp_pubsub/srv/speak.hpp>
#include "rclcpp/rclcpp.hpp"

using std::chrono_literals::operator""ms;

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  if (argc != 3) {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
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
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),
                   "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
                "service not available, waiting again...");
  }

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) ==
      rclcpp::FutureReturnCode::SUCCESS) {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Response: %s",
                result.get()->output.c_str());
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),
                 "Failed to call service reply_server");
  }

  rclcpp::shutdown();
  return 0;
}
