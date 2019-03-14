/**
 * indoor sensor firmware based on ATMEGA328p (arduino nano / pro )
 * - DEBUG: 1602 LCD screen (i2c)
 * - Temperature / Humidity / Preassure: BME 280 (i2C)
 * - CO2: MH-Z19B
 * - Dust Sensor Module DSM501A PM2.5
 * - CO / NH3 / NO2 - MICS-6814
 * - IO: HC12 (HC11)
 */
 
#include "libs/lcd/LiquidCrystal_I2C.h"
#define DISPLAY_I2C_ADDRESS 0x3F
#define DISPLAY_CHARS 16
#define DISPLAY_LINES 2

LiquidCrystal_I2C lcd(DISPLAY_I2C_ADDRESS, DISPLAY_CHARS, DISPLAY_LINES); 

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Arduino LCM I");
  lcd.setCursor(0, 1);
  lcd.print("Power By Ec-yuan!");
}

void loop(){}
