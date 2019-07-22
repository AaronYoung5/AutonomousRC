// ROS include
#include "ros/ros.h"

// Messages
#include "common_msgs/Control.h"
#include "std_msgs/String.h"

// External packages
#include "serial/serial.h"

serial::Serial ser;

void controlCallback(const common_msgs::Control::ConstPtr &msg) {
  std::cout << "TEST" << std::endl;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "arduino_interface");
  ros::NodeHandle n;

  ros::Subscriber write_sub =
      n.subscribe("keyboard_control", 10, controlCallback);

  try {
    ser.setPort("/dev/ttyACM0");
    ser.setBaudrate(115200);
    serial::Timeout to = serial::Timeout::simpleTimeout(1000);
    ser.setTimeout(to);
    ser.open();
  } catch (serial::IOException &e) {
    ROS_ERROR_STREAM("Unable to open port ");
    return -1;
  }

  if (ser.isOpen()) {
    ROS_INFO_STREAM("Serial Port initialized");
  } else {
    return -1;
  }

  while (ros::ok()) {

    if (ser.available()) {
      ROS_INFO_STREAM("Reading from serial port");
      std_msgs::String result;
      result.data = ser.read(ser.available());
      // ROS_INFO_STREAM("Read: " << result.data);
      std::cout << "Data Received :: " << result.data.c_str() << std::endl;
    }

    ros::spinOnce();
  }
}
