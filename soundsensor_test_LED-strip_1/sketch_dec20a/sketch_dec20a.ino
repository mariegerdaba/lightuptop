
#include <Adafruit_DotStar.h>
#include <SPI.h> 

#define NUMPIXELS 30 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN    A2
#define CLOCKPIN   A3
Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);


//  Declaration and initialization of the input pin

int Analog_Eingang = A0; // X-axis-signal
int Digital_Eingang = 3; // Button



void setup ()
{

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.



 pinMode (Analog_Eingang, INPUT);
 pinMode (Digital_Eingang, INPUT);

 Serial.begin (9600); // Serial output with 9600 bps
 
}
// The program reads the current value of the input pins
// and outputs it via serial out



void loop ()
{

 float Analog;
 int Digital;
   int      head  = 1; //tail = -10; // Index of first 'on' and 'off' pixels
  uint32_t color = 0xFF0000;      // 'On' color (starts red)
 // Current value will be read and converted to voltage
 
 Analog = analogRead (Analog_Eingang) * (5.0 / 1023.0);
 Digital = digitalRead (Digital_Eingang);

 //... and outputted here
// Serial.print ("Analog voltage value:"); Serial.print (Analog, 4); Serial.print ("V, ");
// Serial.print ("Extreme value:");
 if(Digital==1)
 {
 Serial.println (" reached");
// LED Strip ein
strip.setPixelColor(head, color); // 'On' pixel at head
//  strip.setPixelColor(tail, 0);     // 'Off' pixel at tail
//  strip.show();                     // Refresh strip
////  delay(20);                        // Pause 20 milliseconds (~50 FPS)
//
//  if(++head >= NUMPIXELS) {         // Increment head index.  Off end of strip?
//    head = 0;                       //  Yes, reset head index to start
//    if((color >>= 8) == 0)          //  Next color (R->G->B) ... past blue now?
//      color = 0xFF0000;             //   Yes, reset to red
//  }
//  if(++tail >= NUMPIXELS) tail = 0; // Increment, reset tail index
//  delay(2000);
 }

 
 else
 {
 Serial.println (" not reached yet");
// LED Strip aus
 }
 Serial.println ("----------------------------------------------------------------");
 delay (200);
}
