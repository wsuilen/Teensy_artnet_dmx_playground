#include "Dmx_controller_switch.h"
#include "Ledstrip.h"

#include <FastLED.h>

void Dmx_controller_switch::set_leds_by_artnet(Artnet &artnet, CRGB *leds)
{
  uint16_t r = 0;
  uint16_t g = 0;
  uint16_t b = 0;
  int amount_of_rgb_leds = 3 * 13;

  uint16_t i = 0; // deze houdt bij waar we zijn in het artnet packet
  for (int j = 0; j < amount_of_rgb_leds; ++j)
  {
    for (int k = 0; k < 3; ++k)
    {
      switch (k)
      {
      case 0:
        r = artnet.getDmxFrame()[i];
        break;
      case 1:
        g = artnet.getDmxFrame()[i];
        break;
      case 2:
        b = artnet.getDmxFrame()[i];
        break;
      default:
        r = 0;
        g = 0;
        b = 0;
      }
      ++i;
    }
    leds[j].setRGB(r, g, b);
  }

  FastLED.show();
}