//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include "libs/LiquidCrystal_I2C/LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
   lcd.setCursor(0,0);
  lcd.print("Arduino LCM I");
   lcd.setCursor(0,1);
  lcd.print("Power By Ec-yuan!");
}


void loop()
{
}
