#include "Ledstrip.h"
#include <FastLED.h>

Ledstrip::Ledstrip(int _amount_of_leds, int _led_pin, uint8_t * _universes)
{
    amount_of_leds = _amount_of_leds;
    led_pin = _led_pin;
    CRGB leds[amount_of_leds];
    universes[0] = _universes[0];
    universes[1] = _universes[1];
}

Ledstrip::Ledstrip() {
    amount_of_leds = 13;
    led_pin = 7;
    leds[amount_of_leds];
    universes[0] = 1;
    universes[1] = 2;

}

CRGB * Ledstrip::get_leds() {
    return leds;
}

int Ledstrip::get_amount_of_leds() {
    return amount_of_leds;
}

uint8_t * Ledstrip::get_universe() {
    return universes;
}