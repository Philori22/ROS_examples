#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

#include <sstream>>

int main(int argc, char **argv)
{
    //initialise new ROS node names "speed_pub"
    ros::init(argc, argv, "speed_pub");
    
    // create a node handle: it is refernce assigned to a new node
    ros::NodeHandle n;

    // create a publisher with a topic "speed_publisher" that will send Twist
    ros::Publisher speed_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);

    //Rate is a class that is used to define frequency for a loop. Here we send a messae every second.
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
        ROS_INFO_STREAM("Sending random velocity command:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}