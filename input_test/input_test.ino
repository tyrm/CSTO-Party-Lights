//Assign Pins
  //Ditigal
const int modeInterupt = 0; //Interupt Pin, Digital Pin 2
const int dataPin  = 4; //Light
const int clockPin = 5;
  //Analog
//const int spectrumLeft = 0; //Unused in this version
//const int spectrumRight = 1; //Unused in this version
const int knoba = 2;
const int knobb = 3;

//Init Light Pixels
const int numPixels = 140;

//Init Global Variables
int mode = 0; //What program is running
int analoga = 0;
int agalogb = 0;

void setup() {
  Serial.begin(9600);
  
  attachInterrupt(modeInterupt, button, FALLING);
}

void loop() {
  Serial.print(analogRead(knoba);
  Serial.print("  ");
  Serial.println(analogRead(knobb);
  delay(1000);
}

void button() {
  Serial.println("boop");
}
