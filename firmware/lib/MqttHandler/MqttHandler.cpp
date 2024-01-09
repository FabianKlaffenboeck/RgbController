//
// Created by FabianKlaffenboeck on 03/12/2023.
//

#include "MqttHandler.h"
#include <WiFiClient.h>
#include "PubSubClient.h"
#include "../EepromHandler/EepromHandler.h"
#include "../WifiHandler/WifiHandler.h"
#include "ArduinoJson.h"
#include "../config.h"


LedStrip *pLedStrip = nullptr;
WiFiClient espClient;
PubSubClient client(espClient);
unsigned long UpdateTimeLast = 0;


void changeCallback(char *topic, byte *payload, unsigned int length) {
    StaticJsonDocument<255> doc;

    DeserializationError error = deserializeJson(doc, payload, length);
    if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
    }

    byte brightness = doc["brightness"]; // 255
    byte red = doc["red"]; // 255
    byte green = doc["green"]; // 255
    byte blue = doc["blue"]; // 255
    bool state = doc["state"]; // true

    pLedStrip->setColor(Color{brightness,red,green,blue});
    pLedStrip->setState(state);

}

void publishStatus() {
    StaticJsonDocument<255> doc;

    doc["brightness"] = pLedStrip->getColor().brightness;
    doc["red"] = pLedStrip->getColor().red;
    doc["green"] = pLedStrip->getColor().green;
    doc["blue"] = pLedStrip->getColor().blue;
    doc["state"] = pLedStrip->getState();

    String output;
    serializeJson(doc, output);

    client.publish(stateTopic, output.c_str());
}


void setupMqtt(LedStrip *pStrip) {
    pLedStrip = pStrip;
    client.setServer(mqttServer, mqttPort);
    client.setCallback(changeCallback);
}

bool connectToMqttServer() {
    unsigned long ConnTryStartTime = millis();

    while (!client.connected()) {
        Serial.println("Connecting to MQTT...");

        if (client.connect("", mqttUser, mqttPassword)) {
            Serial.println("connected");
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(1000);
        }
        if (millis() - ConnTryStartTime > emergCuttofTime) {
            return false;
        }
    }

    client.subscribe(cmdTopic);
    return true;
}

void mqttHandleLoop() {
    connectToMqttServer();
    client.loop();

    if (millis() - UpdateTimeLast > updateDuration) {
        UpdateTimeLast = millis();
        publishStatus();
    }
}
