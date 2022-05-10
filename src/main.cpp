#include <Arduino.h>
#include <Artnet.h>
#include <FastLED.h>
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>
#include <SPI.h>
#include "Feedback.h"
#include "Dmx_controller.h"
#include "Dmx_controller_switch.h"
#include "Ledstrip.h"

const uint8_t ledpin = 7; // hoe krijg ik deze toegankelijk in classes?
#define NUM_LEDS 13
#define NUM_STRIPS 1

// Ledstrip ledstrip_1(13, 7);

// Ledstrip ledstrips[] = {ledstrip_1};
const int amount_of_leds = 13;
CRGB leds[amount_of_leds];

Artnet artnet;
byte ip[] = {192, 168, 0, 190};        // Teensy
byte broadcast[] = {192, 168, 0, 255}; // Broadcast address
byte mac[] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC};
uint16_t universe = 1;

int artnet_length = artnet.getLength();

Dmx_controller dmx_controller;
Dmx_controller_switch dmx_controller_switch;
Feedback feedback;

void setup()
{
  Serial.begin(115200);
  artnet.begin(mac, ip);
  artnet.setBroadcast(broadcast);

  FastLED.addLeds<1, WS2812B, 7, RGB>(leds, 13);
  FastLED.setBrightness(50);
  FastLED.setMaxPowerInVoltsAndMilliamps(12, 500);
  fill_solid(leds, 13, CRGB::Black);
  FastLED.show();
}

void loop()
{
  uint16_t incoming_packet = artnet.read();

  if (incoming_packet == ART_DMX && artnet.getUniverse() == universe)
  {
    dmx_controller_switch.set_leds_by_artnet(artnet, leds);
    // feedback.print_dmx_info(artnet);
  }
}
