// module:  delay
// project: spook

#ifndef SPK_DELAY_EXT_H
#define SPK_DELAY_EXT_H

#include "blech.h"

void spk_delay_set_ms_per_tick(blc_nat32 milliseconds);

blc_nat32 spk_delay_ticks_for_ms(blc_nat32 milliseconds);

#endif
