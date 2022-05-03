#ifndef LEDSTRIP_CONTROLLER_H
#define LEDSTRIP_CONTROLLER_H

#include "Ledstrip.h"
#include <Artnet.h>
#include <FastLED.h>

class Ledstrip_controller {
    public:
    void configure_fastled(Ledstrip ledstrip);
    void configure_artnet(Ledstrip ledstrip, Artnet& artnet_ptr);
};

#endif