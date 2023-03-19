#pragma once

#include <stdint.h>

/*  P0  */
__sbit __at (0x80) P00;
__sbit __at (0x81) P01;
__sbit __at (0x82) P02;
__sbit __at (0x83) P03;
__sbit __at (0x84) P04;
__sbit __at (0x85) P05;
__sbit __at (0x86) P06;
__sbit __at (0x87) P07;

/*  P1  */
__sbit __at (0x90) P10;
__sbit __at (0x91) P11;
__sbit __at (0x92) P12;
__sbit __at (0x93) P13;
__sbit __at (0x94) P14;
__sbit __at (0x95) P15;
__sbit __at (0x96) P16;
__sbit __at (0x97) P17;

/*  P2  */
__sbit __at (0xA0) P20;
__sbit __at (0xA1) P21;
__sbit __at (0xA2) P22;
__sbit __at (0xA3) P23;
__sbit __at (0xA4) P24;
__sbit __at (0xA5) P25;
__sbit __at (0xA6) P26;
__sbit __at (0xA7) P27;

/*  P3  */
__sbit __at (0xB0) P30;
__sbit __at (0xB1) P31;
__sbit __at (0xB2) P32;
__sbit __at (0xB3) P33;
__sbit __at (0xB4) P34;
__sbit __at (0xB5) P35;
__sbit __at (0xB6) P36;
__sbit __at (0xB7) P37;

/*  P5  */
__sbit __at (0xC8) P50;
__sbit __at (0xC9) P51;
__sbit __at (0xCA) P52;
__sbit __at (0xCB) P53;
__sbit __at (0xCC) P54;
__sbit __at (0xCD) P55;
__sbit __at (0xCE) P56;
__sbit __at (0xCF) P57;

#define GPIO_MODE_QUASI_BIDIRECTIONAL   0x0
#define GPIO_MODE_PUSH_PULL             0x1
#define GPIO_MODE_HIGH_IMPEDANCE        0x2
#define GPIO_MODE_OPEN_DRAIN            0x3

void gpio_set_mode(uint8_t port, uint8_t pin, uint8_t mode);

void gpio_set_pull_up(uint8_t port, uint8_t pin, uint8_t pull_up);

void gpio_set_digital(uint8_t port, uint8_t pin, uint8_t digital);

void gpio_set_value(uint8_t port, uint8_t pin, uint8_t value);

uint8_t gpio_get_value(uint8_t port, uint8_t pin);

void gpio_set_i2c_pins(uint8_t i2c_pins);