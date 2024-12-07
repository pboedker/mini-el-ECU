// Screen.h
#ifndef Screen_h
#define Screen_h

#include <Arduino.h>

class Screen {
  private:
    int i;

    // Unused
    byte newChar0[8] =
    {
      B00000,
      B00000,
      B00000,
      B00000,
      B00000,
      B00000,
      B00000,
      B00000
    };

  // Bargraph 1
  byte newChar1[8] = 
  {
    B00000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B00000
  };
  
  // Bargraph 2
  byte newChar2[8] = 
  {
    B00000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B0000
  };
  
  // Bargraph 3
  byte newChar3[8] = 
  {
    B00000,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B00000
  };
  
  // Bargraph 4
  byte newChar4[8] = 
  {
    B00000,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B00000
  };
  
  // Bargraph 5
  byte newChar5[8] = 
  {
    B00000,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B00000
  };
  
  public:
    Screen(int pin);
    int getPin();
    void Bargraph(int iValue);
  
};

#endif
