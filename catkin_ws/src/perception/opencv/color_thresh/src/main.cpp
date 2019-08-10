// ROS include
#include "ros/ros.h"
#include "color_thresh/color_thresholder.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "opencv_color_thresh");
  ros::NodeHandle n("~");

  ColorThresholder converter(n);

  ros::spin();
}
