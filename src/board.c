#include "board.h"
#include "adc.h"

#define VIN_FACTOR ((10000 + 1000) / 1000)

uint8_t board_get_vin(void) {
    return (uint8_t) ((uint32_t) adc_read(0) * VIN_FACTOR * MEASURED_5V_MV / 4095 / 100);
}