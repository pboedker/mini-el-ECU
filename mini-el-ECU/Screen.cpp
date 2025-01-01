// Screen.cpp
#include "Screen.h"

Screen::Screen(LiquidCrystal_I2C* initLCD) {
  lcd = initLCD;
}

void Screen::Init(byte cols, byte rows) {
  // Bargraph 0 (we're using a space instead)
//  byte newChar0[8] = {
//    B00000,
//    B00000,
//    B00000,
//    B00000,
//    B00000,
//    B00000,
//    B00000,
//    B00000};
  
  // Bargraph 1
  byte newChar1[8] = {
    B00000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B00000};
  
  // Bargraph 2
  byte newChar2[8] = {
    B00000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B00000};
  
  // Bargraph 3
  byte newChar3[8] = {
    B00000,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B00000};
  
  // Bargraph 4
  byte newChar4[8] = {
    B00000,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B00000};
  
  // Bargraph 5
  byte newChar5[8] = {
    B00000,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B00000};

  // Initialize the lcd with the size
  lcd->begin(cols, rows);
      
//  lcd->createChar(0, newChar0);
  lcd->createChar(1, newChar1);
  lcd->createChar(2, newChar2);
  lcd->createChar(3, newChar3);
  lcd->createChar(4, newChar4);
  lcd->createChar(5, newChar5);

  // Turn on backlight and clear the screen
  lcd->backlight();
  lcd->clear();

  keyIdleLow = 770;
}

// Writes a bargraph of 0-100, divided into 20 chars
void Screen::Bargraph(byte barValue) {
  byte i;
  
  i = 20;
  while (barValue > 0)
  {
    if (barValue >= 5) // Write a full character (width 5)
    {
      lcd->write(5);
      barValue -= 5;
    }
    else // Write a partial character (width == barValue rest)
    {
      lcd->write(barValue);
      barValue = 0;
    }
    i -= 1;
  }
  
  while (i > 0) // Write the rest as spaces (barValue is now zero)
  {
    i--;
    lcd->write(' ');
  }
}

// Displays a message on the LCD
void Screen::DisplayMessage(const char* message, byte col, byte row) {
    lcd->setCursor(col, row);
    lcd->print(message);
}

void Screen::MenuSelect(byte menu) {
  menuActive = menu;
  menuInit = true;
  menuTicksAtChange = millis();
  lcd->clear();
  MenuUpdate();
}

void Screen::MenuUpdate() {
  char myBuffer[10]; // Buffer to hold the formatted string
  int value;

  // Change, so that each case has an init part and an update part.
  switch (menuActive)
  {
    case 0:
      if (menuInit) {
        DisplayMessage("mini-el Control Unit", 0, 1);
        DisplayMessage(version, 7, 2);
      }
      if (millis() >= (menuTicksAtChange + 3000)) {
        MenuSelect(1);
      }
      break;
      
    case 1:
      lcd->setCursor(0, 0);
      value = map(regs[REG_SPEED], 55, 500, 0, 1000);
      value = max(0, value);
      Bargraph(value / 10);

//      dtostrf(regs[REG_SPEED] / 10, 3, 0, myBuffer);
//      DisplayMessage(myBuffer, 0, 1);

      value = 770 - keyIdleLow;
      lcd->setCursor(0, 1);
      if (regs[REG_KEYS] < (127 - value / 5)) {
        lcd->print("Trip      ");
      }
      else if (regs[REG_KEYS] < (242 - value / 4)) {
        lcd->print("Lights Off");        
      }
      else if (regs[REG_KEYS] < (333 - value / 3)) {
        lcd->print("Heat Low  "); 
      }
      else if (regs[REG_KEYS] < (398 - value / 2)) {
        lcd->print("Heat High ");        
      }
      else if (regs[REG_KEYS] < (470 - value / 2)) {
        lcd->print("Wiper     ");        
        digitalWrite(DoutWiper, RELAY_ON);
      }
      else if (regs[REG_KEYS] < (568 - value)) {
        lcd->print("Wiper Off ");        
        digitalWrite(DoutWiper, RELAY_OFF);
      }
      else if (regs[REG_KEYS] < (649 - value)) {
        lcd->print("Fan       ");
        digitalWrite(DoutFan, RELAY_ON);
      }
      else if (regs[REG_KEYS] < (690 - value)) {
        lcd->print("Washer    ");        
        digitalWrite(DoutWasher, RELAY_ON);
      }
      else if (regs[REG_KEYS] < (738 - value)) {
        lcd->print("Fan Off   ");        
        digitalWrite(DoutFan, RELAY_OFF);
      }
      else {
        keyIdle = true;
        lcd->print("No key      ");
        digitalWrite(DoutWasher, RELAY_OFF);
      }
      
      dtostrf((float)regs[REG_BAT_I] / 10, 6, 1, myBuffer);
      DisplayMessage(myBuffer, 12, 1);
      lcd->print(" A");
      
      dtostrf((float)regs[REG_BAT_V] / 10, 5, 1, myBuffer);
      DisplayMessage(myBuffer, 13, 2);
      lcd->print(" V");

      regs[REG_GEAR] = regs[REG_SPEED] / 200;
      if (regs[REG_GEAR] == 1) {
        DisplayMessage("\"D\"", 0, 2);
      }
      else if (regs[REG_GEAR] == 2) {
        DisplayMessage("\"R\"", 0, 2);
      }
      else {
        DisplayMessage("\"N\"", 0, 2);
      }

      dtostrf(regs[REG_KEYS], 3, 0, myBuffer);
      DisplayMessage(myBuffer, 4, 2);
      dtostrf(keyIdleLow, 3, 0, myBuffer);
      DisplayMessage(myBuffer, 8, 2);
      dtostrf(value, 2, 0, myBuffer);
      DisplayMessage(myBuffer, 11, 2);

      lcd->setCursor(0, 3);
      value = map(regs[REG_SOC], 110, 1000, 0, 1000);
      value = max(0, value);
      Bargraph(value / 10);
      break;
      
    case 2:
      break;
  }

  menuInit = false;
}

