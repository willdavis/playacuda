#include "led_channels.h"
#include "color_wheel.h"

void confetti()
{
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( current_hue + random8(64), 200, 255);
}
