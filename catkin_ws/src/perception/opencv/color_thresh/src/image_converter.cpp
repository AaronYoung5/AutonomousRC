#include "color_thresh/image_converter.h"

ColorThresh::ColorThresh(ros::NodeHandle &n) { 
  
  n.param("/perception/image_topic/", image_topic_, "/perception/mono_image/");
  n.param("/perception/flip/", image_flip_, true);
  n.param("/perception/display/", image_display_, true);

  // Subscribe to input video feed and publish cone positions
  image_transport::ImageTransport it(n);

  sub_ = it.subscribe(image_topic_, 1,
                      &ImageConverter::imageCallback, this);

  pub_ = n.advertise<common_msgs::ConeImage2D>("perception/color_thresh/cone_image_2d", 1);
}

void ColorThresh::imageCallback(const sensor_msgs::Image::ConstPtr &msg) {
  // Get pointer to cv image
  cv_bridge::CvImagePtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGRA8);
  } catch (cv_bridge::Exception &e) {
    ROS_ERROR("cv_bridge exception: %s", e.what());
    return;
  }

  // Display original image
  if (image_flip_)
    cv::flip(cv_ptr->image, cv_ptr->image, -1);
  if (image_display_)
    cv::imshow(ORIGINAL_WINDOW, cv_ptr->image);

  cv::Mat image_hsv;

  cv::cvtColor(cv_ptr->image, image_hsv, cv::COLOR_BGR2HSV);

  cv::Mat1b green_mask, red_mask;

  // CHRONO SETTINGS

  // Detects GREEN :: L(50, 50, 50) -> H(175, 175, 175)
  // Also Detects GREEN :: L(50, 50, 50) -> H(75, 255, 255)
  // Green has H value around 60
  // cv::inRange(image_hsv, cv::Scalar(50, 50, 0), cv::Scalar(75, 255, 255),
  // green_mask);

  // Detects RED :: L(0, 50, 0) -> H(2, 200, 255)
  // Red has H value around 0
  // cv::inRange(image_hsv, cv::Scalar(0, 50, 0), cv::Scalar(2, 200, 255),
  // red_mask);

  // REAL LIFE SETTINGS SETTINGS

  // Detects GREEN :: L(50, 50, 50) -> H(175, 175, 175)
  // Also Detects GREEN :: L(50, 50, 50) -> H(75, 255, 255)
  // Green has H value around 60
  cv::inRange(image_hsv, cv::Scalar(70, 200, 50), cv::Scalar(90, 255, 255),
              green_mask);
  // rgb(25, 213, 149)
  // Detects RED :: L(0, 50, 0) -> H(2, 200, 255)
  // Red has H value around 0
  cv::inRange(image_hsv, cv::Scalar(0, 200, 50), cv::Scalar(7, 255, 255),
              red_mask);
  // cv::adaptiveThreshold(cv::Mat1b(cv_ptr->image), red_mask, 255,
  // cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 5, 0);

  cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(10, 10),
                                              cv::Point(-1, -1));
  cv::erode(green_mask, green_mask, element);
  cv::erode(red_mask, red_mask, element);
  element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(20, 20),
                                              cv::Point(-1, -1));
  cv::dilate(green_mask, green_mask, element);
  cv::dilate(red_mask, red_mask, element);

  cv::Mat1b mask = green_mask | red_mask;

  if (should_imshow)
    cv::imshow(THRESH_WINDOW, mask);

  cv::Mat1b green_canny_output, red_canny_output;

  // Find green cones
  cv::Canny(green_mask, green_canny_output, 1, 1);
  std::vector<std::vector<cv::Point>> green_contours;
  findContours(green_canny_output, green_contours, cv::RETR_TREE,
               cv::CHAIN_APPROX_SIMPLE);

  std::vector<std::vector<cv::Point>> green_contours_poly(
      green_contours.size());
  std::vector<cv::Rect> green_cones;
  for (size_t i = 0; i < green_contours.size(); i++) {
    cv::approxPolyDP(green_contours[i], green_contours_poly[i], 3, true);
    cv::Rect temp = cv::boundingRect(green_contours_poly[i]);
    if (temp.area() > 500) {
      green_cones.push_back(temp);
    }
  }

  // Find red cones
  cv::Canny(red_mask, red_canny_output, 1, 1);
  std::vector<std::vector<cv::Point>> red_contours;
  findContours(red_canny_output, red_contours, cv::RETR_TREE,
               cv::CHAIN_APPROX_SIMPLE);

  std::vector<std::vector<cv::Point>> red_contours_poly(red_contours.size());
  std::vector<cv::Rect> red_cones;
  for (size_t i = 0; i < red_contours.size(); i++) {
    cv::approxPolyDP(red_contours[i], red_contours_poly[i], 3, true);
    cv::Rect temp = cv::boundingRect(red_contours_poly[i]);
    red_cones.push_back(temp);
  }

  cv::Mat1b canny_output = green_canny_output | red_canny_output;

  if (should_imshow)
    cv::imshow(CANNY_WINDOW, canny_output);

  cv::Scalar yellow = cv::Scalar(0, 255, 255);
  cv::Scalar blue = cv::Scalar(255, 0, 0);
  cv::Scalar green = cv::Scalar(0, 255, 0);

  for (size_t i = 0; i < green_cones.size(); i++) {
      cv::rectangle(cv_ptr->image, green_cones[i].tl(), green_cones[i].br(),
                    green, 2);
  }

  for (size_t i = 0; i < red_cones.size(); i++) {
      cv::rectangle(cv_ptr->image, red_cones[i].tl(), red_cones[i].br(),
                    green, 2);
  }

  if (should_imshow)
    cv::imshow(OBJ_WINDOW, cv_ptr->image);

  cv::waitKey(3);

  // Output 2d cone positions
  common_msgs::ConeImage2D cone2d;

  int i, j;
  for (i = 0, j = 0; i < green_cones.size(), j < red_cones.size(); i++, j++) {
    common_msgs::Cone
  }
}

float ColorThresh::areaTriangle(Triangle tri) {
  return abs((tri.x.x * (tri.y.y - tri.z.y) + tri.y.x * (tri.z.y - tri.x.y) +
              tri.z.x * (tri.x.y - tri.y.y)) /
             2.0f);
}

bool ColorThresh::isInside(cv::Point pt, Triangle tri) {
  float A0 = areaTriangle(tri);

  float A1 = areaTriangle(Triangle(pt, tri.y, tri.z));

  float A2 = areaTriangle(Triangle(pt, tri.x, tri.z));

  float A3 = areaTriangle(Triangle(pt, tri.x, tri.y));

  return (A0 == A1 + A2 + A3);
}
