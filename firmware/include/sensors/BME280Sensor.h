#pragma once

#include "interfaces/ISensor.h"

class BME280Sensor : public ISensor {
public:
    void init() override;
    SensorData read() override;
    ~BME280Sensor() override = default;

private:
    // Replace with actual sensor library object later
    // e.g., Adafruit_BME280 bme;
    bool isInitialized = false;
};
