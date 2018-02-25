/* mini-el Control Unit
  v1.1  24022018  Getting some IO's ready.
*/

// Common libraries.
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Local libraries.
#include "DefineIO.h"

/*-----( Declare Constants )-----*/
const int tCycle = 10; // 10ms cycle time.

// Bargraph 0
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

/*-----( Declare objects )-----*/
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

/*-----( Declare Variables )-----*/
unsigned long ulTick, ulTickCnt;
int timer1s, timer100ms;
unsigned long ulTemp;
int iBar, iBarD;

float fKeyV; // The voltage from the keyboard
float fBatV; // The voltage of the battery
float fBatI; // The current from the battery



// setup: Runs once.
void setup()   
{
  Serial.begin(9600); // We will receive characters

  // initialize the lcd for 20 chars 4 lines, turn on backlight. Create some new characters
  lcd.begin(20,4);  
  lcd.createChar(0, newChar0);
  lcd.createChar(1, newChar1);
  lcd.createChar(2, newChar2);
  lcd.createChar(3, newChar3);
  lcd.createChar(4, newChar4);
  lcd.createChar(5, newChar5);

  // Set analog pins to input
  pinMode(AinKey, INPUT);
  pinMode(AinBatV, INPUT);
  pinMode(AinBatI, INPUT);

  // Turn on backlight
  lcd.backlight();

  // Show splash screen and then clear the screen
  lcd.clear();
  menu(0, true);
  delay(3000);
  lcd.clear();
  
  // Get the milliseconds in preparation for first timer event.
  ulTick = millis();
  ulTickCnt = 0;
  
  timer1s = 0;
  timer100ms = 0;
  iBarD = 1;
} /*---( end setup )---*/



/*---( loop: Runs constantly )---*/
void loop()
{
  int AinValue = 0; // Temporary value from the sensor

  // Update the tick counter with elapsed milliseconds since last
  ulTemp = millis();
  if (ulTemp > ulTick)
  {
    ulTickCnt += (ulTemp - ulTick);
    ulTick = ulTemp;
  }
  
  // Check if we should do a cycle
  if (ulTickCnt >= tCycle)
  {
    // Update the tick counter with the cycle time
    ulTickCnt -= tCycle;
    
    // Do a bargraph... 
    iBar += iBarD;
    if (iBar >= 100 || iBar <= 0)
    {
      iBarD = -iBarD;
    }
    // lcd.setCursor(0, 3);
    // Bargraph(iBar);    
      
    // Update 100ms timer and react to it
    timer100ms += tCycle;
    if (timer100ms >= 100)
    {
      // Update timer for next time
      timer100ms = 0;

      // Print out keyboard voltage
      AinValue = analogRead(AinKey);      
      fKeyV = map(AinValue, 0, 1023, 5000, 0);
      lcd.setCursor(0, 2);
      lcd.print("     ");  
      lcd.setCursor(0, 2);
      lcd.print(fKeyV / 1000, 3);  
    }

    lcd.setCursor(0, 3);
    Bargraph(fKeyV / 50);    
    
    // Update 1 second timer and react to it
    timer1s += tCycle;
    if (timer1s >= 1000)
    {
      // Update timer for next time
      timer1s = 0;
      
      // Update several values from analog input
      getInput();
      lcd.setCursor(10, 0);
      if (fBatV < 0)
      {
        fBatV = 0;
      }
      if (fBatV < 10)
      {
        lcd.print(" ");
      }        
      lcd.print(fBatV,1);
      lcd.print("V");

      fBatI = -9;
      lcd.setCursor(0,0);
      if (fBatI >= 0)
      {
        lcd.print(" ");
        if (fBatI < 10)
        {
          lcd.print(" ");
        }        
        if (fBatI < 100)
        {
          lcd.print(" ");
        }        
      }
      else
      {
        if (fBatI > -100)
        {
          lcd.print(" ");
        }
        if (fBatI > -10)
        {
          lcd.print(" ");
        }
      }
      lcd.print(fBatI,0);
      lcd.print("A");
    }
    
  }
} /*---( end loop )---*/



/*---( getInput: Updates the various inputs to update variables )---*/
void getInput()
{
  int AinValue = 0; // Temporary value from the sensor

  // Read the value from the sensor
  AinValue = analogRead(AinBatI);      
  // Map it to the range of the analog variable, first integer then with one decimal
  fBatI = map(AinValue, 0, 1023, -2000, 2000);
  fBatI = fBatI / 10;
  
  // read the value from the sensor:
  AinValue = analogRead(AinBatV);      
  // Map it to the range of the analog variable, first integer then with one decimal
  fBatV = map(AinValue, 0, 1023, 0, 500);  
  fBatV = fBatV / 10;
} /*---( end getInput )---*/



void menu(int iScreen, boolean bBuild)
{
  char cPSB;
  int iPSB;
    
  if (bBuild)
  {
    lcd.clear();
  }
  
  switch (iScreen)
  {
    case 0:
      lcd.setCursor(0,1);
      lcd.print("mini-el Control Unit");
      lcd.setCursor(8,2);
      lcd.print("v1.0");
      break;
      
    case 1:
      lcd.setCursor(0,0);
      for (iPSB = 0; iPSB < 6; iPSB++)
      {
        lcd.write(iPSB);
      }
      break;
      
    case 2:
      break;
  }  
}

void Bargraph(int iValue)
{
  int i;
  
  i = 20;
  while (iValue > 0)
  {
    if (iValue >= 5)
    {
      lcd.write(5);
      iValue -= 5;
    }
    else
    {
      lcd.write(iValue);
      iValue = 0;
    }
    i -= 1;
  }
  
  while (i > 0)
  {
    i--;
    lcd.write(iValue);
  }
}

