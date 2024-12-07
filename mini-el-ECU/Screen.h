// Screen.h
#ifndef Screen_h
#define Screen_h

#include <Arduino.h>

class LED {
  private:
    int ledPin;
    unsigned char ledState;

  public:
    LED(int pin);
    void turnON();
    void turnOFF();
    int getState();
    void Bargraph(int iValue);

};


#endif
