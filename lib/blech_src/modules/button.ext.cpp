// module:  button
// project: spook

#include "button.ext.h"

#include <M5Unified.hpp>

blc_bits32 spk_button_get_button_ptr(blc_nat8 num) {
    if (num == 0) {
        return (blc_bits32)&M5.BtnA;
    } else if (num == 1) {
        return (blc_bits32)&M5.BtnB;
    } else if (num == 2) {
        return (blc_bits32)&M5.BtnC;
    } else {
        return 0;
    }
}

blc_bool spk_button_was_pressed(blc_bits32 bptr) {
    m5::Button_Class& button = *(m5::Button_Class*)(bptr);
    return button.wasPressed();
}

blc_bool spk_button_was_released(blc_bits32 bptr) {
    m5::Button_Class& button = *(m5::Button_Class*)(bptr);
    return button.wasReleased();
}
