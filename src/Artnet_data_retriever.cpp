#include "Artnet_data_retriever.h"
Artnet_data_retriever::Artnet_data_retriever()
{
    ip[0] = 192;
    ip[1] = 168;
    ip[2] = 0;
    ip[3] = 199;
    broadcast[0] = 192;
    broadcast[1] = 168;
    broadcast[2] = 0;
    broadcast[3] = 255;
    mac[0] = 0x04;
    mac[1] = 0xE9;
    mac[2] = 0xE5;
    mac[3] = 0x00;
    mac[4] = 0x69;
    mac[5] = 0xEC;
}

Artnet &Artnet_data_retriever::get_artnet()
{
    return * artnet;
}

byte *Artnet_data_retriever::get_ip()
{
    return ip;
}

byte *Artnet_data_retriever::get_broadcast()
{
    return broadcast;
}

byte *Artnet_data_retriever::get_mac()
{
    return mac;
}