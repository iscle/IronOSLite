#include "eeprom.h"

static __sfr __at (0xC2) IAP_DATA;
static __sfr __at (0xC3) IAP_ADDRH;
static __sfr __at (0xC4) IAP_ADDRL;
static __sfr __at (0xC5) IAP_CMD;
static __sfr __at (0xC6) IAP_TRIG;
static __sfr __at (0xC7) IAP_CONTR;
static __sfr __at (0xF5) IAP_TPS;

// IAP_CMD
#define CMD_IDLE    (0)
#define CMD_READ    (1)
#define CMD_WRITE   (2)
#define CMD_ERASE   (3)

// IAP_CONTR
#define IAPEN   (1 << 7)
#define SWBS    (1 << 6)
#define SWRST   (1 << 5)

void eeprom_init(void) {
    IAP_CONTR = IAPEN;
    IAP_TPS = 30; // CPU is running at 30MHz
}

void eeprom_write(uint16_t addr, uint8_t data) {
    IAP_ADDRH = (addr >> 8) & 0xFF;
    IAP_ADDRL = addr & 0xFF;
    IAP_DATA = data;
    IAP_CMD = CMD_WRITE;
    IAP_TRIG = 0x5A;
    IAP_TRIG = 0xA5;
    while (IAP_CONTR & SWBS);
}

uint8_t eeprom_read(uint16_t addr) {
    IAP_ADDRH = addr >> 8;
    IAP_ADDRL = addr & 0xFF;
    IAP_CMD = CMD_READ;
    IAP_TRIG = 0x5A;
    IAP_TRIG = 0xA5;
    while (IAP_CONTR & SWBS);
    return IAP_DATA;
}