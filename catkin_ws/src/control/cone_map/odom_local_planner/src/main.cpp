// ROS include
#include "ros/ros.h"
#include "mpc_control/controller.h"

int main(int argc, char **argv){
	ros::init(argc, argv, "mpc_control");
	ros::NodeHandle n("~");

	Controller controller(n);
	ros::spin();
}
