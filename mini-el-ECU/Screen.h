// Screen.h
#ifndef Screen_h
#define Screen_h

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Screen {
  private:
    LiquidCrystal_I2C* lcd;
    unsigned long menuTicksAtChange;
    byte activeMenu;

  public:
    byte iBar;
    
    Screen(LiquidCrystal_I2C* myLCD);
    void Init(byte cols, byte rows);
    void Bargraph(byte barValue);
    void DisplayMessage(const char* message, byte col, byte row);
    void MenuSelect(byte menu);
    void MenuUpdate();
};

#endif
