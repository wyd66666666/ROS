#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

void cirCallback(const geometry_msgs::Twist::ConstPtr &msg)
{
    ROS_INFO("%f %f %f %f %f %f",msg->linear.x,msg->linear.y,msg->linear.z,msg->angular.x,msg->angular.y,msg->angular.z);
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/turtle1/cmd_vel", 10, cirCallback);
    ros::spin();
    return 0;


}
