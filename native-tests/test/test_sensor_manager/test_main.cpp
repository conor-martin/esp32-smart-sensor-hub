#include <unity.h>
#include "SensorManager.cpp"
#include "SensorManager.h"
#include "MockSensor.h"

MockSensor mockPir, mockEnv, mockLight;
SensorManager* manager;


void setUp() {
    SensorData pir = { true, 0, 0, 0, 0 };
    SensorData env = { false, 21.5f, 40.0f, 1012.0f, 0 };
    SensorData light = { false, 0, 0, 0, 150.0f };

    mockPir.setTestData(pir);
    mockEnv.setTestData(env);
    mockLight.setTestData(light);

    std::vector<ISensor*> sensors = { &mockPir, &mockEnv, &mockLight };
    manager = new SensorManager(sensors);
}

void tearDown() {
    delete manager;
}

void test_sensor_manager_aggregates_data() {
    SensorData result = manager->read_all();

    TEST_ASSERT_TRUE(result.motionDetected);
    TEST_ASSERT_EQUAL_FLOAT(21.5f, result.temperature);
    TEST_ASSERT_EQUAL_FLOAT(40.0f, result.humidity);
    TEST_ASSERT_EQUAL_FLOAT(1012.0f, result.pressure);
    TEST_ASSERT_EQUAL_FLOAT(150.0f, result.lightLevel);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_sensor_manager_aggregates_data);
    return UNITY_END();
}

