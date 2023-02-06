
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 60
#define DATA_PIN 2

uint8_t gHue = 0;

// Define the array of leds
CRGB leds[NUM_LEDS];

// Initialize sound sensor
int Analog_Eingang = A5;
// variable to store the value coming from the sensor
int sensorValue; 
int Colouractive = false;
int storeValues[200]; 
int Summe = 0;
int average = 0;
int l; 


void setup() { 
  
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   
  pinMode (Analog_Eingang, INPUT);
 
  Serial.begin (9600); // Serial output with 9600 bits per second



}



void loop() { 
  sensorValue = analogRead (Analog_Eingang);
  
// Serial.println (analogRead(Analog_Eingang));

 for (l= 0; l <= 200; l++) 
    { 
  
    storeValues[l] =  sensorValue;
    //Summe = Summe + analogRead(Analog_Eingang);
    //delay (20);
   };

   
 
 for (l= 0; l <= 200; l++) 
    { 
  
    //storeValues[i] = analogRead (Analog_Eingang);
    Summe = Summe + storeValues[l];
   };

  
  Summe = Summe / 200;    
 
 // Serial.println ("Summe: ");
 //Serial.println (Summe);


//negativ wert in positiven umrechnen
int i;
int c;
uint8_t gHue = 0;

// if (Colouractive == true) {
//     for(c=0; c<NUM_LEDS; c++) {
// //  leds[c].setBrightness(0);
//     leds[c].setHue(gHue+=5);
//     //FastLED.show();
//   //FastLED.clear();
//   }}

//int brightness
//FastLED.setBrightness(0);

  // Current value will be read 
 Serial.println (sensorValue);
 int equalize = (sensorValue-450);
 // int equalize = (sensorValue-450);

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