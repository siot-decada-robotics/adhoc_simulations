# adhoc-simulations

## About
`adhoc-simulations` is a development project branching from [Free Fleet](https://github.com/siot-decada-robotics/free_fleet). This project allows you to launch a map and spawn robots into the map separately. Spawned robots have the free fleet node included. The following 3 types of robots can be spawned:
- turtlebot3
- caato
- locust (under development)

## Prerequisites
- [Ubuntu 20.04 LTS](https://releases.ubuntu.com/20.04/)
- [ROS1 - Noetic](https://wiki.ros.org/noetic)

Install all non-ROS prerequisite packages,

```bash
sudo apt update && sudo apt install \
  git wget qt5-default \
  python3-rosdep \
  python3-vcstool \
  python3-colcon-common-extensions
```
<br>

## Examples
### Turtlebot3
For turtlebot3 to work on your PC please ensure that you have completed the PC setup for turtlebot3 for **noetic** as instructed [here](https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/). 

Next, start a new ROS1 workspace, and pull in the necessary repositories

```bash
mkdir -p ~/adhoc_sim_ws/src
cd ~/adhoc_sim_ws/src
git clone https://github.com/siot-decada-robotics/adhoc_simulations.git
git clone https://github.com/siot-decada-robotics/free_fleet.git -b noetic-devel-multi-fix
git clone https://github.com/eclipse-cyclonedds/cyclonedds.git
git clone https://github.com/rhaschke/robot_state_publisher -b noetic-devel

git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git -b noetic-devel
git clone https://github.com/ROBOTIS-GIT/turtlebot3.git -b noetic-devel

cd robot_state_publisher
git checkout 661628a76bbb

sudo apt install ros-noetic-gazebo-ros-pkgs ros-noetic-dwa-local-planner
```
Install dependencies through rosdep, source ROS1 and build
```
cd ~/adhoc_sim_ws
rosdep install --from-paths src --ignore-src --rosdistro noetic -yr
source /opt/ros/noetic/setup.bash
colcon build --cmake-args -DCMAKE_BUILD_TYPE=RELEASE
```
*Now you can launch the **map of the turtlebot3 house***
```
source ~/adhoc_sim_ws/install/setup.bash
roslaunch adhoc_simulations sim_base_tb3_house.launch
```
*And launch as many **other turtlebot3s** as you want in separate terminals onto the same map!*
```bash
source ~/adhoc_sim_ws/install/setup.bash
roslaunch adhoc_simulations sim_bot_tb3_0.launch
# When launching more than one tb3, change the robot_name argument in the launch file to differentiate among the different robots.
```
<br>

### Caato
Caato requires the TEB planner package as a prerequisite
```
sudo apt-get install ros-noetic-teb-local-planner
```
Once again, start a new ROS1 workspace, and pull in the necessary repositories

```bash
mkdir -p ~/adhoc_sim_ws/src
cd ~/adhoc_sim_ws/src
git clone https://github.com/siot-decada-robotics/adhoc_simulations.git
git clone https://github.com/siot-decada-robotics/free_fleet.git -b noetic-devel-multi-fix
git clone https://github.com/eclipse-cyclonedds/cyclonedds.git
git clone https://github.com/rhaschke/robot_state_publisher -b noetic-devel

git clone https://github.com/siot-decada-robotics/caato.git
git clone https://github.com/siot-decada-robotics/ira_laser_tools.git -b siot_caato
git clone https://git.siotgov.tech/decada_robotics/roboteq_diff_driver.git

cd robot_state_publisher
git checkout 661628a76bbb

sudo apt install ros-noetic-gazebo-ros-pkgs ros-noetic-dwa-local-planner
```
Similarly, install dependencies through rosdep, source ROS1 and build
```
cd ~/adhoc_sim_ws
rosdep install --from-paths src --ignore-src --rosdistro noetic -yr
source /opt/ros/noetic/setup.bash
colcon build --cmake-args -DCMAKE_BUILD_TYPE=RELEASE
```
*Now you can launch the **map of mbc level 10***
```
source ~/adhoc_sim_ws/install/setup.bash
roslaunch adhoc_simulations sim_base_mbc.launch
```
*And launch as many **other caatos** as you want in separate terminals onto the same map!*
```bash
source ~/adhoc_sim_ws/install/setup.bash
roslaunch adhoc_simulations sim_bot_caato_0.launch
#When launching more than one caato, change the robot_name argument in the launch file to differentiate among the different robots.
```
<br>
Refer to siot-decada-robotics/caato repository (private) for more information on how to navigate caato.
<br>

## Free Fleet Integration
Follow the installation instructions for Server in ROS2 in the [free_fleet repository](https://github.com/siot-decada-robotics/free_fleet/tree/noetic-devel-multi-fix#server-in-ros2).

Now you can monitor and send commands to your robots launched in `adhoc simulations` using the commands provided in free fleet. 

<br>

## RMF Integration
Once you have integrated with Free Fleet, you can run adhoc_sim with the RMF system. Ensure that you have the following processes running before launching adhoc_simulations
- [RMF Demos](https://github.com/siot-decada-robotics/rmf_demos) -> `ros2 launch rmf_demos mbc_no_sim.launch.xml`
- [Free Fleet Server](https://github.com/siot-decada-robotics/free_fleet) -> `ros2 launch ff_examples_ros2 turtlebot3_fleet_server.launch.xml`
- [RosBridge](https://github.com/siot-decada-robotics/ros1_bridge) -> `ros2 run ros1_bridge clock_bridge`

To allow the doors and lifts to appear on RMF you must source the door and lift plugins in your adhoc simulations workspace. *Note: This is a temporary fix*
```bash
# IMPT: Change the file paths to match the file path where rmf_demos is stored in your computer!!!
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/rmf_demos_ws/install/rmf_door_msgs/lib:~/rmf_demos_ws/install/rmf_building_sim_gazebo_plugins/lib:~/rmf_demos_ws/install/rmf_building_sim_common/lib:/opt/ros/foxy/lib:~/rmf_demos_ws/install/rmf_lift_msgs/lib
```
Thereafter you can launch a turtlebot3 in **mbc L9** and control it through RMF. You can spawn tb3 on **mbc L10** as well by changing the *map*, *z-coordinate* and *level* in the launch file appropriately.
```
roslaunch adhoc_simulations mbc.launch
```
