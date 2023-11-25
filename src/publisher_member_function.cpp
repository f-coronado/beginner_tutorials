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
* @file publisher_member_function.cpp
* @author f-coronado
* @brief Publisher script
* @date 11/20/2023
*
* @copyright Copyright (c) 2023
*
*/
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <memory>
#include <string>
#include <functional>
#include <boost/chrono.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <rclcpp/time.hpp>
#include "std_msgs/msg/string.hpp"
#include <cpp_pubsub/srv/speak.hpp>
#include "rclcpp/rclcpp.hpp"

using std::chrono_literals::operator""ms;
using std::placeholders::_1;

class MinimalPublisher : public rclcpp::Node
{
public:
  /**
   * @brief Create the minimal publisher
   */
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    /**
     * @brief Define the descirption of the parameter
     */
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
    param_desc.description = "This parameter is used to define the name";

    /**
     * @brief Define the parameter as 'name'
     */
    this->declare_parameter("name", "Fabrizzio", param_desc);
    RCLCPP_DEBUG(this->get_logger(), "The default parameter is Fabrizzio");

    /**
     * @brief Create a parameter monitor
     */
    parameter_monitor = std::make_shared<rclcpp::ParameterEventHandler>(this);

    auto param_cb = std::bind(&MinimalPublisher::param_callback, this, _1);
    param_handle_ = parameter_monitor->add_parameter_callback("name", param_cb);

    // publisher items
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    RCLCPP_DEBUG(this->get_logger(), "Publisher has been initiated");
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));

    client_ = this->create_client<cpp_pubsub::srv::Speak>("speak");
    RCLCPP_DEBUG(this->get_logger(), "Client created");
    while (!client_->wait_for_service(1000ms)) {
      if (!rclcpp::ok()) {
        RCLCPP_FATAL(rclcpp::get_logger("rclcpp"), "Interrupted");
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted");
        exit(EXIT_FAILURE);
      }
      RCLCPP_WARN(rclcpp::get_logger("rclcpp"), "Service unavailable");
    }

    tf_static_broadcaster_ =
      std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);
  }

private:
  // Members needed for publisher
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::TimerBase::SharedPtr transformTimer;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
  // members needed for parameter
  std::shared_ptr<rclcpp::ParameterEventHandler> parameter_monitor;
  std::shared_ptr<rclcpp::ParameterCallbackHandle> param_handle_;
  rclcpp::Client<cpp_pubsub::srv::Speak>::SharedPtr client_;
  std::string Message;
  // members needed for transform frame
  std::shared_ptr<tf2_ros::StaticTransformBroadcaster> tf_static_broadcaster_;


  /**
   * @brief Checks the name parameter every 5s and outputs or publishes the
   * corresponding message
   *
   */
  void timer_callback()
  {
    if (get_parameter("name").as_string() == "john") {
      RCLCPP_ERROR(this->get_logger(), "Name passed is invalid");
      RCLCPP_FATAL(this->get_logger(), "Name not updated");
      RCLCPP_DEBUG_STREAM(this->get_logger(), "Do not pass name 'john'");
    } else {
      auto message = std_msgs::msg::String();
      message.data = "Hello, world! my name is " +
        get_parameter("name").as_string() + " " +
        std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }
    if (count_ % 10 == 0) {
      call_change_parameter();
      transform_callback();
    }
  }

  /**
   * @brief Used by call_change_parameter to update the value of the parameter
   *
   * @param response_future
   */
  void response_cb(
    const rclcpp::Client<cpp_pubsub::srv::Speak>::SharedFuture
    response_future)
  {
    // Process the response
    auto response = response_future.get();
    RCLCPP_INFO(
      this->get_logger(),
      "Changed param: %s",
      response->output.c_str());
  }

  /**
   * @brief Specifies service parameters and invokes the response
   *
   */
  int call_change_parameter()
  {
    auto request = std::make_shared<cpp_pubsub::srv::Speak::Request>();
    request->name = "name";
    request->date = "date";
    RCLCPP_INFO(
      this->get_logger(),
      "Checking for updated parameter..");
    auto param_change_cb = std::bind(&MinimalPublisher::response_cb, this, _1);
    client_->async_send_request(request, param_change_cb);
    return 1;
  }

  /**
   * @brief parameter callback, updates the value of the parameter
   *
   * @param param
   */
  int param_callback(const rclcpp::Parameter & param)
  {
    RCLCPP_INFO(
      this->get_logger(),
      "param_callback: Received an update to name parameter");
    RCLCPP_WARN(
      this->get_logger(),
      "The name parameter has been changed");
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));

    return 1;
  }

  void transform_callback()
  {
    geometry_msgs::msg::TransformStamped t;

    RCLCPP_INFO(this->get_logger(), "Publishing transform...");
    t.header.stamp = this->get_clock()->now();
    t.header.frame_id = "world";  // parent frame
    t.child_frame_id = "talk";  // child frame

    t.transform.translation.x = 6.0;
    t.transform.translation.y = 1.0;
    t.transform.translation.z = 9.0;

    t.transform.rotation.x = .12;
    t.transform.rotation.y = .05;
    t.transform.rotation.z = .003;
    t.transform.rotation.w = 0.01;

    tf_static_broadcaster_->sendTransform(t);
    RCLCPP_INFO(this->get_logger(), "Transform published!");
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
