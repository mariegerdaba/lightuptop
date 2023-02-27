#include <FastLED.h>

#define NUM_LEDS 27

int Analog_Eingang = A5;
int sensorValue;


void setup() { 
  pinMode (Analog_Eingang, INPUT);
  Serial.begin (9600); // Serial output with 9600 bits per second
}

void loop() {
sensorValue = analogRead (Analog_Eingang);
Serial.println (sensorValue);
}
