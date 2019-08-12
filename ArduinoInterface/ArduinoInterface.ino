#include "PWMController.h"
#include "SerialHandler.h"

// Constants
const long BAUD_RATE = 115200;

// --- Steering --- //
const uint8_t STEERING_PIN = 9; // Pin on arduino

// --- Motor --- //
const uint8_t MOTOR_PIN = 6; // Pin on arduino

// Custom objects
SerialHandler serialHandler;
PWMController motorController(PWMController::MOTOR_REVERSE, MOTOR_PIN);
PWMController steeringController(PWMController::STEERING_REVERSE, STEERING_PIN);

void setup() {
  Serial.begin(BAUD_RATE);
  Serial.setTimeout(50);

  serialHandler.establishConnection();
}
void loop() {
  serialHandler.Advance();

  // motorController.setTarget(serialHandler.GetThrottle());
  // motorController.Advance();

  steeringController.setTarget(serialHandler.GetSteering());
  steeringController.Advance();

  // Debugging
  // Serial.println((int)serialHandler.GetSteering());
  // Serial.println(steeringController.GetCurrent());
  // delay(25);
}
