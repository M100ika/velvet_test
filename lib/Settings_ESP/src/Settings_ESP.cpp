#include <Arduino.h>
#include "Settings_ESP.h"

String macToString(uint64_t mac) {
    char buf[20];
    snprintf(buf, sizeof(buf), "%04X%08X", (uint16_t)(mac >> 32), (uint32_t)mac);
    return String(buf);
}