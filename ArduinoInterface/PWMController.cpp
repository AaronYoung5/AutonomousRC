#include "PWMController.h"

PWMController::PWMController(PWMController::CONTROLLER_TYPE type, int pin)
    : Thread(), type(type), TRIM_PW(0), lcd(rs, en, d4, d5, d6, d7) {
  servo.attach(pin);

  setInterval(100); // Sets interval to 100ms

  switch (type) {
  case PWMController::STEERING_NORMAL:
    MAX_PW = STEERING_NORMAL_PW_LEFT;
    MIN_PW = STEERING_NORMAL_PW_RIGHT;
    NEUTRAL_PW = STEERING_NORMAL_PW_NEUTRAL + TRIM_PW;
    MAX_PW_DELTA = STEERING_MAX_PW_ACCEL;
    break;
  case PWMController::STEERING_REVERSE:
    MIN_PW = STEERING_REVERSE_PW_LEFT;
    MAX_PW = STEERING_REVERSE_PW_RIGHT;
    NEUTRAL_PW = STEERING_REVERSE_PW_NEUTRAL + TRIM_PW;
    MAX_PW_DELTA = STEERING_MAX_PW_ACCEL;
    break;
  case PWMController::MOTOR_NORMAL:
    MAX_PW = MOTOR_NORMAL_PW_THROTTLE;
    MIN_PW = MOTOR_NORMAL_PW_BRAKE;
    NEUTRAL_PW = MOTOR_NORMAL_PW_NEUTRAL - TRIM_PW;
    MAX_PW_DELTA = MOTOR_MAX_PW_ACCEL;
    break;
  case PWMController::MOTOR_REVERSE:
    MIN_PW = MOTOR_REVERSE_PW_THROTTLE;
    MAX_PW = MOTOR_REVERSE_PW_BRAKE;
    NEUTRAL_PW = MOTOR_REVERSE_PW_NEUTRAL - TRIM_PW;
    MAX_PW_DELTA = MOTOR_MAX_PW_ACCEL;
    break;
  }

  pulsewidth = NEUTRAL_PW;
  lcd.begin(16, 2);
}

PWMController::~PWMController() {}

void PWMController::run() {
  pulsewidth = pulsewidth >= MAX_PW
                   ? MAX_PW
                   : pulsewidth <= MIN_PW ? MIN_PW : pulsewidth;
  this->servo.writeMicroseconds(pulsewidth * 1000);
}

float PWMController::map(float x, float in_min, float in_max, float out_min,
                         float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void PWMController::SetPercent(float percent) {
  switch (type) {
  case PWMController::MOTOR_NORMAL:
  case PWMController::MOTOR_REVERSE:
    pulsewidth = map(percent, -1, 1, MIN_PW, MAX_PW);
    lcd.setCursor(0, 0);
    lcd.print("M PW: " + String((float)pulsewidth));
    break;
  case PWMController::STEERING_NORMAL:
  case PWMController::STEERING_REVERSE:
    pulsewidth = map(percent, -1, 1, MIN_PW, MAX_PW);
    lcd.setCursor(0, 1);
    lcd.print("S PW: " + String((float)pulsewidth));

    break;
  }
}

void PWMController::SetPosition(PWMController::CONTROLLER_POSITION position) {
  switch (position) {
  case PWMController::NEUTRAL:
    pulsewidth = NEUTRAL_PW;
    break;
  case PWMController::MAX:
    pulsewidth = MAX_PW;
    break;
  case PWMController::MIN:
    pulsewidth = MIN_PW;
    break;
  }
}

void PWMController::Neutral() { pulsewidth = NEUTRAL_PW; }

void PWMController::Maximum() { pulsewidth = MAX_PW; }

void PWMController::Minimum() { pulsewidth = MIN_PW; }