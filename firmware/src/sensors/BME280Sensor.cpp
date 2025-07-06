#include "sensors/BME280Sensor.h"
#include <Arduino.h>  // For Serial debug prints

void BME280Sensor::init() {
    // In real code, initialize I2C and sensor here
    // e.g., isInitialized = bme.begin(0x76);

    Serial.println("[BME280Sensor] init called (stub)");
    isInitialized = true;
}

SensorData BME280Sensor::read() {
    SensorData data;

    if (!isInitialized) {
        Serial.println("[BME280Sensor] Not initialized!");
        return data;
    }

    // In real code, read from BME280
    // e.g., data.temperature = bme.readTemperature();

    data.temperature = 23.4f;
    data.humidity = 45.6f;
    data.pressure = 1012.3f;

    Serial.println("[BME280Sensor] Returning fake data");
    return data;
}
