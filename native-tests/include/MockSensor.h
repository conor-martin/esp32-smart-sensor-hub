#ifndef MOCKSENSOR_H
#define MOCKSENSOR_H

#include "sensor.h"

class MockSensor : public ISensor {
public:
    void init() override;
    SensorData read() override;
    void setTestData(const SensorData& data);
    ~MockSensor() override = default;
private:
    SensorData mockData;
};

#endif
