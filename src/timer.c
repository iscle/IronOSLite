#include "timer.h"
#include <stdint.h>
#include "stc8h.h"

#define T1_M(x) (((x) & 0x3) << 4)
#define T0_M(x) ((x) & 0x3)
#define TR0 (1 << 4)

#define T0_LOAD_VALUE (3036) // 40Hz

volatile uint8_t seconds = 0;

void timer_isr(void) __interrupt (TIMER0_VECTOR) {
    static volatile uint8_t count = 0;
    // Timer interrupts every 25ms, so 40 interrupts = 1 second
    if (count++ >= 40) {
        count = 0;
        seconds++;
    }
}

void timer_init(void) {
    TMOD = T1_M(3) | T0_M(0);
    TH0 = (T0_LOAD_VALUE >> 8) & 0xFF;
    TL0 = T0_LOAD_VALUE & 0xFF;
    EA = 1;
    ET0 = 1;
    TCON = TR0; // Enable timer
}