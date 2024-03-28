//
// Created by FabianKlaffenboeck on 03/12/2023.
//

#ifndef RGBCONTROLLER_FIRMWARE_EEPROMHANDLER_H
#define RGBCONTROLLER_FIRMWARE_EEPROMHANDLER_H

#include "LedHandler.h"

void setupEeprom();

void storeConfig(LedStrip *pStrip);

void loadConfig(LedStrip *pStrip);

#endif //RGBCONTROLLER_FIRMWARE_EEPROMHANDLER_H
