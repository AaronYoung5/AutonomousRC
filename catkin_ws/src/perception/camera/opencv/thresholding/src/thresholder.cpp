#include "thresholding/thresholder.h"

Thresholder::Thresholder(ros::NodeHandle &n) {
  std::string image_topic, cone_topic;
  n.param<std::string>("image_topic", image_topic, "image_data_raw");
  n.param<std::string>("cone_topic", cone_topic, "cone_image_map");
  n.param("display", image_display_, false);
  n.param("simulating", image_simulated_, true);

  // Subscribe to input video feed and publish cone positions
  image_transport::ImageTransport it(n);
  sub_ = it.subscribe(image_topic, 1, &Thresholder::imageCallback, this);

  pub_ = n.advertise<perception_msgs::ConeImageMap>(cone_topic, 1);
}

void Thresholder::imageCallback(const sensor_msgs::Image::ConstPtr &msg) {
  // Get pointer to cv image
  cv_bridge::CvImagePtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGRA8);
  } catch (cv_bridge::Exception &e) {
    ROS_ERROR("cv_bridge exception: %s", e.what());
    return;
  }

  // If simulated, flip image (only about the x axis)
  if (image_simulated_)
    cv::flip(cv_ptr->image, cv_ptr->image, -1);

  // If desired, display original image
  if (image_display_)
    cv::imshow(ORIGINAL_WINDOW, cv_ptr->image);

  std::vector<cv::Rect> green_cones, red_cones;
  if (image_simulated_) {
    green_cones =
        Threshold(cv_ptr, cv::Scalar(50, 50, 0), cv::Scalar(75, 255, 255), false);
    red_cones =
        Threshold(cv_ptr, cv::Scalar(0, 50, 0), cv::Scalar(2, 200, 255), false);
  } else {
    // Works inside sbel room
    // green_cones =
    // Threshold(cv_ptr, cv::Scalar(70, 200, 50), cv::Scalar(90, 255, 255) );
    // red_cones =
    // Threshold(cv_ptr, cv::Scalar(0, 200, 50), cv::Scalar(7, 255, 255) );

    // Works outside sbel room
    green_cones = Threshold(cv_ptr, cv::Scalar(70, 75, 50),
                            cv::Scalar(90, 255, 255), false);
    red_cones = Threshold(cv_ptr, cv::Scalar(80, 75, 50),
                          cv::Scalar(100, 255, 255), true);
  }

  // If desired, draw and display bounded rectangles on image
  if (image_display_) {
    auto yellow = cv::Scalar(0, 255, 255);
    // Draw green detected cones
    drawDetectedCones(cv_ptr, green_cones, yellow);
    // Draw red detected cones
    drawDetectedCones(cv_ptr, red_cones, yellow);
    cv::imshow(OBJ_WINDOW, cv_ptr->image);
  }

  perception_msgs::ConeImageMap cone_msg;
  cone_msg.header = msg->header;
  cone_msg.green_cones =
      CreateConeMsgArray(green_cones, perception_msgs::Cone::GREEN);
  cone_msg.red_cones =
      CreateConeMsgArray(red_cones, perception_msgs::Cone::RED);
  cone_msg.height = msg->height;
  cone_msg.width = msg->width;

  pub_.publish(cone_msg);

  cv::waitKey(1);
}

std::vector<cv::Rect> Thresholder::Threshold(cv_bridge::CvImagePtr &cv_ptr,
                                             cv::Scalar lower_hsv,
                                             cv::Scalar upper_hsv,
                                             bool invert) {
  // Convert image to hsv format
  cv::Mat image_hsv;
  if (invert) {
    cv::bitwise_not(cv_ptr->image, cv_ptr->image);
  }
  cv::cvtColor(cv_ptr->image, image_hsv, cv::COLOR_BGR2HSV);

  // Threshold image using provided range
  cv::Mat1b mask;
  cv::inRange(image_hsv, lower_hsv, upper_hsv, mask);
  // cv::imshow(THRESH_WINDOW, mask);

  // Erode and dialate thresholded image to magnify results
  cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5),
                                              cv::Point(-1, -1));
  cv::erode(mask, mask, element);
  cv::dilate(mask, mask, element);
  cv::erode(mask, mask, element);

  element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(20, 20),
                                      cv::Point(-1, -1));
  cv::dilate(mask, mask, element);

  // Detect edges
  cv::Mat1b canny_output;
  cv::Canny(mask, canny_output, 1, 1);
  std::vector<std::vector<cv::Point>> contours;
  findContours(canny_output, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

  // Create bounded rectangles around detected cones
  std::vector<std::vector<cv::Point>> contours_poly(contours.size());
  std::vector<cv::Rect> cones;
  for (size_t i = 0; i < contours.size(); i++) {
    cv::approxPolyDP(contours[i], contours_poly[i], 3, true);
    cv::Rect temp = cv::boundingRect(contours_poly[i]);
    if (temp.area() > 100) {
      if (temp.tl().y > cv_ptr->image.size().height / 4.0f && temp.area() > 50)
        cones.push_back(temp);
    }
  }

  if (invert) {
    cv::bitwise_not(cv_ptr->image, cv_ptr->image);
  }

  return cones;
}

void Thresholder::drawDetectedCones(cv_bridge::CvImagePtr &cv_ptr,
                                    std::vector<cv::Rect> cones,
                                    cv::Scalar color) {
  for (cv::Rect cone : cones) {
    cv::rectangle(cv_ptr->image, cone.tl(), cone.br(), color, 2);
  }
}

std::vector<perception_msgs::Cone>
Thresholder::CreateConeMsgArray(std::vector<cv::Rect> &rects, uint8_t color) {
  // // Output 2d cone positions
  std::vector<perception_msgs::Cone> cones;

  for (cv::Rect rect : rects) {
    perception_msgs::Cone cone;

    cone.color = color;

    cone.tl.x = rect.tl().x;
    cone.tl.y = rect.tl().y;

    cone.br.x = rect.br().x;
    cone.br.y = rect.br().y;

    cones.push_back(cone);
  }
  return cones;
}

cv::Scalar Thresholder::ScalarHSV2BGR(cv::Scalar hsv_scalar) {
  cv::Mat rgb;
  cv::Mat hsv(1, 1, CV_8UC3, hsv_scalar);
  cvtColor(hsv, rgb, cv::COLOR_HSV2BGR);
  return cv::Scalar(rgb.data[0], rgb.data[1], rgb.data[2]);
}
