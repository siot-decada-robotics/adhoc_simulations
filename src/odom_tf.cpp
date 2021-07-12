#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <cstdio>
#include <tf2/LinearMath/Quaternion.h>

float z_processed = 0.0;
std::string static_robot_name;

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  z_processed = -1*msg->pose.pose.position.z; //msg->pose.pose.position.z;
}

int main(int argc, char** argv){
  ros::init(argc, argv, "odometry_publisher");

  ros::NodeHandle n;
  ros::Subscriber odom_sub = n.subscribe("/tb3_0/odom", 50, odomCallback);
  tf2_ros::TransformBroadcaster odom_broadcaster;

  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();
  ROS_INFO("Spinning until killed publishing tb3/odom/processed to /tb3_0/base_footprint");

  ros::Rate r(50.0);
  while(n.ok()){

    ros::spinOnce();               // check for incoming messages
    current_time = ros::Time::now();
    ROS_INFO("I heard: [%lf]", z_processed);    
    
    static_robot_name = argv[1];
    static tf2_ros::StaticTransformBroadcaster static_broadcaster;
    geometry_msgs::TransformStamped static_transformStamped;
    
    static_transformStamped.header.stamp = ros::Time::now();
    static_transformStamped.header.frame_id = static_robot_name + "/odom/processed";
    static_transformStamped.child_frame_id = static_robot_name + "/base_footprint";
    
    static_transformStamped.transform.translation.x = 0.0;
    static_transformStamped.transform.translation.y = 0.0;
    static_transformStamped.transform.translation.z = z_processed;
    tf2::Quaternion quat;
    static_transformStamped.transform.rotation.x = 0.0;
    static_transformStamped.transform.rotation.y = 0.0;
    static_transformStamped.transform.rotation.z = 0.0;
    static_transformStamped.transform.rotation.w = 1.0;

    static_broadcaster.sendTransform(static_transformStamped);
    
    last_time = current_time;
    r.sleep();
  }
}
