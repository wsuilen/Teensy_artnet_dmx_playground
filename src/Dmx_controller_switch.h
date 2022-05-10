#ifndef DMX_CONTROLLER_SWITCH_H
#define  DMX_CONTROLLER_SWITCH_H

#include <FastLED.h>
#include <Artnet.h>
#include <Ledstrip.h>

class Dmx_controller_switch {
    public: 

    void set_leds_by_artnet(Artnet& artnet, CRGB * leds);
};

#endif