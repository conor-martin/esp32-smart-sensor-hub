// include/SensorData.h
#pragma once

struct SensorData {
    // Optional motion detection (PIR)
    bool motionDetected = false;

    // Optional environmental data (BME280)
    float temperature = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;

    // Optional light level (BH1750)
    float lightLevel = 0.0f;
};
