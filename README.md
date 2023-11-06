# Beginner Tutorials

## Overview
This ros 2 project is a simple publisher and subscriber demo. A publisher named talker is created to broadcast a string onto the topic. A subscriber named listener is created to subscribe to what is broadcasted over the topic, which is only being broadcasted to by the talker. 

## Build and run steps
```bash
#1 Download the project into your ros2_ws/src/
cd ~/ros2_ws/src/
git clone https://github.com/f-coronado/beginner_tutorials.git
#2 
cd ~/ros2_ws
#3
colcon build --packages-select cpp_pubsub
#4 Source your steup.bash
source /path/to/your/ros2_ws/install/setup.bash
#5 Open two new terminals by pressing Ctrl+Shift+T
#6 Run the publisher on one terminal
ros2 run cpp_pubsub talker
#7 Run the subscriber on another terminal
ros2 run cpp_pubsub listener
#8 Ctrl+C to end the script
```

## Assumptions and Dependencies
```bash
This project was built on ros2 humble, see below to install
https://docs.ros.org/en/humble/Installation.html
The below steps should be done in your ros2_ws

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

