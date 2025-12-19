// module:  neohex
// project: spook

#ifndef SPK_NEOHEX_EXT_H
#define SPK_NEOHEX_EXT_H

#include "blech.h"

#ifdef __cplusplus
extern "C" {
#endif

#define spk_neohex_NUM_PIXELS 37
#define spk_neohex_MAIN_LAYER 0
#define spk_neohex_OVERLAY_LAYER 1

void spk_neohex_init();

void spk_neohex_set_overlay_active(blc_bool active);

void spk_neohex_clear(blc_nat8 layer);
void spk_neohex_show(blc_nat8 layer);

void spk_neohex_set_pixel_color(blc_nat16 pixel, blc_nat32 color, blc_nat8 layer);
blc_nat32 spk_neohex_get_pixel_color(blc_nat16 pixel, blc_nat8 layer);

blc_nat32 spk_neohex_make_hsv(blc_nat16 hue, blc_nat8 sat, blc_nat8 val);

#ifdef __cplusplus
}
#endif

#endif
