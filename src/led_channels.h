#ifndef LED_CHANNELS_H
#define LED_CHANNELS_H

#define COLOR_ORDER       GRB
#define CHIPSET           WS2811
#define MIN_BRIGHTNESS    50
#define MAX_BRIGHTNESS    200
#define FRAMES_PER_SECOND 60

#define SHORT_LENGTH_LEDS   30
#define MEDIUM_LENGTH_LEDS  45
#define LONG_LENGTH_LEDS    60
#define RIB_LENGTH_LEDS     23
#define TEETH_LENGTH_LEDS   7

CRGB tail_leds[SHORT_LENGTH_LEDS];
CRGB body_leds[LONG_LENGTH_LEDS];
CRGB lips_leds[MEDIUM_LENGTH_LEDS];
CRGB ribs_leds[RIB_LENGTH_LEDS];
CRGB teeth_leds[TEETH_LENGTH_LEDS];

#endif
