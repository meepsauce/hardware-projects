
#include <FastLED_NeoPixel.h>

// How many LEDs are attached to the Arduino?
#define NUM_LEDS 4

// LED brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50


FastLED_NeoPixel<8, 1, NEO_GRB> strip1;
FastLED_NeoPixel<NUM_LEDS, 2, NEO_GRB> strip2;
FastLED_NeoPixel<NUM_LEDS, 8, NEO_GRB> strip3;
FastLED_NeoPixel<NUM_LEDS, 9, NEO_GRB> strip4;
FastLED_NeoPixel<NUM_LEDS, 10, NEO_GRB> strip5;


void setup() {
  strip1.begin();  // initialize strip (required!)
  

  strip2.begin();  // initialize strip (required!)
  
  strip3.begin();  // initialize strip (required!)
  

   strip4.begin();  // initialize strip (required!)
  

   strip5.begin();  // initialize strip (required!)


  strip1.setBrightness(BRIGHTNESS);
strip2.setBrightness(BRIGHTNESS);
  strip3.setBrightness(BRIGHTNESS);
  strip4.setBrightness(BRIGHTNESS);
  strip5.setBrightness(BRIGHTNESS);
}


void loop() {
 
    colorWipe(strip1.Color(255, 0, 0), 25);  // red
    colorWipe(strip1.Color(0, 255, 0), 25);  // green
    colorWipe(strip1.Color(0, 0, 255), 25);  // blue
 
  
    theaterChase(strip1.Color(0, 255, 255), 100, 3, 5);  // cyan
    theaterChase(strip1.Color(255, 0, 255), 100, 3, 5);  // magenta
    theaterChase(strip1.Color(255, 255, 0), 100, 3, 5);  // yellow
  
    rainbow(10, 3);
    
    //blank(1000);
  
}


void colorWipe(uint32_t color, unsigned long wait) {
	for (unsigned int i = 0; i < strip1.numPixels(); i++) {
		strip1.setPixelColor(i, color);
		strip1.show();

     strip2.setPixelColor(i, color);
     strip2.show();

     strip3.setPixelColor(i, color);
   strip3.show();

   strip4.setPixelColor(i, color);
   strip4.show();

   strip5.setPixelColor(i, color);
   strip5.show();

		delay(wait);
	}
}

void theaterChase(uint32_t color, unsigned long wait, unsigned int groupSize, unsigned int numChases) {
	for (unsigned int chase = 0; chase < numChases; chase++) {
		for (unsigned int pos = 0; pos < groupSize; pos++) {
			strip1.clear(); 
			strip2.clear();
			strip3.clear();
			strip4.clear();
			strip5.clear();// turn off all LEDs
      
			for (unsigned int i = pos; i < strip1.numPixels(); i += groupSize) {
				strip1.setPixelColor(i, color);  // turn on the current group
        strip2.setPixelColor(i, color);  // turn on the current group
        strip3.setPixelColor(i, color);  // turn on the current group
        strip4.setPixelColor(i, color);  // turn on the current group
        strip5.setPixelColor(i, color);  // turn on the current group
    
			}
			strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
      
			delay(wait);
		}
	}
}


void rainbow(unsigned long wait, unsigned int numLoops) {
	for (unsigned int count = 0; count < numLoops; count++) {
		// iterate through all 8-bit hues, using 16-bit values for granularity
		for (unsigned long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
			for (unsigned int i = 0; i < strip1.numPixels(); i++) {
				unsigned long pixelHue = firstPixelHue + (i * 65536UL / strip1.numPixels()); // vary LED hue based on position
				strip1.setPixelColor(i, strip1.ColorHSV(pixelHue));  // assign color, using gamma curve for a more natural look
        strip2.setPixelColor(i, strip1.ColorHSV(pixelHue));  // assign color, using gamma curve for a more natural look
        strip3.setPixelColor(i, strip1.ColorHSV(pixelHue));  // assign color, using gamma curve for a more natural look
        strip4.setPixelColor(i, strip1.ColorHSV(pixelHue));  // assign color, using gamma curve for a more natural look
        strip5.setPixelColor(i, strip1.ColorHSV(pixelHue));  // assign color, using gamma curve for a more natural look
        
			}
			strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
   
			delay(wait);
		}
	}
}
