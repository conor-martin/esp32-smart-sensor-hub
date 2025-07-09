// src/main.cpp

#include <Arduino.h>
#include "display.h"

void setup() {
    Serial.begin(115200);
    display::init();
}

void loop() {
    SensorData dummy;
    display::update(dummy);
    delay(2000);
}
