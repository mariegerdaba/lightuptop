// include FastLED library
#include <FastLED.h>

//number of LEDs in the strip
#define NUM_LEDS 30
// LED strip 1; right arm
#define DATA_PIN 2
// LED strip 2; left arm
#define DATA_PIN 7
#define BRIGHTNESS 100
#define LED_TYPE    WS2811
#define UPDATES_PER_SECOND 10
#define COLOR_ORDER GRB

// Define the array of leds
CRGB leds[NUM_LEDS];
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

//define variables
int Analog_Eingang = A5;
int i;
int a;
int b;

uint16_t sensorValue;

//calculate average
uint16_t storeValues[200];
int count = 0;
int avg;

void setup() {
  // power-up safety delay
  delay( 3000 ); 
  // GRB ordering is typical
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  
  pinMode (Analog_Eingang, INPUT);
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;
 //currentBlending = NOBLEND; 
 // Serial output with 9600 bits per second
 Serial.begin (9600); 
}


void loop() {
sensorValue = analogRead (Analog_Eingang);
//Serial.println (sensorValue);

// calculate average 
storeValues[count] = analogRead (Analog_Eingang);

  if (count < 199) {
    count++;
    } else {
    count = 0;

    avg = average(storeValues, 200);
    Serial.println(avg);
    }

static int equalize = (sensorValue-avg);
//Serial.println (sensorValue);

//the active LEDs change with the (music) volume 
{
  for(i=0; i<=equalize && i < NUM_LEDS; i++)
  {   
    static uint8_t startIndex = 0;
    // startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);
  
  } 
}
  FastLED.show();

// the inactive LEDs fade to black
  for(b=0; b < NUM_LEDS; b++)
  {   
  leds[b].fadeToBlackBy(10);
  } 
}

//function calculate average 
double average(int arr[], int size) {
  uint32_t sum = 0;                

   for (a = 0; a < size; ++a) {
      sum += arr[a];
   }
   return double(sum) / size;
}

//function colour, each LED has a different colour 
// Example from Fast LED Library, Github, https://github.com/FastLED/FastLED/blob/master/examples/ColorPalette/ColorPalette.ino

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    int equalize = (sensorValue-avg);
    for( int i = 0;  i<=equalize && i < NUM_LEDS; ++i) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 5;
        currentBlending = NOBLEND;
    }
}