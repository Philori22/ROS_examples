#include "ros/ros.h"
#include "services_tut/ATI.h"

bool add(services_tut::ATI::Request &req, services_tut::ATI::Response &res)
{ 
    res.sum = req.a + req.b;
    ROS_INFO("Request: x=%d, y=%d", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%id", (long int)res.sum);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "addTwoInts_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("add_two_ints", add);
    ROS_INFO("Ready to add two ints.");
    ros::spin();

    return 0;
}