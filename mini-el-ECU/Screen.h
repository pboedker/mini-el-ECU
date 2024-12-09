// Screen.h
#ifndef Screen_h
#define Screen_h

#include <Arduino.h>

class Screen {
  private:
    int i;
    LiquidCrystal_I2C* lcd;

  public:
    Screen(LiquidCrystal_I2C* myLCD, int pin);
    int getPin();
    void Bargraph(int iValue);
    void Menu(int iScreen, boolean bBuild);
};

#endif
