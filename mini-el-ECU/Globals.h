// Globals.h
#ifndef Globals_h
#define Globals_h

#include <arduino.h>

extern char version[];

// Declaring pin numbers for IO
// Beware, A0-A5 has the values 14-19 !
//extern byte D0_var =         0; // - Reserved for Serial Rx?
//extern byte D1_var =         1; // - Reserved for Serial Tx?
//extern byte DinSpeed =       2; // Speed sensor (INT0)
//extern byte D3_var =         3; // Not used (INT1, PWM)
//extern byte DinBeam =        4; // Beam (stalk)
//extern byte DinHead =        5; // Head light (also PWM)
//extern byte D6_var =         6; // Not used (PWM)
extern byte DinDrive; // Gear selector, Drive
extern byte DinReverse; // Gear selector, Reverse
//extern byte D5_var =         9; // Not used (PWM)
//extern byte D10_var =       10; // Not used (PWM)
extern byte DoutWiper;// =     11; // Windscreen wiper (also PWM)
extern byte DoutWasher;// =    12; // Windscreen washer
extern byte DoutFan;// =       13; // Windscreen fan (LED)
//extern byte Ain0_var =      A0; // - Not used
extern byte AinKeys;// =       A1; // Input pin for the keyboard encoding
extern byte AinBatI;// =       A2; // Input pin for the battery current
extern byte AinBatV;// =       A3; // Input pin for the full battery voltage
//extern byte Ain4_var =      A4; // I2C-SDA for 4x20 LCD Display
//extern byte Ain5_var =      A5; // I2C-SCL for 4x20 LCD Display

// Reserving relay functions
// 1: High Beam
// 2: Fan
// 3: Wiper
// 4: Washer
// 5: 
// 6: 
// 7: 
// 8:  

extern int regs[8];
extern byte REG_SPEED;
extern byte REG_SOC;
extern byte REG_KEYS;
extern byte REG_BAT_I;
extern byte REG_BAT_V;
extern byte REG_GEAR;

#define RELAY_ON 0
#define RELAY_OFF 1

#endif
