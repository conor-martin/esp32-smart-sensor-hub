// include/sensors/BME280Sensor.h

#pragma once
#include "interfaces/ISensor.h"
#include <Adafruit_BME280.h>

class BME280Sensor : public ISensor {
public:
    void init() override;
    SensorData read() override;
    ~BME280Sensor() override = default;

private:
    Adafruit_BME280 bme;
    bool isInitialized = false;
};
