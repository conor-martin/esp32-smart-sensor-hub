// src/main.cpp

#include <Arduino.h>
#include "display.h"
#include <SensorManager.h>
#include "sensors/PIRSensor.h"
#include "sensors/BH1750Sensor.h"
#include "sensors/BME280Sensor.h"

SensorManager* manager;
bool lastMotion = false;

void setup() {
    Serial.begin(115200);
    display::init();
    display::show_splash("Booting...\nSystem Initialising...");

    static PIRSensor pir; // PIR sensor for motion detection
    static BH1750Sensor light; // Light sensor for ambient light level
    static BME280Sensor bme280;  // Sensor for temperature, humidity, and pressure
    static std::vector<ISensor*> sensors = { &pir, &light, &bme280 };

    static SensorManager mgr(sensors);
    manager = &mgr;

    for (auto* sensor : sensors) {
        sensor->init();
    }
    
    display::show_splash("System Ready!");
    delay(2000);  // show message for 2s before updating normally
}

void loop() {
    SensorData data = manager->read_all();

    // Update display with sensor data
    display::update(data);

    // Only log motion state changes
    if (data.motionDetected != lastMotion) {
        Serial.print("[Motion] ");
        Serial.println(data.motionDetected ? "Detected" : "Cleared");
        lastMotion = data.motionDetected;
    }
    delay(250);
}
