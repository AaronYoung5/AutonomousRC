#include "Common.h"
#include "PWMController.h"
#include "SerialHandler.h"

using namespace Common;

// --- Steering --- //
const int STEERING_PIN = 9; // Pin on arduino

// --- Motor --- //
const int MOTOR_PIN = 5;

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

  Serial.println("Finished Setup :: ");
  Serial.println("Motor Pin :: " + MOTOR_PIN);
  Serial.println("Steering Pin :: " + STEERING_PIN);
  delay(1000);
  Serial.println("Starting Loop");
}
void loop() {
  if (serialHandler->shouldRun())
    serialHandler->run();

  if (motorController->shouldRun())
    motorController->run();

  if (steeringController->shouldRun())
    steeringController->run();

  motorController->SetPercent(serialHandler->GetMessage().throttle);
  steeringController->SetPercent(serialHandler->GetMessage().steering);

  // Serial.println("Steering Position :: MAX");
  // steeringController->SetPosition(PWMController::MAX);
  // delay(2000);
  // Serial.println("Steering Position :: NEUTRAL");
  // steeringController->SetPosition(PWMController::NEUTRAL);
  // delay(2000);
  // Serial.println("Steering Position :: MIN");
  // steeringController->SetPosition(PWMController::MIN);
  // delay(2000);
  // Serial.println("Steering Position :: NEUTRAL");
  // steeringController->SetPosition(PWMController::NEUTRAL);
  // delay(2000);
}
