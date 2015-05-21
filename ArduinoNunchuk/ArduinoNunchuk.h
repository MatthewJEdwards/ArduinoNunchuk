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
    int analogX;
    int analogY;
    int accelX;
    int accelY;
    int accelZ;
    int zButton;
    int cButton;

    void init();
    void update();

private:
    void _sendByte(byte data, byte location);
};

#endif
