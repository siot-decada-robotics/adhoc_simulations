# Adhoc-Simulations

# About
Below are the instructions to install and run multi-turtlebot simulations. It allows for each robot to be spawned indvidually at separate times.

# Installation
## Prerequisites
* Ubuntu 20.04 LTS
* ROS1 - Noetic


## Create Workspace
```
mkdir -p ~/multi_turtlebot3_ws/src
```

## Download repositories
The packages are all from forked repositories as there are certain things that need to be changed in order to run the multi robot simulation with navigation.

For example
* robot_state_publisher fork is to allow for usage of prefix for transforms
* turtlebot3_simulations fork contains additional and edited launch files as well as an rviz plugin (referenced from the free fleet rviz plugin) to handle the publishing the ```move_base_simple/goal ``` under the desired namespace.
* turtlebot3 fork contains edited ```.gazebo.xacro``` and ```.urdf.xacro ``` files in so that gazebo will broadcast the odom to base_footprint transforms with the correct prefixes.
```
cd ~/multi_turtlebot3_ws/src 
git clone -b noetic-devel-multi-fix https://github.com/lkw303/turtlebot3_simulations.git
git clone -b noetic-devel-multi-fix https://github.com/lkw303/turtlebot3.git
git clone https://github.com/rhaschke/robot_state_publisher -b noetic-devel

```

## Build
```
cd ~/multi_turtlebot3_ws
source /opt/ros/noetic/setup.bash
colcon build
```

# Running the multi launch simulation

Launch gazebo and rviz with turtlebot3 house without any robots
```
cd ~/multi_turtlebot3_ws
source install/setup.bash
roslaunch turtlebot3_gazebo empty_turtlebot3_house.launch
```

Launch the remaining robots in separate terminals
```
export TURTLEBOT3_MODEL=burger
roslaunch turtlebot3_gazebo ad_hoc_bot0.launch 
```
```
roslaunch turtlebot3_gazebo ad_hoc_bot1.launch 
```
```
roslaunch turtlebot3_gazebo ad_hoc_bot2.launch 
```
