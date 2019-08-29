#include "point_cloud_thresholder/thresholder.h"

PointCloudThresholder::PointCloudThresholder() {}

pcl::PCLPointCloud2 &
PointCloudThresholder::Threshold(const pcl::PCLPointCloud2::ConstPtr &msg) {
  std::vector<uint8_t> points;

  ColorRange green(Color(20, 120, 0), Color(200, 255, 50));
  ColorRange red(Color(0, 0, 150), Color(100, 100, 255));

  int j = 0;
  int color_offset = 12;
  int offset = 16;
  for (int i = color_offset; i < (msg->row_step * msg->height); i += offset) {

    Color point_color(msg->data[i], msg->data[i + 1], msg->data[i + 2]);


    if (green.WithinRange(point_color) || red.WithinRange(point_color)) {
      points.insert(points.end(), &msg->data[i - color_offset],
                    &msg->data[i + 4]);
    }
  }

  thresholded_msg_.data.resize(0);
  createPointCloud2(points);
  return thresholded_msg_;
}

void PointCloudThresholder::createPointCloud2(std::vector<uint8_t> &points) {
  pcl_conversions::toPCL(ros::Time::now(), thresholded_msg_.header.stamp);
  thresholded_msg_.header.frame_id = "zed_left_camera_frame";

  // Convert x/y/z to fields
  thresholded_msg_.fields.resize(4);
  thresholded_msg_.fields[0].name = "x";
  thresholded_msg_.fields[1].name = "y";
  thresholded_msg_.fields[2].name = "z";
  thresholded_msg_.fields[3].name = "rgb";

  int offset = 0;
  for (size_t d = 0; d < thresholded_msg_.fields.size(); d++, offset += 4) {
    thresholded_msg_.fields[d].offset = offset;
    thresholded_msg_.fields[d].datatype = pcl::PCLPointField::FLOAT32;
    thresholded_msg_.fields[d].count = 1;
  }

  thresholded_msg_.point_step = offset;

  thresholded_msg_.is_bigendian = false;
  thresholded_msg_.is_dense = false;

  thresholded_msg_.width = points.size() / 16;
  thresholded_msg_.height = 1;

  thresholded_msg_.row_step =
      thresholded_msg_.point_step * thresholded_msg_.width;

  thresholded_msg_.data.resize(thresholded_msg_.row_step);
  memcpy(&thresholded_msg_.data[0], points.data(), thresholded_msg_.row_step);
}
