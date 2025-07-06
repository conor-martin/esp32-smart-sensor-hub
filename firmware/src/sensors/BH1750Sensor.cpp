# include "sensors/BH1750Sensor.h"
#include <Arduino.h>  // For Serial debug prints

void BH1750Sensor::init() {
    // In real code, initialize I2C and sensor here
    // e.g., isInitialized = bh1750.begin();
    
    Serial.println("[BH1750Sensor] init called (stub)");
    isInitialized = true;
}

SensorData BH1750Sensor::read() {
    SensorData data;

    if (!isInitialized) {
        Serial.println("[BH1750Sensor] Not initialized!");
        return data;
    }

    // In real code, read from BH1750
    // e.g., data.lightIntensity = bh1750.readLightLevel();
    
    data.lightLevel = 150.0f;  // stub value

    Serial.println("[BH1750Sensor] Returning fake data");
    return data;
}