#include "ros/ros.h"
#include "common_msgs/Control.h"
int main (int argc, char** argv){
        ros::init(argc,argv,"straight_line_control");

        ros::NodeHandle n;
        ros::Duration(5).sleep();
        
        ros::Publisher chatter_pub = n.advertise<common_msgs::Control>("control",1);

        ros::Rate loop_rate(10);

        int count = 0;
        while(ros::ok()){
                
                common_msgs::Control msg;
                msg.steering = 1.00;
                if(count<50)
                        msg.throttle = 0.12;
                else{
                        msg.throttle = 0;
                        chatter_pub.publish(msg);
                        ros::shutdown();
                }
                
                chatter_pub.publish(msg);


                loop_rate.sleep();
                ++count;

        }
        return 0;
}
