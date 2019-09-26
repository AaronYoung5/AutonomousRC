// ROS include
#include "ros/ros.h"
#include "cone_midpoint_control_with_reverse/controller.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "cone_midpoint_control_with_reverse");
  ros::NodeHandle n("~");

  Controller controller(n);

  ros::spin();
}
