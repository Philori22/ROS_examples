#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>

using namespace std;

ros::Publisher velocity_Publisher;
ros::Subscriber pose_subscriber;
turtlesim::Pose turtlesim_pose;


const double PI = 3.14159265359;

//methods for movie
void move(double speed, double distance, bool isForward);
void rotate(double angular_speed, double angle, bool clockwise);
double degrees2radians(double angle_in_degrees);
double setAbsoluteOrientation(double desired_angle);
void poseCallback(const turtlesim::Pose::ConstPtr & pose_message);
double moveGoal(turtlesim::Pose goal_pose, double distance_tolerance);
double getDistance(double x1, double y1, double x2, double y2);
void gridClean();
void spiralClean();


int main(int argc, char **argv)
{
    // initiate new ROS node "turtlesim_cleaner"
    ros::init(argc, argv, "turtlesim_cleaner_node");
    ros::NodeHandle n;

    //for move function
    double speed, angular_speed;
    double distance, angle;
    bool isForward, clockwise;

    velocity_Publisher = n.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 100);
    pose_subscriber = n.subscribe("/turtle1/pose", 10, poseCallback);

    /* Testing move function 
    cout << "enter, speed: ";
    cin >> speed;
    cout << "ender distance: ";
    cin >> distance;
    cout << "forward?: ";
    cin >> isForward;

    move(speed, distance, isForward);
    */

    /* testing rotate function
    cout << " enter angular_speed: ";
    cin >> angular_speed;
    cout << " enter angle: ";
    cin >> angle;
    cout << " enter clockwise: ";
    cin >> clockwise;

    rotate(degrees2radians(angular_speed), degrees2radians(angle), clockwise);
    */

   ros::Rate loop_rate(0.1);

     //testing absolute (Desired) orientation
     /*
     setAbsoluteOrientation(degrees2radians(120));
     loop_rate.sleep();
     setAbsoluteOrientation(degrees2radians(-60));
     loop_rate.sleep();
     setAbsoluteOrientation(degrees2radians(0)); 
     */

    /*
    turtlesim::Pose goal_pose;
    goal_pose.x=1;
    goal_pose.y=1;
    goal_pose.theta=0;
    moveGoal(goal_pose, 0.01);
    loop_rate.sleep(); */

    //gridClean();
    spiralClean();


    ros::spin();

    return 0;
}

void move(double speed, double distance, bool isForward)
{
    geometry_msgs::Twist vel_msg;
    //distance = speed * time

    // set a random linar veloxity in the x-axis
    if (isForward)
        vel_msg.linear.x = abs(speed);
    else
        vel_msg.linear.x = -abs(speed);
    vel_msg.linear.y = 0;
    vel_msg.linear.z = 0;

    //set a random angular velocity in the y-axis
    vel_msg.angular.x = 0;
    vel_msg.angular.y = 0;
    vel_msg.angular.z = 0;

    // t0: current time
    double t0 = ros::Time::now().toSec();
    double current_distance = 0;
    ros::Rate loop_rate(100); // 10 msgs per second
    // loop
    do
    {
        // publish the velocity
        velocity_Publisher.publish(vel_msg);
        // estimate the distance = speed * (t1-t0)
        double t1 = ros::Time::now().toSec();
        current_distance = speed * (t1 - t0);
        ros::spinOnce();
        loop_rate.sleep();

    } while (current_distance < distance); // current_distance_moved_by_robot <=distance
    vel_msg.linear.x = 0;
    velocity_Publisher.publish(vel_msg);
}

void rotate(double angular_speed, double relative_angle, bool clockwise)
{
    geometry_msgs::Twist vel_msg;

    //set random linear velocity in the x-axis
    vel_msg.linear.x = 0;
    vel_msg.linear.y = 0;
    vel_msg.linear.z = 0;

    //set random angular velocity in the y-axis
    vel_msg.angular.x = 0;
    vel_msg.angular.y = 0;

    if (clockwise)
        vel_msg.angular.z = -abs(angular_speed);
    else
        vel_msg.angular.z = abs(angular_speed);
    
    double current_angle = 0.0;
    double t0 = ros::Time::now().toSec();
    ros::Rate loop_rate(10);
    do
    {
        velocity_Publisher.publish(vel_msg);
        double t1 = ros::Time::now().toSec();
        current_angle = angular_speed * (t1 - t0);
        ros::spinOnce();
        loop_rate.sleep();
    } while (current_angle < relative_angle);
    vel_msg.angular.z = 0;
    velocity_Publisher.publish(vel_msg);
}

