#include "circle_through_3_cones/controller.h"
#include <cmath>

// subscribes to a cone_map topic, publishes to control  topic.
Controller::Controller(ros::NodeHandle &n) {
  std::string cone_map_topic, control_topic;
  n.param<std::string>("cone_map_topic", cone_map_topic, "cone_map");
  n.param<std::string>("control_topic", control_topic, "control");

  pub_ = n.advertise<common_msgs::Control>(control_topic, 1);
  sub_ = n.subscribe(cone_map_topic, 1, &Controller::mapCallback, this);
}

// TODO: not sure this does the right thing, need it to take in mesages from
// cone map topic
void Controller::mapCallback(
    const perception_msgs::ConeDepthMap::ConstPtr &msg) {
  common_msgs::Control control;
  int nRed, nGreen;
  nRed = msg->red_cones.size();
  nGreen = msg->green_cones.size();

  float gCones[nGreen][2];
  float rCones[nRed][2];
  for (int i = 0; i < nGreen; i++) {
    gCones[i][0] = msg->green_cones[i].pos.x;
    gCones[i][1] = msg->green_cones[i].pos.y;
  }
  for (int i = 0; i < nRed; i++) {
    rCones[i][0] = msg->red_cones[i].pos.x;
    rCones[i][1] = msg->red_cones[i].pos.y;
  }
  bool runCircle;
  if (nRed >= 1 && nGreen >= 1) {
    // finding 3 smallest r and g cones
    Vec2<> r1(rCones[0][0], rCones[0][1]);
    Vec2<> g1(gCones[0][0], gCones[0][1]);
    for (int i = 1; i < nRed; i++) {
      if (rCones[i][1] < r1.y()) {
        r1 = Vec2<>(rCones[i][0], rCones[i][1]);
      }
    }
    for (int i = 1; i < nGreen; i++) {
      if (gCones[i][1] < g1.y()) {
        g1 = Vec2<>(gCones[i][0], gCones[i][1]);
      }
    }
    Vec2<> p1(0, 0);
    Vec2<> p2((r1.x() + g1.x()) / 2, (r1.y() + g1.y()) / 2);
    Vec2<> p3(p2.x(), -p2.y());
    std::array<float, 3> path = calcCircle(p1, p2, p3);
    // TODO: radius might not be in cm, convert to cm.
    float theta = asin(.48 / path[2]);
    if (path[0] > 0) {
      // steering positive
      control.steering = theta / 0.32;
    } else {
      control.steering = -theta / 0.32;
    }
    control.throttle = 0.11;
  } else {
    if (nGreen == 0 && nRed == 0) {
      control.throttle = 0;
      control.steering = 0;
      control.braking = 1;
    } else {
      if (msg->red_cones.size() == 0) {
        control.steering = -.6;
      } else {
        control.steering = .6;
      }
      control.throttle = .11;
    }
  }
  clamp(control);
  pub_.publish(control);
}

// takes in 3 Vec2 points, and returns a float[3] in the form {x,y,r} for the
// circle defined by those 3 points.
std::array<float, 3> Controller::calcCircle(Vec2<> p1, Vec2<> p2, Vec2<> p3) {
  Vec2<> mid1((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2);
  Vec2<> mid2((p1.x() + p3.x()) / 2, (p1.y() + p3.y()) / 2);
  float m1 = -(p1.x() - p2.x()) / (p1.y() - p2.y());
  float m2 = -(p1.x() - p3.x()) / (p1.y() - p3.y());
  float x = (m2 * mid2.x() - m1 * mid1.x() + mid1.y() - mid2.y()) / (m2 - m1);
  float y = m1 * (x - mid1.x()) + mid1.y();
  float r =
      sqrt((mid1.x() - x) * (mid1.x() - x) + (mid1.y() - y) * (mid1.y() - 1));
  return {x, y, r};
}
