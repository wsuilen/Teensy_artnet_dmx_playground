#ifndef FASTLED_H
#define  FASTLED_H

#include <FastLED.h>
#include <Artnet.h>

class Dmx_controller {
    public: 

    void set_leds_by_artnet(CRGB leds[], Artnet& artnet);
};

#endif