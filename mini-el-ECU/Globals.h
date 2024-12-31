// Globals.h
#ifndef Globals_h
#define Globals_h

#include <arduino.h>

extern char version[];

// Declaring pin numbers for IO
// Beware, A0-A5 has the values 14-19 !
//#define D0_var 0 // - Reserved for Serial Rx?
//#define D1_var 1 // - Reserved for Serial Tx?
//#define DinSpeed 2 // Speed sensor (INT0)
//#define D3_var 3 // Not used (INT1, also PWM)
//#define DinBeam 4 // Beam (stalk)
//#define DinHead 5 // Head light (also PWM)
//#define D6_var 6 // Not used (also PWM)
#define DinDrive 7 // Gear selector, Drive
#define DinReverse 8 // Gear selector, Reverse
//#define D9_var 9 // Not used (PWM)
#define DoutWiper 10 // Not used (also PWM)
#define DoutWasher 11 // Windscreen wiper (also PWM)
#define DoutFan 12 // Windscreen washer
#define D13_var 13 // Windscreen fan (LED)
//#define Ain0_var =      A0; // - Not used
#define AinKeys A1 // Input pin for the keyboard encoding
#define AinBatI A2 // Input pin for the battery current
#define AinBatV A3 // Input pin for the full battery voltage
//#define Ain4_var A4 // I2C-SDA for 4x20 LCD Display
//#define Ain5_var A5 // I2C-SCL for 4x20 LCD Display

// Reserving relay functions
// 1: High Beam
// 2: Wiper
// 3: Washer
// 4: Fan
// 5: 
// 6: 
// 7: 
// 8:  
#define RELAY_ON 0
#define RELAY_OFF 1

extern int regs[8];
#define REG_SPEED 0
#define REG_SOC 1
#define REG_KEYS 2
#define REG_BAT_I 3
#define REG_BAT_V 4
#define REG_GEAR 5


#endif
