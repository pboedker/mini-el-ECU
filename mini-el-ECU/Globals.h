// Globals.h
#ifndef Globals_h
#define Globals_h

#include <arduino.h>

// Declaring pin numbers for IO
// A0-A5 also doubling as enum for register array
//extern byte Ain0_var =      A0; // - Not used
extern byte AinKeys;// =       A1; // Input pin for the keyboard encoding
extern byte AinBatI;// =       A2; // Input pin for the battery current
extern byte AinBatV;// =       A3; // Input pin for the full battery voltage
//extern byte Ain4_var =      A4; // I2C-SDA for 4x20 LCD Display
//extern byte Ain5_var =      A5; // I2C-SCL for 4x20 LCD Display
//extern byte D0_var =         0; // - Reserved for Serial Rx?
//byte D1_var =         1; // - Reserved for Serial Tx?
//byte DinSpeed =       2; // Speed sensor (INT0)
//byte D3_var =         3; // Not used (INT1, PWM)
//byte DinBeam =        4; // Beam (stalk)
//byte DinHead =        5; // Head light (also PWM)
//byte D6_var =         6; // Not used (PWM)
//byte DinDrive =       7; // Gear selector, Drive
//byte DinReverse =     8; // Gear selector, Reverse
//byte D5_var =         9; // Not used (PWM)
//byte D10_var =       10; // Not used (PWM)
//byte DoutWiper =     11; // Windscreen wiper (also PWM)
//byte DoutWasher =    12; // Windscreen washer
//byte DoutFan =       13; // Windscreen fan (LED)

// Reserving relay functions (not part of SW)
// 1: High Beam
// 2: Main lights
// 3: 
// 4: 
// 5: 
// 6: 
// 7: 
// 8:  

extern word regs[8];
// Regs 0-5 use the defines from A0-A5
extern byte REG_SPEED;
extern byte REG_SOC;

#endif
