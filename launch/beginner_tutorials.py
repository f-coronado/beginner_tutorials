"""
@file bgeinner_tutorials.py
@brief This launch file initiates the talker, listener and server nodes
@date 11/20/2023
@copyright Copyright (c) 2023
"""

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([

    # Launch our 3 nodes
        Node(
            package='cpp_pubsub',
            executable='talker',
            name='minimal_publisher'
        ),
        Node(
            package='cpp_pubsub',
            executable='listener',
            name='listener'
        ),
        Node(
            package='cpp_pubsub',
            executable='server',
            name='server',
        )
    ])