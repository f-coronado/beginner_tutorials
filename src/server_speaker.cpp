// MIT License

// Copyright (c) 2023 f-coronado

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <rclcpp/rclcpp.hpp>
#include <cpp_pubsub/srv/speak.hpp>
#include <string>
#include <memory>

  /**
  * @brief Returns the response based on request
  *
  * @param request Two strings: name, date
  * @param response String: output
  */
  void speak(const std::shared_ptr<cpp_pubsub::srv::Speak::Request> request,
            std::shared_ptr<cpp_pubsub::srv::Speak::Response>      response){

    response->output = "Hi, my name is " + request->name + " and today is " + request->date;

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Incoming request by\nname: %s\nTimestamp is: %s",
    request->name.c_str(),
    request->date.c_str());
    // RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending back the generated response:   %s" << response->output << "]");
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending back the generated response: %s", response->output.c_str());

  // # create service callback function, show in logger
  };

  /**
  * @brief calls the response for the speak function
  *
  * @param response
  */
  // void response_cb(rclcpp::Client<cpp_pubsub::srv::Speak> response){

  //   RCLCPP_INFO(this->get_logger(), "Name passed is: %s", response.get()->output.c_str());
  //   Message = response.get()->output.c_str();

  // };

  // 
  // int server_cb(){

  //   auto request = std::make_shared<cpp_pubsub::srv::Speak::Request>();
  //   request -> name;
  //   request -> date;
  //   // RCLCPP_INFO(this->get_logger(), "Modifying name using the server");
  //   auto  cb_ptr = std::bind(&MinimalPublisher::response_cb, this, _1);
  //   client -> async_send_request(request, cb_ptr);
  //   return 1;

  // }


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
  rclcpp::Service<cpp_pubsub::srv::Speak>::SharedPtr service =
    node->create_service<cpp_pubsub::srv::Speak>("speak", &speak);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready hear a name and date:.");


  /**
  * @brief Spin the server node
  */
  rclcpp::spin(node);
  rclcpp::shutdown();
}