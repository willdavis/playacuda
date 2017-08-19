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

#define POWER_MODE_PIN 9

typedef void (*PatternList[])();
PatternList swimming_patterns = { fuego, juggle, confetti, pulse };
PatternList idle_pattern = { confetti };

uint8_t patterns_size = 4;
uint8_t current_pattern = 0;

void next_pattern()
{
  current_pattern = (current_pattern + 1) % patterns_size;
}

void setup()
{
  delay(3000); // sanity delay
  pinMode(POWER_MODE_PIN,INPUT_PULLUP);  // Power mode - LOW= Idle, HIGH= Swimming

  FastLED.addLeds<CHIPSET, 3, COLOR_ORDER>(tail_leds, SHORT_LENGTH_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<CHIPSET, 4, COLOR_ORDER>(body_leds, LONG_LENGTH_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<CHIPSET, 5, COLOR_ORDER>(lips_leds, MEDIUM_LENGTH_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<CHIPSET, 6, COLOR_ORDER>(ribs_leds, RIB_LENGTH_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<CHIPSET, 8, COLOR_ORDER>(teeth_leds, TEETH_LENGTH_LEDS).setCorrection(TypicalLEDStrip);
}

void loop()
{
  // check the power mode toggle switch
  // HIGH = swimming, LOW = idle
  if(digitalRead(POWER_MODE_PIN)) {
    swimming_patterns[current_pattern]();
  } else {
    idle_pattern[0]();
  }

  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);

  EVERY_N_SECONDS( 10 ) { next_pattern(); }
  EVERY_N_MILLISECONDS( 20 ) { current_hue++; }
}
