// Screen.h
#ifndef Screen_h
#define Screen_h

#include <LiquidCrystal_I2C.h>
#include "Globals.h"

class Screen {
  private:
    LiquidCrystal_I2C* lcd;
    unsigned long menuTicksAtChange;
    byte menuActive;
    bool menuInit;
    bool keyIdle;
    int keyIdleLow;
    
  public:
    Screen(LiquidCrystal_I2C* myLCD);
    void Init(byte cols, byte rows);
    void Bargraph(byte barValue);
    void DisplayMessage(const char* message, byte col, byte row);
    void MenuSelect(byte menu);
    void MenuUpdate();
};

#endif


