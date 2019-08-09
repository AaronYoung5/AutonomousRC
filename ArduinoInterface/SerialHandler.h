#pragma once

#include "Common.h"
#include "LCD.h"
#include <Thread.h>

class SerialHandler : public Thread {
public:
  // Public class variables
  enum AckType : uint8_t { OK, NOT_OK };
  enum ControlMessageType { STEERING, THROTTLE };

  struct ControlMessage {
    float throttle;
    float steering;
    uint8_t padding = 0;
  } message_;

private:
  // Private class variables

public:
  // Public methods
  SerialHandler();

  void run();

  void establishConnection();

  struct ControlMessage GetMessage() {
    return message_;
  }

private:
  // Private methods
};
