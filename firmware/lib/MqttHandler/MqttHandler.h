//
// Created by FabianKlaffenboeck on 03/12/2023.
//

#ifndef RGBCONTROLLER_FIRMWARE_MQTTHANDLER_H
#define RGBCONTROLLER_FIRMWARE_MQTTHANDLER_H

#include "LedHandler.h"

void setupMqtt(LedStrip *pStrip);

void mqttHandleLoop();

#endif //RGBCONTROLLER_FIRMWARE_MQTTHANDLER_H
