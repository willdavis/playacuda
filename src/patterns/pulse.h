#include "led_channels.h"
#include "color_wheel.h"

// colored stripes pulsing at a defined Beats-Per-Minute (BPM)
void pulse()
{
  uint8_t bpm = 62;
  uint8_t beat = beatsin8(bpm, 64, 255);
  CRGBPalette16 palette = PartyColors_p;

  for(int i = 0; i < SHORT_LENGTH_LEDS; i++) {
    tail_leds[i] = ColorFromPalette(palette, current_hue+(i*2), beat-current_hue+(i*10));
  }
}
