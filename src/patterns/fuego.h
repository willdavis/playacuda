#include "led_channels.h"
#include "color_wheel.h"

#define COOLING  55
#define SPARKING 120

byte heat[SHORT_LENGTH_LEDS];
CRGB heat_color;

// Fire2012 by Mark Kriegsman, July 2012
void fuego()
{
  fadeToBlackBy(body_leds, LONG_LENGTH_LEDS, 20);

  for(int i=0; i < MEDIUM_LENGTH_LEDS; i++) {
    lips_leds[i] = CRGB::Red;
  }

  // Step 1.  Cool down every cell a little
  for(int i = 0; i < SHORT_LENGTH_LEDS; i++) {
    heat[i] = qsub8(heat[i], random8(0, ((COOLING * 10) / SHORT_LENGTH_LEDS) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for(int k = SHORT_LENGTH_LEDS - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if(random8() < SPARKING) {
    int y = random8(7);
    heat[y] = qadd8(heat[y], random8(160,255));
  }

  // Step 4.  Map from heat cells to LED colors
  for(int j = 0; j < SHORT_LENGTH_LEDS; j++) {
    heat_color = HeatColor(heat[j]);

    tail_leds[j] = heat_color;
    body_leds[j] = heat_color;
  }
}
