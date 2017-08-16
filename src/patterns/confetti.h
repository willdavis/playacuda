#include "led_channels.h"
#include "color_wheel.h"

void confetti()
{
  fadeToBlackBy(tail_leds, SHORT_LENGTH_LEDS, 10);
  fadeToBlackBy(body_leds, LONG_LENGTH_LEDS, 10);
  fadeToBlackBy(lips_leds, MEDIUM_LENGTH_LEDS, 10);

  int short_pos = random16(SHORT_LENGTH_LEDS);
  int long_pos = random16(LONG_LENGTH_LEDS);
  int medium_pos = random16(MEDIUM_LENGTH_LEDS);

  tail_leds[short_pos] += CHSV(current_hue + random8(64), 200, 255);
  body_leds[long_pos] += CHSV(current_hue + random8(64), 200, 255);
  lips_leds[medium_pos] += CHSV(current_hue + random8(64), 200, 255);
}
