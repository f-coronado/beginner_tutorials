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

        # DeclareLaunchArgument(
        #     "talker_rate",
        #     default_value = "100",
        #     description="talker rate"
        # ),

        # DeclareLaunchArgument(
        #     "log_level",
        #     default_value = TextSubstitution(text=str("info")),
        #     description="Logging level"
        # ),
    ])