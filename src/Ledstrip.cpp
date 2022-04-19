#include "Ledstrip.h"
#include <FastLED.h>

Ledstrip::Ledstrip(int _amount_of_leds, const int * _led_pin)
{
    amount_of_leds = _amount_of_leds;
    led_pin = _led_pin;
    CRGB leds[amount_of_leds];
    configure_fastled();
}

CRGB * Ledstrip::get_leds() {
    return leds;
}

int Ledstrip::get_amount_of_leds() {
    return amount_of_leds;
}

void Ledstrip::configure_fastled() {
// FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<1, WS2812B, 7, RGB>(leds, 13);
  FastLED.setBrightness(50);
  FastLED.setMaxPowerInVoltsAndMilliamps(12, 500);
  fill_solid(leds, amount_of_leds, CRGB::Black);
  FastLED.show();
}
