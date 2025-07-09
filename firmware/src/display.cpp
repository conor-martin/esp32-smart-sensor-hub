// src/display.cpp

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "display.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Reset pin not used with I2C

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

namespace display {

    void init() {
        if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
            while (true) {
                // Loop forever if OLED init fails
            }
        }
        oled.clearDisplay();
        oled.setTextColor(SSD1306_WHITE);
        oled.display();
    }

    void update(const SensorData& data) {
        oled.clearDisplay();
        oled.setTextSize(1);
        oled.setCursor(0, 0);
        oled.setTextColor(SSD1306_WHITE);

        oled.print("Motion: ");
        oled.println(data.motionDetected ? "YES" : "NO");

        oled.display();
    }

    void show_splash(const char* message) {
        oled.clearDisplay();
        oled.setTextSize(1);
        oled.setCursor(0, 0);
        oled.setTextColor(SSD1306_WHITE);
        oled.println(message);
        oled.display();
}
}
