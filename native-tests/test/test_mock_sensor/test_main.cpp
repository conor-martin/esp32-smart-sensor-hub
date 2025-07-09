#include <unity.h>
#include "MockSensor.h"
#include "../../src/MockSensor.cpp"

void setUp(void) {}     // Unity expects this
void tearDown(void) {}  // Unity expects this

void test_always_passes() {
    TEST_ASSERT_TRUE(true);
}

void test_mock_sensor_returns_expected_data() {
    MockSensor sensor;
    SensorData input = {
        .motionDetected = true,
        .temperature = 22.5f,
        .humidity = 55.0f,
        .pressure = 1012.0f,
        .lightLevel = 123.4f
    };

    sensor.setTestData(input);
    SensorData output = sensor.read();

    TEST_ASSERT_TRUE(output.motionDetected);
    TEST_ASSERT_EQUAL_FLOAT(22.5f, output.temperature);
    TEST_ASSERT_EQUAL_FLOAT(55.0f, output.humidity);
    TEST_ASSERT_EQUAL_FLOAT(1012.0f, output.pressure);
    TEST_ASSERT_EQUAL_FLOAT(123.4f, output.lightLevel);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_always_passes);
    RUN_TEST(test_mock_sensor_returns_expected_data);
    return UNITY_END();
}

