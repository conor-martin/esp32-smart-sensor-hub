// include/sensor.h

#ifndef SENSOR_H
#define SENSOR_H

#include "SensorData.h"

namespace sensor {
    void init();
    SensorData read_all();
}

#endif

