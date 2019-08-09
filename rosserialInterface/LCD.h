#pragma once

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

class LC {
private:
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

public:
  static LC &shared_instance() {
    static LC lcd;
    return lcd;
  }

  LiquidCrystal_I2C getLC() { return lcd; }

private:
  LC() {
    lcd.begin(16, 2);
    lcd.backlight();
  }
};
