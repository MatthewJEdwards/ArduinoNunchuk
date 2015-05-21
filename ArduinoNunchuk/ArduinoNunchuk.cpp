/*
 * ArduinoNunchuk.cpp - Improved Wii Nunchuk library for Arduino
 *
 * Original project copyright 2011-2013 Gabriel Bianconi, http://www.gabrielbianconi.com/
 *
 * Project URL: https://github.com/MatthewJEdwards/ArduinoNunchuk
 *
 */

#include <Arduino.h>
#include <Wire.h>
#include "ArduinoNunchuk.h"

#define ADDRESS 0x52

void ArduinoNunchuk::init() {
    uint8_t error;
    Wire.begin(); 
    error = ArduinoNunchuk::_sendByte(0x55, 0xF0);
    error += ArduinoNunchuk::_sendByte(0x00, 0xFB);
    if (error != 0) {
        // Error, nunchuk probably not connected
        isConnected = false;
        return;
    }
    isConnected = true;
    ArduinoNunchuk::update();
}

void ArduinoNunchuk::update() {
    uint8_t bytes_returned = 0;
    uint8_t count = 0;
    uint8_t values[6] = {0};
    uint8_t error = 0;

    bytes_returned = Wire.requestFrom(ADDRESS, 6);
    if (bytes_returned == 0) {
        // Error, nunchuk probably not connected
        isConnected = false;
        return;
    }

    while(Wire.available()) {
        values[count] = Wire.read();
        count += 1;
    }

    ArduinoNunchuk::analogX = values[0];
    ArduinoNunchuk::analogY = values[1];
    ArduinoNunchuk::accelX = (values[2] << 2) | ((values[5] >> 2) & 3);
    ArduinoNunchuk::accelY = (values[3] << 2) | ((values[5] >> 4) & 3);
    ArduinoNunchuk::accelZ = (values[4] << 2) | ((values[5] >> 6) & 3);
    ArduinoNunchuk::zButton = !((values[5] >> 0) & 1);
    ArduinoNunchuk::cButton = !((values[5] >> 1) & 1);

    error = ArduinoNunchuk::_sendByte(0x00, 0x00);
    if (error != 0) {
        // Error, nunchuk probably not connected
        isConnected = false;
        return;
    }
}

/* Send a byte to the nunchuk, returning 0 for success or nonzero for error */
uint8_t ArduinoNunchuk::_sendByte(uint8_t data, uint8_t location) {
    uint8_t error = 0;
    Wire.beginTransmission(ADDRESS);
    Wire.write(location);
    Wire.write(data);
    error = Wire.endTransmission();
    delay(10);
    return error;
}
