#include "ros/ros.h"

#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <sensor_msgs/image_encodings.h>

#include "common_msgs/Control.h"
#include "opencv_msgs/ConeImageMap.h"

static const std::string ORIGINAL_WINDOW = "Original Image";
static const std::string THRESH_WINDOW = "Thresholded Image";
static const std::string CANNY_WINDOW = "Canny Image";
static const std::string OBJ_WINDOW = "Objects Detected Image";

typedef cv::Point3_<cv::Point> Triangle;

class ImageConverter {
private:
  ros::Publisher control_pub_;
  ros::Subscriber image_sub_;

public:
  ImageConverter(ros::NodeHandle &n);
  ~ImageConverter() {}

private:
  void imageCallback(const opencv_msgs::ConeImageMap::ConstPtr &msg);

  void clamp(common_msgs::Control &control);
};
