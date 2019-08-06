// ROS include
#include "ros/ros.h"

// Messages
#include "common_msgs/Control.h"
#include "std_msgs/String.h"

// External packages
#include "serial/serial.h"

serial::Serial ser;

enum ControlType {
  STEERING,
  THROTTLE,
};

struct ControlMessage {
  float throttle;
  float steering;
  uint8_t padding = 0;
} message;

void controlCallback(const common_msgs::Control::ConstPtr &msg) {
  message = ControlMessage{msg->throttle, msg->steering};
  int size = sizeof(message);
  uint8_t buffer[size + 4];
  memcpy(buffer + 4, &message, size);
  buffer[0] = size;
  ser.flush();
  ser.write(buffer, size);
  std::cout << "Motor Sent :: "
            << (*(struct ControlMessage *)(buffer + 4)).throttle << std::endl;
  std::cout << "Steering Sent :: "
            << (*(struct ControlMessage *)(buffer + 4)).steering << std::endl;

  // while (!ser.available()) {
  // }
  // std::cout << "Data Received :: ";
  // while (ser.available()) {
    std::string data = ser.read(sizeof(uint8_t));
    // std::cout << data;
  // }
  // std::cout << std::endl;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "arduino_interface");
  ros::NodeHandle n;

  ros::Subscriber write_sub = n.subscribe("control", 1, controlCallback);

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
      std::cout << "Data Received :: ";
      while (ser.available()) {
        std::string data = ser.read();
        std::cout << data;
      }
      std::cout << std::endl;
    }

    ros::spinOnce();
  }

}
