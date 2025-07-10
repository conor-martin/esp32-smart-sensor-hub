// include/sensors/BH1750Sensor.h

#pragma once
#include <ISensor.h>

class BH1750Sensor : public ISensor {
public:
    void init() override;
    SensorData read() override;
    ~BH1750Sensor() override = default;

private:
    bool isInitialized = false;
};