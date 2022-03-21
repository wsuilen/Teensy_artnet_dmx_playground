#include <Arduino.h>
#include <Artnet.h>
#include <FastLED.h>
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>
#include <SPI.h>

#define LED_PIN 7
#define NUM_LEDS 13
#define NUM_STRIPS 1

CRGB leds[NUM_LEDS]; // creates a CRGB representation for every led in an array

Artnet artnet;
byte ip[] = {192, 168, 0, 199}; // Teensy
byte broadcast[] = {192, 168, 0, 255}; // Broadcast address
byte mac[] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC};
uint16_t universe = 1;

uint8_t dmxFrame1 = 0;
uint8_t dmxFrame2 = 0;
uint8_t dmxFrame3 = 0;
uint8_t dmxFrame4 = 0;

void setup() {
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

void loop() {
   
  uint16_t incoming_packet = artnet.read();

  if (incoming_packet == ART_POLL) { // checks if incoming_packet contains the art_net protocol
    Serial.println("Poll");
  }

    if (incoming_packet == ART_DMX && artnet.getUniverse() == universe) {
    // dmxFrame1 = artnet.getDmxFrame()[0];
    dmxFrame2 = artnet.getDmxFrame()[0];
    dmxFrame3 = artnet.getDmxFrame()[1];
    dmxFrame4 = artnet.getDmxFrame()[2];

    // FastLED.setBrightness(dmxFrame1);
    fill_solid(leds, NUM_LEDS, CRGB(dmxFrame2, dmxFrame3, dmxFrame4));
    FastLED.show();

    // print out our data
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
  }
}




// Het aan de praat krijgen van de Led-strip met FASTLED
// https://www.youtube.com/watch?v=rPvGLSuMaLA

// Maak verbinding met ethernet
// NativeEthernet.h
// https://forum.pjrc.com/threads/62400-Teensy-4-1-IP-Address