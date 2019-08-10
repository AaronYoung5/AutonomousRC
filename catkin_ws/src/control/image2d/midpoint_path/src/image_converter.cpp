
#include "thresholding/image_converter.h"
#include "geometry_msgs/Point.h"

using namespace geometry_msgs;

ImageConverter::ImageConverter(ros::NodeHandle &n)
    : control_pub_(n.advertise<common_msgs::Control>("control", 1)),
      image_sub_(n.subscribe("/perception/color_thresh/cone_image_2d", 1,
                             &ImageConverter::imageCallback, this)) {}

void ImageConverter::imageCallback(
    const opencv_msgs::ConeImageMap::ConstPtr &msg) {
  common_msgs::Control control;

  if (msg->green_cones.size() == 0 && msg->red_cones.size() == 0) {
    control.throttle = 0;
    control.steering = 0;
  } else {
    Point avgG;
    avgG.x = (msg->green_cones[0].tl.x + msg->green_cones[0].br.x) / 2;
    avgG.y = (msg->green_cones[0].tl.y + msg->green_cones[0].br.y) / 2;
    for (size_t i = 1; i < msg->green_cones.size(); i++) {
      Point holdG((msg->green_cones[i].tl + msg->green_cones[i].br) / 2);
      if (holdG.y > avgG.y) {
        avgG = holdG;
      }
    }
      Point avgR;
      avgR.x = (msg->red_cones[0].tl.x + msg->red_cones[0].br.x) / 2;
      avgR.y = (msg->red_cones[0].tl.y + msg->red_cones[0].br.y) / 2;
    for (size_t i = 1; i < red_cones.size(); i++) {
      Point holdG((msg->red_cones[i].tl + msg->red_cones[i].br) / 2);
      if (holdG.y > avgR.y) {
        avgR = holdG;
      }
    }
    Point destination((avgR + avgG) / 2);
    Point center(msg->width / 2, msg->height / 2);
    control.steering = (destination.x - center.x) / center.x;
    control.throttle = .12;
  }
  // Output modified video stream
  clamp(control);
  control_pub_.publish(control);
}

void ImageConverter::clamp(common_msgs::Control &control) {
  control.throttle =
      control.throttle > 1 ? 1 : control.throttle < 0 ? 0 : control.throttle;
  control.steering =
      control.steering > 1 ? 1 : control.steering < -1 ? -1 : control.steering;
}
