// module:  power
// project: spook

#include "power.ext.h"

#include <M5Capsule.h>

blc_nat8 spk_power_get_battery_level() {
    return M5Capsule.Power.getBatteryLevel();
}
