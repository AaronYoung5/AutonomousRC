#include "point_cloud_thresholder/cone_detector.h"

PointCloudConeDetector::PointCloudConeDetector(ros::NodeHandle &n) {
  // std::string image_topic, cone_topic;
  // n.param<std::string>("image_topic", image_topic, "image_data_raw");
  // n.param<std::string>("cone_topic", cone_topic, "cone_image_map");
  // n.param("display", image_display_, false);
  // n.param("simulating", image_simulated_, true);

  // subscribe to point cloud feed
  sub_ = n.subscribe("zed/zed_node/point_cloud/cloud_registered", 1,
                     &PointCloudConeDetector::cloudCallback, this);

  pub_ = n.advertise<perception_msgs::ConeDepthMap>("new_point_cloud", 1);
}

void PointCloudConeDetector::cloudCallback(const sensor_msgs::PointCloud2::ConstPtr &msg) {
  sensor_msgs::PointCloud2& thresholded_msg = thresholder_.Threshold(msg);

  perception_msgs::ConeDepthMap cone_map =
      clusterer_.Cluster(thresholded_msg);

  pub_.publish(cone_map);
}
