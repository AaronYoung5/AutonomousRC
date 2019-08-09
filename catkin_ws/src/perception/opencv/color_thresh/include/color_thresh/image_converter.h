#include "ros/ros.h"

#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <sensor_msgs/image_encodings.h>

#include "common_msgs/ConeImage2D.h"

static const std::string ORIGINAL_WINDOW = "Original Image";
static const std::string THRESH_WINDOW = "Thresholded Image";
static const std::string CANNY_WINDOW = "Canny Image";
static const std::string OBJ_WINDOW = "Objects Detected Image";

typedef cv::Point3_<cv::Point> Triangle;

class ColorThresh {
private:
  image_transport::Subscriber sub_;

  ros::Publisher pub_;

  std::string image_topic_;
  bool image_flip_, image_display_;

public:
  (ros::NodeHandle &n);
  ~ImageConverter() {
    try {
      if (image_display_) {
      cv::destroyWindow(ORIGINAL_WINDOW);
      cv::destroyWindow(THRESH_WINDOW);
      cv::destroyWindow(CANNY_WINDOW);
      cv::destroyWindow(OBJ_WINDOW);
      }
    }
    catch (cv::Exception &e) {
      std::cout << "Unsuccessfully closed opencv window that was never opened" << std::endl;
    }
  }

private:
  void imageCallback(const sensor_msgs::Image::ConstPtr &msg);

  float areaTriangle(Triangle tri);

  bool isInside(cv::Point pt, Triangle point);
};
