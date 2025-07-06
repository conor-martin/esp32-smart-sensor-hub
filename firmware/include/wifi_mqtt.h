#ifndef WIFI_MQTT_H
#define WIFI_MQTT_H

#include "sensor.h"

namespace wifi_mqtt {
    void init();
    void publish(const SensorData& data);
}

#endif
