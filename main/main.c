#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

void led_1(void *pvParameters)
{

    while (1)
    {

        gpio_set_level(12, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(12, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void led_2(void *pvParameters)
{

    while (1)
    {
        gpio_set_level(14, 1);
        vTaskDelay(pdMS_TO_TICKS(1500));
        gpio_set_level(14, 0);
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}

void log_message(void *pvParameters)
{

    while (1)
    {
        ESP_LOGI("SYSTEM", "System is active!");
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}

void app_main(void)
{
    gpio_config_t ledler = {
        .pin_bit_mask = (1ULL << 12) | (1ULL << 14),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE};
    gpio_config(&ledler);
    BaseType_t led_1_task = xTaskCreate(&led_1, "LED 1", 1024, NULL, 6, NULL);
    BaseType_t led_2_task = xTaskCreate(&led_2, "LED 2", 1024, NULL, 5, NULL);
    BaseType_t log_task = xTaskCreate(&log_message, "LOG", 1024, NULL, 5, NULL);

    if (led_1_task != pdPASS || led_2_task != pdPASS || log_task != pdPASS)
    {
        ESP_LOGE("Error!", "Error");
    }

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
