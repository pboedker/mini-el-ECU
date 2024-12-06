/* Test of Ruggeduino and several IO
 20 character 4 line I2C Display
 Start serial monitor and type characters to the screen
*/

/*-----( Import needed libraries )-----*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*-----( Declare Constants )-----*/
const boolean TEST_DISPLAY = true;
const boolean TEST_RS232 = false;
const boolean TEST_TOGGLE_O12 = true;
const boolean TEST_TOGGLE_O13 = true;
const int OUT_PIN12 = 12;
const int OUT_PIN13 = 13;

/*-----( Declare objects )-----*/
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

/*-----( Declare Variables )-----*/
unsigned long time1, time2, time3, time4;


/*----( SETUP: RUNS ONCE )----*/
void setup()   
{
  if (TEST_TOGGLE_O12)
  {
    // set the digital pin as output:
    pinMode(OUT_PIN12, OUTPUT);      
    digitalWrite(OUT_PIN12, HIGH); // LOW => Relay ON
  }
  
  if (TEST_TOGGLE_O13)
  {
    // set the digital pin as output:
    pinMode(OUT_PIN13, OUTPUT);      
    digitalWrite(OUT_PIN13, HIGH); // LOW => Relay ON
  }
  
  if (TEST_RS232)
  {
    Serial.begin(9600); // We will receive characters
  }

  if (TEST_DISPLAY)
  {
    lcd.begin(20,4);  // initialize the lcd for 20 chars 4 lines, turn on backlight
  }

  // ------- Start with 2 blinks of backlight  -------------
  if (TEST_DISPLAY)
  {
    for(int i = 0; i < 2; i++)
    {
      lcd.backlight();
      delay(200);
      lcd.noBacklight();
      delay(200);
    }
    lcd.backlight(); // leave backlight on  

    //-------- Write characters on the display ------------------
    // NOTE: Cursor Position: Lines and Characters start at 0  
    lcd.setCursor(0,0); //Start at character 0 on line 0
    lcd.print("12345678901234567890");
    delay(1000);
  }
}/*--(end setup )---*/


/*----( LOOP: RUNS CONSTANTLY )----*/
void loop()
{
  // When characters arrive over the serial port...
  if (TEST_RS232 and TEST_DISPLAY and Serial.available()) 
  {
    // Wait a bit for the entire message to arrive
    delay(100);
    // Clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) 
    {
      // Display each character to the LCD
      lcd.write(Serial.read());
    }
  }

  if (TEST_TOGGLE_O12) 
  {
    lcd.clear();

    lcd.setCursor(0,1); //Start at character 0 on line 1
    lcd.print(time2 - time1);
    lcd.setCursor(0,2); //Start at character 0 on line 2
    lcd.print(time4 - time3);
    
    // Turn ON the digital out pin 
/*    digitalWrite(OUT_PIN12, HIGH);
    digitalWrite(OUT_PIN13, LOW);
    lcd.setCursor(0,0); //Start at character 0 on line 0
    lcd.print("HIGH");
*/    // Wait a bit 
    time1 = millis();
    time3 = micros();
    delay(1000);
    time2 = millis();
    time4 = micros();
    
/*    // Turn OFF the digital out pin 
    digitalWrite(OUT_PIN12, LOW);
    digitalWrite(OUT_PIN13, HIGH);
    lcd.setCursor(0,0); //Start at character 0 on line 0
    lcd.print("LOW ");
    // Wait a bit 
    delay(1000);
*/
  }
}/* --(end main loop )-- */



/* ( THE END ) */

