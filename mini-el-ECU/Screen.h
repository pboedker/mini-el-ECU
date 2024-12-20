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

    word numbers[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    #define WORD_0 0
    #define WORD_1 1
    #define WORD_2 2
    #define WORD_3 3
    #define WORD_4 4
    #define WORD_5 5
    #define WORD_6 6
    #define WORD_7 7
    
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
