//
// Created by FabianKlaffenboeck on 03/12/2023.
//

#include "EepromHandler.h"
#include "Arduino.h"
#include <EEPROM.h>
#include "../config.h"

void setupEeprom() {
    EEPROM.begin(12);
}

void storeConfig(LedStrip *pStrip) {
    EEPROM.write(RedAddr, pStrip->getColor().red);
    EEPROM.write(GreenAddr, pStrip->getColor().green);
    EEPROM.write(BlueAddr, pStrip->getColor().blue);
    EEPROM.write(BrightnessAddr, pStrip->getColor().brightness);
    EEPROM.write(StateAddr, pStrip->getState());
    EEPROM.commit();
}

void loadConfig(LedStrip *pStrip) {
    byte red = EEPROM.read(RedAddr);
    byte green = EEPROM.read(GreenAddr);
    byte blue = EEPROM.read(BlueAddr);
    byte brightness = EEPROM.read(BrightnessAddr);
    byte state = EEPROM.read(StateAddr);

    pStrip->setColor(Color{100, 0, 100, 255});
    pStrip->setState(state);
}

