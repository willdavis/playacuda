/**
 * Playacuda
 */
#include "Arduino.h"
#include "FastLED.h"

#define COLOR_ORDER       GRB
#define CHIPSET           WS2811
#define NUM_LEDS          30
#define MIN_BRIGHTNESS    50
#define MAX_BRIGHTNESS    200
#define FRAMES_PER_SECOND 120

CRGB leds[NUM_LEDS];

void juggle() {
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16(i+7,0,NUM_LEDS)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}

void setup()
{
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, 5, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}

void loop()
{
  juggle();
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}
