#include "point_cloud/point_cloud_thresholder.h"

PointCloudThresholder::PointCloudThresholder(ros::NodeHandle &n) {
  std::string image_topic, cone_topic;
  n.param<std::string>("image_topic", image_topic, "image_data_raw");
  n.param<std::string>("cone_topic", cone_topic, "cone_image_map");
  n.param("display", image_display_, false);
  n.param("simulating", image_simulated_, true);

  // subscribe to point cloud feed
  sub_ =
      n.subscribe(image_topic, 1, &PointCloudThresholder::imageCallback, this);

  pub_ = n.advertise<sensor_msgs::PointCloud2>("new_point_cloud", 1);
}

void PointCloudThresholder::imageCallback(
    const sensor_msgs::PointCloud2::ConstPtr &msg) {
  std::vector<uint8_t> in_range_points;

  bool redInRange = false;
  bool greenInRange = false;
  bool blueInRange = false;

  // looking for green cones right now
  uint8_t redLow = 0;
  uint8_t redHigh = 255;

  uint8_t greenLow = 0;
  uint8_t greenHigh = 255;

  uint8_t blueLow = 0;
  uint8_t blueHigh = 255;

  int j = 0;
	int offset = 12;
  for (int i = offset; i < (msg->row_step * msg->height);
       i += 16) { // loop through every point in pointcloud
    if (i < (msg->row_step * msg->height)) {
      // ROS_INFO_STREAM("RGB :: [" << (int)msg->data[i] << ", " <<
      // (int)msg->data[i+1] << ", " << (int)msg->data[i+2] << "]");
    }
    if (msg->data[i] < redLow || msg->data[i] > redHigh) {
			ROS_INFO("RED :: not in range");
      redInRange = false;
    }
    if (msg->data[i + 1] < greenLow || msg->data[i + 1] > greenHigh) {
			ROS_INFO("GREEN :: not in range");
      greenInRange = false;
    }
    if (msg->data[i + 2] < blueLow || msg->data[i + 2] > blueHigh) {
			ROS_INFO("BLUE :: not in range");
      blueInRange = false;
    }

    if ((redInRange && greenInRange &&
         blueInRange)) { // if red green and blue aren't in range then make
                         // pixel black
      memcpy(&in_range_points.data()[j], &(msg->data[i - offset]), 16);
      j += 16;
    }
  } // end for loop
  sensor_msgs::PointCloud2 new_msg;
  createPCL2(new_msg, in_range_points);
  pub_.publish(new_msg);
}

void PointCloudThresholder::createPCL2(sensor_msgs::PointCloud2 &msg, std::vector<uint8_t>& points) {
  msg.header.stamp = ros::Time::now();
  msg.header.frame_id = "base_link";

  // Convert x/y/z to fields
  msg.fields.resize(3);
  msg.fields[0].name = "x";
  msg.fields[1].name = "y";
  msg.fields[2].name = "z";
  msg.fields[2].name = "rgb";

  int offset = 0;
  for (size_t d = 0; d < msg.fields.size(); d++, offset += 4) {
    msg.fields[d].offset = offset;
    msg.fields[d].datatype = sensor_msgs::PointField::FLOAT32;
    msg.fields[d].count = 1;
  }

  msg.point_step = offset;

  msg.is_bigendian = false;
  msg.is_dense = false;

  msg.width = points.size() / 16;
  msg.height = 1;

  msg.row_step = msg.point_step * msg.width;
}
