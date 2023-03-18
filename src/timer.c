#include "timer.h"

static __sfr __at (0x88) TCON;
static __sfr __at (0x89) TMOD;
static __sfr __at (0x8A) TL0;
static __sfr __at (0x8B) TL1;
static __sfr __at (0x8C) TH0;
static __sfr __at (0x8D) TH1;
static __sfr __at (0x8E) AUXR;
static __sfr __at (0x8F) INTCLKO;
static __sfr __at (0xAA) WKTCL;
static __sfr __at (0xAB) WKTCH;
static __sfr __at (0xD1) T4T3M;
static __sfr __at (0xD2) T4H;
static __sfr __at (0xD3) T4L;
static __sfr __at (0xD4) T3H;
static __sfr __at (0xD5) T3L;
static __sfr __at (0xD6) T2H;
static __sfr __at (0xD7) T2L;
#define TM2PS   (*(__xdata volatile unsigned char *) 0xFEA2)
#define TM3PS   (*(__xdata volatile unsigned char *) 0xFEA3)
#define TM4PS   (*(__xdata volatile unsigned char *) 0xFEA4)

void timer_init(void) {
    // TODO
}