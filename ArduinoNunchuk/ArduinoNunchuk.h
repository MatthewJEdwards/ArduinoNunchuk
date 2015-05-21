/*
 * ArduinoNunchuk.h - Improved Wii Nunchuk library for Arduino
 *
 * Original project copyright 2011-2013 Gabriel Bianconi, http://www.gabrielbianconi.com/
 *
 * Project URL: https://github.com/MatthewJEdwards/ArduinoNunchuk
 *
 */

#ifndef ArduinoNunchuk_H
#define ArduinoNunchuk_H

#include <Arduino.h>

class ArduinoNunchuk {
public:
    uint8_t analogX;
    uint8_t analogY;
    uint16_t accelX;
    uint16_t accelY;
    uint16_t accelZ;
    bool zButton;
    bool cButton;
    bool isConnected;

    void init();
    void update();

private:
    uint8_t _sendByte(uint8_t data, uint8_t location);
};

#endif
