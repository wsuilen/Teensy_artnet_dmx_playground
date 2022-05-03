#include <Arduino.h>
#include <Artnet.h>
#include <FastLED.h>
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>
#include <SPI.h>
#include "Feedback.h"
#include "Dmx_controller.h"
#include "Ledstrip.h"

const uint8_t ledpin = 7; // hoe krijg ik deze toegankelijk in classes?
int number_of_leds = 0;
#define NUM_LEDS number_of_leds
// #define NUM_STRIPS 1

// Ledstrip ledstrip_1(13, 7);

// Ledstrip ledstrips[] = {ledstrip_1};
const int amount_of_leds = 13;
CRGB leds[amount_of_leds];

Artnet artnet;
Artnet *artnet_ptr = &artnet;
byte ip[] = {192, 168, 0, 199};                    // Teensy
byte broadcast[] = {192, 168, 0, 255};             // Broadcast address
byte mac[] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC}; // mac address
uint16_t universe = 1;

int artnet_length = artnet.getLength();

Dmx_controller dmx_controller;
Feedback feedback;

void setup()
{
  Serial.begin(115200);
  artnet.begin(mac, ip);
  artnet.setBroadcast(broadcast);

  FastLED.addLeds<1, WS2812B, 7, RGB>(leds, number_of_leds);
  FastLED.setBrightness(50);
  FastLED.setMaxPowerInVoltsAndMilliamps(12, 500);
  fill_solid(leds, 13, CRGB::Black);
  FastLED.show();
}

int amount = 0;

void loop()
{
  uint16_t incoming_packet = artnet.read();
  ++amount;

  // if (incoming_packet == ART_POLL) { // checks if incoming_packet contains the art_net protocol
  //   Serial.println("Poll");
  // }


  if (incoming_packet == ART_DMX && artnet.getUniverse() == universe)
  {
    dmx_controller.set_leds_by_artnet(artnet, leds);
    // feedback.print_dmx_info(artnet);
  }
}

/*
Setup:
6 ledstrips
260 leds per strip

Elk universe heeft 512 channels -> 512/3 = 170 leds kunnen aangestuurd worden per universe
(6 * 260) / 170 = 9,18
Er zijn dus 10 universes nodig om alle data over te dragen (op een zo efficient mogelijke manier).

Aangezien een artnet packet 32768 DMX universes* kan verzenden, is er ruim voldoende capaciteit om 2 universes te gebruiken per ledstrip.
In dat geval gebruiken we 130 * 3 = 390 channels per universe.

* bron: https://en.wikipedia.org/wiki/Art-Net#:~:text=The%20protocol%20can%20address%2032768,networks%20with%20other%20addressing%20requirements.

*/