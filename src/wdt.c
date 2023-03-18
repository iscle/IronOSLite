#include "wdt.h"

static __sfr __at (0xC1) WDT_CONTR;

#define EN_WDT (1 << 5)
#define CLR_WDT (1 << 4)
#define WDT_PS(x) ((x) & 0x07)

void wdt_init(void) {
    WDT_CONTR = EN_WDT | CLR_WDT | WDT_PS(6);
}

void wdt_reset(void) {
    WDT_CONTR |= CLR_WDT;
}