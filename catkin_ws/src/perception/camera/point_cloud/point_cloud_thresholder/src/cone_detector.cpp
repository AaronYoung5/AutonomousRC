#include "point_cloud_thresholder/cone_detector.h"

PointCloudConeDetector::PointCloudConeDetector(ros::NodeHandle &n)
    : max_markers_(0) {
  std::string image_topic, cone_topic;
  n.param<std::string>("image_topic", image_topic,
                       "/zed/zed_node/point_cloud/cloud_registered");
  n.param<std::string>("cone_topic", cone_topic, "cone_image_map");
  n.param("display", image_display_, false);
  n.param("simulating", image_simulated_, true);

  // subscribe to point cloud feed
  sub_ =
      n.subscribe(image_topic, 1, &PointCloudConeDetector::cloudCallback, this);

  pub_ = n.advertise<perception_msgs::ConeDepthMap>(cone_topic, 1);
  cloud_pub_ = n.advertise<pcl::PCLPointCloud2>("thresholded_pc", 1);
  marker_pub_ = n.advertise<visualization_msgs::MarkerArray>("cones_array", 1);
}

void PointCloudConeDetector::cloudCallback(
    const pcl::PCLPointCloud2::ConstPtr &msg) {
  pcl::PCLPointCloud2 &thresholded_msg = thresholder_.Threshold(msg);
  cloud_pub_.publish(thresholded_msg);

  perception_msgs::ConeDepthMap cone_map = clusterer_.Cluster(thresholded_msg);

  visualization_msgs::MarkerArray marker_array;
  int j = 1;
  for (perception_msgs::ConeXY cone : cone_map.red_cones) {
    visualization_msgs::Marker marker;
    marker.header.frame_id = "/zed_left_camera_frame";
    marker.header.stamp = ros::Time::now();
    marker.ns = "basic_shapes";
    marker.id = j++;
    marker.type = visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = cone.pos.x;
    marker.pose.position.y = cone.pos.y;
    marker.pose.position.z = cone.pos.z;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = 0.1;
    marker.scale.y = 0.1;
    marker.scale.z = 0.1;
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;
    marker_array.markers.push_back(marker);
  }
  if (j > max_markers_) {
    max_markers_ = j;
  }
  while (j < max_markers_) {
    visualization_msgs::Marker marker;
    marker.header.frame_id = "/zed_left_camera_frame";
    marker.header.stamp = ros::Time::now();
    marker.ns = "basic_shapes";
    marker.id = j++;
    marker.action = visualization_msgs::Marker::ADD;
    marker.scale.x = 0.1;
    marker.scale.y = 0.1;
    marker.scale.z = 0.1;
    marker.color.a = 0.0;
    marker_array.markers.push_back(marker);
  }
  marker_pub_.publish(marker_array);

  pub_.publish(cone_map);
}
