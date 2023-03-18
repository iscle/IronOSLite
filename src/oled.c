#include "oled.h"
#include "i2c.h"

// Define I2C Address
#define OLED_ADDR 0x3C

// Define Commands
#define OLED_CMD_DISPLAY_OFF 0xAE
#define OLED_CMD_DISPLAY_ON 0xAF
#define OLED_CMD_SET_COL_ADDRESS 0x21
#define OLED_CMD_SET_PAGE_ADDRESS 0x22
#define OLED_CMD_SET_START_LINE 0x40
#define OLED_CMD_SET_CONTRAST 0x81

extern void oled_clear(uint8_t state);

static void oled_cmd(uint8_t cmd) {
    i2c_write(OLED_ADDR, 0x00, &cmd, 1);
}

static void oled_data(uint8_t data) {
    i2c_write(OLED_ADDR, 0x40, &data, 1);
}

void oled_init(void) {
    oled_cmd(OLED_CMD_DISPLAY_OFF); // 0xAE
    oled_cmd(0x00); // Set lower column address
    oled_cmd(0x10); // Set higher column address
    oled_cmd(0x40); // Set display start line
    oled_cmd(0xB0); // Set page start address
    oled_cmd(0x81); // Set contrast
    oled_cmd(0xC5); // Contrast value (0 - 255)
    oled_cmd(0xA0); // Set segment re-map
    oled_cmd(0xA6); // Set normal display
    oled_cmd(0xA8); // Set multiple ratio
    oled_cmd(0x1F); // Multiplex ratio (15 to 63)
    oled_cmd(0xC0); // Set COM output scan direction
    oled_cmd(0xD3); // Set display offset
    oled_cmd(0x30); // Display offset value (0 - 63)
    oled_cmd(0xD5); // Set display clock divide ratio/oscillator frequency
    oled_cmd(0x80); // Display clock divide ratio/oscillator frequency value
    oled_cmd(0xD9); // Set pre-charge period
    oled_cmd(0x22); // Pre-charge period value (1 - 15)
    oled_cmd(0xDA); // Set COM pins hardware configuration
    oled_cmd(0x12); // COM pins hardware configuration value
    oled_cmd(0xDB); // Set VCOMH deselect level
    oled_cmd(0x20); // VCOMH deselect level value
    oled_cmd(0x8D); // Set charge pump enable/disable
    oled_cmd(0x15); // Charge pump enable/disable value
    oled_clear(0x00);
    oled_cmd(OLED_CMD_DISPLAY_ON);
}