// ROS include
#include "ros/ros.h"
#include "color_thresh/image_converter.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "opencv_color_thresh");
  ros::NodeHandle n;

  ImageConverter converter(n);

  ros::spin();
}
