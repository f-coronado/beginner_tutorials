
"""
@file bag_record.py
@brief This launch file starts a bag record for all topics
@date 11/22/2023
@copyright Copyright (c) 2023
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():

    return LaunchDescription([

       DeclareLaunchArgument(
           "bag_location", 
            default_value="listener_rosbag",
        ),

        # Create a process to execute
        ExecuteProcess(
            cmd=["ros2", "bag", "play", LaunchConfiguration("bag_location")],
            output="screen"
            # output result to terminal
        ),

        # Launch our 3 nodes
        Node(
            package="cpp_pubsub",
            executable="talker",
            name="talker"
        ),

        Node(
            package="cpp_pubsub",
            executable="listener",
            name="listener"
        ),

        Node(
            package="cpp_pubsub",
            executable="server",
            name="server"
        )
    ])