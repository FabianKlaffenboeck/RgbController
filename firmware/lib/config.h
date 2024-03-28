//
// Created by FabianKlaffenboeck on 03/12/2023.
//

#ifndef RGBCONTROLLER_FIRMWARE_CONFIG_H
#define RGBCONTROLLER_FIRMWARE_CONFIG_H

#include <IPAddress.h>

//config neoPixel
#define LED_PIN 2
#define NUM_LEDS 36

// eeprom layout
#define RedAddr 0
#define GreenAddr 1
#define BlueAddr 2
#define BrightnessAddr 3
#define StateAddr 4

// MQTT Broker config
#define mqttServer "mqtt01.klaffenboeck.eu"
#define mqttPort 1883
#define mqttUser ""
#define mqttPassword ""

#define cmdTopic "home/lighting/bedroom/UnderBedLight/cmd"
#define stateTopic "home/lighting/bedroom/UnderBedLight/state"

#define emergCuttofTime 30000
#define updateDuration 5000

//Wifi Config
const char SSID[] = "Klaffenboeck_Wifi";
const char PWD[] = "31862025034211431218";
const IPAddress local_IP(192, 168, 188, 130);
const IPAddress gateway(192, 168, 188, 1);
const IPAddress subnet(255, 255, 255, 0);
const IPAddress primaryDNS(192, 168, 188, 102);

#endif //RGBCONTROLLER_FIRMWARE_CONFIG_H
