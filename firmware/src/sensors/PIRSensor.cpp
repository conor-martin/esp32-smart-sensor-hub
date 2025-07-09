// src/sensors/PIRSensor.cpp
#include "sensors/PIRSensor.h"
#include <Arduino.h>  // For Serial debug prints

namespace {
    constexpr int PIR_PIN = 14;  // Adjust this if needed
    constexpr unsigned long MOTION_HOLD_TIME = 3000;  // ms
}

void PIRSensor::init() {
    pinMode(PIR_PIN, INPUT);
    delay(1000);  // Allow voltage to settle — increase this if needed
    isInitialized = true;
    Serial.println("[PIRSensor] Initialized on pin 14");
}

SensorData PIRSensor::read() {
    SensorData data;

    if (!isInitialized) {
        Serial.println("[PIRSensor] Not initialized!");
        return data;
    }
    
    int state = digitalRead(PIR_PIN);
    unsigned long now = millis();

    // debounce logic
    if (state == HIGH) {
        motionState = true;
        lastTriggerTime = now;
    }

    if (motionState && (now - lastTriggerTime > MOTION_HOLD_TIME)) {
        motionState = false;  // Reset after hold time
    }

    data.motionDetected = motionState;
    Serial.printf("[PIRSensor] Motion: %s\n", motionState ? "YES" : "NO");
    return data;
}
