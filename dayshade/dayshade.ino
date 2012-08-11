//Import Libraries
#include "SPI.h"
#include "Adafruit_WS2801.h"

//Assign Pins
  //Ditigal
int modeInterupt = 2; //Interupt Pin
int dataPin  = 4; //Light
int clockPin = 5;
  //Analog
//int spectrumLeft = 0; //Unused in this version
//int spectrumRight = 1; //Unused in this version
int knoba = 2;
int knobb = 3;

//Init Light Pixels
int numPixels = 140;
Adafruit_WS2801 dayshade = Adafruit_WS2801(numPixels, dataPin, clockPin, WS2801_GRB);

//Init Global Variables
int mode = 0; //What program is running
int analoga = 0;
int agalogb = 0;

//

void setup() {
  dayshade.begin(); 
  dayshade.show(); // Update LED contents, to start they are all 'off'
  
  
}

void loop() {
  switch (mode) {
    case 0:
      makeFire();
      break;
    case 1:
      break;
  }
}

//************************************************ Programs *************************************************//
/***************** Make Fire *****************\
| A faux fire effect.  |
| analoga: 
\*****************************************/
void makeFire(){
  for(int i=0; i<numPixels; i++){
    dayshade.setPixelColor(i,Color(random(120)+135,random(40),0));
    int anum = random(2);
    if(anum==1){
      dayshade.setPixelColor(i,Color(0,0,0));
    }
    int anums = random(400);
    if(anums==1){
      dayshade.setPixelColor(i,Color(255,255,0));
    }
  }
  dayshade.show();   // write all the pixels out
  delay(60);
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
