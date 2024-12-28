// Globals.cpp
#include "Globals.h"

char version[] = "v1.2.1";

// Declaring pin numbers for IO
// Beware, A0-A5 is 14-19 !
//byte D0_var =         0; // - Reserved for Serial Rx?
//byte D1_var =         1; // - Reserved for Serial Tx?
//byte DinSpeed =       2; // Speed sensor (INT0)
//byte D3_var =         3; // Not used (INT1, PWM)
//byte DinBeam =        4; // Beam (stalk)
//byte DinHead =        5; // Head light (also PWM)
//byte D6_var =         6; // Not used (PWM)
byte DinDrive =       7; // Gear selector, Drive
byte DinReverse =     8; // Gear selector, Reverse
//byte D5_var =         9; // Not used (PWM)
//byte D10_var =       10; // Not used (PWM)
//byte DoutWiper =     11; // Windscreen wiper (also PWM)
//byte DoutWasher =    12; // Windscreen washer
//byte DoutFan =       13; // Windscreen fan (LED)
//byte Ain0_var =      A0; // - Not used
byte AinKeys =       A1; // Input pin for the keyboard encoding
byte AinBatI =       A2; // Input pin for the battery current
byte AinBatV =       A3; // Input pin for the full battery voltage
//byte Ain4_var =      A4; // I2C-SDA for 4x20 LCD Display
//byte Ain5_var =      A5; // I2C-SCL for 4x20 LCD Display

// Reserving relay functions (not part of SW)
// 1: High Beam
// 2: Main lights
// 3: 
// 4: 
// 5: 
// 6: 
// 7: 
// 8:  

int regs[8];
byte REG_SPEED = 0;
byte REG_SOC = 1;
byte REG_KEYS = 2;
byte REG_BAT_I = 3;
byte REG_BAT_V = 4;
byte REG_GEAR = 5;

