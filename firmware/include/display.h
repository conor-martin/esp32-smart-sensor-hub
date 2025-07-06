// include/display.h

#ifndef DISPLAY_H
#define DISPLAY_H

#include "sensor.h"

namespace display {
    void init();
    void update(const SensorData& data);
}

#endif
