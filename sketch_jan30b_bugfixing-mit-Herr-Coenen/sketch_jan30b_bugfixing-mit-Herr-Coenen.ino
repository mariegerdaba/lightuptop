
// 30.1.: Bugfixing mit Herr Coenen



#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 28
#define DATA_PIN 2
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];

// Initialize sound sensor
uint32_t Analog_Eingang = A5;
//int Digital_Eingang = 5;
uint32_t sensorValue; // variable to store the value coming from the sensor

//int threshold = 0;





void setup() { 
  
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   
  pinMode (Analog_Eingang, INPUT);
 
  Serial.begin (9600); // Serial output with 9600 bits per second
}



void loop() { 

 //float Analog;
  //int i;
//int equalize = (sensorValue*0.06-1); //
//negativ wert in positiven umrechnen
int equalize = (sensorValue-510);
int i;

  // Current value will be read 
  sensorValue = analogRead (Analog_Eingang);
  //Serial.println (sensorValue);


  //Serial.print ("Analog voltage value:"); Serial.print (Analog, 4); Serial.print ("V, ");
  //Serial.print ("Extreme value:");


  // Aanzahl der LEDs die leuchten == threshold value 


  //if (sensorValue > 500 && sensorValue < 700)
  {{
//    Serial.println (sensorValue);
    for(i=0; i<equalize && i <= 27; i++)
    {
    leds[i] = CRGB::Green;
}}
     FastLED.show();
     //i=0;
     FastLED.clear();
     //delay(1000);
  
}
 // else
  {
    Serial.println (sensorValue);
    for(i=0; i<27; i++)
    {
    leds[i] = CRGB::Black;
}

}
     FastLED.show();
  
}
  




  
  // Turn the LED on, then pause
 // leds[0] = CRGB::Red;
 // FastLED.show();
 // delay(500);
  // Now turn the LED off, then pause
 // leds[0] = CRGB::Black;
 // FastLED.show();
 // delay(500);