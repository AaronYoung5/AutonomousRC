#pragma once

#include <ros/ros.h>

#include <common_utilities/Vector.h>
#include <control_utilities/Common.h>

#include <common_msgs/Control.h>
#include <perception_msgs/ConeDepthMap.h>

using namespace common_utilities;
using namespace control_utilities;

class Controller {
private:
  ros::Publisher pub_;
  ros::Subscriber sub_;

public:
  Controller(ros::NodeHandle &n);

private:
  void mapCallback(const perception_msgs::ConeDepthMap::ConstPtr &msg);
  std::array<float, 3> calcCircle(Vec2<> p1,Vec2<> p2, Vec2<> p3);

};
