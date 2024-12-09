// Screen.cpp
#include <LiquidCrystal_I2C.h>
#include "Screen.h"

//// Unused
//byte newChar0[8] =
//{
//  B00000,
//  B00000,
//  B00000,
//  B00000,
//  B00000,
//  B00000,
//  B00000,
//  B00000
//};

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


Screen::Screen(LiquidCrystal_I2C* initLCD, int pin) {
  i = pin;
  lcd = initLCD;

  // initialize the lcd for 20 chars 4 lines. Create some new characters
//  lcd->begin(20, 4);  
// TODO  lcd.createChar(0, newChar0);
//  lcd->createChar(1, newChar1);
//  lcd->createChar(2, newChar2);
//  lcd->createChar(3, newChar3);
//  lcd->createChar(4, newChar4);
//  lcd->createChar(5, newChar5);

  // Turn on backlight
//  lcd->backlight();

  // Show splash screen and then clear the screen
//  lcd->clear();
//  Menu(0, true);
//  delay(3000);
//  lcd->clear();

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

void Screen::Menu(int iScreen, boolean bBuild)
{
  char cPSB;
  int iPSB;
    
  if (bBuild)
  {
    lcd->clear();
  }
  
  switch (iScreen)
  {
    case 0:
      lcd->setCursor(0,1);
      lcd->print("mini-el Control Unit");
      lcd->setCursor(8,2);
      lcd->print("v1.2");
      break;
      
    case 1:
      lcd->setCursor(0,0);
      for (iPSB = 0; iPSB < 6; iPSB++)
      {
        lcd->write(iPSB);
      }
      break;
      
    case 2:
      break;
  }  
}


