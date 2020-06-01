#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <turtlesim/Pose.h>

// Topic messages callback - prints out the pose (x,y,theta) of the turtle on each call
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    ROS_INFO("Turtle Pose: @[%f, %f, %f]",msg->x, msg->y, msg->theta);
}

int main(int argc, char **argv)
{
    // Initiate a new ROS node "sub_pose", create node handle node
	ros::init(argc, argv, "sub_pose");
	ros::NodeHandle node;

    // Subscribe to "/turtle1/pose" topic, message queue=1, call poseCallback().
    ros::Subscriber sub = node.subscribe("/turtle1/pose", 1, poseCallback);

    // publish to /turtle1/cmd_vel topic, geometry_msgs::Twist message
    ros::Publisher speed_publisher = node.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);

    //frequency for a loop: 1hz (a message every second).
    ros::Rate loop_rate(1.0);

    while (ros::ok())
    {
        // message object
        geometry_msgs::Twist msg;

        // random linear & angular (x,z) values
        msg.linear.x= double(rand())/double(RAND_MAX);
        msg.angular.z = double(rand())/double(RAND_MAX) - 1;

        // publish messages with message object.
        speed_publisher.publish(msg);
        ROS_INFO_STREAM("Turtlesim moves with /vel_cmd values:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z<< "\n\n");

        // spin once - callback
        ros::spinOnce();
        // sleep until time loop again
        loop_rate.sleep();
    }

    return 0;
}