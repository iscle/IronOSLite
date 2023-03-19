#pragma once

#include <stdint.h>

// The real 5v rail voltage measured at the output of the regulator
#define MEASURED_5V_MV 5000

// Max voltage supported by the function is 255 (25.5v)
uint8_t board_get_vin(void);