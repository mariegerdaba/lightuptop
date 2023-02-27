#include <Adafruit_DotStar.h>

#define NUMPIXELS 6 
#define DATAPIN    2 
#define CLOCKPIN   A3

Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);



int Analog_Eingang = A5;
int Digital_Eingang = 5;

void setup ()
{

 pinMode (Analog_Eingang, INPUT);
 pinMode (Digital_Eingang, INPUT);

 Serial.begin (9600); // Serial output with 9600 bps
 strip.begin();
}


// The program reads the current value of the input pins
// and outputs it via serial out
void loop ()
{
 float Analog;
 int Digital;

 // Current value will be read and converted to voltage
 Analog = analogRead (Analog_Eingang) * (5.0 / 1023.0);
 Digital = digitalRead (Digital_Eingang);

  // Serial.print ("Analog voltage value:"); Serial.print (Analog, 4); Serial.print ("V, ");
// Serial.print ("Extreme value:");
 
 if(Digital==1)
 {
 Serial.println (" reached");
  strip.setPixelColor(0, 0xFF0000);
  strip.show();
//  delay(00);
 }
 
 else
 {
// Serial.println (" not reached yet");
 strip.setPixelColor(0, 0x000000);
 strip.show();
 }
// Serial.println ("----------------------------------------------------------------");
// delay (200);
}
