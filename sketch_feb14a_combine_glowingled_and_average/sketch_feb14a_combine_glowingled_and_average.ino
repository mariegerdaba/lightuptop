#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 27
#define DATA_PIN 2
#define BRIGHTNESS 100
#define LED_TYPE    WS2811
#define UPDATES_PER_SECOND 10
#define COLOR_ORDER GRB

// Define the array of leds
CRGB leds[NUM_LEDS];

int Analog_Eingang = A5;
int i;
int a ;
int b;
int c;
uint16_t sensorValue;

//Mittelwert berechnen
uint16_t storeValues[200];
int count = 0;
int avg;

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  pinMode (Analog_Eingang, INPUT);
  FastLED.setBrightness(  BRIGHTNESS );
  Serial.begin (9600); // Serial output with 9600 bits per second
}

void loop() {
sensorValue = analogRead (Analog_Eingang);
Serial.println (sensorValue);

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
int equalize = (sensorValue-avg);
// Serial.println (equalize);
// show leds 
  for(i=0; i<=equalize && i < NUM_LEDS; i++)
  {   
 leds[i] = CRGB::Green;
  } 
  FastLED.show();
// delay (20);
  for(b=0; b< NUM_LEDS; b++)
  {   
 leds[b] = CRGB::Black;
  } 
}

double average(int arr[], int size) {
  uint32_t sum = 0;                

   for (a = 0; a < size; ++a) {
      sum += arr[a];
   }
   return double(sum) / size;
}