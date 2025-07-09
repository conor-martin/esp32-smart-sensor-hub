#include "sensors/BH1750Sensor.h"
#include <BH1750.h>
#include <Wire.h>
#include <Arduino.h>

namespace {
    BH1750 lightMeter;
}

void BH1750Sensor::init() {
    Wire.begin();  // SDA = GPIO21, SCL = GPIO22 by default
    if (lightMeter.begin()) {
        isInitialized = true;
        Serial.println("[BH1750] Initialized");
    } else {
        Serial.println("[BH1750] Failed to initialize");
    }
}

SensorData BH1750Sensor::read() {
    SensorData data;
    if (!isInitialized) {
        Serial.println("[BH1750] Not initialized!");
        return data;
    }

    float lux = lightMeter.readLightLevel();
    data.lightLevel = lux;

    Serial.printf("[BH1750] Light: %.2f lux\n", lux);
    return data;
}