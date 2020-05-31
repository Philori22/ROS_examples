#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>>

int main(int argc, char **argv)
{
    //initialise new ROS node names "talker"
    ros::init(argc, argv, "talker");
    
    // create a node handle: it is refernce assigned to a new node
    ros::NodeHandle n;

    // create a publisher with a topic "chatter" that will send a String message
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    //Rate is a class that is used to define frequency for a loop. Here we send a messae every second.
    ros::Rate loop_rate(1.0);


    //count no. of messages sent, create unique string for ea message
    int count = 0;
    while (ros::ok())
    {
        // message object
        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();

        ROS_INFO(" %s", msg.data.c_str());

        // publish messages with message object.
        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}