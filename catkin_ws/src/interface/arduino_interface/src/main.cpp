// ROS include
#include "ros/ros.h"

// Messages
#include "common_msgs/Control.h"
#include "std_msgs/String.h"

// External packages
#include "serial/serial.h"

serial::Serial ser;

enum ControlType { THROTTLE, BRAKING, STEERING };

struct ControlMessage {
  float throttle;
  float braking;
  float steering;
} message;

void controlCallback(const common_msgs::Control::ConstPtr &msg) {
  // std::cout << "Sending Control Message" << std::endl;
  message = ControlMessage{msg->throttle, msg->braking, msg->steering};
  int size = sizeof(message);
  uint8_t *buffer = (uint8_t *)malloc(size + 4);
  memcpy(buffer + 4, &message, size);
  buffer[0] = size;
  ser.flush();
  ser.write(buffer, sizeof(message) + 4);
  std::cout << "Data Sent :: "
            << (*(struct ControlMessage *)(buffer + 4)).throttle << std::endl;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "arduino_interface");
  ros::NodeHandle n;

  ros::Subscriber write_sub = n.subscribe("control", 10, controlCallback);

  try {
    ser.setPort("/dev/ttyACM0");
    ser.setBaudrate(115200);
    serial::Timeout to = serial::Timeout::simpleTimeout(1000);
    ser.setTimeout(to);
    ser.open();
  } catch (serial::IOException &e) {
    std::cout << "Serial Port Initialization Unsuccessful" << std::endl;
    ser.close();
    ros::shutdown();
    return -1;
  }

  if (ser.isOpen()) {
    std::cout << "Serial Port Initializated" << std::endl;
  } else {
    ser.close();
    ros::shutdown();
    return -1;
  }

  while (ros::ok()) {
    if (ser.available()) {
      std_msgs::String result;
      result.data = ser.read(ser.available());
      std::cout << "Data Received :: " << result.data.c_str() << std::endl;
    }

    ros::spinOnce();
  }
}
