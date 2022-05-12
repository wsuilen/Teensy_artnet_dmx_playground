#ifndef ARTNET_DATA_RETRIEVER_H
#define ARTNET_DATA_RETRIEVER_H

#include <Artnet.h>

class Artnet_data_retriever {
    private:
    Artnet artnet;
    byte ip[4] = {192, 168, 0, 199};                    // Teensy
    byte broadcast[4] = {192, 168, 0, 255};             // Broadcast address
    byte mac[6] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC}; // mac address

    public:
    Artnet& get_artnet();
    byte* get_ip();
    byte* get_broadcast();
    byte* get_mac();
};

#endif