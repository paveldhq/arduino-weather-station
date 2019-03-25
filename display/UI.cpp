#include "UI.h"
#include <Adafruit_ILI9341.h>

/**
   Print wrapper
*/
void UI::print(int16_t x, int16_t y, word fg, word bg, String text) {
  this->_tft->setCursor(x, y);
  this->_tft->setTextColor(fg, bg);
  this->_tft->println(text);
}

/**
   string sprintf wrapper
*/
String UI::getString(float val) {
  char buffer[50];
  int _val = (int) val;
  sprintf( buffer,  _elementText.text, _val);
  return String(buffer);
}

/**
   to compare float values
*/
long UI::floatToLong(float & val, int prec) {
  return (long) (val * pow(10, prec));
}

/**
   Constructor
*/
UI::UI (Adafruit_ILI9341 & tft,  UI_Element  element, UI_Element_Text  elementText) {
  _tft =  & tft;
  _element =  element;
  _elementText = elementText;
}

/**
   Draws placeholder
*/
void UI::drawElement() {
  this->_tft->fillRoundRect(_element.x, _element.y, _element.width, _element.height, _element.radius, _element.bgColor);
}

/**
   Draws  / redraws text
*/
void UI::drawValue(float value) {
  long v1 = floatToLong(value, 2);
  long v2 = floatToLong(_currentValue, 2);

  int16_t  _x =  _element.x + 25;
  int16_t  _y =  _element.y + 55;

  if (v1 != v2) {
    print (_x, _y, _element.bgColor, _element.bgColor, String(getString( _currentValue )));
    _currentValue = value;
  }
  print (_x, _y, _elementText.fgColor, _element.bgColor, String(getString( value )));
}
