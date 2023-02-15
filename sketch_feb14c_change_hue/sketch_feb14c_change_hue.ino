#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 30
#define DATA_PIN 2
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

int Analog_Eingang = A5;
int i;
int a ;
int b;
int c;
uint16_t sensorValue;
//uint8_t hue = 0;
// static int hue = 0;
// uint16_t gHue = 0;
// uint8_t  gHueDelta = 3;

//Mittelwert berechnen
uint16_t storeValues[200];
int count = 0;
int avg;

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  pinMode (Analog_Eingang, INPUT);
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;
 // currentBlending = NOBLEND; 
Serial.begin (9600); // Serial output with 9600 bits per second

//for(c=0; c<NUM_LEDS; c++) {
//leds[c].setHue(hue+=5);
// }
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


// int size = 200; 
//if ( equalize <= NUM_LEDS) {equalize = (sensorValue-500);}
static int equalize = (sensorValue-avg);
Serial.println (sensorValue);

//the active LEDs change with the volume 
{
  for(i=0; i<=equalize && i < NUM_LEDS; i++)
  {   
  //  leds[i] = CRGB::Green;
    static uint8_t startIndex = 0;
    // startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);
  
  } 
}
  FastLED.show();

  for(b=0; b < NUM_LEDS; b++)
  {   
//  leds[b] = CRGB::Black;
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

//FUNKTION COLOUR
void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    int equalize = (sensorValue-avg);

    
    for( int i = 0;  i<=equalize && i < NUM_LEDS; ++i) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 5;
    }
}
