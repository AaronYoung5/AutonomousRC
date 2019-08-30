#pragma once

#include <ros/ros.h>

#include <common_utilities/Vector.h>
#include <control_utilities/Common.h>

#include <common_msgs/Control.h>
#include <perception_msgs/ConeDepthMap.h>

#include <rviz_visual_tools/rviz_visual_tools.h>

#include <math.h>

using namespace common_utilities;
using namespace control_utilities;

class Controller {
private:
  ros::Publisher pub_;
  ros::Subscriber sub_;

  rviz_visual_tools::RvizVisualToolsPtr visual_tools_;

public:
  Controller(ros::NodeHandle &n);

private:
  void mapCallback(const perception_msgs::ConeDepthMap::ConstPtr &msg);

  void visualizePath(std::vector<Vec2<>> &path, rviz_visual_tools::colors color);
  void visualizeRadius(int radius, rviz_visual_tools::colors color);
};
