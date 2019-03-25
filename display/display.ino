/**
   DISPLAY dependencies
*/
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

/**
   PIN setup
*/
#define TFT_DC 2
#define TFT_CS 15
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

/**
   Custom font from http://oleddisplay.squix.ch
*/
#include "LocalFont24.h"

/**
   BME280 dependencies
*/
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA  (1013.25)
#define BME280_ADDR           0x76

Adafruit_BME280 bme;

/**
   UI rendering wrapper dependency
*/
#include "UI.h"

#define UI_ELEM_WIDTH         240
#define UI_ELEM_HEIGHT        80
#define UI_ELEM_RADIUS        5

#define OFFSET_TEMP           0
#define OFFSET_HUM            (OFFSET_TEMP  + UI_ELEM_HEIGHT)
#define OFFSET_PRE            (OFFSET_HUM   + UI_ELEM_HEIGHT)

// Color definitions
#define BLACK                 0x0000
#define BLUE                  0x2134
#define GREEN                 0x1BE2
#define WHITE                 0xFFFF
#define PURPLE                0x7814

UI * uiTemp = new UI(
  tft,
  UI_Element { 0, OFFSET_TEMP, UI_ELEM_WIDTH, UI_ELEM_HEIGHT, BLUE, UI_ELEM_RADIUS },
  UI_Element_Text { WHITE, "T %d  C" }
);

UI * uiHum = new UI(
  tft,
  UI_Element { 0, OFFSET_HUM, UI_ELEM_WIDTH, UI_ELEM_HEIGHT, GREEN, UI_ELEM_RADIUS },
  UI_Element_Text{ WHITE, "H %d  %%" }
);

UI * uiPre = new UI(
  tft,
  UI_Element { 0, OFFSET_PRE, UI_ELEM_WIDTH, UI_ELEM_HEIGHT, PURPLE, UI_ELEM_RADIUS },
  UI_Element_Text { WHITE, "P %d  hPa"}
);

void setup() {
  /*
     Serial.begin(9600);
     Serial.println("ILI9341 Test!");
  */

  bme.begin(BME280_ADDR);
  tft.begin();
  tft.setFont(& Open_Sans_Light_32 );
  tft.fillScreen(ILI9341_BLACK);
  uiTemp->drawElement();
  uiHum->drawElement();
  uiPre->drawElement();
}

void loop(void) {
  uiTemp->drawValue(bme.readTemperature());
  uiHum->drawValue(bme.readHumidity());
  uiPre->drawValue((bme.readPressure() / 100.0F));
  delay(2000);
}
