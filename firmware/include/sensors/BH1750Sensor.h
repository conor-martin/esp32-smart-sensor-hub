#  pragma once

# include "interfaces/ISensor.h"

class BH1750Sensor : public ISensor {
public:
    void init() override;
    SensorData read() override;
    ~BH1750Sensor() override = default;
private:
    // Replace with actual sensor library object later
    // e.g., BH1750 bh1750;
    bool isInitialized = false;
};