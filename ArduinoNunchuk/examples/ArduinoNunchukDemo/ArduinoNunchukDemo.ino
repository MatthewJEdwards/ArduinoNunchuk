/*
 * ArduinoNunchukDemo.ino
 *
 * Original project copyright 2011-2013 Gabriel Bianconi, http://www.gabrielbianconi.com/
 *
 * Project URL: https://github.com/MatthewJEdwards/ArduinoNunchuk
 *
 */

#include <Wire.h>
#include <ArduinoNunchuk.h>

#define BAUDRATE 19200

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup() {
    Serial.begin(BAUDRATE);
    nunchuk.init();
}

void loop() {
    if (!nunchuk.isConnected) {
        Serial.println("No nunchuk connected");
        nunchuk.init();
        delay(100);
        return;
    }

    nunchuk.update();

    Serial.print(nunchuk.analogX, DEC);
    Serial.print(' ');
    Serial.print(nunchuk.analogY, DEC);
    Serial.print(' ');
    Serial.print(nunchuk.accelX, DEC);
    Serial.print(' ');
    Serial.print(nunchuk.accelY, DEC);
    Serial.print(' ');
    Serial.print(nunchuk.accelZ, DEC);
    Serial.print(' ');
    Serial.print(nunchuk.zButton, DEC);
    Serial.print(' ');
    Serial.println(nunchuk.cButton, DEC);
}
