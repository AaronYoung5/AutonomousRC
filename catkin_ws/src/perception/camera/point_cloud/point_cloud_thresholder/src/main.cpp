// ROS include
#include "ros/ros.h"
#include "point_cloud/point_cloud_thresholder.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "thresholding");
  ros::NodeHandle n("~");

  PointCloudThresholder thresholder(n);

  ros::spin();
}
