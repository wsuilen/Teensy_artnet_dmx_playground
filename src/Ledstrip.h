#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <FastLED.h>

class Ledstrip
{
private:
    int amount_of_leds;
    int led_pin;
    CRGB leds[13];
    uint8_t universes[2];

public:
    Ledstrip(int _amount_of_leds, int _led_pin, uint8_t * _universes);
    Ledstrip();
    int get_amount_of_leds();
    CRGB * get_leds();
    uint8_t * get_universe();
};

#endif