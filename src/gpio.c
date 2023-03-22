#include "gpio.h"
#include "stc8h.h"

void gpio_set_mode(uint8_t port, uint8_t pin, uint8_t mode) {
    switch (port) {
        case 0:
        P0M1 = (P0M1 & ~(1 << pin)) | (((mode >> 1) & 0x1) << pin);
        P0M0 = (P0M0 & ~(1 << pin)) | ((mode & 0x1) << pin);
        break;
        case 1:
        P1M1 = (P1M1 & ~(1 << pin)) | (((mode >> 1) & 0x1) << pin);
        P1M0 = (P1M0 & ~(1 << pin)) | ((mode & 0x1) << pin);
        break;
        case 2:
        P2M1 = (P2M1 & ~(1 << pin)) | (((mode >> 1) & 0x1) << pin);
        P2M0 = (P2M0 & ~(1 << pin)) | ((mode & 0x1) << pin);
        break;
        case 3:
        P3M1 = (P3M1 & ~(1 << pin)) | (((mode >> 1) & 0x1) << pin);
        P3M0 = (P3M0 & ~(1 << pin)) | ((mode & 0x1) << pin);
        break;
        case 4:
        P4M1 = (P4M1 & ~(1 << pin)) | (((mode >> 1) & 0x1) << pin);
        P4M0 = (P4M0 & ~(1 << pin)) | ((mode & 0x1) << pin);
        break;
        case 5:
        P5M1 = (P5M1 & ~(1 << pin)) | (((mode >> 1) & 0x1) << pin);
        P5M0 = (P5M0 & ~(1 << pin)) | ((mode & 0x1) << pin);
        break;
        case 6:
        P6M1 = (P6M1 & ~(1 << pin)) | (((mode >> 1) & 0x1) << pin);
        P6M0 = (P6M0 & ~(1 << pin)) | ((mode & 0x1) << pin);
        break;
        case 7:
        P7M1 = (P7M1 & ~(1 << pin)) | (((mode >> 1) & 0x1) << pin);
        P7M0 = (P7M0 & ~(1 << pin)) | ((mode & 0x1) << pin);
        break;
    }
}

void gpio_set_pull_up(uint8_t port, uint8_t pin, uint8_t pull_up) {
    switch (port) {
        case 0:
        P0PU = (P0PU & ~(1 << pin)) | ((pull_up & 0x1) << pin);
        break;
        case 1:
        P1PU = (P1PU & ~(1 << pin)) | ((pull_up & 0x1) << pin);
        break;
        case 2:
        P2PU = (P2PU & ~(1 << pin)) | ((pull_up & 0x1) << pin);
        break;
        case 3:
        P3PU = (P3PU & ~(1 << pin)) | ((pull_up & 0x1) << pin);
        break;
        case 4:
        P4PU = (P4PU & ~(1 << pin)) | ((pull_up & 0x1) << pin);
        break;
        case 5:
        P5PU = (P5PU & ~(1 << pin)) | ((pull_up & 0x1) << pin);
        break;
        case 6:
        P6PU = (P6PU & ~(1 << pin)) | ((pull_up & 0x1) << pin);
        break;
        case 7:
        P7PU = (P7PU & ~(1 << pin)) | ((pull_up & 0x1) << pin);
        break;
    }
}

void gpio_set_digital(uint8_t port, uint8_t pin, uint8_t digital) {
    switch (port) {
        case 0:
        P0IE = (P0IE & ~(1 << pin)) | ((digital & 0x1) << pin);
        break;
        case 1:
        P1IE = (P1IE & ~(1 << pin)) | ((digital & 0x1) << pin);
        break;
        case 2:
        P2IE = (P2IE & ~(1 << pin)) | ((digital & 0x1) << pin);
        break;
        case 3:
        P3IE = (P3IE & ~(1 << pin)) | ((digital & 0x1) << pin);
        break;
        case 4:
        P4IE = (P4IE & ~(1 << pin)) | ((digital & 0x1) << pin);
        break;
        case 5:
        P5IE = (P5IE & ~(1 << pin)) | ((digital & 0x1) << pin);
        break;
        case 6:
        P6IE = (P6IE & ~(1 << pin)) | ((digital & 0x1) << pin);
        break;
        case 7:
        P7IE = (P7IE & ~(1 << pin)) | ((digital & 0x1) << pin);
        break;
    }
}

void gpio_set_value(uint8_t port, uint8_t pin, uint8_t value) {
    switch (port) {
        case 0:
        P0 = (P0 & ~(1 << pin)) | ((value & 0x1) << pin);
        break;
        case 1:
        P1 = (P1 & ~(1 << pin)) | ((value & 0x1) << pin);
        break;
        case 2:
        P2 = (P2 & ~(1 << pin)) | ((value & 0x1) << pin);
        break;
        case 3:
        P3 = (P3 & ~(1 << pin)) | ((value & 0x1) << pin);
        break;
        case 4:
        P4 = (P4 & ~(1 << pin)) | ((value & 0x1) << pin);
        break;
        case 5:
        P5 = (P5 & ~(1 << pin)) | ((value & 0x1) << pin);
        break;
        case 6:
        P6 = (P6 & ~(1 << pin)) | ((value & 0x1) << pin);
        break;
        case 7:
        P7 = (P7 & ~(1 << pin)) | ((value & 0x1) << pin);
        break;
    }
}

uint8_t gpio_get_value(uint8_t port, uint8_t pin) {
    switch (port) {
        case 0:
        return (P0 >> pin) & 0x1;
        case 1:
        return (P1 >> pin) & 0x1;
        case 2:
        return (P2 >> pin) & 0x1;
        case 3:
        return (P3 >> pin) & 0x1;
        case 4:
        return (P4 >> pin) & 0x1;
        case 5:
        return (P5 >> pin) & 0x1;
        case 6:
        return (P6 >> pin) & 0x1;
        case 7:
        return (P7 >> pin) & 0x1;
        default:
        return 0;
    }
    return 0;
}

void gpio_set_i2c_pins(uint8_t i2c_pins) {
    P_SW2 = (P_SW2 & ~(0x3 << 4)) | ((i2c_pins & 0x3) << 4);
}
