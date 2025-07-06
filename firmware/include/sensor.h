// include/sensor.h

#ifndef SENSOR_H
#define SENSOR_H

struct SensorData {
    bool motionDetected = false;
    float temperature = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;
    float lightLevel = 0.0f;
};

namespace sensor {
    void init();
    SensorData read_all();
}

#endif
