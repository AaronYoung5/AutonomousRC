#pragma once

#include "ros/ros.h"

#include "perception_msgs/ConeDepthMap.h"
#include "sensor_msgs/PointCloud2.h"

class PointCloudClusterer {
public:
  PointCloudClusterer();

  perception_msgs::ConeDepthMap &Cluster(sensor_msgs::PointCloud2 &msg);
};
