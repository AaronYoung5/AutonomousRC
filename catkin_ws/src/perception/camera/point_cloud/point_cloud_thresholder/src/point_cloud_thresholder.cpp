#include "point_cloud/point_cloud_thresholder.h"

PointCloudThresholder::PointCloudThresholder(ros::NodeHandle &n){
	std::string image_topic, cone_topic;
	n.param<std::string>("image_topic", image_topic, "image_data_raw");
	n.param<std::string>("cone_topic", cone_topic, "cone_image_map");
	n.param("display", image_display_, false);
	n.param("simulating", image_simulated_, true);

	//subscribe to point cloud feed
	sub_ = n.subscribe(image_topic, 1, &PointCloudThresholder::imageCallback, this);

	pub_ = n.advertise<sensor_msgs::PointCloud2>("new_point_cloud", 1);
}

void PointCloudThresholder::imageCallback(const sensor_msgs::PointCloud2::ConstPtr &msg){
	sensor_msgs::PointCloud2 new_msg;
	new_msg = *msg;

	bool redInRange = false;
	bool greenInRange = false;
	bool blueInRange = false;

	//looking for green cones right now
	uint8_t redLow = 0;
	uint8_t redHigh = 255;

	uint8_t greenLow = 0;
	uint8_t greenHigh = 255;

	uint8_t blueLow = 0;
	uint8_t blueHigh = 255;

	for(int i = 12; i < (msg->row_step * msg->height); i+=16){ //loop through every point in pointcloud
		if (i < (msg->row_step * msg->height)) {
			ROS_INFO_STREAM("RGB :: [" << (int)msg->data[i] << ", " << (int)msg->data[i+1] << ", " << (int)msg->data[i+2] << "]");
		}
		if(msg->data[i] < redLow || msg->data[i] > redHigh){
			redInRange = false;
		}
		if(msg->data[i+1] < greenLow || msg->data[i+1] > greenHigh){
			greenInRange = false;
		}
		if(msg->data[i+2] < blueLow || msg->data[i+2] > blueHigh){
			blueInRange = false;
		}
		
		if(!(redInRange && greenInRange && blueInRange)){ //if red green and blue aren't in range then make pixel black
			new_msg.data[i] = (uint8_t) 0;
			new_msg.data[i+1] = (uint8_t) 0;
			new_msg.data[i+2] = (uint8_t) 0;
		}
	} //end for loop
	pub_.publish(new_msg);
}
