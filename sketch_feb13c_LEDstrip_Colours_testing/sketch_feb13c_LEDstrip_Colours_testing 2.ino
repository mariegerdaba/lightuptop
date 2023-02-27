#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 27
#define DATA_PIN 2

int i;

CRGB leds[NUM_LEDS];

void setup() {
  delay( 3000 ); // power-up safety delay
  
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical

}

void loop() {
  for(i=0; i<=NUM_LEDS; i++)
   { leds[i] = CRGB::Green; 
   }
  FastLED.show();
}

