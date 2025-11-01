#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED1_GPIO 2
#define LED2_GPIO 4

// Task 1: Blink LED1
void led1_task(void *pvParameter)
{
    while (1)
    {
        gpio_set_level(LED1_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(LED1_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

// Task 2: Blink LED2 (different rate)
void led2_task(void *pvParameter)
{
    while (1)
    {
        gpio_set_level(LED2_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(300));
        gpio_set_level(LED2_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(300));
    }
}

void app_main(void)
{
    gpio_reset_pin(LED1_GPIO);
    gpio_set_direction(LED1_GPIO, GPIO_MODE_OUTPUT);

    gpio_reset_pin(LED2_GPIO);
    gpio_set_direction(LED2_GPIO, GPIO_MODE_OUTPUT);

    // Create tasks
    xTaskCreate(led1_task, "LED1 Task", 2048, NULL, 5, NULL);
    xTaskCreate(led2_task, "LED2 Task", 2048, NULL, 5, NULL);
}
