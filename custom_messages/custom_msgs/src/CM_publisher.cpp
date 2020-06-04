#include "ros/ros.h"
#include "std_msgs/String.h"
#include "custom_msgs/dogs.h"

#include <sstream>>

int main(int argc, char **argv)
{
    //initialise new ROS node named "dogownerone"
    ros::init(argc, argv, "dogownerone");
    
    // create a node handle: it is refernce assigned to a new node
    ros::NodeHandle n;

    // create a publisher with a topic "chatter" that will send a String message
    ros::Publisher dog_info = n.advertise<custom_msgs::dogs>("doginfo", 1000);

    //Rate is a class that is used to define frequency for a loop. Here we send a messae every second.
    ros::Rate loop_rate(1.0);


    //count no. of messages sent, create unique string for ea message
    int count = 0;
    while (ros::ok())
    {
        // message object
        custom_msgs::dogs msg;

        msg.id = 01;
        msg.name = "otis";
        msg.age = double(rand())/double(RAND_MAX);
        msg.breed = "fluffy";

        ROS_INFO_STREAM("Hey my dog is..."<<" id:"<<msg.id<<" name: "<<msg.name<< "  age: " <<msg.age<<" breed: "<<msg.breed<< "\n\n");


        // publish messages with message object.
        dog_info.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}