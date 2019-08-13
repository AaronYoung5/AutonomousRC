#include "cone_midpoint_control_2/controller.h"

Controller::Controller(ros::NodeHandle &n) {
  std::string control_topic, cone_topic;
  n.param<std::string>("control_topic", control_topic, "control");
  n.param<std::string>("cone_topic", cone_topic, "cone_image_map");

  pub_ = n.advertise<common_msgs::Control>(control_topic, 1);
  sub_ = n.subscribe(cone_topic, 1, &Controller::imageCallback, this);
}

void Controller::imageCallback(const perception_msgs::ConeImageMap::ConstPtr &msg) {
  common_msgs::Control control;
  int height = msg->height;
  int width = msg->width;

  std::vector<perception_msgs::Cone> green_cones = msg->green_cones;
  std::vector<perception_msgs::Cone> red_cones = msg->red_cones;

  if (green_cones.size() == 0 && red_cones.size() == 0) {
    control.throttle = 0;
    control.steering = 0;
    control.braking = 1;
  } else if (green_cones.size() == 0 || red_cones.size() == 0) {
    control.throttle = .2;
    control.steering = green_cones.size() == 0 ? .6 : -.6;
  } else if (red_cones.size() == 1 || green_cones.size() == 1) {
    Vec2<> avgG1((green_cones[0].tl.x + green_cones[0].br.x) / 2,
                 (green_cones[0].tl.y + green_cones[0].br.y) / 2);
    for (int i = 1; i < green_cones.size(); i++) {
      Vec2<> holdG((green_cones[i].tl.x + green_cones[i].br.x) / 2,
                   (green_cones[i].tl.y + green_cones[i].br.y) / 2);
      if (holdG.y() > avgG1.y()) {
        avgG1 = holdG;
      }
    }

    Vec2<> avgR1((red_cones[0].tl.x + red_cones[0].br.x) / 2,
                 (red_cones[0].tl.y + red_cones[0].br.y) / 2);
    for (int i = 1; i < red_cones.size(); i++) {
      Vec2<> holdR((red_cones[i].tl.x + red_cones[i].br.x) / 2,
                   (red_cones[i].tl.y + red_cones[i].br.y) / 2);
      if (holdR.y() > avgR1.y()) {
        avgR1 = holdR;
      }
    }
    Vec2<> destination((avgR1 + avgG1) / 2);
    Vec2<> center(width / 2, height / 2);
    control.steering = (destination.x() - center.x()) / center.x();
    control.throttle = .2;
  } else {
    //   // finding lower left green cone
    Vec2<> avgG1((green_cones[0].tl.x + green_cones[0].br.x) / 2,
                 (green_cones[0].tl.y + green_cones[0].br.y) / 2);
    for (int i = 1; i < green_cones.size(); i++) {
      Vec2<> holdG((green_cones[i].tl.x + green_cones[i].br.x) / 2,
                   (green_cones[i].tl.y + green_cones[i].br.y) / 2);
      if (holdG.y() > avgG1.y()) {
        avgG1 = holdG;
      }
    }
    // finding second lowest left green cone
    Vec2<> avgG2((green_cones[0].tl.x + green_cones[0].br.x) / 2,
                 (green_cones[0].tl.y + green_cones[0].br.y) / 2);
    if (avgG2.x() == avgG1.x() && avgG2.y() == avgG2.y())
      Vec2<> avgG2((green_cones[1].tl.x + green_cones[1].br.x) / 2,
                   (green_cones[1].tl.y + green_cones[1].br.y) / 2);
    for (size_t i = 1; i < green_cones.size(); i++) {
      Vec2<> holdG((green_cones[i].tl.x + green_cones[i].br.x) / 2,
                   (green_cones[i].tl.y + green_cones[i].br.y) / 2);
      if (holdG.y() > avgG2.y() && holdG.x() != avgG1.x() &&
          holdG.y() != avgG1.y()) {
        avgG2 = holdG;
      }
    }

    //   // finding lower left red cone
    Vec2<> avgR1((red_cones[0].tl.x + red_cones[0].br.x) / 2,
                 (red_cones[0].tl.y + red_cones[0].br.y) / 2);
    for (int i = 1; i < red_cones.size(); i++) {
      Vec2<> holdR((red_cones[i].tl.x + red_cones[i].br.x) / 2,
                   (red_cones[i].tl.y + red_cones[i].br.y) / 2);
      if (holdR.y() > avgR1.y()) {
        avgR1 = holdR;
      }
    }
    // finding second lowest left red cone
    Vec2<> avgR2((red_cones[0].tl.x + red_cones[0].br.x) / 2,
                 (red_cones[0].tl.y + red_cones[0].br.y) / 2);
    if (avgR2.x() == avgR1.x() && avgR2.y() == avgR1.y())
      Vec2<> avgR2((red_cones[1].tl.x + red_cones[1].br.x) / 2,
                   (red_cones[1].tl.y + red_cones[1].br.y) / 2);
    for (size_t i = 1; i < red_cones.size(); i++) {
      Vec2<> holdR((red_cones[i].tl.x + red_cones[i].br.x) / 2,
                   (red_cones[i].tl.y + red_cones[i].br.y) / 2);
      if (holdR.y() > avgR2.y() && holdR.x() != avgR1.x() &&
          holdR.y() != avgR1.y()) {
        avgR2 = holdR;
      }
    }

    // weighted average for G1/G2 and R1/R2 x coordinates
    int xPositionDestination =((int)( (float)avgG1.x() * 0.25 + (float)avgG2.x() * 0.75)+(int)((float)avgR1.x() * 0.25 + (float)avgR2.x() * 0.75))/2;
    // setting destination
    Vec2<> destination(xPositionDestination,0);
    // checking buffer for destination with G1&R1
    if (destination.x() < avgR1.x() + 0.05 * width)
      destination.x() = avgR1.x() + 0.05 * width;
   else if (destination.x() > avgG1.x() - 0.05 * width)
      destination.x() = avgG1.x() - 0.05 * width;
    // finding center
    Vec2<> center(width / 2, height / 2);
    // setting steering
    control.steering = (destination.x() - center.x()) / (float)center.x();

    control.throttle = .2;
  }

  clamp(control);
  pub_.publish(control);
}
