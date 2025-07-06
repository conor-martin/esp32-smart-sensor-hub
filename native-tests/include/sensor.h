#ifndef SENSOR_H
#define SENSOR_H

struct SensorData {
    bool motionDetected = false;
    float temperature = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;
    float lightLevel = 0.0f;
};

class ISensor {
public:
    virtual void init() = 0;
    virtual SensorData read() = 0;
    virtual ~ISensor() = default;
};

#endif
