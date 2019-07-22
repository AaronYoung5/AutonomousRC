#include "PWMController.h"
#include "SerialHandler.h"
#include "Common.h"

using namespace Common;

// --- General --- //
// const long BAUD_RATE = 115200;

// --- Steering --- //
const int STEERING_PIN = 9; // Pin on arduino
double steeringOutput = 0;
double steering = 0;
double oldSteering = 0;
double pwmSteeringOutput = 0;
int steeringServoPosition = 0;

// --- Motor --- //
const int MOTOR_PIN = 5;
int engineServoPosition = 0;
double throttle = 0;
double oldEngine = 0;
double pwmEngineOutput = 0;
double engineOutput = 0;
double braking = 0;

// --- Potentiometer --- //
const int POTENTIOMETER_PIN = A0;
const int POTENTIOMETER_UPPER_BOUND = 1024;

// --- PID constants --- //
const double MOTOR_MIN_VEL = 0.40;
const double ENGINE_VEL_CONSTANT = 0.66;

const double STEERING_MIN_VEL = 0.40;
const double STEERING_VEL_CONSTANT = 0.66;

// Custom objects
SerialHandler *serialHandler;
PWMController *motorController;
PWMController *steeringController;

void setup() {
  Serial.begin(BAUD_RATE);
  serialHandler = new SerialHandler();
  motorController = new PWMController(PWMController::MOTOR_NORMAL, MOTOR_PIN);
  steeringController = new PWMController(PWMController::STEERING_NORMAL, STEERING_PIN);

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
  Serial.println("Steering Position :: MAX");
  steeringController->SetPosition(PWMController::MAX);
  delay(2000);
  Serial.println("Steering Position :: NEUTRAL");
  steeringController->SetPosition(PWMController::NEUTRAL);
  delay(2000);
  Serial.println("Steering Position :: MIN");
  steeringController->SetPosition(PWMController::MIN);
  delay(2000);
  Serial.println("Steering Position :: NEUTRAL");
  steeringController->SetPosition(PWMController::NEUTRAL);
  delay(2000);
}

double carOutput(double throttle, double braking) {
  engineOutput = ((double)throttle + (double)braking) / 2.0;
}
