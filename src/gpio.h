#pragma once

#include <stdint.h>

#define GPIO_MODE_QUASI_BIDIRECTIONAL   0x00
#define GPIO_MODE_PUSH_PULL             0x01
#define GPIO_MODE_HIGH_IMPEDANCE        0x02
#define GPIO_MODE_OPEN_DRAIN            0x03

void gpio_set_mode(uint8_t port, uint8_t pin, uint8_t mode);

void gpio_set_pull_up(uint8_t port, uint8_t pin, uint8_t pull_up);

void gpio_set_digital(uint8_t port, uint8_t pin, uint8_t digital);

void gpio_set_value(uint8_t port, uint8_t pin, uint8_t value);

uint8_t gpio_get_value(uint8_t port, uint8_t pin);

void gpio_set_i2c_pins(uint8_t i2c_pins);