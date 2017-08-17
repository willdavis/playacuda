#include "led_channels.h"

void juggle() {
  fadeToBlackBy(tail_leds, SHORT_LENGTH_LEDS, 20);
  fadeToBlackBy(body_leds, LONG_LENGTH_LEDS, 20);
  fadeToBlackBy(lips_leds, MEDIUM_LENGTH_LEDS, 20);

  byte dothue = 0;
  for(int i = 0; i < 8; i++) {
    tail_leds[beatsin16(i+7,0,SHORT_LENGTH_LEDS)] |= CHSV(dothue, 200, 255);
    body_leds[beatsin16(i+7,0,LONG_LENGTH_LEDS)] |= CHSV(dothue, 200, 255);
    lips_leds[beatsin16(i+7,0,MEDIUM_LENGTH_LEDS)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }

  for(int i=0; i < TEETH_LENGTH_LEDS; i++) {
    teeth_leds[i] = CRGB::Green;
  }

  for(int i=0; i < RIB_LENGTH_LEDS; i++) {
    ribs_leds[i] = CHSV(current_hue, 200, 255);
  }
}
