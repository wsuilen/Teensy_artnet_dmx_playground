#ifndef ARTNET_DATA_RETRIEVER_H
#define ARTNET_DATA_RETRIEVER_H

#include <Artnet.h>

class Artnet_data_retriever {
    private:
    Artnet * artnet = new Artnet();
    byte ip[4];       
    byte broadcast[4];
    byte mac[6];    

    public:
    Artnet_data_retriever();
    Artnet& get_artnet();
    byte* get_ip();
    byte* get_broadcast();
    byte* get_mac();
};

#endif