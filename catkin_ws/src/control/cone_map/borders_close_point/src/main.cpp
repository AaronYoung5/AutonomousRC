// ROS include
#include "ros/ros.h"
#include "circle_through_3_cones/controller.h"

int main(int argc, char **argv){
	ros::init(argc, argv, "circle_through_3_cones");
	ros::NodeHandle n("~");

	Controller controller(n);
	ros::spin();
}
