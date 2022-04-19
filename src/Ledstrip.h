#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <FastLED.h>

class Ledstrip
{
private:
    int amount_of_leds;
    const int * led_pin;
    CRGB leds[];

public:
    Ledstrip(int _amount_of_leds, const int * led_pin);
    CRGB * get_leds();
    int get_amount_of_leds();
    void configure_fastled();
};

#endif