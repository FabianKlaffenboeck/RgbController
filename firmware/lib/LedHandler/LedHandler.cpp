//
// Created by FabianKlaffenboeck on 03/12/2023.
//

#include "LedHandler.h"

const Color &LedStrip::getColor() const {
    return color;
}

void LedStrip::setColor(const Color &color) {
    LedStrip::color = color;
    neoPixel.fill(Adafruit_NeoPixel::Color(color.red, color.green, color.blue));
    neoPixel.setBrightness(color.brightness);
    neoPixel.show();
}

bool LedStrip::getState() const {
    return state;
}

void LedStrip::setState(bool state) {
    LedStrip::state = state;
    if (state) {
        neoPixel.fill(Adafruit_NeoPixel::Color(color.red, color.green, color.blue));
        neoPixel.show();
    } else {
        neoPixel.fill(Adafruit_NeoPixel::Color(0, 0, 0));
        neoPixel.show();
    }
}

LedStrip::LedStrip(byte ledCnr, byte ledPin) {
    neoPixel = Adafruit_NeoPixel(ledCnr, ledPin, NEO_GRB + NEO_KHZ800);
    neoPixel.begin();
    neoPixel.fill(Adafruit_NeoPixel::Color(0, 0, 0));
    neoPixel.show();
}
