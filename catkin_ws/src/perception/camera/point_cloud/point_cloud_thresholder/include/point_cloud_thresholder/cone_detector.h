#pragma once

#include "ros/ros.h"

#include "perception_msgs/ConeDepthMap.h"
#include "sensor_msgs/PointCloud2.h"

#include "point_cloud_thresholder/clusterer.h"
#include "point_cloud_thresholder/thresholder.h"

class PointCloudConeDetector {
private:
  ros::Publisher pub_;
  ros::Subscriber sub_;

  PointCloudThresholder thresholder_;
  PointCloudClusterer clusterer_;

public:
  PointCloudConeDetector(ros::NodeHandle &n);

private:
  void cloudCallback(const sensor_msgs::PointCloud2::ConstPtr &msg);
};
