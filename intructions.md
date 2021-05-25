# Introduction

This launch folder contains the instructions to launch files to launch single turtlebots one by one either from the same machine or separate containers or machines

# Instructions

## Set up for launching from separate machines or within containers

### Configure Environment variables
* On the each device and on every shell, before running any ros commands, run:
``` export ROS_MASTER_URI=http://<desired IP of ROS Master>:< desired port>```
```export ROS_IP=<IP of the current device>```

* For the shell that will be launching the world:
```export GAZEBO_MASTER_URI=http://<desired IP of device>:11345```

### Launch the world

```roslaunch <package name> empty_world.launch```
or
```roslaunch <package name> empty_turtlebot.launch```

### Launch the robots individually
```roslaunch <package name> bot<bot number>.launch```

### Control the robots using teleop keys
run the teleopkeys and remap the namespace and node name in order to prevent namespace clashes when running on different robots
```rosrun teleop_twist_keyboard teleop_twist_keyboard.py /cmd_vel:=/tb3_<bot number>/cmd_vel -r __node:=tb3_<bot number> -r __ns:=/tb3_<bot number>```

# Things To Do (TTD)/ Work in progress
 1. create the correct transform links and publish them using the tf publisher
 2. implement a move base with the launch files