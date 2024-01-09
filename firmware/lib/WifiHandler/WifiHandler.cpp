//
// Created by FabianKlaffenboeck on 03/12/2023.
//

#include "WifiHandler.h"
#include <ESP8266WiFi.h>
#include "../config.h"

void setupWifi() {
    if (!WiFi.config(local_IP, gateway, subnet, primaryDNS)) {
        Serial.println("Failed to configure");
    }

    Serial.print("Connecting to ");
    Serial.println(SSID);

    WiFi.begin(SSID, PWD);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }

    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

const char * getIp(){
    return WiFi.localIP().toString().c_str();
};