// Screen.cpp
#include "Screen.h"

LED::LED(int pin) {
  ledPin   = pin;
  ledState = LOW;
  pinMode(ledPin, OUTPUT);
}

void LED::turnON() {
  ledState = HIGH;
  digitalWrite(ledPin, ledState);
}

void LED::turnOFF() {
  ledState = LOW;
  digitalWrite(ledPin, ledState);
}

int LED::getState() {
  return ledState;
}

void LED::Bargraph(int iValue)
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

