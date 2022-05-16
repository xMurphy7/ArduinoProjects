#include <LiquidCrystal_I2C.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // sets lcd's backlight to high
  lcd.setBacklight(HIGH);
  // initialize the serial communications:
  Serial.begin(9600);  
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // sets cursor to 0(col), 0(row)
    lcd.setCursor(0,0);  
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
         lcd.write(Serial.read());     
    }  
  }
}