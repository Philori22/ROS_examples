# Robot Operating System (ROS) examples
While reviewing the basics for the ROS framework, some packages were created - the repository contains Basics, Motion, OpenCV, Localization, Navigation and SLAM in ROS. All of the following examples are written in *C++*, with exception to aspects which are otherwise specified.


## ROS Basics
Robot Operating system is an open-source, robotics middlweare often used when designing an implementing functionality within robots. You could simply consider it as a peer-to-peer network of processes that are processing data together. This network is comprised of nodes, master, parameter server, messages, services, topics and bags.

Nodes are processes that perform some action. these software modules reister with the ROS master node and communicate with other nodes in the system. Each node is independent, but interact with others using the communication capability. The Master node establishes this commuication with other nodes in the system, oftenly with internet protocal called TCPROS in ROS. 

Nodes send (publish) messages on channels called 'topics', and listen for messages by 'subscribing' to the topics.
### ROS Topics
A node sends out a message by _publishing_ it in a given topic. The topic name can be used to identify the content of the message. The node interested in a certin type of data will _subscribe_ to the approprite topic. The following examples publish and subscribe to a given topic, sending a message of a certain type.
* [Example 1](https://github.com/Philori22/ROS_examples/tree/master/chatting): Sending and Receiving "Hello World" messages of type _String_ using `chatter` _topic_, _(how unique)_.
  > **_talker.cpp_, 'talker'** publisher node, publishes the String message 'Hello world' to _topic_ "chatter", counting the number of messages send with an id.
  > **_listener.cpp_, 'listener'** subscriber node, subscribes the the "chatter topic" and calls `chatterCallback()`, which prints an acknowledgement to terminal with the number message id.
* [Example 2](http://github.com): **_publishing & subscribing_** using Turtlesim. , with geometry messages (Angular and linear velocity).
  > **_robot_move_topics.cpp_, 'speed_pub'** publisher node, publishes geometry messages (Random Angular and linear velocity values) to `/turtle1/cmd_vel` Turtlesim _topic_, to move the turtle aroud the environment. <br>
  > **_turtlesim_pose.cpp_, 'sub_pose'** subscribes to the `/turtle1/pose` Turtlesim _topic_, and prints the turtles position _(x,y,theta)_ to terminal.

### ROS Services
Publish/subscribe model is very flexible, but its not appropriate for request/reply interactions, which are often needed in distibuted systems. Services establish Request/Reply, which are deined by a pair of message structures: one for for request and one for the reply.

## ROS Motion

## ROS-OpenCV
### ROS Computer Vision

### ROS Laser Rangefinder

## rosserial (connecting to hardware, e.g. Arduino)

#### To-be updated
