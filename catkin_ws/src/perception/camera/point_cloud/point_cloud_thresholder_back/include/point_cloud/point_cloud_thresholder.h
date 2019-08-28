#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"

class PointCloudThresholder {
private:
  ros::Subscriber sub_;

  ros::Publisher pub_;

  bool image_display_, image_simulated_;

public:
  PointCloudThresholder(ros::NodeHandle &n);

private:
  void imageCallback(const sensor_msgs::PointCloud2::ConstPtr &msg);
  void createPCL2(sensor_msgs::PointCloud2 &msg, std::vector<uint8_t> &points);
};

