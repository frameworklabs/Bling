// module:  logging
// project: spook

#include "neohex.ext.h"

#include <Adafruit_NeoPixel.h>

#define LED_PIN 13        // Pin connected to the LED data line

static Adafruit_NeoPixel strip(spk_neohex_NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
static blc_nat32 strip_buffer[spk_neohex_NUM_PIXELS];
static blc_bool is_overlay_active = false;

bool is_direct_layer(blc_nat8 layer) {
    if (is_overlay_active) {
        return layer == spk_neohex_OVERLAY_LAYER;
    } else {
        return layer == spk_neohex_MAIN_LAYER;
    }
}

void spk_neohex_init() {
    Serial.println("Initializing strip");
    strip.begin();
    strip.setBrightness(5);
    strip.clear();
}

void spk_neohex_set_overlay_active(blc_bool active) {
    if (active == is_overlay_active) {
        return;
    }
    is_overlay_active = active;
    if (is_overlay_active) {
        // Copy current strip colors to buffer
        for (blc_nat16 i = 0; i < spk_neohex_NUM_PIXELS; ++i) {
            strip_buffer[i] = strip.getPixelColor(i);
        }

        // And clear the strip for overlay drawing
        strip.clear();
        strip.show();
    } else {
        // Restore buffer to strip
        for (blc_nat16 i = 0; i < spk_neohex_NUM_PIXELS; ++i) {
            strip.setPixelColor(i, strip_buffer[i]);
        }
        strip.show();

        // And clear the buffer
        for (auto& col : strip_buffer) {
            col = 0;
        }
    }
}

void spk_neohex_clear(blc_nat8 layer) {
    if (!is_direct_layer(layer)) {
        for (auto& col : strip_buffer) {
            col = 0;
        }
        return;
    }
    strip.clear();
}

void spk_neohex_show(blc_nat8 layer) {
    if (!is_direct_layer(layer)) {
        return;
    }
    strip.show();
}

void spk_neohex_set_pixel_color(blc_nat16 pixel, blc_nat32 color, blc_nat8 layer) {
    if (!is_direct_layer(layer)) {
        strip_buffer[pixel] = color;
        return;
    }
    strip.setPixelColor(pixel, color);
}

blc_nat32 spk_neohex_get_pixel_color(blc_nat16 pixel, blc_nat8 layer) {
    if (!is_direct_layer(layer)) {
        return strip_buffer[pixel];
    }
    return strip.getPixelColor(pixel);
}

blc_nat32 spk_neohex_make_hsv(blc_nat16 hue, blc_nat8 sat, blc_nat8 val) {
    return Adafruit_NeoPixel::ColorHSV(hue, sat, val);
}
