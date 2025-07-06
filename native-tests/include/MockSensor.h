#ifndef MOCKSENSOR_H
#define MOCKSENSOR_H

#include "SensorData.h"
#include "interfaces/ISensor.h"

class MockSensor : public ISensor {
public:
    void init() override {}
    SensorData read() override { return data; }

    void setTestData(const SensorData& testData) {
        data = testData;
    }

private:
    SensorData data;
};

#endif // MOCKSENSOR_H
