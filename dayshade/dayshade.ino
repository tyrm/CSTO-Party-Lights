//Import Libraries
#include "SPI.h"
#include "Adafruit_WS2801.h"

//Assign Pins
  //Ditigal
const int modeInterupt = 2; //Interupt Pin
const int dataPin  = 4; //Light
const int clockPin = 5;
  //Analog
//int spectrumLeft = 0; //Unused in this version
//int spectrumRight = 1; //Unused in this version
const int knoba = 2;
const int knobb = 3;

//Init Light Pixels
const int numPixels = 140;
Adafruit_WS2801 dayshade = Adafruit_WS2801(numPixels, dataPin, clockPin, WS2801_GRB);

//Init Global Variables
int mode = 0; //What program is running
int analoga = 0;
int agalogb = 0;

//

void setup() {
  dayshade.begin(); 
  dayshade.show(); // Update LED contents, to start they are all 'off'
  
  randomSeed(analogRead(random(8)));
}

// You may have noticed I'm using 0-1023 as my range, this is because this is the
// range returned by analogRead(). Since the range is constant it makes sense for
// the function to assuming the incoming range and map() it to usable ranges.
void loop() {
  switch (mode) {
    case 0:
      makeFire();
      break;
    case 1:
      sparkle(1023,512);
      break;
    case 2:
      white(0);
      break;
    case 3:
      fillAll(0);
  }
}

//************************************************ Programs *************************************************//
/***** Make Fire ******\
| A faux fire effect.  |
| analoga:             |
\**********************/
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
/***************************** Sparkle ****************************\
| Makes a random pixel white at random interals that slowly plays  |
| analoga:                                                         |
\******************************************************************/
void sparkle(int likelyhood,int speedArg){
  static byte drop[numPixels];
  int theSpeed = map(speedArg,0,1023,1,10);
  
  // This range may seem random, but my favourite setting is at 10
  // and I wanted 10 to be exatly in the middle.
  if(random(map(likelyhood,0,1023,2,18)==1)){
    drop[random(numPixels)]=255;
  }
  for(int i=0; i<numPixels; i++){
    dayshade.setPixelColor(i,Color(drop[i],map(drop[i],0,255,0,175),map(drop[i],0,255,0,140)));
    
    if(drop[i]>theSpeed){
      drop[i]-=theSpeed;
    }else {
      drop[i]=0;
    };
  }
  dayshade.show();   // write all the pixels out
  delay(10);
}
/****************** White ******************\
| A full white fill for full illimunation.  |
| analoga:                                  |
\*******************************************/
void white(int shade){
  for(int i=0; i<numPixels; i++){
    dayshade.setPixelColor(i,Color(255,map(shade,0,1023,175,255),map(shade,0,1023,140,255)));
  }
  dayshade.show();   // write all the pixels out
  delay(500);
}
/************ Fill All ************\
| A fill of color for all pixels.  |
| analoga: Color Hue               |
\**********************************/
void fillAll(int argHue){
  byte WheelPos = map(argHue,0,1023,0,255);
  
  for(int i=0; i<numPixels; i++){
    dayshade.setPixelColor(i,Wheel(WheelPos));
  }
  dayshade.show();   // write all the pixels out
  delay(500);
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
