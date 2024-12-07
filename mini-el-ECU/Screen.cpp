// Screen.cpp
#include "Screen.h"


Screen::Screen(int pin) {
  i = pin;
}

int Screen::getPin() {
  return i;
}

void Screen::Bargraph(int iValue)
{
  int i;
  
  i = 20;
  while (iValue > 0)
  {
    if (iValue >= 5)
    {
      // TODOlcd.write(5);
      iValue -= 5;
    }
    else
    {
      // TODO lcd.write(iValue);
      iValue = 0;
    }
    i -= 1;
  }
  
  while (i > 0)
  {
    i--;
    // TODO lcd.write(iValue);
  }
}

