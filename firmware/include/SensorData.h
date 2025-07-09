// include/SensorData.h
#pragma once

struct SensorData {
    // Motion detection (PIR)
    bool motionDetected = false;

    // Environmental data (BME280)
    float temperature = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;

    // Light level (BH1750)
    float lightLevel = 0.0f;
};
