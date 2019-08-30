#include "point_cloud_thresholder/cone_detector.h"

#include <pcl/console/time.h>

PointCloudConeDetector::PointCloudConeDetector(ros::NodeHandle &n)
    : max_markers_(0) {
  std::string cloud_topic, cone_topic;
  n.param<std::string>("cloud_topic", cloud_topic,
                       "/zed/zed_node/point_cloud/cloud_registered");
  n.param<std::string>("cone_topic", cone_topic, "cone_image_map");
  n.param("display", visualize_, false);
  n.param("simulating", image_simulated_, true);

  // subscribe to point cloud feed
  sub_ =
      n.subscribe(cloud_topic, 1, &PointCloudConeDetector::cloudCallback, this);

  pub_ = n.advertise<perception_msgs::ConeDepthMap>(cone_topic, 1);
  cloud_pub_ = n.advertise<pcl::PCLPointCloud2>("thresholded_pc", 1);
  marker_pub_ = n.advertise<visualization_msgs::MarkerArray>("cones_array", 1);

  visual_tools_.reset(new rviz_visual_tools::RvizVisualTools(
      "/zed_left_camera_frame", "/rviz_visual_markers"));
  visual_tools_->enableBatchPublishing(true);
}

void PointCloudConeDetector::cloudCallback(
    const pcl::PCLPointCloud2::ConstPtr &msg) {
  pcl::console::TicToc tt;
  std::cerr << "Thresholding...\n", tt.tic();
  pcl::PCLPointCloud2::Ptr thresholded_msg(new pcl::PCLPointCloud2());
  thresholder_.Threshold(thresholded_msg, msg);
  std::cerr << ">> Done: " << tt.toc() << " ms" << std::endl;

  if (visualize_) {
    cloud_pub_.publish(thresholded_msg);
  }

  std::cerr << "Clustering...\n", tt.tic();
  perception_msgs::ConeDepthMap cone_map;
  clusterer_.Cluster(cone_map, thresholded_msg);
  std::cerr << ">> Done: " << tt.toc() << " ms" << std::endl;

  if (visualize_) {
    visualizeCones(cone_map);
  }

  pcl_conversions::fromPCL(msg->header, cone_map.header);
  pub_.publish(cone_map);
}

void PointCloudConeDetector::visualizeCones(
    perception_msgs::ConeDepthMap &cone_map) {
  // visualization_msgs::MarkerArray marker_array;
  // int j = 1;
  visual_tools_->deleteAllMarkers();
  for (perception_msgs::ConeXY cone : cone_map.red_cones) {
    Eigen::Isometry3d pose;
    pose = Eigen::AngleAxisd(0, Eigen::Vector3d::UnitY());
    pose.translation() = Eigen::Vector3d(cone.pos.x, cone.pos.y, cone.pos.z);
    Eigen::Vector3d min_point, max_point;
    min_point << -0.075, -0.075, -0.075;
    max_point << 0.075, 0.075, 0.075;
    visual_tools_->publishWireframeCuboid(pose, min_point, max_point,
                                          rviz_visual_tools::RED);
    // j++;
  }
  for (perception_msgs::ConeXY cone : cone_map.green_cones) {
    Eigen::Isometry3d pose;
    pose = Eigen::AngleAxisd(0, Eigen::Vector3d::UnitY());
    pose.translation() = Eigen::Vector3d(cone.pos.x, cone.pos.y, cone.pos.z);
    Eigen::Vector3d min_point, max_point;
    min_point << -0.075, -0.075, -0.075;
    max_point << 0.075, 0.075, 0.075;
    visual_tools_->publishWireframeCuboid(pose, min_point, max_point,
                                          rviz_visual_tools::GREEN);
    // j++;
  }
  visual_tools_->trigger();
  // if (j > max_markers_) {
  //   max_markers_ = j;
  // }
  // while (j < max_markers_) {
  //   visualization_msgs::Marker marker;
  //   marker.header.frame_id = "/zed_left_camera_frame";
  //   marker.header.stamp = ros::Time::now();
  //   marker.ns = "basic_shapes";
  //   marker.id = j++;
  //   marker.action = visualization_msgs::Marker::ADD;
  //   marker.scale.x = 0.1;
  //   marker.scale.y = 0.1;
  //   marker.scale.z = 0.1;
  //   marker.color.a = 0.0;
  //   marker_array.markers.push_back(marker);
  // }
  // marker_pub_.publish(marker_array);
}
