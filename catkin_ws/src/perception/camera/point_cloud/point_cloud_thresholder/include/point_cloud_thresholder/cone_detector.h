#pragma once

#include "ros/ros.h"

#include "pcl/PCLPointCloud2.h"
#include "perception_msgs/ConeXY.h"
#include "perception_msgs/ConeDepthMap.h"

#include "point_cloud_thresholder/clusterer.h"
#include "point_cloud_thresholder/thresholder.h"

#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"

class PointCloudConeDetector {
private:
  ros::Publisher pub_;
  ros::Subscriber sub_;

  ros::Publisher cloud_pub_, marker_pub_;

  PointCloudThresholder thresholder_;
  PointCloudClusterer clusterer_;

  bool image_display_, image_simulated_;

  int max_markers_;

public:
  PointCloudConeDetector(ros::NodeHandle &n);

private:
  void cloudCallback(const pcl::PCLPointCloud2::ConstPtr &msg);
};
