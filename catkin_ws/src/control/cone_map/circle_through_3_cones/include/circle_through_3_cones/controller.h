#pragma once

#include <ros/ros.h>

#include<common_utilities/Vector.h>
#include <control_utilities/Common.h>

#include <common_msgs/Control.h>
#include <perception_msgs/ConeImageMap.h>

using namespace common_utilities;
using namespace control_utilities;

class Controller {
private:
  ros::Publisher pub_;
  ros::Subscriber sub_;

public:
  Controller(ros::NodeHandle &n);
~Controller(){}

private:
  void imageCallback(const perception_msgs::ConeImageMap::ConstPtr &msg);
};
