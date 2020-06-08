# Robot Operating System (ROS) examples
Going over the basics for ROS, some code was written in c++, with exception to aspects in python. The repository contains _ROS Basics, Motion, ROS-OpenCV, rosserial, Localization, Navigation and SLAM_ in ROS (with small aspect looking to Modelling for Gazebo).

Alot of the content based-off the following resources, with some deviation, they've been also helpsful:
* [*University of Bath Unit:* - EE50237: Robotics software](http://www.bath.ac.uk/catalogues/2018-2019/ee/EE50237.html)
* [*ROS.org:* ROS Documentation Webpage](http://wiki.ros.org/)
* [*Udemy:* ROS for Beginners: Basics, Motion, and OpenCV](https://www.udemy.com/course/ros-essentials/)
* [*Udemy:* ROS for Beginners II: Localization, Navigation and SLAM](https://www.udemy.com/course/ros-navigation/)
* [Anis Koubaa Github: ross_essentials_cpp](https://github.com/aniskoubaa/ros_essentials_cpp)
* [Anis Koubaa Github: navigation](https://github.com/aniskoubaa/ros_course_part2)



### Dependencies
[to be finished.]

## ROS Basics
Robot Operating system is an open-source, robotics middlweare often used when designing an implementing functionality within robots. You could simply consider it as a peer-to-peer network of processes that are processing data together. This network is comprised of nodes, master, parameter server, messages, services, topics and bags.

Nodes are processes that perform some action. these software modules reister with the ROS master node and communicate with other nodes in the system. Each node is independent, but interact with others using the communication capability. The Master node establishes this commuication with other nodes in the system, oftenly with internet protocal called TCPROS in ROS. 

Nodes send (publish) messages on channels called 'topics', and listen for messages by 'subscribing' to the topics.


### ROS Topics
A node sends out a message by _publishing_ it in a given topic. The topic name can be used to identify the content of the message. The node interested in a certin type of data will _subscribe_ to the approprite topic. The following examples publish and subscribe to a given topic, sending a message of a certain type.
* [Example 1](https://github.com/Philori22/ROS_examples/blob/master/Example1/): **'chatting' package: _Sending and Receiving "Hello World" messages of type _String_ using `chatter` _topic_, _(how unique)_._**
  > **_talker.cpp_, 'talker'** publisher node, publishes the String message 'Hello world' to _topic_ "chatter", counting the number of messages send with an id. <br>
  
  > **_listener.cpp_, 'listener'** subscriber node, subscribes the the "chatter topic" and calls `chatterCallback()`, which prints an acknowledgement to terminal with the number message id.
  
  
* [Example 2](https://github.com/Philori22/ROS_examples/tree/master/Example2): **'mover_diy' package: _publishing & subscribing to Turtlesim _Topics_, `/turtle1/cmd_vel` & `/turtle1/pose`._**
  > **_robot_move_topics.cpp_ - 'speed_pub' node**, publishes geometry messages (Random Angular and linear velocity values) to `/turtle1/cmd_vel` Turtlesim _topic_, to move the turtle around the environment. <br>
  
  > **_turtlesim_pose.cpp_ - 'sub_pose' node**,  expands on `speed_pub`, publishes geometry messages to `/turtle1/cmd_vel`; also subscribes to `/turtle1/pose` Turtlesim _topic_, and outputs both pose and geometry parameters _(x,y,theta)_ to terminal.

### Custom ROS messages (msg)
http://wiki.ros.org/msg - provides basis on the concept of messages. Sometimes the standard message formats are not suitable for the hardware being used, thus you might have to define your own to use within your system.
* Creating and using custom messages: [Custom_msg/dogs](https://github.com/Philori22/ROS_examples/tree/master/custom_messages)

```
ros@ubuntu:~/catkin_ws$ rosmsg show dogs
[custom_msgs/dogs]:
int32 id
string name
float32 age
string breed
```


  
 * Using Custom ROS Messages.
`#include <custom_msgs/dogs.h>`
   

### ROS Services
Publish/subscribe model is very flexible, but its not appropriate for request/reply interactions, which are often needed in distibuted systems. Services establish Request/Reply, which are deined by a pair of message structures: one for for request and one for the reply.
* **Service examples:** [link](
https://github.com/Philori22/ROS_examples/tree/master/services_Examples/).
> [/ros_service_assignment](https://github.com/Philori22/ROS_examples/tree/master/services_Examples/ros_service_assignment) <br>
> [/services_tut](
https://github.com/Philori22/ROS_examples/tree/master/services_Examples/services_tut).

## ROS Motion

## ROS-OpenCV
### ROS Computer Vision

### ROS Laser Rangefinder

## rosserial (connecting to hardware, e.g. Arduino)

#### To-be updated
