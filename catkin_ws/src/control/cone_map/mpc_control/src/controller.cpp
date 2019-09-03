#include "mpc_control/controller.h"
#include <cmath>

// subscribes to a cone_map topic, publishes to control  topic.
Controller::Controller(ros::NodeHandle &n) {
  std::string cone_topic, control_topic;
  n.param<std::string>("cone_topic", cone_topic, "cone_map");
  n.param<std::string>("control_topic", control_topic, "control");

  pub_ = n.advertise<common_msgs::Control>(control_topic, 1);
  sub_ = n.subscribe(cone_topic, 1, &Controller::mapCallback, this);
}

// TODO: not sure this does the right thing, need it to take in mesages from
// cone map topic
void Controller::mapCallback(
    const perception_msgs::ConeDepthMap::ConstPtr &msg) {
  common_msgs::Control control;



  clamp(control);
  pub_.publish(control);
}
