# ESP32 FreeRTOS Multitasking Demo

This project demonstrates basic multi-tasking on the ESP32 using FreeRTOS tasks (`xTaskCreate`), delays (`vTaskDelay`), and GPIO control within the ESP-IDF framework.

## Features
- **LED 1 Task:** Blinks an LED at a 500ms interval (Priority 6).
- **LED 2 Task:** Blinks an LED at a 1500ms interval (Priority 5).
- **Log Task:** Outputs system status logs via UART every 3000ms.
