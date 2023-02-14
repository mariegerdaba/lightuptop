#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 27
#define DATA_PIN 2
#define BRIGHTNESS 5
#define LED_TYPE    WS2811
// #define UPDATES_PER_SECOND 100
#define COLOR_ORDER GRB

// Define the array of leds
CRGB leds[NUM_LEDS];
//source: https://learn.microsoft.com/en-us/windows/win32/api/d3d12/ns-d3d12-d3d12_render_target_blend_desc
// //int BlendEnable = true; 
//TBlendType    currentBlending;
//CRGBPalette16 currentPalette;

// Initialize sound sensor
int Analog_Eingang = A5;
// uint8_t gHue = 0;
//static int8_t hue = 0;
static int hue = 0;
//int hue = 0;
int i;
int c;
int b;
int sensorValue;

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
//FastLED.setBrightness(  10 );
  //currentBlending = NOBLEND; 
  //currentBlending = LINEARBLEND;

  pinMode (Analog_Eingang, INPUT);

  FastLED.setBrightness(  BRIGHTNESS );
 
  Serial.begin (9600); // Serial output with 9600 bits per second

for(c=0; c<=NUM_LEDS; c++) {
// // // //  leds[c].setBrightness(0);
//leds[c].fadeLightBy(190);
//leds[c].nscale8( 192);
leds[c].setHue(hue+=5);

//leds[i] = (brightness);
// leds[c] = CHSV((hue+=5), 255, 150);
// // leds[i].fadeLightBy(64);
// // FastLED.clear();
// // return 0;

 FastLED.show();
// }
}
}

void loop() {

  sensorValue = analogRead (Analog_Eingang);
  //Serial.println (sensorValue);

  int equalize = (sensorValue-490);
   Serial.println (equalize);

  //uint8_t brightness = 255;

  { for(i=0; i<=equalize && i <= NUM_LEDS; i++)
    {   
//leds[i].fadeLightBy(30);
//FastLED.setBrightness(5);
leds[i].maximizeBrightness();
//  uint8_t brightness = 250;
//  leds[i] = (brightness);
// leds[c] = CHSV(hue++, 255, 200);
// leds[i] =CHSV(hue, 255, 10);
  // FastLED.setBrightness(250);
    // leds[i] = CRGB::Green;
    //  for(c=0; c<NUM_LEDS; c++) {
    //   leds[c].setHue(gHue+=5); }
    //currentBlending = LINEARBLEND;
   // leds[i] = CRGB::Green;
     //Colouractive = true;
     } 
  }

  FastLED.show();

  for(i=0; i<=NUM_LEDS; i++)
  {   
 leds[i] = CRGB::Black;
  } 
  

  FastLED.show();

   //FastLED.delay(1000 / UPDATES_PER_SECOND);
    
// {for(b=0; b <=NUM_LEDS; b++) 
// {
//    uint8_t brightness = 10;
//   // CHSV _targetHSV = rgb2hsv_approximate(leds[i]); // to use the current color of leds[0]
//   // _targetHSV.v = 10;  // set the brightness 0 -> 100
//   // leds[i] = _targetHSV; 
// //leds[b].nscale8( 192);
// // leds[b].fadeToBlackBy( 192 );
// // leds[c].CHSV((hue+=5), 255, 0);
// //leds[b].fadeLightBy(250);
// //FastLED.setBrightness(5);
// }
// }
//   FastLED.show();
}