// convert angle degrees to radian
double degrees2radians(double angle_in_degrees)
{
    return angle_in_degrees *PI / 180.0;
}

// set the absolut orientation of the robot
double setAbsoluteOrientation(double desired_angle_radians)
{
    double relative_angle_radians = desired_angle_radians - turtlesim_pose.theta;
    bool clockwise = ((relative_angle_radians<0)?true:false);
    // cout<<desired_angle_radians<<","<<turtlesim_pose.theta<<","<<relative_angle_radians<<","<<clockwise<<endl;
    rotate(abs(relative_angle_radians), abs(relative_angle_radians), clockwise);
}

void poseCallback(const turtlesim::Pose::ConstPtr & pose_message)
{
    turtlesim_pose.x=pose_message->x;
    turtlesim_pose.y=pose_message->y;
    turtlesim_pose.theta=pose_message->theta;
}

double getDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

double moveGoal(turtlesim::Pose goal_pose, double distance_tolerance)
{
    geometry_msgs::Twist vel_msg;

    ros::Rate loop_rate(10);
    do{
        /***** Proportional Controller *****/
        vel_msg.linear.x = 1.5*getDistance(turtlesim_pose.x, turtlesim_pose.y, goal_pose.x, goal_pose.y);
        vel_msg.linear.y = 0;
        vel_msg.linear.z = 0;

        //angular velocity in the z-axis
        vel_msg.angular.x = 0;
        vel_msg.angular.y = 0;
        vel_msg.angular.z = 4*(atan2(goal_pose.y-turtlesim_pose.y, goal_pose.x-turtlesim_pose.x)-turtlesim_pose.theta);


        velocity_Publisher.publish(vel_msg);

        ros::spinOnce();
        loop_rate.sleep();
    }while(getDistance(turtlesim_pose.x, turtlesim_pose.y, goal_pose.x, goal_pose.y)> distance_tolerance);

cout<<"end move goal"<<endl;
vel_msg.linear.x =0;
vel_msg.angular.z=0;
velocity_Publisher.publish(vel_msg);
}

void gridClean()
{
    ros::Rate loop(0.5);
    turtlesim::Pose pose;
    pose.x=1;
    pose.y=1;
    pose.theta=0;
    moveGoal(pose, 0.01);
    loop.sleep();
    setAbsoluteOrientation(0);
    loop.sleep();

    move(2, 9, true);
    loop.sleep();
    rotate(degrees2radians(10), degrees2radians(90), false);
    loop.sleep();
    move(2,9,true);

    rotate(degrees2radians(10), degrees2radians(90), false);
    loop.sleep();
    move(2,1,true);
    rotate(degrees2radians(10), degrees2radians(90), false);
    loop.sleep();
    move(2,9,true);

}

void spiralClean(){
    geometry_msgs::Twist vel_msg;
    double count=0;

    double constant_speed=4;
    double vk = 1;
    double wk = 2;
    double rk = 0.5;
    ros::Rate loop(1);

    do{
        rk=rk+0.5;
        vel_msg.linear.x = rk;
        vel_msg.linear.y=0;
        vel_msg.linear.z=0;

        vel_msg.angular.x =0;
        vel_msg.angular.y =0;
        vel_msg.angular.z =constant_speed;

        cout<<"vel_msg.linear.x = "<< vel_msg.linear.x<<endl;
        cout<<"vel_msg.angular.z = "<< vel_msg.angular.z<<endl;
        velocity_Publisher.publish(vel_msg);

        ros::spinOnce();

        loop.sleep();
        cout<<rk<<","<<vk<<","<<endl;
    }while ((turtlesim_pose.x<6) && (turtlesim_pose.y<6));
    vel_msg.linear.x=0;
    velocity_Publisher.publish(vel_msg);


}