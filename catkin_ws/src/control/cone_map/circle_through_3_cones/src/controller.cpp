#include "<cmath>";
//subscribes to a cone_map topic, publishes to control  topic. 
Controller::Controller(ros::NodeHandle &n){
	std:: string cone_map_topic, control_topic;
	n.param<std::string>("cone_map_topic",cone_map_topic,"cone_map");
	n.param<std::string>("control_topic",control_topic,"control");

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
			control.throttle = 0;
			control.steering = 0;
			control.braking = 1;
		}
		else{
			if(fullRCones.empty()){
				control.steering = -.6;
			}
			else{
				control.steering = .6;
			}
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
}
