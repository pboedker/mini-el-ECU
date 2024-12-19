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
unsigned long ulTicks; 


/*-----( Declare objects )-----*/
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
Screen myScreen(&lcd);
//Task task10(10);
Task taskScreen(500);
Task taskSecond(1000);


/*-----( Declare Variables )-----*/
int iBarD;

float fKeyV; // The voltage from the keyboard
float fBatV; // The voltage of the battery
float fBatI; // The current from the battery



// setup: Runs once.
void setup() {
  Serial.begin(9600); // We will receive characters

  // Set the lcd size
  myScreen.Init(20,4);

  // Set analog pins to input
  pinMode(AinKey, INPUT);
  pinMode(AinBatV, INPUT);
  pinMode(AinBatI, INPUT);

  // Show splash screen and then clear the screen
  myScreen.MenuSelect(0);

  iBarD = 1;
} /*---( end setup )---*/



/*---( loop: Runs constantly )---*/
void loop() {
  int AinValue = 0; // Temporary value from the sensor

  ulTicks = millis();

  if (taskScreen.Tick(ulTicks)){
    // Do a bargraph... 
    myScreen.iBar += 2*iBarD;
    if (myScreen.iBar >= 100 || myScreen.iBar <= 0)
    {
      iBarD = -iBarD;
    }

//    // Print out keyboard voltage
//    AinValue = analogRead(AinKey);      
//    fKeyV = map(AinValue, 0, 1023, 5000, 0);
//    lcd.setCursor(0, 2);
//    lcd.print("     ");  
//    lcd.setCursor(0, 2);
//    lcd.print(fKeyV / 1000, 3);

    myScreen.MenuUpdate();
  }

  if (taskSecond.Tick(ulTicks)){
  }
  
} /*---( end loop )---*/



/*---( getInput: Updates the various inputs to update variables )---*/
void getInput() {
  int AinValue; // Temporary value from the sensor

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



/* --- Various gold --- 
float valueFloat = 23.456; // Example float value
char bufferFloat[6]; // Buffer to hold the formatted string
// Format the float to ##.# (width 4, 1 decimal place)
dtostrf(valueFloat, 4, 1, bufferFloat);

int valueInt = 123;
char bufferInt[20];
// Convert integer to string with format specifier
sprintf(bufferInt, "%d", valueInt);
--- */

