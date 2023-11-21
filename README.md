# Beginner Tutorials

## Overview
This ros 2 project is a simple publisher and subscriber demo. A publisher named talker is created to broadcast a string onto the topic. A subscriber named listener is created to subscribe to what is broadcasted over the topic, which is only being broadcasted to by the talker. 

## Build and run steps
Clone the project into your ros2_ws/src/
```sh
cd ~/ros2_ws/src/
git clone https://github.com/f-coronado/beginner_tutorials.git
```

Navigate into your ros2 workspace
```sh
cd ~/ros2_ws
```

Build the package
```sh
colcon build --packages-select cpp_pubsub
```
Source your setup.bash
```sh
source /path/to/your/ros2_ws/install/setup.bash
```

Open two new terminals by pressing Ctrl+Shift+T


Run the publisher on one terminal
```sh
ros2 run cpp_pubsub talker
```

Run the subscriber on another terminal
```sh
ros2 run cpp_pubsub listener
```

Ctrl+C to end the script
# Examples of how to use launch file and run nodes
Launching the publisher, subscriber and server nodes from ros2_ws
```sh
ros2 launch cpp_pubsub_beginner_tutorials.py
```
To set the name parameter open another terminal using Ctrl+Shift+T and enter
```sh
ros2 param set /minimal_publisher name whateverNameYouWant
```
To test errors and debug infos open rqt_console. Make sure with severities is not checked off or deselect all severity levels
```sh
ros2 run rqt_console rqt_console
```
Then run
```sh
ros2 param set /minimal_publisher name john

```

Alternatively you can run the nodes independently
```sh
ros2 run cpp_pubsub server
```
```sh
ros2 run cpp_pubsub talker
```
```sh
ros2 run cpp_pubsub listener
```

## Assumptions and Dependencies
This project was built on ros2 humble, see below to install
https://docs.ros.org/en/humble/Installation.html
The steps below should be completed in your ros2_ws

 This package uses rclcpp and std_msgs, it is good practice to check for missing dependencies before building
```sh
rosdep install -i --from-path src --rosdistro humble -y 
```
If some dependencies are missing, update your workspace
```sh
sudo apt update
sudo apt full-upgrade
```

Make sure the required lines below are in your bashrc script
```sh
gedit ~/.bashrc
```
Add the following to the bottom of your bashrc
```sh
source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash
source /usr/share/colcon_cd/function/colcon_cd.sh
source /opt/ros/humble/setup.bash
source ~/ros2_ws/install/setup.bash
```