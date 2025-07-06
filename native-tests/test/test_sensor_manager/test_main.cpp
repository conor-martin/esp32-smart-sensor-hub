#include <unity.h>
#include "MockSensor.h"

void setUp(void) {}     // Unity expects this
void tearDown(void) {}  // Unity expects this

void test_always_passes() {
    TEST_ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_always_passes);
    return UNITY_END();
}

