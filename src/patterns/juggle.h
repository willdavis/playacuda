#include "led_channels.h"

void juggle() {
  fadeToBlackBy(tail_leds, SHORT_LENGTH_LEDS, 20);

  byte dothue = 0;
  for(int i = 0; i < 8; i++) {
    tail_leds[beatsin16(i+7,0,SHORT_LENGTH_LEDS)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}
