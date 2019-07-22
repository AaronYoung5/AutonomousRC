#pragma once

#include <Servo.h>

// Average Duty Cycle by command, <Motor to control>_<Reverse or
// Normal>_<Neutral, forward, or back>
const float STEERING_NORMAL_DUTY_NEUTRAL = 9.285;
const float STEERING_NORMAL_DUTY_RIGHT = 6.63;
const float STEERING_NORMAL_DUTY_LEFT = 11.9;
const float STEERING_REVERSE_DUTY_NEUTRAL = 8.8;
const float STEERING_REVERSE_DUTY_RIGHT = 11.4;
const float STEERING_REVERSE_DUTY_LEFT = 6.145;
const float STEERING_MAX_DUTY_ACCEL = 0.50;

const float STEERING_NORMAL_PW_NEUTRAL = 1.541;
const float STEERING_NORMAL_PW_RIGHT = 1.101;
const float STEERING_NORMAL_PW_LEFT = 1.981;
const float STEERING_REVERSE_PW_NEUTRAL = 1.4605;
const float STEERING_REVERSE_PW_RIGHT = 1.9005;
const float STEERING_REVERSE_PW_LEFT = 1.021;
const float STEERING_MAX_PW_ACCEL = 0.50;

const float MOTOR_NORMAL_DUTY_NEUTRAL = 9.04;
const float MOTOR_NORMAL_DUTY_RIGHT = 6.14;
const float MOTOR_NORMAL_DUTY_LEFT = 12.0;
const float MOTOR_REVERSE_DUTY_NEUTRAL = 9.035;
const float MOTOR_REVERSE_DUTY_RIGHT = 11.9;
const float MOTOR_REVERSE_DUTY_LEFT = 6.265;
const float MOTOR_MAX_DUTY_ACCEL = 0.50;

const float MOTOR_NORMAL_PW_NEUTRAL = 1.5;
const float MOTOR_NORMAL_PW_RIGHT = 1.02;
const float MOTOR_NORMAL_PW_LEFT = 2;
const float MOTOR_REVERSE_PW_NEUTRAL = 1.5;
const float MOTOR_REVERSE_PW_RIGHT = 1.98;
const float MOTOR_REVERSE_PW_LEFT = 1.0205;
const float MOTOR_MAX_PW_ACCEL = 0.50;

class PWMController {
  public:
    enum CONTROLLER_TYPE {
      STEERING_NORMAL,
      STEERING_REVERSE,
      MOTOR_NORMAL,
      MOTOR_REVERSE
    };

    enum CONTROLLER_POSITION {
      NEUTRAL,
      MAX,
      MIN
    };

  private:
    double MIN_DUTY_CYCLE;
    double MAX_DUTY_CYCLE;
    double NEUTRAL_DUTY_CYCLE;
    double MAX_DUTY_DELTA;
    double TRIM_DUTY;

    double MIN_PW;
    double MAX_PW;
    double NEUTRAL_PW;
    double MAX_PW_DELTA;
    double TRIM_PW;

    Servo servo;

  public:
    PWMController(CONTROLLER_TYPE controller_type, int pin);
    ~PWMController();

    void SetPosition(PWMController::CONTROLLER_POSITION position);
    void Neutral();
    void Maximum();
    void Minimum();

  private:
    void attach(int pin);
    void writeMicroseconds(int value);
    void writeDutyCycle(int value);
    int readMicroseconds();
    int readDutyCycle();
    bool attached();
};
