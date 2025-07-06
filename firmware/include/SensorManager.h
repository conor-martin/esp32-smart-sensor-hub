// include/SensorManager.h
#pragma once
#include "interfaces/ISensor.h"
#include <vector>

class SensorManager {
public:
    explicit SensorManager(const std::vector<ISensor*>& sensors);
    void initAll();
    SensorData read_all();

private:
    std::vector<ISensor*> sensors;
};
