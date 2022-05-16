#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <FastLED.h>

class Ledstrip
{
private:
    int amount_of_leds;
    int led_pin;
    CRGB leds[13];
    int universes[2];

public:
    Ledstrip(int _amount_of_leds, int _led_pin, int * _universes);
    Ledstrip();
    int get_led_pin();
    int get_amount_of_leds();
    CRGB * get_leds();
    int * get_universe();
};

#endif