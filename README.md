# Teensy_artnet_dmx_playground

This is a project initiated by Sven de Hoog as part of the HBO-ICT program of the Fontys Hogeschool in Eindhoven (NL). Stakeholder for this project is Chagall. Chagall is a singer who uses technology to combine her movements and music into an audiovisual show: https://www.youtube.com/watch?v=GFd0C2PyoPc 

The code above - with the working title "Teensy Artnet DMX Playground" - was written as a challenge to improve functionality of the ledstrips that Chagall uses in her shows. We have been working with a Teensy 4.1 microcontroller. The controllers recieves DMX data via the Artnet protocol from (in her case) TouchDesigner. In the upcoming section I will give an explanation of how the code works.

# How does it work?

The Artnet_data_retriever class controls the incoming traffic. It has an Arnet object that can collect the incoming artnet data. It also holds variables for the IP, Broadcast and Mac address of the microcontroller.

The Ledstrip class contains all the necessary variables to represent each ledstrip that will be controlled per microcontroller. In this specific use case, we are testing with six ledstrips that each have 13 leds. At the moment they are hardcoded, but after succesfully testing the prototype and with keeping an eye on expansion of the code, we will create an interface in which they are manually adjustable. 

The Ledstrip_controller class is where the magic happens. It holds both the instances of Ledstrips and the Artnet_data_retriever. It then configures the FastLED (responsible for sending data to the leds) and Artnet (responsible for retrieving artnet data) external libraries. Then, it organises the incoming artnet data in a way that it can be sent directly to the leds. In main.cpp we  call the Ledstrip_controller methods for starting the process. There are a few serial prints for the sake of debugging.

Finally, we included a Feedback class to handle some more debugging, because we encountered some problems in the expected color output, versus the actual output.