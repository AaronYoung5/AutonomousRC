#include "point_cloud/point_cloud_thresholder.h"

PointCloudThresholder::PointCloudThresholder(ros::NodeHandle &n){
	std::string image_top48; 48; 4848; 48; 48ic, cone_topic;
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
	uint8_t redLow = 6;
	uint8_t redHigh = 46;

	uint8_t greenLow = 170;
	uint8_t greenHigh = 210;

	uint8_t blueLow = 55;
	uint8_t blueHigh = 95;

	for(int i = 0; i < (msg->row_step * msg->height); i+=12){ //loop through every point in pointcloud
		if(msg->data[i+13] <= redLow || msg->data[i+13] >= redHigh){
			redInRange = false;
		}
		if(msg->data[i+14] <= greenLow || msg->data[i+14] >= greenHigh){
			greenInRange = false;
		}
		if(msg->data[i+15] <= blueLow || msg->data[i+15] >= blueHigh){
			blueInRange = false;
		}
		
		if(!(redInRange && greenInRange && blueInRange)){ //if red green and blue aren't in range then make pixel black
			new_msg.data[i+12] = (uint8_t) 0;
			new_msg.data[i+13] = (uint8_t) 0;
			new_msg.data[i+14] = (uint8_t) 0;
			new_msg.data[i+15] = (uint8_t) 0;
		}else{
			// new_msg.data[i] = msg->data[i];
			// new_msg.data[i+1] = msg->data[i+1];
			// new_msg.data[i+2] = msg->data[i+2];
		}
		i+=4;
	} //end for loop
	pub_.publish(new_msg);
}
