#include "Dmx_controller.h"

#include <FastLED.h>

void Dmx_controller::set_leds_by_artnet(CRGB leds[], Artnet& artnet){
    // r: artnet.getDmxFrame() % 3 == 0
    // g: artnet.getDmxFrame() % 3 == 1
    // b: artnet.getDmxFrame() % 3 == 2

    for (int i = 0; i < artnet.getLength(); ++i) {
        int r = 0;
        int g = 0;
        int b = 0;

        if (artnet.getDmxFrame()[i] % 3 == 0) {
            r = artnet.getDmxFrame()[i];
        } else if (artnet.getDmxFrame()[i] % 3 == 1)
        {
            g = artnet.getDmxFrame()[i];
        } else if (artnet.getDmxFrame()[i] % 3 == 2) {
            b = artnet.getDmxFrame()[i];
        }

        leds[i] = CRGB(r, g, b);
        FastLED.show();
    }
}