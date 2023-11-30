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
@file bgeinner_tutorials.py.

@brief This launch file initiates the talker, listener and server nodes
@date 11/20/2023
@copyright Copyright (c) 2023
"""

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    return LaunchDescription([

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
