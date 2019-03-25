#pragma once

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_ILI9341.h>

struct UI_Element {
  int16_t  x;
  int16_t  y;
  int16_t  width;
  int16_t  height;
  word bgColor;
  int radius;
};

struct UI_Element_Text {
  word fgColor;
  const char * text;
};

class UI {
  private:
    Adafruit_ILI9341 *  _tft;
    UI_Element          _element;
    UI_Element_Text     _elementText;
    float               _currentValue;

    /**
      Print wrapper
    */
    void print(int16_t x, int16_t y, word fg, word bg, String text);

    /**
       string sprintf wrapper
    */
    String getString(float val);

    /**
       to compare float values
    */
    long floatToLong(float & val, int prec);
  public:
    /**
       Constructor
    */
    UI (Adafruit_ILI9341 & tft,  UI_Element  element, UI_Element_Text  elementText);

    /**
       Draws placeholder
    */
    void drawElement();

    /**
       Draws  / redraws text
    */
    void drawValue(float value);
};
