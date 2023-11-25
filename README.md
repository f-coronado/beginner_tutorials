## Overview
This ros 2 project is a simple publisher and subscriber demo. A publisher named talker is created to broadcast a string onto the topic. A subscriber named listener is created to subscribe to what is broadcasted over the topic, which is only being broadcasted to by the talker. 

## Build and run steps
Clone the project into your ros2_ws/src/
```sh
cd ~/ros2_ws/src/
git clone https://github.com/f-coronado/cpp_pubsub.git
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

Ctrl+C to end the scripts
# Running nodes and setting parameter
Launching the publisher, subscriber and server nodes from ros2_ws using a launch file
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

Alternatively you can run the nodes independently, make sure to run the server node first because the talker node waits for it
```sh
ros2 run cpp_pubsub server
```
```sh
ros2 run cpp_pubsub talker
```
```sh
ros2 run cpp_pubsub listener
```

# Inspecting TF frames
The publisher node sends the transform from the world to talk frame every 10s. In real time you can view the static transform being sent over using tf_ros executables.

First launch beginner_tutorials.py
```sh
ros2 launch cpp_pubsub beginner_tutorials.py
```
Then use tf2_echo to view the frame sent from the source/world frame to target/talk frame
```sh
ros2 run tf2_ros tf2_echo world talk
```
Alternatively, you can use tf2_tools to create a diagram of frames being broadcasted by tf2 over ROS. 
```sh
ros2 run tf2_tools view_frames
```

# Running ROS test
In your ros2 workspace, run the test
```sh
colcon test --packages-select cpp_pubsub 
```
View the results
```sh
cat log/latest_test/cpp_pubsub/stdout_stderr.log 
```

# Recording and playing back bag file
Use bag_record launch file to run nodes and record automatically
```sh
ros2 launch cpp_pubsub bag_record.py bag_record:=true bag_filepath:=results
```
You can also play back a prerecorded bag file and view it in realtime, First launch listener node.
```sh
ros2 run cpp_pubsub listener
```
Then in a new terminal, navigate to bag recording folder and play the bag file
```sh
cd ~/your_ros2_workspace/src/cpp_pubsub/results/bag_recordings/
ros2 bag play bag_recordings_0.db3
```
You should see the listener print messages from the bag. You can see more information about the bag recording using the following
```sh
ros2 bag info bag_recordings_0.db3 
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