#pragma once

#include "ros/ros.h"

#include "common_utilities/Color.h"
#include "pcl/PCLPointCloud2.h"
#include <pcl_conversions/pcl_conversions.h>

using namespace common_utilities;

class PointCloudThresholder {
private:
  pcl::PCLPointCloud2 thresholded_msg_;

public:
  PointCloudThresholder();

  pcl::PCLPointCloud2 &
  Threshold(const pcl::PCLPointCloud2::ConstPtr &msg);

private:
  void createPointCloud2(std::vector<uint8_t> &points);
};
