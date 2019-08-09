#include "SerialHandler.h"

SerialHandler::SerialHandler() : Thread() {
  // Thread will start enabled
  enabled = true;
  setInterval(100); // Sets the interval to be 100ms
  Serial.setTimeout(50);
}

void SerialHandler::run() {
  while (Serial.available() > 0) {
    // read the incoming byte:
    uint8_t sizeBuffer[4];
    Serial.readBytes(sizeBuffer, 4);
    int size = ((int *)sizeBuffer)[0];
    uint8_t messageBuffer[size];
    Serial.readBytes(messageBuffer, size);
    message_ = *((struct ControlMessage *)messageBuffer);
    Serial.println();
    // Serial.print(message.throttle);
    // Serial.println(message.braking);
    // Serial.println(message.steering);
  }
}

void SerialHandler::establishConnection() {
  delay(1000);
  LC::shared_instance().getLC().clear();
  LC::shared_instance().getLC().setCursor(0, 0);
  LC::shared_instance().getLC().print("Establishing");
  LC::shared_instance().getLC().setCursor(0, 1);
  LC::shared_instance().getLC().print("Connection");
  delay(1000);
  while (Serial.available() <= 0) {
    Serial.println();
    delay(300);
  }
  delay(1000);
  LC::shared_instance().getLC().clear();
  LC::shared_instance().getLC().setCursor(0, 0);
  LC::shared_instance().getLC().print("Connection");
  LC::shared_instance().getLC().setCursor(0, 1);
  LC::shared_instance().getLC().print("Established");
  delay(1000);
  LC::shared_instance().getLC().clear();
}
