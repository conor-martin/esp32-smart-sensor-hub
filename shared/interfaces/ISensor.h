// shared/interfaces/ISensor.h
#pragma once

#include "../SensorData.h"

class ISensor {
public:
    virtual void init() = 0;
    virtual SensorData read() = 0;
    virtual ~ISensor() = default;
};