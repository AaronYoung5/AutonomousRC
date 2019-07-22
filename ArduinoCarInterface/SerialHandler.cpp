#include "SerialHandler.h"

SerialHandler::SerialHandler() : Thread() {
  // Thread will start enabled
  enabled = true;
  setInterval(100); // Sets the interval to be 100ms
}

void SerialHandler::run() {
  while (Serial.available() > 0) {
    // read the incoming byte:
    uint8_t sizeBuffer[4];
    Serial.readBytes(sizeBuffer, 4);
    int size = ((int *)sizeBuffer)[0];
    uint8_t messageBuffer[size];
    Serial.readBytes(messageBuffer, size);
    message = *((struct ControlMessage *)messageBuffer);
  }
}
