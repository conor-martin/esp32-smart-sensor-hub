#pragma once
#include <SensorData.h>
#include <ISensor.h>

class MockSensor : public ISensor {
public:
    void init() override;
    SensorData read() override;
    void setTestData(const SensorData& data);
    ~MockSensor() override = default;

private:
    SensorData mockData;
};
