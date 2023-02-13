#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 27
#define DATA_PIN 2
//#define BRIGHTNESS 200
#define LED_TYPE    WS2811
// #define UPDATES_PER_SECOND 100

// Define the array of leds
CRGB leds[NUM_LEDS];
//source: https://learn.microsoft.com/en-us/windows/win32/api/d3d12/ns-d3d12-d3d12_render_target_blend_desc
// //int BlendEnable = true; 
 // TBlendType    currentBlending;
// CRGBPalette16 currentPalette;

// Initialize sound sensor
int Analog_Eingang = A5;
//int8_t gHue = 0;
static int8_t hue = 0;
int i;
int c;
int sensorValue;

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical

  // FastLED.setBrightness(  BRIGHTNESS );

  //currentBlending = NOBLEND; 
  //currentBlending = LINEARBLEND;

  pinMode (Analog_Eingang, INPUT);
 
  Serial.begin (9600); // Serial output with 9600 bits per second

{
for(c=0; c<=NUM_LEDS; c++) {
// // // //  leds[c].setBrightness(0);
//leds[c].fadeLightBy(190);
//leds[c].nscale8( 192);

leds[c].setHue(hue+=5);
// leds[c].CHSV((hue+=5), 255, 150);

// //   leds[i].fadeLightBy(64);
// // //   //FastLED.clear();
// // // return 0;
}
// FastLED.show();
// }
}
}

uint16_t gHue = 0;
uint8_t  gHueDelta = 3;

void loop() {

  sensorValue = analogRead (Analog_Eingang);
  //Serial.println (sensorValue);

  int equalize = (sensorValue-480);


  gHue += gHueDelta; // compute new hue
  //gHue = gHue % 360; // bring hue back in range


  {for(i=0; i<=equalize && i <= NUM_LEDS; i++)
    {   
  //leds[i].fadeLightBy(30);
// leds[i].maximizeBrightness();
 leds[c] = CHSV(gHueDelta, 255, 200);
  // FastLED.setBrightness(250);
    // leds[i] = CRGB::Green;
    //  for(c=0; c<NUM_LEDS; c++) {
    //   leds[c].setHue(gHue+=5); }
    //currentBlending = LINEARBLEND;
      //  leds[i] = CRGB::Green;
     //Colouractive = true;
     } 
  }

  FastLED.show();
   //FastLED.delay(1000 / UPDATES_PER_SECOND);
    
  Serial.println(hue);
int b;
{for(b=0; b <=NUM_LEDS; b++) 
{
leds[c] =CHSV(gHueDelta, 255, 10);
//leds[b].nscale8( 192);
//leds[b].fadeToBlackBy( 192 );
// leds[c].CHSV((hue+=5), 255, 0);

//leds[b].fadeLightBy(250);
//FastLED.setBrightness(5);
}
}
  FastLED.show();
  

}
