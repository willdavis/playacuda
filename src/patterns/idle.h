#include "led_channels.h"
#include "color_wheel.h"

// lazy pattern to save power
// used when POWER_MODE_PIN = LOW
void idle()
{
  uint8_t beat = beatsin8(62, 64, 255);
  CRGBPalette16 palette = PartyColors_p;
  CRGB color;

  fadeToBlackBy(teeth_leds, TEETH_LENGTH_LEDS, 20);
  fadeToBlackBy(ribs_leds, RIB_LENGTH_LEDS, 20);

  for(int i = 0; i < LONG_LENGTH_LEDS; i++) {
    color = ColorFromPalette(palette, current_hue+(i*2), beat-current_hue+(i*10));

    if(i < SHORT_LENGTH_LEDS){ tail_leds[i] = color; }
    if(i < MEDIUM_LENGTH_LEDS){ lips_leds[i] = color; }
    body_leds[i] = color;
  }
}
