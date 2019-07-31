#include "Common.h"
#include "PWMController.h"
#include "SerialHandler.h"

using namespace Common;

// --- Steering --- //
const int STEERING_PIN = 9; // Pin on arduino

// --- Motor --- //
const int MOTOR_PIN = 6;

// Custom objects
SerialHandler *serialHandler;
PWMController *motorController;
PWMController *steeringController;

void setup() {
  Serial.begin(BAUD_RATE);
  
  serialHandler = new SerialHandler();
  motorController = new PWMController(PWMController::MOTOR_NORMAL, MOTOR_PIN);
  steeringController =
      new PWMController(PWMController::STEERING_NORMAL, STEERING_PIN);

  // Set servos to neutral value
  motorController->SetPosition(PWMController::NEUTRAL);
  steeringController->SetPosition(PWMController::NEUTRAL);

  Serial.println("Finished Setup");
  delay(1000);
  Serial.println("Starting Loop");
  delay(1000);
}
void loop() {
  if (serialHandler->shouldRun())
    serialHandler->run();

  if (motorController->shouldRun()) {
    motorController->SetPercent(serialHandler->GetMessage().throttle);
    motorController->run();
  }

  if (steeringController->shouldRun()) {
    steeringController->SetPercent(serialHandler->GetMessage().steering);
    steeringController->run();
  }
}
