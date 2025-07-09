// include/sensors/PIRSensor.h
#pragma once
#include "interfaces/ISensor.h"

class PIRSensor : public ISensor {
public:
    void init() override;
    SensorData read() override;
    ~PIRSensor() override = default;

private:
    bool isInitialized = false;
    bool motionState = false;
    unsigned long lastTriggerTime = 0;
};
