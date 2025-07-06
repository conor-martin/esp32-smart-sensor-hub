// src/sensor.cpp

#include "sensor.h"

namespace sensor {

    void init() {
        // TODO: Initialize real sensors (I2C, PIR pinMode, etc.)
    }

    SensorData read_all() {
        SensorData data;
        // TODO: Read from BME280, BH1750, PIR, etc.
        data.motionDetected = false;
        data.temperature = 21.0f;
        data.humidity = 50.0f;
        data.pressure = 1012.0f;
        data.lightLevel = 150.0f;
        return data;
    }

}
