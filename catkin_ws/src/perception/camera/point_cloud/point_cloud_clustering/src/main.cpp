// ROS include
#include "ros/ros.h"
#include "point_cloud_clustering/point_cloud_clustering.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "pcl_detecting");
  ros::NodeHandle n("~");

  PointCloudThresholder thresholder(n);

  ros::spin();
}
