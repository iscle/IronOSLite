#include "wdt.h"
#include "stc8h.h"

#define EN_WDT (1 << 5)
#define CLR_WDT (1 << 4)
#define WDT_PS(x) ((x) & 0x07)

void wdt_init(void) {
    WDT_CONTR = EN_WDT | CLR_WDT | WDT_PS(6);
}

void wdt_reset(void) {
    WDT_CONTR |= CLR_WDT;
}