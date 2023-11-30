# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http:#www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
@file bag_record.py.

@brief This launch file starts a bag record for all topics
@date 11/22/2023
@copyright Copyright (c) 2023
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
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

        ExecuteProcess(
            condition=IfCondition(LaunchConfiguration(['bag_record'])),
            cmd=['ros2', 'bag', 'record', '-a', '-o',
                 LaunchConfiguration('bag_filepath')],
            output='screen'
            # output result to terminal
        ),

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
