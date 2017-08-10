#ifndef LED_CHANNELS_H
#define LED_CHANNELS_H

#define COLOR_ORDER       GRB
#define CHIPSET           WS2811
#define NUM_LEDS          30
#define MIN_BRIGHTNESS    50
#define MAX_BRIGHTNESS    200
#define FRAMES_PER_SECOND 60

CRGB leds[NUM_LEDS];

#endif
