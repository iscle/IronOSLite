#pragma once

#include <stdint.h>

#define ADC_VREF 5.0

void adc_init(void);

uint16_t adc_read(uint8_t ch);