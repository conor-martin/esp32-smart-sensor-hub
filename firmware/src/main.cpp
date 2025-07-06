// src/main.cpp

#include <Arduino.h>
#include "sensor.h"
#include "display.h"

void setup() {
    Serial.begin(115200);
    sensor::init();
    display::init();
}

void loop() {
    SensorData data = sensor::read_all();
    display::update(data);
    delay(1000);
}
