#include "MockSensor.h"

void MockSensor::init() {
    // No-op for mock
}

SensorData MockSensor::read() {
    return data;
}

void MockSensor::setTestData(const SensorData& testData) {
    data = testData;
}
