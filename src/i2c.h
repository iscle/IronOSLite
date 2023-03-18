#pragma once

#include <stdint.h>

void i2c_init(void);

void i2c_read(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t len);

void i2c_write(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t len);

void i2c_write_byte(uint8_t addr, uint8_t reg, uint8_t data);

void i2c_read_byte(uint8_t addr, uint8_t reg, uint8_t *data);