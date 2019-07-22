#pragma once

#include "Arduino.h"

namespace Common {
// Constants
const long BAUD_RATE = 115200;

// Methods
static void blink() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
  }
}
} // namespace Common
