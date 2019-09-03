// ROS include
#include "ros/ros.h"
#include "centerline_follower/controller.h"

int main(int argc, char **argv){
	ros::init(argc, argv, "centerline_follower");
	ros::NodeHandle n("~");

	Controller controller(n);
	ros::spin();
}
