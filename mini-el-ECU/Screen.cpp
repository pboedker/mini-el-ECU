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
  activeMenu = menu;
  menuTicksAtChange = millis();
  lcd->clear();
  MenuUpdate();
}

void Screen::MenuUpdate() {
  bool init = (menuTicksAtChange == millis());
  char myBuffer[10]; // Buffer to hold the formatted string

  init = true;
  // Change, so that each case has an init part and an update part.
  switch (activeMenu)
  {
    case 0:
      if (init) {
        DisplayMessage("mini-el Control Unit", 0, 1);
        DisplayMessage("v1.2.0", 7, 2);
      }
      if (millis() >= (menuTicksAtChange + 3000)) {
        MenuSelect(1);
      }
      break;
      
    case 1:
      lcd->setCursor(0, 0);
      Bargraph(regs[REG_SPEED] / 10);

      dtostrf(regs[REG_SPEED] / 10, 3, 0, myBuffer);
      DisplayMessage(myBuffer, 0, 1);
      
      dtostrf((float)regs[AinBatI] / 10, 5, 1, myBuffer);
      DisplayMessage(myBuffer, 13, 1);
      lcd->print(" A");
      
      dtostrf((float)regs[AinBatV] / 10, 5, 1, myBuffer);
      DisplayMessage(myBuffer, 13, 2);
      lcd->print(" V");

      lcd->setCursor(0, 3);
      Bargraph(regs[REG_SOC] / 10);
      break;
      
    case 2:
      break;
  }  
}


