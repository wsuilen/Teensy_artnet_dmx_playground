#include "Ledstrip_controller.h"

void Ledstrip_controller::configure_fastled(Ledstrip ledstrip)
{
    FastLED.addLeds<1, WS2812B, 7, RGB>(ledstrip.get_leds(), ledstrip.get_amount_of_leds()); // 'this' cannot be used in a constant expressionC/C++(2435) ??
    FastLED.setBrightness(50);
    FastLED.setMaxPowerInVoltsAndMilliamps(12, 500);
    fill_solid(ledstrip.get_leds(), ledstrip.get_amount_of_leds(), CRGB::Black);
    FastLED.show();
}

void Ledstrip_controller::configure_artnet(Ledstrip ledstrip, Artnet &artnet_ptr)
{

}