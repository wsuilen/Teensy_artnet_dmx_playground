#ifndef LEDSTRIP_CONTROLLER_H
#define LEDSTRIP_CONTROLLER_H

#include <Artnet.h>
#include <FastLED.h>
#include "Ledstrip.h"
#include "Artnet_data_retriever.h"

class Ledstrip_controller
{
    Artnet_data_retriever artnet_data_retriever;
    Ledstrip ledstrips[6];

public:
    Ledstrip_controller();
    // void add_ledstrip(Ledstrip &_ledstrip);
    void configure_fastled();
    void configure_artnet();
    void set_leds_by_artnet();
};

#endif