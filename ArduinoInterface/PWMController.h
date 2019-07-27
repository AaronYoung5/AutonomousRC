#pragma once

#include <Servo.h>
#include <Thread.h>

#include <LiquidCrystal.h>

// Average Duty Cycle by command, <Motor to control>_<Reverse or
// Normal>_<Neutral, forward, or back>

const float STEERING_NORMAL_PW_NEUTRAL = 1.541;
const float STEERING_NORMAL_PW_RIGHT = 1.101;
const float STEERING_NORMAL_PW_LEFT = 1.981;
const float STEERING_REVERSE_PW_NEUTRAL = 1.4605;
const float STEERING_REVERSE_PW_RIGHT = 1.9005;
const float STEERING_REVERSE_PW_LEFT = 1.021;
const float STEERING_MAX_PW_ACCEL = 0.50;

const float MOTOR_NORMAL_PW_NEUTRAL = 1.5;
const float MOTOR_NORMAL_PW_THROTTLE = 1.98;
const float MOTOR_NORMAL_PW_BRAKE = 1.0205;
const float MOTOR_REVERSE_PW_NEUTRAL = 1.5;
const float MOTOR_REVERSE_PW_THROTTLE = 1.0205;
const float MOTOR_REVERSE_PW_BRAKE = 1.98;
const float MOTOR_MAX_PW_ACCEL = 0.50;

class PWMController : public Thread {
public:
  enum CONTROLLER_TYPE {
    STEERING_NORMAL,
    STEERING_REVERSE,
    MOTOR_NORMAL,
    MOTOR_REVERSE
  };

  enum CONTROLLER_POSITION { NEUTRAL, MAX, MIN };

private:
  float MIN_PW;
  float MAX_PW;
  float NEUTRAL_PW;
  float MAX_PW_DELTA;
  float TRIM_PW;

  float pulsewidth;

  Servo servo;
  const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd;

  PWMController::CONTROLLER_TYPE type;

public:
  PWMController(CONTROLLER_TYPE controller_type, int pin);
  ~PWMController();

  void SetPosition(PWMController::CONTROLLER_POSITION position);
  void SetPercent(float percent);
  void Neutral();
  void Maximum();
  void Minimum();
  void run();

private:
  void attach(int pin);
  void writeMicroseconds(int value);
  bool attached();
  float map(float x, float in_min, float in_max, float out_min, float out_max);
};
