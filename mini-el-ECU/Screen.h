// Screen.h
#ifndef Screen_h
#define Screen_h

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Screen {
  private:
    LiquidCrystal_I2C* lcd;

  public:
    int iBar;
    int iSeconds;
    
    Screen(LiquidCrystal_I2C* myLCD);
    void Init(int cols, int rows);
    void Bargraph(int iValue);
    void DisplayMessage(const char* message, int col, int row);
    void Menu(int iScreen, boolean bBuild);
};

#endif
