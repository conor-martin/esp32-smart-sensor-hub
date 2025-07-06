#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

struct SensorData {
    bool motionDetected;
    float temperature;
    float humidity;
    float pressure;
    float lightLevel;
};

namespace sensor {
    void init();
    SensorData read_all();
}

#endif
