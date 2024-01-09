#include <Arduino.h>
#include <ArduinoOTA.h>
#include "../lib/WifiHandler/WifiHandler.h"
#include "../lib/MqttHandler/MqttHandler.h"
#include "../lib/EepromHandler/EepromHandler.h"
#include "../config.h"

LedStrip ledStrip(NUM_LEDS, LED_PIN);

void setup() {
    Serial.begin(9600);

    ArduinoOTA.begin();

    setupWifi();
    setupEeprom();
    setupMqtt(&ledStrip);
    loadConfig(&ledStrip);
}

void loop() {
    mqttHandleLoop();
    ArduinoOTA.handle();
}