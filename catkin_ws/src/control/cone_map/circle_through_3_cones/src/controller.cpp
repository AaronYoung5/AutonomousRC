#include "<cmath>";
//subscribes to a cone_map topic, publishes to control  topic. 
Controller::Controller(ros::NodeHandle &n){
	std:: string cone_map_topic, control_topic;
	n.param<std::string>("cone_map_topic",cone_map_topic,"cone_map");
	n.param<std::string>("control_topic",control_topic,"control");

	pub_ = n.advertise<common_msgs::Control>(control_topic,1);
	sub_ = n.subscribe (cone_topic, 1, &Controller::imageCallback, this);
}
//not sure this does the right thing
void Controller:: imageCallback(const perception_msgs::ConeImageMap::ConstPtr &msg){
	
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
}
