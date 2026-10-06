#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h> // For printf

// Task A definition
void vTaskA(void *pvParameters) {
    for (;;) {
        printf("Task A running\n");
        vTaskDelay(pdMS_TO_TICKS(1000)); // Block for 1 second
    }
}

// Task B definition
void vTaskB(void *pvParameters) {
    for (;;) {
        printf("Task B running\n");
        vTaskDelay(pdMS_TO_TICKS(1500)); // Block for 1.5 seconds
    }
}

int main(void) {
    // STM32 Hardware Initialization (e.g., HAL_Init(), SystemClock_Config(), UART Init) must go here
    
    // Initial startup message required by Part II[cite: 20]
    printf("BCA182 FreeRTOS Multisensor\n");
    printf("System starting...\n");

    // Create the two simple tasks required by Part III[cite: 20]
    xTaskCreate(vTaskA, "Task A", 128, NULL, 1, NULL);
    xTaskCreate(vTaskB, "Task B", 128, NULL, 1, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    // The program should never reach this loop
    while (1) {
    }
}