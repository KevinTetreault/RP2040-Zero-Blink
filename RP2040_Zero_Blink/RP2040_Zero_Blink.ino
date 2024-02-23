// Blink WS2812B LED on Waveshare RP2040 Zero board
// Requires Adafruit_NeoPixel library
#include <Adafruit_NeoPixel.h>

// Define pin used to drive WS2812B/NeoPixel
// PIN_NEOPIXEL is predefined pin for Waveshare RP2040 Zero (see Arduino_pins.h)
#define PIN PIN_NEOPIXEL

// Number of NeoPixels attached to the Arduino
#define NUMPIXELS 1 
#define DELAYVAL 500  // Blink time (ms)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  pixels.begin(); // Init NeoPixel strip object
  pixels.clear(); // Set all pixel colors to 'off'
}

void loop()
{
  uint8_t r = 0, g = 0, b = 0;
  static uint8_t iter = 0;

  switch (iter) {
    case 0:
      r = 150;
      break;

    case 1:
      g = 150;
      break;

    case 2:
      b = 150;
      break;
  }
  if (++iter > 2)   // increment from 0 - 2
    iter = 0;

  // pixels.setPixelColor() works with a string of LEDS, we have just 1 at position 0
  // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
  pixels.setPixelColor(0, pixels.Color(r, g, b));
  pixels.show();   // Send the updated pixel colors to the hardware
  delay(DELAYVAL);
}
