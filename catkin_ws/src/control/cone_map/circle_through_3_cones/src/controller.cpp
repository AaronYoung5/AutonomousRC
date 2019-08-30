<<<<<<< HEAD
#include <cmath>
#include "circle_through_3_cones/controller.h"

//subscribes to a cone_map topic, publishes to control  topic. 
Controller::Controller(ros::NodeHandle &n) {
=======
#include "<cmath>";
//subscribes to a cone_map topic, publishes to control  topic. 
Controller::Controller(ros::NodeHandle &n){
>>>>>>> 1b51b11038f65a072f38f4ab930e8301277e0079
	std:: string cone_map_topic, control_topic;
	n.param<std::string>("cone_map_topic",cone_map_topic,"cone_map");
	n.param<std::string>("control_topic",control_topic,"control");

<<<<<<< HEAD
	pub_ = n.advertise<common_msgs::Control>(control_topic, 1);
	sub_ = n.subscribe (cone_map_topic, 1, &Controller::mapCallback, this);
}

//TODO: not sure this does the right thing, need it to take in mesages from cone map topic
void Controller::mapCallback(const perception_msgs::ConeDepthMap::ConstPtr &msg){
	common_msgs::Control control;
	int nRed,nGreen;
		nRed = msg->red_cones.size();
		nGreen = msg->green_cones.size();

	float gCones[nGreen][2];
	float rCones[nRed][2];
	for (int i=0;i<nGreen;i++){
		gCones[i][0] = msg->green_cones[i].pos.x;
		gCones[i][1] = msg->green_cones[i].pos.y;
	}
	for(int i = 0;i<nRed;i++){
		rCones[i][0] = msg->red_cones[i].pos.x;
		rCones[i][1] = msg->red_cones[i].pos.y;
	}
	bool runCircle;
	if(nRed>=1&&nGreen>=1){
		//finding 3 smallest r and g cones
		Vec2<> r1(rCones[0][0],rCones[0][1]);
		Vec2<> g1(gCones[0][0],gCones[0][1]);
		for(int i=1;i<nRed;i++){
			if(rCones[i][1]<r1.y()){
				r1 = Vec2<>(rCones[i][0], rCones[i][1]);
			}
		}
		for(int i=1;i<nGreen;i++){
			if(gCones[i][1]<g1.y()){
				g1 = Vec2<>(gCones[i][0], gCones[i][1]);
			}
		}
		Vec2<> p1 (0,0);
		Vec2<> p2((r1.x()+g1.x())/2, (r1.y()+g1.y())/2);
		Vec2<> p3(p2.x(), -p2.y());
		std::array<float, 3> path = calcCircle(p1,p2,p3);
		//TODO: radius might not be in cm, convert to cm.
		float theta = asin(.48/path[2]);
		if(path[0]>0){
			//steering positive
			control.steering = theta/0.32;
		}
		else {
			control.steering = -theta/0.32;
		}
		control.throttle = 0.11;
	}
	else {
		if(nGreen==0&&nRed==0){
=======
	pub_ = n.advertise<common_msgs::Control>(control_topic,1);
	sub_ = n.subscribe (cone_topic, 1, &Controller::imageCallback, this);
}
//TODO: not sure this does the right thing, need it to take in mesages from cone map topic
void Controller:: imageCallback(const perception_msgs::ConeImageMap::ConstPtr &msg){
	common_msgs::Control control;
	//TODO: add a system that puts all the green cones and red cones into a [n][2] array with each one having [x,y]. These should only include minimum number of cones (and only the closest ones). if there are 3 red and 5 green, only include the 3 closest green. But, also record the nMax (in the previous example this would be 5. Also store all r and g cones in fullRCones and fullGCones.
	int n = //TODO: smallest number of cones, in either red or green;
	int nMax = //TODO: largest number of cones, in either red or green.
	float [n][2] gCones = //TODO: fill;
	float [n][2] rCones = //TODO: fill;
	//TODO: make the fullRCones and fullGCones with correct sizes.
	bool runCircle;
	if(n>=3){
		//finding 3 smallest r and g cones
		Vec2<> r1 = (rCones[0][0],rCones[0][1]);
		Vec2<> r2 = (-1,-1);
		Vec2<> r3 = (-1,-1);
		Vec2<> g1 = (gCones[0][0],gCones[0][1]);
		Vec2<> g2 = (-1,-1);
		Vec2<> g3 = (-1,-1);
		for(int i=0;i<n;i++){
			
		}

	}
	else if(n==2){

	}
	else if(n==1){
		
	}
	else if(n==0){
		if(nMax==0){
>>>>>>> 1b51b11038f65a072f38f4ab930e8301277e0079
			control.throttle = 0;
			control.steering = 0;
			control.braking = 1;
		}
		else{
<<<<<<< HEAD
			if(msg->red_cones.size()==0){
=======
			if(fullRCones.empty()){
>>>>>>> 1b51b11038f65a072f38f4ab930e8301277e0079
				control.steering = -.6;
			}
			else{
				control.steering = .6;
			}
<<<<<<< HEAD
			control.throttle = .11;
		}
	}
	clamp(control);
	pub_.publish(control);
}

//takes in 3 Vec2 points, and returns a float[3] in the form {x,y,r} for the circle defined by those 3 points.
std::array<float, 3> Controller::calcCircle(Vec2<> p1,Vec2<> p2, Vec2<> p3){
	Vec2<> mid1((p1.x()+p2.x())/2,(p1.y()+p2.y())/2);
	Vec2<> mid2((p1.x()+p3.x())/2,(p1.y()+p3.y())/2);
	float m1 = -(p1.x()-p2.x())/(p1.y()-p2.y());
	float m2 = -(p1.x()-p3.x())/(p1.y()-p3.y());
	float x = (m2*mid2.x()-m1*mid1.x()+mid1.y()-mid2.y())/(m2-m1);
	float y = m1*(x-mid1.x())+mid1.y();
	float r = sqrt((mid1.x()-x)*(mid1.x()-x)+(mid1.y()-y)*(mid1.y()-1));
	return {x,y,r};
=======
			control.throttle = .12;
		}
	}
	//What does clamp do??
	clamp(control);
	pub_publish(control);
}

//takes in 3 Vec2 points, and returns a float[3] in the form {x,y,r} for the circle defined by those 3 points.
float [3] Controller::calcCircle(Vec2<> p1,Vec2<> p2, Vec2<> p3){
	Vec2<> mid1 = ((p1.x+p2.x)/2,(p1.y+p2.y)/2);
	Vec2<> mid2 = ((p1.x+p3.x)/2,(p1.y+p3.y)/2);
	float m1 = -(p1.x-p2.x)/(p1.y-p2.y);
	float m2 = -(p1.x-p3.x)/(p1.y-p3.y);
	float x = (m2*mid2.x-m1*mid1.x+mid1.y-mid2.y)/(m2-m1);
	float y = m1*(x-mid1.x)+mid1.y;
	float r = sqrt((mid1.x-x)*(mid1.x-x)+(mid1.y-y)*(mid1.y-1));
	float [3] fnl = {x,y,r};
	return fnl;
>>>>>>> 1b51b11038f65a072f38f4ab930e8301277e0079
}
