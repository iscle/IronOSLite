#include "i2c.h"
#include "gpio.h"
#include "stc8h.h"

// I2CCFG
#define ENI2C       (1 << 7)
#define MSSL        (1 << 6)
#define MSSPEED(x)  ((x) & 0x1F)

// I2CMSCR
#define EMSI                        (1 << 7)
#define MSCMD_STBY                  (0x0)
#define MSCMD_START                 (0x1)
#define MSCMD_SEND                  (0x2)
#define MSCMD_RECVACK               (0x3)
#define MSCMD_RECV                  (0x4)
#define MSCMD_SENDACK               (0x5)
#define MSCMD_STOP                  (0x6)
#define MSCMD_START_SEND_RECVACK    (0x9)
#define MSCMD_SEND_RECVACK          (0xA)
#define MSCMD_RECV_SENDACK          (0xB)
#define MSCMD_RECV_SENDNAK          (0xC)

// I2CMSAUX
#define WDTA    (1 << 0)

static void i2c_wait(void) {
    while (!(I2CMSST & 0x40));
    I2CMSST &= ~0x40;
}

void i2c_init(void) {
    I2CCFG = ENI2C | MSSL | MSSPEED(17); // MSSPEED = 17 => 395kHz @ FOSC = 30MHz
    I2CMSCR = MSCMD_STBY;
    I2CMSAUX = 0x00;
    gpio_set_pull_up(2, 4, 1);
    gpio_set_mode(2, 4, GPIO_MODE_OPEN_DRAIN);
    gpio_set_pull_up(2, 5, 1);
    gpio_set_mode(2, 5, GPIO_MODE_OPEN_DRAIN);
    gpio_set_i2c_pins(1);
}

void i2c_read(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t len) {

}

static void i2c_cmd(uint8_t cmd) {
    I2CMSCR = cmd;
    i2c_wait();
}

void i2c_write(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t len) {
    I2CMSAUX = WDTA; // Enable automatic transmission
    i2c_cmd(MSCMD_START);
    I2CTXD = addr << 1;
    i2c_wait();
    I2CTXD = reg;
    i2c_wait();
    while (len--) {
        I2CTXD = *(data++);
        i2c_wait();
    }
    I2CMSAUX = 0x00; // Disable automatic transmission
    i2c_cmd(MSCMD_STOP);
}

void i2c_write_byte(uint8_t addr, uint8_t reg, uint8_t data) {
    i2c_write(addr, reg, &data, 1);
}

void i2c_read_byte(uint8_t addr, uint8_t reg, uint8_t *data) {
    i2c_read(addr, reg, data, 1);
}