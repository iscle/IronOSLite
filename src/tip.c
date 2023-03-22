#include "tip.h"
#include "gpio.h"
#include "adc.h"

void tip_early_init(void) {
    P34 = 0;
    gpio_set_mode(3, 4, GPIO_MODE_PUSH_PULL);
}

void tip_init(void) {
    gpio_set_mode(1, 1, GPIO_MODE_HIGH_IMPEDANCE);
    gpio_set_digital(1, 1, 0);

    gpio_set_mode(1, 6, GPIO_MODE_HIGH_IMPEDANCE);
    gpio_set_digital(1, 6, 0);
}

uint16_t tip_get_current(void) {
    return adc_read(1);
}

uint16_t tip_get_temp(void) {
    return adc_read(6);
}