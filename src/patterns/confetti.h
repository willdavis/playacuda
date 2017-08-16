#include "led_channels.h"
#include "color_wheel.h"

void confetti()
{
  fadeToBlackBy(tail_leds, SHORT_LENGTH_LEDS, 10);
  int pos = random16(SHORT_LENGTH_LEDS);
  tail_leds[pos] += CHSV(current_hue + random8(64), 200, 255);
}
