#pragma once

#include <stdint.h>

void tip_early_init(void);

void tip_init(void);

uint16_t tip_get_current(void);

uint16_t tip_get_temp(void);