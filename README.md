# FLN_DKESP
ESP8266 software for LED-Control in our darkroom (silk-screen printing)


## Software

This project is using some libraries using homie-esp8266. This is an implementation for auto-discovery capable MQTT convention.

See:

* https://github.com/homieiot/homie-esp8266    <-- The ESP866 homie implementation
* https://github.com/euphi/HomieNodeCollection <-- some useful "nodes" for homie-esp8266, this includes RGB strips and input pins as "contact"
* https://github.com/fablabnbg/ESP_HomieBME280Node <-- support for BME280 sensors
* https://github.com/euphi/HomieLoggerNode <-- logging mechanism

## Build

Build with platformio. Just install platformio and run `pio build`.
