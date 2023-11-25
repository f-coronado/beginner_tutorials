# Any C++ source files needed to build this target (simple-gtest).
#find_package(std_msgs REQUIRED)


#add_executable(simple-gtest simple_test.cpp)
#ament_target_dependencies(simple-gtest std_msgs rclcpp)

#rosidl_target_interfaces(simple-gtest ${PROJECT_NAME} "rosidl_typesupport_cpp")

#target_include_directories(simple-gtest PUBLIC
#  ${CMAKE_SOURCE_DIR}/include
#  ${CMAKE_SOURCE_DIR}/libs
#  ${CMAKE_BINARY_DIR}/cpp_pubsub/msg  # Adjust this path
#)


# Any dependent libraires needed to build this target.
#target_link_libraries(simple-gtest PUBLIC
#  # list of libraries:
#  gtest
#  )

# Enable CMake’s test runner to discover the tests included in the
# binary, using the GoogleTest CMake module.
#gtest_discover_tests(simple-gtest)