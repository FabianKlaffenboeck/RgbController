//
// Created by FabianKlaffenboeck on 03/12/2023.
//

#ifndef RGBCONTROLLER_FIRMWARE_LEDHANDLER_H
#define RGBCONTROLLER_FIRMWARE_LEDHANDLER_H

#include <Adafruit_NeoPixel.h>

struct Color {
    byte brightness = 0;
    byte red = 0;
    byte green = 0;
    byte blue = 0;
};

class LedStrip {
    Adafruit_NeoPixel neoPixel;
    Color color;
    bool state = false;

public:
    LedStrip(byte ledCnr, byte ledPin);

    [[nodiscard]] const Color &getColor() const;

    void setColor(const Color &color);

    [[nodiscard]] bool getState() const;

    void setState(bool state);
};

#endif //RGBCONTROLLER_FIRMWARE_LEDHANDLER_H
