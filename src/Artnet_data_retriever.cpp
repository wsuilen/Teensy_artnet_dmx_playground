# include "Artnet_data_retriever.h"

    Artnet& Artnet_data_retriever::get_artnet() {
        return artnet;
    }

    byte* Artnet_data_retriever::get_ip() {
        return ip;
    }

    byte* Artnet_data_retriever::get_broadcast() {
        return broadcast;
    }

    byte* Artnet_data_retriever::get_mac() {
        return mac;
    }