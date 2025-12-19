// project: Bling
// copyright: 2025, Framework Labs

#include <M5Capsule.h>
#include <Adafruit_NeoPixel.h>

extern "C" {
#include "app/app.h"
#include "modules/delay.ext.h"
}

// Setup and Loop

constexpr uint32_t MS_PER_TICK = 20; // 50 Hz

void setup() {
    setCpuFrequencyMhz(80);

    auto cfg = M5.config();
    cfg.serial_baudrate = 115200;
    M5Capsule.begin(cfg);

    spk_delay_set_ms_per_tick(MS_PER_TICK);

    blc_blech_01app01app01_init();
}

void loop() {
    TickType_t prevWakeTime = xTaskGetTickCount();

    while (true) {
        M5Capsule.update();
    
        blc_blech_01app01app01_tick();

        vTaskDelayUntil(&prevWakeTime, MS_PER_TICK);
    }
}
