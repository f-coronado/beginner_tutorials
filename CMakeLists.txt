cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/Speak.srv"
)

# adding the executables and naming them so we can run the nodes using ros2 run
add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(server src/server_speaker.cpp)
ament_target_dependencies(server rclcpp std_msgs)

add_executable(client src/client_response.cpp)
ament_target_dependencies(client rclcpp std_msgs)

# adding targets so ros2 run can find the executable
install(TARGETS
  talker
  listener
  server
  client
  DESTINATION lib/${PROJECT_NAME}
)

rosidl_target_interfaces(talker
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(listener
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(server
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(client
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(DIRECTORY launch
DESTINATION share/${PROJECT_NAME}/)


ament_export_dependencies(rosidl_default_runtime)
ament_package()
