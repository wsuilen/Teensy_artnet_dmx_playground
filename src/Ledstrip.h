#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <FastLED.h>

class Ledstrip
{
private:
    int amount_of_leds;
    int * amount_of_leds_ptr;
    int led_pin;
    int * led_pin_ptr;
    CRGB leds[];

public:
    Ledstrip(const int _amount_of_leds, const int led_pin);
    CRGB * get_leds();
    int get_amount_of_leds();
    void configure_fastled();
};

#endif