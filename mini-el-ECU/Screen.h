// Screen.h
#ifndef Screen_h
#define Screen_h

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "Globals.h"


//extern word regs[8];
//extern byte REG_SPEED;
//extern byte REG_SOC;
//extern byte AinBatI;// =       A2; // Input pin for the battery current
//extern byte AinBatV;// =       A3; // Input pin for the full battery voltage

class Screen {
  private:
    LiquidCrystal_I2C* lcd;
    unsigned long menuTicksAtChange;
    byte activeMenu;
    
  public:
    Screen(LiquidCrystal_I2C* myLCD);
    void Init(byte cols, byte rows);
    void Bargraph(byte barValue);
    void DisplayMessage(const char* message, byte col, byte row);
    void MenuSelect(byte menu);
    void MenuUpdate();
};

#endif


