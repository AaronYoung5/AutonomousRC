#pragma once

#include <ros/ros.h>

<<<<<<< HEAD
#include <common_utilities/Vector.h>
#include <control_utilities/Common.h>

#include <common_msgs/Control.h>
#include <perception_msgs/ConeDepthMap.h>
=======
#include<common_utilities/Vector.h>
#include <control_utilities/Common.h>

#include <common_msgs/Control.h>
#include <perception_msgs/ConeImageMap.h>
>>>>>>> 1b51b11038f65a072f38f4ab930e8301277e0079

using namespace common_utilities;
using namespace control_utilities;

class Controller {
private:
  ros::Publisher pub_;
  ros::Subscriber sub_;

public:
  Controller(ros::NodeHandle &n);
<<<<<<< HEAD

private:
  void mapCallback(const perception_msgs::ConeDepthMap::ConstPtr &msg);
  std::array<float, 3> calcCircle(Vec2<> p1,Vec2<> p2, Vec2<> p3);

=======
~Controller(){}

private:
  void imageCallback(const perception_msgs::ConeImageMap::ConstPtr &msg);
>>>>>>> 1b51b11038f65a072f38f4ab930e8301277e0079
};
