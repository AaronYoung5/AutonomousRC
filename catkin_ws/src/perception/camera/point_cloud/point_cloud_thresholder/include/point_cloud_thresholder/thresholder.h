#pragma once

#include "ros/ros.h"

#include "common_utilities/Color.h"
#include "sensor_msgs/PointCloud2.h"

using namespace common_utilities;

class PointCloudThresholder {
private:
  sensor_msgs::PointCloud2 thresholded_msg_;

public:
  PointCloudThresholder();

  sensor_msgs::PointCloud2 &
  Threshold(const sensor_msgs::PointCloud2::ConstPtr &msg);

private:
  void createPointCloud2(std::vector<uint8_t> &points);
};
