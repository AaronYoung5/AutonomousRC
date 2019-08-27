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
  // sensor_msgs::PointCloud2 new_msg;
  // new_msg = *msg;

  bool thresh_green = true;
  uint8_t redLow, redHigh;
  uint8_t greenLow, greenHigh;
  uint8_t blueLow, blueHigh;
  if (thresh_green) {
	  // Green Cone Threshold
	  // 	R :: [20, 200]
	  // 	G :: [120, 255]
	  // 	B :: [0, 50]
	  redLow = 20;
	  redHigh = 200;

	  greenLow = 120;
	  greenHigh = 255;

	  blueLow = 0;
	  blueHigh = 50;
  }
  else {
	  // Red Cone Threshold
	  // 	R :: [0, 100]
	  // 	G :: [0, 50]
	  // 	B :: [90, 255]
	  redLow = 0;
	  redHigh = 100;

	  greenLow = 0;
	  greenHigh = 100;

	  blueLow = 150;
	  blueHigh = 255;
  }


  int j = 0;
  int offset = 12;
  for (int i = offset; i < (msg->row_step * msg->height); i += 16) { // loop through every point in pointcloud
  bool redInRange = true;
  bool greenInRange = true;
  bool blueInRange = true;
    if (msg->data[i] < redLow || msg->data[i] > redHigh) {
      redInRange = false;
    }
    if (msg->data[i + 1] < greenLow || msg->data[i + 1] > greenHigh) {
      greenInRange = false;
    }
    if (msg->data[i + 2] < blueLow || msg->data[i + 2] > blueHigh) {
      blueInRange = false;
    }

    if (redInRange && greenInRange &&
         blueInRange) { // if red green and blue are with in range, add to the new point_cloud
      in_range_points.resize(in_range_points.size() + 16);
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
  msg.header.frame_id = "zed_left_camera_frame";

  // Convert x/y/z to fields
  msg.fields.resize(4);
  msg.fields[0].name = "x";
  msg.fields[1].name = "y";
  msg.fields[2].name = "z";
  msg.fields[3].name = "rgb";

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

  msg.data.resize(msg.row_step);
  memcpy(&msg.data[0], points.data(), msg.row_step);
}
