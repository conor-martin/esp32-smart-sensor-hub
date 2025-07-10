// SensorManager.cpp
#include "SensorManager.h"

SensorManager::SensorManager(const std::vector<ISensor*>& sensors)
    : sensors(sensors) {}

void SensorManager::initAll() {
    for (auto* sensor : sensors) {
        sensor->init();
    }
}

SensorData SensorManager::read_all() {
    SensorData aggregated;
    for (auto* sensor : sensors) {
        SensorData partial = sensor->read();

        if (partial.motionDetected) aggregated.motionDetected = true;
        if (partial.temperature != 0) aggregated.temperature = partial.temperature;
        if (partial.humidity != 0) aggregated.humidity = partial.humidity;
        if (partial.pressure != 0) aggregated.pressure = partial.pressure;
        if (partial.lightLevel != 0) aggregated.lightLevel = partial.lightLevel;
    }
    return aggregated;
}
