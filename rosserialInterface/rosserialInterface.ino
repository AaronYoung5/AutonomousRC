#include <ros.h>

#include <common_msgs/Control.h>

#include "Common.h"
#include "LCD.h"
#include "PWMController.h"

using namespace Common;

// --- Steering --- //
const int STEERING_PIN = 9; // Pin on arduino

// --- Motor --- //
const int MOTOR_PIN = 6; // Pin on arduino

PWMController motorController(PWMController::MOTOR_REVERSE, MOTOR_PIN);
PWMController steeringController(PWMController::STEERING_REVERSE, STEERING_PIN);

ros::NodeHandle n;

void callback(const common_msgs::Control &msg) {
  motorController.SetPercent(msg.throttle);
  steeringController.SetPercent(msg.steering);
}

ros::Subscriber<common_msgs::Control> sub("control", &callback);

void setup() {
  n.initNode();
  n.subscribe(sub);

  motorController.SetPosition(PWMController::NEUTRAL);
  steeringController.SetPosition(PWMController::NEUTRAL);
}

void loop() {
  // if (motorController.shouldRun())
  //   motorController.run();
  //
  // if (steeringController.shouldRun())
  //   steeringController.run();

  n.spinOnce();
}
