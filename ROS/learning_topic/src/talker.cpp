#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    geometry_msgs::Twist msg;
    msg.linear.x=0;
    msg.linear.y=0;
    msg.linear.z=0;

    msg.angular.x=0;
    msg.angular.y=0;
    msg.angular.z=0;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Rate loop_rate(10);
    
    while(ros::ok())
    {
        msg.linear.x=0.5;
	msg.angular.z=0.2;
        ROS_INFO("linear.X=%f angular.x=%f\n",msg.linear.x,msg.angular.x);
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}
