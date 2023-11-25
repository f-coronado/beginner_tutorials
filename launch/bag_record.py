
'''
@file bag_record.py
@brief This launch file starts a bag record for all topics
@date 11/22/2023
@copyright Copyright (c) 2023
'''

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
from launch.substitutions import PythonExpression, LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():

    return LaunchDescription([

       DeclareLaunchArgument(
           'bag_record', 
            default_value='false'
        ),

        DeclareLaunchArgument(
            'bag_filepath',
            default_value='src/cpp_pubsub/results/bag_recordings',
            description='Defines bag filepath'
        ),

        # Create a process to execute
        ExecuteProcess(
            condition = IfCondition(LaunchConfiguration(['bag_record'])),
            cmd=['ros2', 'bag', 'record', '-a', '-o',
                 LaunchConfiguration('bag_filepath')],
            output='screen'
            # output result to terminal
        ),

        # Launch our 3 nodes
        Node(
            package='cpp_pubsub',
            executable='talker',
            name='talker'
        ),

        Node(
            package='cpp_pubsub',
            executable='listener',
            name='listener'
        ),

        Node(
            package='cpp_pubsub',
            executable='server',
            name='server'
        )
    ])