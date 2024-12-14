/* mini-el Control Unit */

// TODO
// Version number struct



// Common libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Local libraries.
#include "DefineIO.h"
#include "Screen.h"
#include "Task.h"


/*-----( Declare Constants )-----*/
const int tCycle = 10; // 10ms cycle time.



/*-----( Declare objects )-----*/
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
Screen myScreen(&lcd);
Task task1(10);
Task taskScreen(500);
Task taskSecond(1000);


/*-----( Declare Variables )-----*/
unsigned long ulTickOld, ulTickCnt; // One tick is 1 ms
int timer1s, timer100ms;
unsigned long ulTemp;
int iBarD;
int iSeconds = 0;

float fKeyV; // The voltage from the keyboard
float fBatV; // The voltage of the battery
float fBatI; // The current from the battery



// setup: Runs once.
void setup()   
{
  Serial.begin(9600); // We will receive characters

  // Set the lcd size
  myScreen.Init(20,4);

  // Set analog pins to input
  pinMode(AinKey, INPUT);
  pinMode(AinBatV, INPUT);
  pinMode(AinBatI, INPUT);

  // Show splash screen and then clear the screen
  myScreen.Menu(0, true);
 
  // Get the milliseconds in preparation for first timer event.
  ulTickOld = millis();
  ulTickCnt = 0;
  
  timer1s = 0;
  timer100ms = 0;
  iBarD = 1;
} /*---( end setup )---*/



/*---( loop: Runs constantly )---*/
void loop()
{
  int AinValue = 0; // Temporary value from the sensor

  ulTemp = millis();

  if (taskScreen.Tick(ulTemp))
  {
    myScreen.Menu(1, false);
  }

  if (taskSecond.Tick(ulTemp))
  {
    iSeconds++;
  }



  // Update the tick counter with elapsed milliseconds since last
  ulTemp = millis();
  if (ulTemp > ulTickOld)
  {
    ulTickCnt += (ulTemp - ulTickOld);
    ulTickOld = ulTemp;
  }
  
  // Check if we should do a cycle
  if (ulTickCnt >= tCycle)
  {
    // Update the tick counter with the cycle time
    ulTickCnt -= tCycle;
    
    // Update 100ms timer and react to it
    timer100ms += tCycle;
    if (timer100ms >= 100)
    {
      // Update timer for next time
      timer100ms = 0;
      
      // Do a bargraph... 
      myScreen.iBar += iBarD;
      if (myScreen.iBar >= 100 || myScreen.iBar <= 0)
      {
        iBarD = -iBarD;
      }
        
      // Print out keyboard voltage
      AinValue = analogRead(AinKey);      
      fKeyV = map(AinValue, 0, 1023, 5000, 0);
      lcd.setCursor(0, 2);
      lcd.print("     ");  
      lcd.setCursor(0, 2);
      lcd.print(fKeyV / 1000, 3);  
    }

    // Update 1 second timer and react to it
    timer1s += tCycle;
    if (timer1s >= 1000)
    {
      // Update timer for next time
      timer1s = 0;

      myScreen.Menu(1, true);

//      // Update several values from analog input
//      getInput();
//      lcd.setCursor(10, 0);
//      if (fBatV < 0)
//      {
//        fBatV = 0;
//      }
//      if (fBatV < 10)
//      {
//        lcd.print(" ");
//      }        
//      lcd.print(fBatV,1);
//      lcd.print("V");

//      fBatI = -8;
//      lcd.setCursor(0,0);
//      if (fBatI >= 0)
//      {
//        lcd.print(" ");
//        if (fBatI < 10)
//        {
//          lcd.print(" ");
//        }        
//        if (fBatI < 100)
//        {
//          lcd.print(" ");
//        }        
//      }
//      else
//      {
//        if (fBatI > -100)
//        {
//          lcd.print(" ");else
//        }
//        if (fBatI > -10)
//        {
//          lcd.print(" ");
//        }
//      }
//      lcd.print(fBatI,0);
//      lcd.print("A");
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


