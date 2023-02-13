#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 27
#define DATA_PIN 2
#define BRIGHTNESS 64
#define LED_TYPE    WS2811
// #define UPDATES_PER_SECOND 100

// variable used for the initial hue of the rainbow
  // we start it out at 0
  // but since it's static, it'll keep it's value as we change it
  static byte initialHue = 0;

  
// Define the array of leds
CRGB leds[NUM_LEDS];
//source: https://learn.microsoft.com/en-us/windows/win32/api/d3d12/ns-d3d12-d3d12_render_target_blend_desc
// //int BlendEnable = true; 
 // TBlendType    currentBlending;
// CRGBPalette16 currentPalette;

// Initialize sound sensor
int Analog_Eingang = A5;
//int8_t gHue = 0;
//static int8_t hue = 0;
int i;
int c;
int sensorValue;

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical

 FastLED.setBrightness(  BRIGHTNESS );

  //currentBlending = NOBLEND; 
  //currentBlending = LINEARBLEND;

  pinMode (Analog_Eingang, INPUT);
 
  Serial.begin (9600); // Serial output with 9600 bits per second

 {
  // int hue
for(c=0; c<=NUM_LEDS; c++) {
// // // //  leds[c].setBrightness(0);
//leds[c].fadeLightBy(190);
//leds[c].nscale8( 192);

  

// CHSV _targetHSV = rgb2hsv_approximate(leds[c]); // to use the current color of leds[0]
//   _targetHSV.h += 5;  // set the brightness 0 -> 100
//   leds[c] = _targetHSV.h; // update leds[0] with the HSV result

//leds[c].setHue(hue+=5);
//  leds[c].CHSV((hue+=5), 255, 150);

// //   leds[i].fadeLightBy(64);
// // //   //FastLED.clear();
// // // return 0;
// }
// FastLED.show();
// // }
// }


   initialHue = initialHue + 1;
   byte changeInHue = leds[c];   
  // byte changeInHue = 255 / NUM_LEDS;
  
  // // use FastLED to fill the LEDs with a rainbow
  // fill_rainbow(leds, NUM_LEDS, initialHue, changeInHue);
}
 }}


void loop() {

  sensorValue = analogRead (Analog_Eingang);
  Serial.println (sensorValue);

  int equalize = (sensorValue-500);
  //Serial.println (equalize);

 
  for(i=0; i<=equalize && i <= NUM_LEDS; i++)
    {  
      CHSV _targetHSV = rgb2hsv_approximate(leds[i]); // to use the current color of leds[0]
  _targetHSV.v = 100;  // set the brightness 0 -> 100
  leds[i] = _targetHSV; // update leds[0] with the HSV result

    }



  FastLED.show();
}

  //leds[i].fadeLightBy(30);
// leds[i].maximizeBrightness();
 //eds[i] = CHSV(hue, 255, v);
  // FastLED.setBrightness(250);
    // leds[i] = CRGB::Green;
    //  for(c=0; c<NUM_LEDS; c++) {
    //   leds[c].setHue(gHue+=5); }
    //currentBlending = LINEARBLEND;
      //  leds[i] = CRGB::Green;
     //Colouractive = true;
  //    } 
  // }

  // FastLED.show();
//    //FastLED.delay(1000 / UPDATES_PER_SECOND);
    
//   //Serial.println(hue);
// int b;
// {for(b=0; b <=NUM_LEDS; b++) 
// {
// // leds[b] =CHSV(hue, 255, v);
// //leds[b].nscale8( 192);
// //leds[b].fadeToBlackBy( 192 );
// // leds[c].CHSV((hue+=5), 255, 0);
// //leds[b].fadeLightBy(250);
// //FastLED.setBrightness(5);
// }


//   FastLED.show();
  



