// module:  logging
// project: spook

#include "logging.ext.h"

#include <Arduino.h>

static void handle_format(const blc_01modules01logging_types01_Format& fmt) {
    if (fmt.colon) {
        Serial.print(':');
    } else if (fmt.comma) {
        Serial.print(',');
    }
    if (fmt.space) {
        Serial.print(' ');
    }
    if (fmt.newline) {
        Serial.println();
    }
    Serial.flush();
}

void spk_logging_log_int32(blc_int32 num, blc_01modules01logging_types01_Format* format) {
    Serial.printf("%d", num);
    handle_format(*format);
}

void spk_logging_log_nat32(blc_nat32 num, blc_01modules01logging_types01_Format* format) {
    Serial.printf("%ul", num);
    handle_format(*format);
}

void spk_logging_log_str(blc_01modules01string01_String* str, blc_01modules01logging_types01_Format* format) {
    Serial.printf("%s", (char*)(str->ptr));
    handle_format(*format);
}
