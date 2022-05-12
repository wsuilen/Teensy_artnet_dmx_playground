#include "Ledstrip_controller.h"

Ledstrip_controller::Ledstrip_controller()
{
  uint8_t universes1[] = {0, 1};
  uint8_t universes2[] = {2, 3};
  uint8_t universes3[] = {4, 5};
  uint8_t universes4[] = {6, 7};
  uint8_t universes5[] = {8, 9};
  uint8_t universes6[] = {10, 11};

  Ledstrip l1 = Ledstrip(13, 7, universes1);
  Ledstrip l2 = Ledstrip(13, 7, universes2);
  Ledstrip l3 = Ledstrip(13, 7, universes3);
  Ledstrip l4 = Ledstrip(13, 7, universes4);
  Ledstrip l5 = Ledstrip(13, 7, universes5);
  Ledstrip l6 = Ledstrip(13, 7, universes6);

  ledstrips[0] = l1;
  ledstrips[1] = l2;
  ledstrips[2] = l3;
  ledstrips[3] = l4;
  ledstrips[4] = l5;
  ledstrips[5] = l6;
}

// void Ledstrip_controller::add_ledstrip(Ledstrip &_ledstrip)
// {
//   for (size_t i = 0; i < 6; i++)
//   {
//     if (ledstrips[i].get_amount_of_leds() == NULL)
//     {
//       ledstrips[i] = _ledstrip;
//       break;
//     }
//   }
// }

void Ledstrip_controller::configure_fastled()
{
  for (size_t i = 0; i < 6; i++)
  {
    FastLED.addLeds<1, WS2812B, 7, RGB>(ledstrips[i].get_leds(), ledstrips[i].get_amount_of_leds());
    FastLED.setBrightness(50);
    FastLED.setMaxPowerInVoltsAndMilliamps(12, 500);
    fill_solid(ledstrips[i].get_leds(), ledstrips[i].get_amount_of_leds(), CRGB::Black);
    FastLED.show();
  }
}

void Ledstrip_controller::configure_artnet()
{
  artnet_data_retriever.get_artnet().begin(artnet_data_retriever.get_mac(), artnet_data_retriever.get_ip());
  artnet_data_retriever.get_artnet().setBroadcast(artnet_data_retriever.get_broadcast());
}

void Ledstrip_controller::set_leds_by_artnet()
{
  // So far only one ledstrip will be controlled. There needs to be a class for the handling of universes.
  Artnet artnet = artnet_data_retriever.get_artnet();

  uint16_t incoming_packet = artnet.read();
  int universe = ledstrips[0].get_universe()[0];

  // if (incoming_packet == ART_POLL) { // checks if incoming_packet contains the art_net protocol
  //   Serial.println("Poll");
  // }

  if (incoming_packet == ART_DMX && artnet.getUniverse() == universe)
  {
    uint16_t r = 0;
    uint16_t g = 0;
    uint16_t b = 0;
    int amount_of_rgb_leds = 3 * 13;

    uint16_t j = 0;

    for (int i = 0; i < amount_of_rgb_leds; ++i)
    {
      if (i % 3 == 0)
      {
        r = artnet.getDmxFrame()[i];
      }
      else if (i % 3 == 1)
      {
        g = artnet.getDmxFrame()[i];
      }
      else if (i % 3 == 2)
      {
        b = artnet.getDmxFrame()[i];
        ledstrips[0].get_leds()[j].setRGB(r, g, b);
        ++j;
      }
    }
    FastLED.show();
  }
}