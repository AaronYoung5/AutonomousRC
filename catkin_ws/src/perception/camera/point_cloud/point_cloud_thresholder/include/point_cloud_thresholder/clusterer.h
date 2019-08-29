#pragma once

#include "ros/ros.h"

#include "pcl/PCLPointCloud2.h"
#include "perception_msgs/ConeDepthMap.h"

class PointCloudClusterer {
private:
  perception_msgs::ConeDepthMap map_;

public:
  PointCloudClusterer();

  perception_msgs::ConeDepthMap &Cluster(pcl::PCLPointCloud2 &msg);
};
