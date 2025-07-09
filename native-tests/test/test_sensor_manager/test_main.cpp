#include <unity.h>
#include "SensorManager.h"
#include "MockSensor.h"
#include "../../src/MockSensor.cpp"
#include "../../firmware/src/SensorManager.cpp"


MockSensor* pir;
MockSensor* env;
MockSensor* light;
SensorManager* manager;

void setUp() {
    pir = new MockSensor();
    env = new MockSensor();
    light = new MockSensor();

    pir->setTestData({ .motionDetected = true });
    light->setTestData({ .lightLevel = 123.4f });
    env->setTestData({ .temperature = 24.0f, .humidity = 50.0f, .pressure = 1010.0f });

    std::vector<ISensor*> sensors = { pir, light, env };
    manager = new SensorManager(sensors);
}

void tearDown() {
    delete pir;
    delete env;
    delete light;
    delete manager;
}

void test_sensor_manager_reads_all() {
    SensorData data = manager->read_all();

    TEST_ASSERT_TRUE(data.motionDetected);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 123.4f, data.lightLevel);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 24.0f, data.temperature);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 50.0f, data.humidity);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 1010.0f, data.pressure);
}

int main(int argc, char** argv) {
    UNITY_BEGIN();
    RUN_TEST(test_sensor_manager_reads_all);
    return UNITY_END();
}
