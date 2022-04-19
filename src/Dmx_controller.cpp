#include "Dmx_controller.h"
#include "Ledstrip.h"

#include <FastLED.h>

void Dmx_controller::set_leds_by_artnet(Artnet& artnet, CRGB * leds){
    // r: artnet.getDmxFrame() % 3 == 0
    // g: artnet.getDmxFrame() % 3 == 1
    // b: artnet.getDmxFrame() % 3 == 2

    uint16_t r = 0;
    uint16_t g = 0;
    uint16_t b = 0;
    int amount_of_rgb_leds = 3 * 13;

    uint16_t j = 0;

    for (int i = 0; i < amount_of_rgb_leds; ++i) {
      if (i % 3 == 0)
      {
        r = artnet.getDmxFrame()[i];
      }
      else if (i % 3 == 1)
      {
        g = artnet.getDmxFrame()[i];
      }
      else if (i % 3 == 2)
      {
        b = artnet.getDmxFrame()[i];
        leds[j].setRGB(r, g, b);
        ++j;
      }
    }
    
    FastLED.show();
}