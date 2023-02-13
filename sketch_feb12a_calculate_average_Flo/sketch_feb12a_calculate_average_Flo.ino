#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 60
#define DATA_PIN 2
#define BRIGHTNESS  64
#define UPDATES_PER_SECOND 100
#define COLOR_ORDER GRB

// Initialize sound sensor
int Analog_Eingang = A5;
// variable to store the value coming from the sensor
int sensorValue;
int Colouractive = false;
int storeValues[200]; //unsigned machen?
int Summe = 0; //uint UNSIGNED INTEGER, IMMER POS, int32bit
int average = 0;
int l; 

//uint8_t gHue = 0;
//If you notice that your pattern is missing out certain LEDs, you
// will need to use the higher resolution beatsin16 instead.
uint16_t gHue = 0;

// Define the array of leds
CRGB leds[NUM_LEDS];

//source: https://learn.microsoft.com/en-us/windows/win32/api/d3d12/ns-d3d12-d3d12_render_target_blend_desc
//int BlendEnable = true; 
TBlendType    currentBlending;
CRGBPalette16 currentPalette;
//extern CRGBPalette16 myRedWhiteBluePalette;
//extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() { 
  delay( 3000 ); // power-up safety delay
  
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   
  pinMode (Analog_Eingang, INPUT);

  FastLED.setBrightness(  BRIGHTNESS );

  currentBlending = LINEARBLEND;
 
  Serial.begin (9600); // Serial output with 9600 bits per second

}



void loop() { 
  sensorValue[200] = analogRead (Analog_Eingang);

   
  //  delay(200);
  //  Serial.println ("ANALOG EINGANG: ");
  //  Serial.println (analogRead(Analog_Eingang));

  //  delay(200);
  //  Serial.println ("Sensor Value: ");
  //  Serial.println (sensorValue);

 for (l= 0; l < 200; l++) 
    { 
  //storeValues[l] =  sensorValue[l];
  //Problem: sensorValue ist ein einzelner Wert, kein Array in dem mehrere Zahlen gespeichert werden 
    storeValues[l] =  sensorValue[counter];
    delay(200);
    Serial.println ("STORE: ");
    Serial.println (storeValues[l]);


    

    //Summe = Summe + analogRead(Analog_Eingang);
    // delay (20);
 };
// counter/index der jedes mal hoch geht sensorValue[counter]
   
 
 for (l= 0; l <= 200; l++) 
    { 
           
    //storeValues[i] = analogRead (Analog_Eingang);
    Summe = Summe + storeValues[l];
   };
 
  // delay (200);
  // Serial.println (Summe);
 
  // average = (Summe*(-1)) / 200;    
  average = Summe / 200;    

 //delay (200);
//  Serial.println ("Average: ");
//  Serial.println (average);


//negativ wert in positiven umrechnen
int i;
int c;
uint8_t gHue = 0;

if (Colouractive == true) {
    for(c=0; c<NUM_LEDS; c++) {
//  leds[c].setBrightness(0);
    leds[c].setHue(gHue+=5);
    //FastLED.show();
  //FastLED.clear();
  }}

//int brightness
//FastLED.setBrightness(0);

  // Current value will be read 
//  Serial.println (sensorValue);
 int equalize = (sensorValue-450);
 
 // int equalize = (sensorValue-Summe);

  {
 
    for(i=0; i<=equalize; i++)
    {   
     uint8_t brightness = 255;
     for(c=0; c<NUM_LEDS; c++) {leds[c].setHue(gHue+=5);}
     leds[i].fadeLightBy(64);
     currentBlending = LINEARBLEND;
      //  leds[i] = CRGB::Green;
     //Colouractive = true;
     }
     

     FastLED.show();
     //FastLED.clear();

  
}
//else
  {for(i=0; i<=NUM_LEDS; i++)
    {
      //FastLED.setBrightness(0);
      //leds[i] = CRGB::Black;
      uint8_t brightness = 30;
      leds[i].fadeLightBy(230);

    }

}
     FastLED.show();
  