# Robot Operating System (ROS) examples
While reviewing the basics for the ROS framework, some packages were created - the repository contains Basics, Motion, OpenCV, Localization, Navigation and SLAM in ROS. All of the following examples are written in c++, with exception to aspects which are otherwise specified.

## ROS Basics
Robot Operating system is an open-source, robotics middlweare often used when designing an implementing functionality within robots. You could simply consider it as a peer-to-peer network of processes that are processing data together. This network is comprised of nodes, master, parameter server, messages, services, topics and bags.

Nodes are processes that perform some action. these software modules reister with the ROS master node and communicate with other nodes in the system. Each node is independent, but interact with others using the communication capability. The Master node establishes this commuication with other nodes in the system, oftenly with internet protocal called TCPROS in ROS. 

Nodes send (publish) messages on channels called 'topics', and listen for messages by 'subscribing' to the topics.
### ROS Topics
A node sends out a message by _publishing_ it in a given topic. The topic name can be used to identify the content of the message. The node interested in a certin type of data will _subscribe_ to the approprite topic.
* Nodes _publishing & subscribibg_ to topic with string messsage "Hello World" _(how surprising)_ 
* 'Speed_pub' node for Turtlesim environment, publishing Geometry msgs (Angular and linear velocity)

### ROS Services


## ROS Motion

## ROS-OpenCV
### ROS Computer Vision

### ROS Laser Rangefinder

## rosserial (connecing to hardware, e.g. Arduino)

#### To-be updated
