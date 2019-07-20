#include "PWMController.h"
#include "SerialHandler.h"

// --- General --- //
const int BAUD_RATE = 115200;

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
  Serial.begin(115200);
  serialHandler = new SerialHandler();
  motorController = new PWMController(PWMController::MOTOR_NORMAL, MOTOR_PIN);
  steeringController = new PWMController(PWMController::STEERING_NORMAL, STEERING_PIN);

  // Set servos to neutral value
   motorController->SetPosition(PWMController::NEUTRAL);
   steeringController->SetPosition(PWMController::NEUTRAL);

  // Force the servos to update themselves to the new position
  //  engineOutput = motorController->update();
  //  steeringOutput = steeringController->update();
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
  // get messages
  //  messager->update();

  // get old values to compare later
//  oldSteering = steeringOutput;
//  oldEngine = engineOutput;

  // get steering, braking, throttle from jetson
  //  steering = messager->getSteering();
  //  braking = messager->getBraking();
  //  throttle = messager->getThrottle();

  // run jetson's values through smoothing library
  //  motorController->setFinalPos(carOutput(throttle, braking));
  //  steeringController->setFinalPos(steering);

  // update smooth path
  //  engineOutput = motorController->update();
  //  steeringOutput = steeringController->update();

//  Serial.print("Steering: ");
//  Serial.println(steeringOutput);
//  Serial.print("Engine: ");
//  Serial.println(engineOutput);
}

void blink() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
  }
}

double carOutput(double throttle, double braking) {
  engineOutput = ((double)throttle + (double)braking) / 2.0;
}
