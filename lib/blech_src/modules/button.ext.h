// module:  button
// project: spook

#ifndef SPK_BUTTON_EXT_H
#define SPK_BUTTON_EXT_H

#include "blech.h"

#ifdef __cplusplus
extern "C" {
#endif

blc_bits32 spk_button_get_button_ptr(blc_nat8 num);

blc_bool spk_button_was_pressed(blc_bits32 bptr);
blc_bool spk_button_was_released(blc_bits32 bptr);

#ifdef __cplusplus
}
#endif

#endif