#include <Arduino.h>
#include <Artnet.h>
#include <FastLED.h>
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>
#include <SPI.h>
#include "Feedback.h"
#include "Dmx_controller.h"

#define LED_PIN 7
#define NUM_LEDS 13
#define NUM_STRIPS 1

CRGB leds[NUM_LEDS]; // creates a CRGB representation for every led in an array

Artnet artnet;
byte ip[] = {192, 168, 0, 199};        // Teensy
byte broadcast[] = {192, 168, 0, 255}; // Broadcast address
byte mac[] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC};
uint16_t universe = 1;

uint8_t dmxFrame1 = 0;
uint8_t dmxFrame2 = 0;
uint8_t dmxFrame3 = 0;
uint8_t dmxFrame4 = 0;

int artnet_length = artnet.getLength();
int amount_of_rgb_leds = NUM_LEDS * 3;

Dmx_controller dmx_controller;
Feedback feedback;

int r = 0;
int g = 0;
int b = 0;

void setup()
{
  Serial.begin(115200);
  artnet.begin(mac, ip);
  artnet.setBroadcast(broadcast);

  // FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<NUM_STRIPS, WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  FastLED.setMaxPowerInVoltsAndMilliamps(12, 500);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  // FastLED.clear();
  FastLED.show();
}

void loop()
{

  uint16_t incoming_packet = artnet.read();

  // if (incoming_packet == ART_POLL) { // checks if incoming_packet contains the art_net protocol
  //   Serial.println("Poll");
  // }

  // hardcoded red leds
  int rgbred[39] = {255, 0, 0, 255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,};
  int rgbblue[39] = {0, 0, 255, 0, 0, 255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255, 0, 0,255};

  // for (int i = 0; i < 39; ++i)
  // {
  //   if (i % 3 == 0) {
  //     rgbs[i] = 255;
  //   } else {
  //     rgbs[i] = 0;
  //   }
  //   Serial.print(rgbs[i] + "\n");
    
  // }
  

  if (incoming_packet == ART_DMX && artnet.getUniverse() == universe)
  {

    int r = 0;
    int g = 0;
    int b = 0;

    int j = 0;

    for (int i = 0; i < amount_of_rgb_leds; ++i)
    {
      if (i % 3 == 0)
      {
        r = artnet.getDmxFrame()[i];
        // r = rgbblue[i];
      }
      else if (i % 3 == 1)
      {
        g = artnet.getDmxFrame()[i];
        // g = rgbblue[i];
      }
      else if (i % 3 == 2)
      {
        b = artnet.getDmxFrame()[i];
        // b = rgbblue[i];
        leds[j].setRGB(r, g, b);
        ++j;
      }
    }
    FastLED.show();

        
    Serial.print("universe number = ");
    Serial.print(artnet.getUniverse());
    Serial.print("\tdata length = ");
    Serial.print(artnet.getLength());
    Serial.print("\tsequence n0. = ");
    Serial.println(artnet.getSequence());
    Serial.print("DMX data: ");
    for (int i = 0 ; i < artnet.getLength() ; i++)
    {
      Serial.print(artnet.getDmxFrame()[i]);
      Serial.print("  ");
    }
    Serial.println();
    Serial.println();

    // dmx_controller.set_leds_by_artnet(leds, artnet);
    // feedback.print_dmx_info(artnet);
  }
}