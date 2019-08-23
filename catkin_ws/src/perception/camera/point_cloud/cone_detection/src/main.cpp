// ROS include
#include "ros/ros.h"
#include "pcl_cone_detect/pcl_cone_detector.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "pcl_detecting");
  ros::NodeHandle n("~");

  PointCloudThresholder thresholder(n);

  ros::spin();
}
