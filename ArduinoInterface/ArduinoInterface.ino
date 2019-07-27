#include "Common.h"
#include "PWMController.h"
#include "SerialHandler.h"
// #include <LiquidCrystal.h>

using namespace Common;

// --- Steering --- //
const int STEERING_PIN = 9; // Pin on arduino

// --- Motor --- //
const int MOTOR_PIN = 6;

// Custom objects
SerialHandler *serialHandler;
PWMController *motorController;
PWMController *steeringController;

// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(BAUD_RATE);
  // lcd.begin(16, 2);
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

  if (motorController->shouldRun()) {
    // lcd.print((float)serialHandler->GetMessage().throttle);
    motorController->SetPercent(serialHandler->GetMessage().throttle);
    motorController->run();
  }

  if (steeringController->shouldRun()) {
    // lcd.setCursor(0, 0);
    // lcd.print((float)serialHandler->GetMessage().steering);
    steeringController->SetPercent(serialHandler->GetMessage().steering);
    steeringController->run();
  }

  // Serial.println(serialHandler->GetMessage().throttle);

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
