/**
 * Playacuda
 */
#include "Arduino.h"
#include "FastLED.h"

#include "led_channels.h"
#include "color_wheel.h"

#include "patterns/fuego.h"
#include "patterns/pulse.h"
#include "patterns/juggle.h"
#include "patterns/confetti.h"

typedef void (*PatternList[])();
PatternList patterns = { fuego, juggle, confetti, pulse };

uint8_t patterns_size = 4;
uint8_t current_pattern = 0;

void next_pattern()
{
  current_pattern = (current_pattern + 1) % patterns_size;
}

void setup()
{
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, 3, COLOR_ORDER>(tail_leds, SHORT_LENGTH_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<CHIPSET, 4, COLOR_ORDER>(body_leds, LONG_LENGTH_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<CHIPSET, 5, COLOR_ORDER>(lips_leds, MEDIUM_LENGTH_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<CHIPSET, 6, COLOR_ORDER>(ribs_leds, RIB_LENGTH_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<CHIPSET, 8, COLOR_ORDER>(teeth_leds, TEETH_LENGTH_LEDS).setCorrection(TypicalLEDStrip);
}

void loop()
{
  patterns[current_pattern]();

  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);

  EVERY_N_SECONDS( 10 ) { next_pattern(); }
  EVERY_N_MILLISECONDS( 20 ) { current_hue++; }
}
