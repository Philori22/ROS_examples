#include "ros/ros.h"
#include "std_msgs/String.h"
#include <custom_msgs/dogs.h>

// Topic messages callback
void dogCallback(const custom_msgs::dogs msg)
{
    ROS_INFO_STREAM("I heard that your doc is:"<<" id:"<<msg.id<<" name: "<<msg.name<< "  age: " <<msg.age<<" breed: "<<msg.breed<< "\n\n");

}

int main(int argc, char **argv)
{
    // Initiate a new ROS node named "listener"
	ros::init(argc, argv, "dogownertwo");
	//create a node handle: it is reference assigned to a new node
	ros::NodeHandle node;


    // Subscribe to a given topic, in this case "chatter".
	//chatterCallback: is the name of the callback function that will be executed each time a message is received.
    ros::Subscriber sub = node.subscribe("doginfo", 1000, dogCallback);

    // Enter a loop, pumping callbacks
    ros::spin();

    return 0;
}