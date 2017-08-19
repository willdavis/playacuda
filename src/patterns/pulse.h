#include "led_channels.h"
#include "color_wheel.h"

// colored stripes pulsing at a defined Beats-Per-Minute (BPM)
void pulse()
{
  uint8_t beat = beatsin8(62, 64, 255);
  CRGBPalette16 palette = PartyColors_p;

  for(int i = 0; i < SHORT_LENGTH_LEDS; i++) {
    tail_leds[i] = ColorFromPalette(palette, current_hue+(i*2), beat-current_hue+(i*10));
  }

  for(int i = 0; i < LONG_LENGTH_LEDS; i++) {
    body_leds[i] = ColorFromPalette(palette, current_hue+(i*2), beat-current_hue+(i*10));
  }

  for(int i = 0; i < MEDIUM_LENGTH_LEDS; i++) {
    lips_leds[i] = ColorFromPalette(palette, current_hue+(i*2), beat-current_hue+(i*10));
  }

  for(int i=0; i < TEETH_LENGTH_LEDS; i++) {
    teeth_leds[i] = CRGB::Red;
  }

  for(int i=0; i < RIB_LENGTH_LEDS; i++) {
    ribs_leds[i] = CRGB::Blue;
  }
}
