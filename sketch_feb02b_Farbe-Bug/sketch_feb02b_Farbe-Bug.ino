
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 60
#define DATA_PIN 2
uint8_t gHue = 0;

// Define the array of leds
CRGB leds[NUM_LEDS];

// Initialize sound sensor
int Analog_Eingang = A5;
int sensorValue; // variable to store the value coming from the sensor
int Colouractive = false;






void setup() { 
  
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   
  pinMode (Analog_Eingang, INPUT);
 
  Serial.begin (9600); // Serial output with 9600 bits per second
 

}



void loop() { 

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
  sensorValue = analogRead (Analog_Eingang);
  Serial.println (sensorValue);
  int equalize = (sensorValue-480);


  {{
 
    for(i=0; i<equalize; i++)

    {   
     leds[i].fadeLightBy(64);
     leds[i] = CRGB::Green;
     //Colouractive = true;
     }
     

     FastLED.show();
     //FastLED.clear();

  
}
//else
  {
    //Serial.println (sensorValue);
    for(i=0; i<NUM_LEDS; i++)
    {
      //FastLED.setBrightness(0);
      //leds[i] = CRGB::Black;
      leds[i].fadeLightBy(230);

}

}
     FastLED.show();
  
}}
