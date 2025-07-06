// src/sensors/PIRSensor.cpp
#include "sensors/PIRSensor.h"
#include <Arduino.h>  // For Serial debug prints

void PIRSensor::init() {
    // In real code, initialize I2C and sensor here
    // e.g., isInitialized = pir.begin();

    Serial.println("[PIRSensor] init called (stub)");
    isInitialized = true;
}

SensorData PIRSensor::read() {
    SensorData data;
    if (!isInitialized) {
        Serial.println("[PIRSensor] Not initialized!");
        return data;
    }

    // In real code, read from PIR sensor
    // e.g., data.motionDetected = pir.detectMotion();
    data.motionDetected = false; // stub value

    Serial.println("[PIRSensor] Returning fake data");
    return data;
}
