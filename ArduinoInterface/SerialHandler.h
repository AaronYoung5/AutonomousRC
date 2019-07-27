#pragma once

#include "Common.h"
#include <Thread.h>

class SerialHandler : public Thread {
public:
  // Public class variables
  enum ControlMessageType { STEERING, THROTTLE, BRAKING };
  struct ControlMessage {
    float throttle;
    float braking;
    float steering;
  } message;

private:
  // Private class variables

public:
  // Public methods
  SerialHandler();

  void run();

  struct ControlMessage GetMessage() {
    return message;
  }

private:
  // Private methods
};
