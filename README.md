# Beginner Tutorials

## Overview
This ros 2 project is a simple publisher and subscriber demo. A publisher named talker is created to broadcast a string onto the topic. A subscriber named listener is created to subscribe to what is broadcasted over the topic, which is only being broadcasted to by the talker. 

## Build and run steps
```bash
#1 Clone the project into your ros2_ws/src/
cd ~/ros2_ws/src/
git clone https://github.com/f-coronado/beginner_tutorials.git
#2 
cd ~/ros2_ws
#3 Build the package
colcon build --packages-select cpp_pubsub
#4 Source your setup.bash
source /path/to/your/ros2_ws/install/setup.bash
#5 Open two new terminals by pressing Ctrl+Shift+T
#6 Run the publisher on one terminal
ros2 run cpp_pubsub talker
#7 Run the subscriber on another terminal
ros2 run cpp_pubsub listener
#8 Ctrl+C to end the script

# Launching the publisher and subscriber nodes from ros2_ws
ros2 launch cpp_pubsub_beginner_tutorials.py
# Running server and client nodes
ros2 run cpp_pubsub server
# Example of calling the service using a client
ros2 run cpp_pubsub client John 2023-11-15
# Example of calling the service using the service call
ros2 service call /speak string_msgs/srv/Speak "{name: 'John', date: "2023-11-15"}"

```

## Assumptions and Dependencies
```bash
This project was built on ros2 humble, see below to install
https://docs.ros.org/en/humble/Installation.html
The steps below should be completed in your ros2_ws

# This package uses rclcpp and std_msgs, it is good practice to check for missing dependencies before building
rosdep install -i --from-path src --rosdistro humble -y
# If some dependencies are missing
sudo apt update
sudo apt full-upgrade

# Make sure the required lines below are in your bashrc script
gedit ~/.bashrc
# Add the following to the bottom of your bashrc
source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash
source /usr/share/colcon_cd/function/colcon_cd.sh
source /opt/ros/humble/setup.bash
source ~/ros2_ws/install/setup.bash

```

