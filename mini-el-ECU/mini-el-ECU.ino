/* mini-el Control Unit */

// TODO
// Version number struct

// Common libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Local libraries.
#include "Globals.h"
#include "Screen.h"
#include "Task.h"


/*-----( Declare Constants )-----*/
unsigned long ulTicks; 


/*-----( Declare objects )-----*/
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
Screen screen(&lcd);
//Task task10(10);
Task task100(100);
Task taskScreen(500);
Task taskSecond(1000);


/*-----( Declare Variables )-----*/


// setup: Runs once.
void setup() {
  // Reset digital pins used for relays
  digitalWrite(DoutBeam, RELAY_OFF);
  digitalWrite(DoutWiper, RELAY_OFF);
  digitalWrite(DoutWasher, RELAY_OFF);
  digitalWrite(DoutFan, RELAY_OFF);
  digitalWrite(DoutHeatLow, RELAY_OFF);
  
  Serial.begin(9600); // We will receive characters

  // Set the lcd size
  screen.Init(20,4);

  // Set analog pins to input
  pinMode(AinKeys, INPUT);
  pinMode(AinBatV, INPUT);
  pinMode(AinBatI, INPUT);

  // Set digital pins used
  pinMode(DoutBeam, OUTPUT);
  pinMode(DoutWiper, OUTPUT);
  pinMode(DoutWasher, OUTPUT);
  pinMode(DoutFan, OUTPUT);
  pinMode(DoutHeatLow, OUTPUT);
  
  // Show splash screen and then clear the screen
  screen.MenuSelect(0);

  regs[REG_SPEED] = 100;
  regs[REG_SOC] = 200;
} /*---( end setup )---*/



/*---( loop: Runs constantly )---*/
void loop() {
  ulTicks = millis();

  if (task100.Tick(ulTicks)) {
  }

  if (taskScreen.Tick(ulTicks)) {
    getInput(true);
    
    screen.MenuUpdate();
  }

  if (taskSecond.Tick(ulTicks)) {
//    regs[REG_SPEED] += 25;
//    if (regs[REG_SPEED] > 500) {
//      regs[REG_SPEED] = 25;
//    }

//    regs[REG_SOC] += 50;
//    if (regs[REG_SOC] > 1000) {
//      regs[REG_SOC] = 100;
//    }
  }
  
} /*---( end loop )---*/



/*---( getInput: Updates the various inputs to update variables )---*/
void getInput(bool raw) {
  int AinValue; // Temporary value from the sensor

  // Read the keyboard voltage, 0-5000 mV
  AinValue = analogRead(AinKeys);
  if (raw) {
    regs[REG_KEYS] = AinValue;
  }
  else {
    regs[REG_KEYS] = map(AinValue, 0, 1023, 0, 5000);
  }

  // Read the value from the sensor, +- 200.0 A
  AinValue = analogRead(AinBatI);      
  if (raw) {
    regs[REG_BAT_I] = AinValue;
  }
  else {
    regs[REG_BAT_I] = map(AinValue, 0, 1023, -2000, 2000);
  }
  
  // read the value from the sensor, 0-50.0 V
  AinValue = analogRead(AinBatV);      
  if (raw) {
    regs[REG_BAT_V] = AinValue;  
  }
  else {
    regs[REG_BAT_V] = map(AinValue, 0, 1023, 0, 500);  
  }
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

