// ROS include
#include "ros/ros.h"
#include "thresholding/image_converter.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "opencv_thresholding");
  ros::NodeHandle n;

  ImageConverter converter(n);

  ros::spin();
}
