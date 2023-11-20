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
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <cpp_pubsub/srv/speak.hpp>


using namespace std::chrono_literals;
using std::placeholders::_1;
// using sharedFuture = rclcpp::Client<cpp_pubsub::srv::Speak>::sharedFuture;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node {
  public:

  /**
  * @brief Create the minimal publisher
  */
    MinimalPublisher() : Node("minimal_publisher"), count_(0) {
      
      /**
      * @brief Define the descirption of the parameter
      */
      auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
      param_desc.description = "This parameter is used to define the name";

      /**
      * @brief Define the parameter as 'name'
      */
      this->declare_parameter("name", "Fabrizzio", param_desc);
      auto param = this -> get_parameter("name");
      auto name = param.get_parameter_value().get<std::string>();
      RCLCPP_DEBUG(this->get_logger(), "The default parameter is Fabrizzio");

      /**
      * @brief Create a parameter monitor
      */
      parameter_monitor = std::make_shared<rclcpp::ParameterEventHandler>(this);

      auto param_cb = std::bind(&MinimalPublisher::parameter_callback, this, _1);
      param_handle_ = parameter_monitor->add_parameter_callback("name", param_cb);  

      // publisher items
      publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
      RCLCPP_DEBUG(this->get_logger(), "Publisher has been initiated");
      timer_ = this->create_wall_timer(
        500ms, std::bind(&MinimalPublisher::timer_callback, this));


      client_ = this->create_client<cpp_pubsub::srv::Speak>("speak");
      RCLCPP_DEBUG(this->get_logger(), "Client created");
      while (!client_->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
          RCLCPP_FATAL(rclcpp::get_logger("rclcpp"), "Interrupted");
          exit(EXIT_FAILURE);
        }
        RCLCPP_WARN(rclcpp::get_logger("rclcpp"), "Service unavailable");
      }
  };

  // auto remote_node = std::string("talker");
  // auto remote_param = std::string("");
  
  private:
    // members needed for parameter
    std::shared_ptr<rclcpp::ParameterEventHandler> parameter_monitor;
    std::shared_ptr<rclcpp::ParameterCallbackHandle> param_handle_;
    rclcpp::Client<cpp_pubsub::srv::Speak>::SharedPtr client_;
    std::string Message;


    void timer_callback(){
    
      auto message = std_msgs::msg::String();
      message.data =
          "Hello, world! my name is Fabrizzio " + std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'",
                  message.data.c_str());
      publisher_->publish(message);

      if (count_ % 10 == 0){
        call_change_parameter();
      }
    
    };

    // Members needed for publisher
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;


    // think this may go into client script 
    int call_change_parameter(){
      auto request = std::make_shared<cpp_pubsub::srv::Speak::Request>();
      request->name = "name";
      request->date = "date";
      RCLCPP_INFO(this->get_logger(), "Updating parameter using call_change_parameter");
      auto param_change_cb =
        std::bind(&MinimalPublisher::response_callback, this, _1);
      client_->async_send_request(request, param_change_cb);
      return 1;
    };

    void response_callback(const rclcpp::Client<cpp_pubsub::srv::Speak>::SharedFuture response_future){
      // Process the response
      auto response = response_future.get();
      RCLCPP_INFO(this->get_logger(), "Changed param: %s", response->output.c_str());
      Message = response->output.c_str();
    };

    /**
    * @brief parameter callback, updates the value of the parameter
    *
    * @param my_param
    */
    void parameter_callback(const rclcpp::Parameter &param){
      RCLCPP_INFO(this->get_logger(),
        "parameter_callback: Received an update to name parameter");
      RCLCPP_WARN(this->get_logger(), "The name parameter has been changed");
      timer_ = this->create_wall_timer (500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  };
 
int main(int argc, char* argv[]) {
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;

}