#include "ros/ros.h"

void imageCallback(const namespace::MSG::ConstPtr &msg) {
	msg->
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "image_detection");
	ros::NodeHandle n;

	ros::Subscriber camera_subscriber = n.subscribe("camera_data", 10, imageCallback);

	ros::spin();
}
