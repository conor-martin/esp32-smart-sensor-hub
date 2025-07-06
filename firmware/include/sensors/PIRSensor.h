// include/sensors/PIRSensor.h
#pragma once
#include "interfaces/ISensor.h"

class PIRSensor : public ISensor {
public:
    void init() override;
    SensorData read() override;
    ~PIRSensor() override = default;

private:
    // Replace with actual sensor library object later
    // e.g., PIR pir;
    bool isInitialized = false;
};
