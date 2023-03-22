#include "adc.h"
#include "stc8h.h"

// ADC_CONTR
#define ADC_POWER   (1 << 7)
#define ADC_START   (1 << 6)
#define ADC_FLAG    (1 << 5)
#define ADC_EPWM    (1 << 4)
#define ADC_CHS(x)  ((x) & 0x0F)

// ADCCFG
#define RESFMT  (1 << 5)
#define SPEED(x) ((x) & 0xF)

// ADCTIM
#define CSSETUP     (1 << 7)
#define CSHOLD(x)   (((x) & 0x3) << 5)
#define SMPDUTY(x)  ((x) & 0x1F)

void adc_init(void) {
    ADC_CONTR = ADC_POWER;
    ADCCFG = RESFMT | SPEED(11);
    ADCTIM = CSHOLD(1) | SMPDUTY(15);
}

uint16_t adc_read(uint8_t ch) {
    ADC_CONTR = (ADC_CONTR & ~ADC_CHS(0x0F)) | ADC_CHS(ch);
    ADC_CONTR |= ADC_START;
    while (!(ADC_CONTR & ADC_FLAG));
    ADC_CONTR &= ~ADC_FLAG;
    return ADC_RESH << 8 | ADC_RESL;
}