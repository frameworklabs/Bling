// module:  delay
// project: spook

#include "delay.ext.h"

static blc_nat32 g_ms_per_tick = 100;

void spk_delay_set_ms_per_tick(blc_nat32 ms_per_tick) {
    g_ms_per_tick = ms_per_tick;
}

blc_nat32 spk_delay_ticks_for_ms(blc_nat32 milliseconds) {
    return milliseconds / g_ms_per_tick;
}
