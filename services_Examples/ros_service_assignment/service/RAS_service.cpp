#include "ros/ros.h"
#include "ros_service_assignment/RectangleAreaService.h"

bool area(ros_service_assignment::RectangleAreaService::Request &req, ros_service_assignment::RectangleAreaService::Response &res)
{ 
    res.sum = req.a * req.b;
    ROS_INFO("Request: x=%d, y=%d", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%id", (long int)res.sum);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "RAS_service");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("Rectangle_area", area);
    ROS_INFO("Ready to add two ints.");
    ros::spin();

    return 0;
}