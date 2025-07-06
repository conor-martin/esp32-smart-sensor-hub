# ESP32 Smart Sensor Hub

[![PlatformIO](https://img.shields.io/badge/platformio-esp32-blue.svg)](https://platformio.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A modular embedded systems project using an **ESP32** microcontroller to monitor motion, light intensity, and environmental conditions (temperature, humidity, pressure). Sensor data is displayed on a 0.96" OLED screen and structured for optional cloud connectivity via MQTT.

This project is built for clarity, modularity, and testability:

- All hardware logic is in the `firmware/` directory
- Fast, hardware-independent unit testing in `native-tests/`

---

## 📁 Project Structure

```text
esp32-smart-sensor-hub/
├── firmware/              # ESP32 PlatformIO project (Arduino framework)
│   ├── src/               # Embedded logic (sensors, display, etc.)
│   ├── include/           # Shared headers
│   ├── lib/               # Optional component libraries
│   └── platformio.ini     # ESP32 config
│
├── native-tests/          # PlatformIO project for native unit testing
│   ├── src/               # Testable modules (mock implementations, logic)
│   ├── include/           # Shared interfaces and test headers
│   ├── test/              # Unity-based test cases
│   └── platformio.ini     # Native test config
```

---

## 🚀 Goals

- 📦 Modular embedded firmware written in C++
- 🥪 Unit-testable logic using mock interfaces
- 🌱 Clean architecture for expansion (MQTT, OTA, power optimization)
- 🤖 CI-ready layout for scalable testing and deployment

---

## 🧰 Tech Stack

- [PlatformIO](https://platformio.org/)
- ESP32 DevKitC
- Arduino framework
- C++17
- [Unity test framework](https://github.com/ThrowTheSwitch/Unity) for native tests

---

## 🔧 Hardware (planned)

- ESP32 DevKitC (Type C)
- SSD1306 OLED Display (I2C)
- GY-BME280 (temperature, humidity, pressure)
- GY-302 BH1750 (light)
- HC-SR501 PIR (motion)

---

## 🥪 Native Testing Strategy

The `native-tests/` project runs host-side unit tests that validate embedded logic using mock sensor classes. This allows rapid feedback and CI/CD integration without requiring hardware.

---

## 📜 License

MIT License – see [LICENSE](LICENSE) for details.

---

## 👤 Author

**Conor Martin**  
[GitHub](https://github.com/conormartin) | [LinkedIn](https://www.linkedin.com/in/conormartin)
