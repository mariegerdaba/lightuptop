#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 27
#define DATA_PIN 2
//#define BRIGHTNESS 100
#define LED_TYPE    WS2811
#define UPDATES_PER_SECOND 10
#define COLOR_ORDER GRB

// Define the array of leds
CRGB leds[NUM_LEDS];

int Analog_Eingang = A5;
int i;
uint16_t sensorValue;

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  pinMode (Analog_Eingang, INPUT);
  // FastLED.setBrightness(  BRIGHTNESS );
 
  Serial.begin (9600); // Serial output with 9600 bits per second
}

void loop() {
 sensorValue = analogRead (Analog_Eingang);
  Serial.println (sensorValue);

//if ( equalize <= NUM_LEDS) {equalize = (sensorValue-500);}

int equalize = (sensorValue-480);
// Serial.println (equalize);

  for(i=0; i<=equalize && i < NUM_LEDS; i++)
  {   
 leds[i] = CRGB::Green;
  } 
  FastLED.show();
// delay (20);
int b; 
  for(b=0; b< NUM_LEDS; b++)
  {   
 leds[b] = CRGB::Black;
  } 
  

}