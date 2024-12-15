// Screen.cpp
#include "Screen.h"

Screen::Screen(LiquidCrystal_I2C* initLCD) {
  lcd = initLCD;
}

void Screen::Init(int cols, int rows) {
  // Bargraph 0
  byte newChar0[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000};
  
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
      
  lcd->createChar(0, newChar0);
  lcd->createChar(1, newChar1);
  lcd->createChar(2, newChar2);
  lcd->createChar(3, newChar3);
  lcd->createChar(4, newChar4);
  lcd->createChar(5, newChar5);

  // Turn on backlight and clear the screen
  lcd->backlight();
  lcd->clear();
}

void Screen::Bargraph(int iValue)
{
  int i;
  
  i = 20;
  while (iValue > 0)
  {
    if (iValue >= 5)
    {
      lcd->write(5);
      iValue -= 5;
    }
    else
    {
      lcd->write(iValue);
      iValue = 0;
    }
    i -= 1;
  }
  
  while (i > 0)
  {
    i--;
    lcd->write(iValue);
  }
}

// Displays a message on the LCD
void Screen::DisplayMessage(const char* message, int col, int row) {
    lcd->setCursor(col, row);
    lcd->print(message);
}

void Screen::Menu(int iScreen, boolean bBuild)
{

  if (bBuild)
  {
    lcd->clear();
  }
  
  switch (iScreen)
  {
    case 0:
      DisplayMessage("mini-el Control Unit", 0, 1);
      DisplayMessage("v1.2.0", 7, 2);
      break;
      
    case 1:
      lcd->setCursor(0, 3);
      Bargraph(iBar);
      lcd->setCursor(0, 0);
      lcd->print(iBar);
      break;
      
    case 2:
      break;
  }  
}


