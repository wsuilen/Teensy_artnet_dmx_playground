#include <Arduino.h>
#include <Artnet.h>
#include <FastLED.h>
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>
#include <SPI.h>
#include "Feedback.h"
#include "Ledstrip_controller.h"

Ledstrip_controller ledstrip_controller;
Feedback feedback;

void setup()
{
  Serial.begin(115200);
  Serial.println("Setup");
  Serial.println("Configure Fastled\n");
  ledstrip_controller.configure_fastled();
  Serial.println("Configure Artnet\n");
  ledstrip_controller.configure_artnet();
  Serial.println("\nLoop\n");
}

void loop()
{
  ledstrip_controller.set_leds_by_artnet();
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