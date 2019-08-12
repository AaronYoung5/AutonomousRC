#pragma once

#include <Servo.h>

// Update rate for the PWM
const uint8_t UPDATE_RATE = 50; // FPS = 50

// Time step for internal dynamics
// const uint8_t STEP_SIZE = 1e-3; // ms

// Average PW for steering in normal and reverse settings for each position
const int STEERING_NORMAL_PW_NEUTRAL = 1541;
const int STEERING_NORMAL_PW_RIGHT = 1101;
const int STEERING_NORMAL_PW_LEFT = 1981;
const int STEERING_REVERSE_PW_NEUTRAL = 1460;
const int STEERING_REVERSE_PW_RIGHT = 1900;
const int STEERING_REVERSE_PW_LEFT = 1021;

// Average PW for the motor in normal and reverse settings for each position
const int MOTOR_NORMAL_PW_NEUTRAL = 1500;
const int MOTOR_NORMAL_PW_THROTTLE = 1980;
const int MOTOR_NORMAL_PW_BRAKE = 1020;
const int MOTOR_REVERSE_PW_NEUTRAL = 1500;
const int MOTOR_REVERSE_PW_THROTTLE = 1020;
const int MOTOR_REVERSE_PW_BRAKE = 1980;

// Response times for the steering and throttle inputs
// const uint8_t STEERING_TIME = 1; // time to go from 0 to +1 (or from 0 to -1)
// const uint8_t THROTTLE_TIME = 1; // time to go from 0 to +1

class PWMController : public Servo {
public:
  enum CONTROLLER_TYPE : uint8_t {
    STEERING_NORMAL,
    STEERING_REVERSE,
    MOTOR_NORMAL,
    MOTOR_REVERSE
  };

private:
  int MIN_PW;
  int MAX_PW;
  int NEUTRAL_PW;
  int TRIM_PW;

  const PWMController::CONTROLLER_TYPE type;

  int current; // Current PWM
  int target;  // Target PWM

public:
  PWMController(CONTROLLER_TYPE controller_type, uint8_t pin)
      : Servo(), type(type), TRIM_PW(0) {
    attach(pin);

    switch (type) {
    case PWMController::STEERING_NORMAL:
      MAX_PW = STEERING_NORMAL_PW_LEFT;
      MIN_PW = STEERING_NORMAL_PW_RIGHT;
      NEUTRAL_PW = STEERING_NORMAL_PW_NEUTRAL + TRIM_PW;
      break;
    case PWMController::STEERING_REVERSE:
      MIN_PW = STEERING_REVERSE_PW_LEFT;
      MAX_PW = STEERING_REVERSE_PW_RIGHT;
      NEUTRAL_PW = STEERING_REVERSE_PW_NEUTRAL + TRIM_PW;
      break;
    case PWMController::MOTOR_NORMAL:
      MAX_PW = MOTOR_NORMAL_PW_THROTTLE;
      MIN_PW = MOTOR_NORMAL_PW_BRAKE;
      NEUTRAL_PW = MOTOR_NORMAL_PW_NEUTRAL - TRIM_PW;
      break;
    case PWMController::MOTOR_REVERSE:
      MIN_PW = MOTOR_REVERSE_PW_THROTTLE;
      MAX_PW = MOTOR_REVERSE_PW_BRAKE;
      NEUTRAL_PW = MOTOR_REVERSE_PW_NEUTRAL - TRIM_PW;
      break;
    }

    target = NEUTRAL_PW;
    current = NEUTRAL_PW;

    writeMicroseconds(NEUTRAL_PW);
  }

  void setTarget(int8_t percent) {
    uint8_t delta = UPDATE_RATE; // PWM increment for each input
    int temp;
    switch (type) {
    case PWMController::MOTOR_NORMAL:
      temp = map(percent, (int8_t)-100, (int8_t)100, MIN_PW, MAX_PW);
      break;
    case PWMController::MOTOR_REVERSE:
      temp = map(percent, (int8_t)100, (int8_t)-100, MIN_PW, MAX_PW);
      break;
    case PWMController::STEERING_NORMAL:
      temp = map(percent, (int8_t)-100, (int8_t)100, MIN_PW, MAX_PW);
      break;
    case PWMController::STEERING_REVERSE:
      temp = map(percent, (int8_t)100, (int8_t)-100, MIN_PW, MAX_PW);
      break;
    }
    target += abs(temp - target) < delta ? 0 : temp > target ? delta : -delta;
  }

  void Advance() {
    // Integrate dynamics, taking as many steps as required to reach the value
    // 'step'
    uint8_t gain = 4; // Gain for internal dynamics
    uint8_t step = 2; // ms

    int deriv = gain * (target - current);

    current += (step / 1000.0f) * deriv;

    // Clamp value
    current = current >= MAX_PW ? MAX_PW : current <= MIN_PW ? MIN_PW : current;

    // Write value to servo
    writeMicroseconds(current);
  }

  int GetCurrent() { return (int)target; }
};
