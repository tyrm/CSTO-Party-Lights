//Import Libraries
#include "SPI.h"
#include "Adafruit_WS2801.h"

//Init Light Pixels
int dataPin  = 2;
int clockPin = 3;
Adafruit_WS2801 dayshade = Adafruit_WS2801(140, dataPin, clockPin, WS2801_GRB);

void setup() {
  dayshade.begin(); 
  dayshade.show(); // Update LED contents, to start they are all 'off'
  
  
}

void loop() {
  
}

//************************************************ Functions ************************************************//

/***************** Color *****************\
| Create a 24 bit color value from R,G,B. |
\*****************************************/
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}
/********************** Wheel **********************\
| Input a value 0 to 255 to get a color value.      |
| The colours are a transition r - g -b - back to r |
\***************************************************/
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
