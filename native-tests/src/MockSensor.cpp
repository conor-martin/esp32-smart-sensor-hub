#include "MockSensor.h"

void MockSensor::init() {
    // No-op for mock
}

SensorData MockSensor::read() {
    return mockData;
}

void MockSensor::setTestData(const SensorData& data) {
    mockData = data;
}
