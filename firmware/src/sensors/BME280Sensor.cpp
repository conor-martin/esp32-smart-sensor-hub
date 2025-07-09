// src/sensors/BME280Sensor.cpp

#include "sensors/BME280Sensor.h"
#include <Arduino.h>

void BME280Sensor::init() {
    if (!bme.begin(0x76)) {
        Serial.println("[BME280Sensor] Failed to initialize!");
        return;
    }
    isInitialized = true;
    Serial.println("[BME280Sensor] Initialized at 0x76");
}

SensorData BME280Sensor::read() {
    SensorData data;

    if (!isInitialized) {
        Serial.println("[BME280Sensor] Not initialized!");
        return data;
    }

    data.temperature = bme.readTemperature();
    data.humidity = bme.readHumidity();
    data.pressure = bme.readPressure() / 100.0F; // hPa
    Serial.printf("[BME280Sensor] Temp: %.2f°C, Hum: %.1f%%, Pressure: %.1f hPa\n",
                  data.temperature, data.humidity, data.pressure);
    return data;
}
