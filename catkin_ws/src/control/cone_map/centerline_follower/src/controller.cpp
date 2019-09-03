#include "centerline_follower/controller.h"

Controller::Controller(ros::NodeHandle &n) {
  std::string cone_topic, control_topic;
  n.param<std::string>("cone_topic", cone_topic, "cone_map");
  n.param<std::string>("control_topic", control_topic, "control");

  pub_ = n.advertise<common_msgs::Control>(control_topic, 1);
  sub_ = n.subscribe(cone_topic, 1, &Controller::mapCallback, this);

  visual_tools_.reset(new rviz_visual_tools::RvizVisualTools(
      "/zed_left_camera_frame", "/rviz_path_visual"));
  visual_tools_->enableBatchPublishing(true);
}

// Message will be in the following format
// For each one, may substitude with "green_cones" instead of red
// msg->red_cones :: std::vector of cone objects
// msg->red_cones[i].pos.x :: accessor for x,y,z positions of cones
void Controller::mapCallback(
    const perception_msgs::ConeDepthMap::ConstPtr &msg) {
  // Control message to publish
  // control.throttle :: [ 0, 1]
  // control.steering :: [-1, 1]
  common_msgs::Control control;

  // Path to follow
  std::vector<Vec2<>> path;

  path.push_back(Vec2<>(1,1));
  path.push_back(Vec2<>(2,5));
  path.push_back(Vec2<>(3,10));

  // Turning radius
  int radius = 10;

  // Visualize path
  visual_tools_->deleteAllMarkers();
  visualizePath(path, rviz_visual_tools::RED);

  // Visualize radius
  visualizeRadius(radius, rviz_visual_tools::MAGENTA);
  visual_tools_->trigger();

  // Publish control message
  clamp(control);
  pub_.publish(control);
}

void Controller::visualizePath(std::vector<Vec2<>> &path,
                               rviz_visual_tools::colors color) {
  EigenSTL::vector_Vector3d path_to_visualize;
  Eigen::Isometry3d pose = Eigen::Isometry3d::Identity();
  std::vector<rviz_visual_tools::colors> colors;

  for (Vec2<> waypoint : path) {
    pose.translation().x() = waypoint.x();
    pose.translation().y() = waypoint.y();
    path_to_visualize.emplace_back(pose.translation());

    colors.push_back(color);
  }

  visual_tools_->publishPath(path_to_visualize, colors);
}

void Controller::visualizeRadius(int radius, rviz_visual_tools::colors color) {
  EigenSTL::vector_Vector3d path_to_visualize;
  Eigen::Isometry3d pose = Eigen::Isometry3d::Identity();
  std::vector<rviz_visual_tools::colors> colors;

  for (int i = 0; i < 10; i++) {
    pose.translation().x() += 1;
    pose.translation().y() += i;

    path_to_visualize.emplace_back(pose.translation());

    colors.push_back(color);
  }

  visual_tools_->publishPath(path_to_visualize, colors);
}
