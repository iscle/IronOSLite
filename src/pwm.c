#include "pwm.h"
#include "stc8h.h"

#define ENO4P (1 << 6)
#define ARPEA (1 << 7)
#define CMSA(x) (((x) & 0x3) << 5)
#define CENA (1 << 0)
#define SMSA(x) ((x) & 0x7)
#define CC4P (1 << 5)
#define CC4E (1 << 4)
#define MOEn (1 << 7)
#define UGn (1 << 0)
#define OCxM_FORCE_LOW (4 << 4)
#define OCxM_PWM_MODE1 (6 << 4)
#define OCxPE (1 << 3)

void pwm_init(void) {
    PWMA_CCMR4 = OCxM_FORCE_LOW;
    PWMA_ENO = ENO4P;
    PWMA_CR1 = ARPEA | CMSA(0) | CENA;
    PWMA_SMCR = SMSA(0);
    PWMA_PSCR = 299;
    PWMA_ARR = 9999;
    PWMA_CCR4 = 5000;
    PWMA_CCER2 = CC4P | CC4E;
    PWMA_BRK = MOEn;
    PWMA_EGR |= UGn;
    PWMA_CCMR4 = OCxM_PWM_MODE1 | OCxPE;
}