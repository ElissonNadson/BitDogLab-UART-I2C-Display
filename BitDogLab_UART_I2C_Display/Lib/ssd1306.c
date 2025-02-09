#include "ssd1306.h"
#include "./src/fonts/font.h"
#include <string.h>

static uint8_t buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];
static i2c_inst_t *i2c_instance;

void ssd1306_init(i2c_inst_t *i2c) {
    i2c_instance = i2c;
    // Enviar comandos de inicialização para o display SSD1306
    uint8_t init_cmds[] = {
        0xAE,       // Display OFF
        0x20, 0x00, // Set Memory Addressing Mode
        0xB0,       // Set Page Start Address for Page Addressing Mode
        0xC8,       // COM Output Scan Direction
        0x00,       // Set low column address
        0x10,       // Set high column address
        0x40,       // Set start line address
        0x81, 0xFF, // Set contrast control register
        0xA1,       // Set segment re-map 0 to 127
        0xA6,       // Set normal display
        0xA8, 0x3F, // Set multiplex ratio (1 to 64)
        0xA4,       // Output RAM to display
        0xD3, 0x00, // Set display offset
        0xD5, 0xF0, // Set display clock divide ratio/oscillator frequency
        0xD9, 0x22, // Set pre-charge period
        0xDA, 0x12, // Set com pins hardware configuration
        0xDB, 0x20, // Set vcomh
        0x8D, 0x14, // Enable charge pump regulator
        0xAF        // Display ON
    };
    i2c_write_blocking(i2c_instance, SSD1306_I2C_ADDRESS, init_cmds, sizeof(init_cmds), false);
}

void ssd1306_clear() {
    memset(buffer, 0, sizeof(buffer));
}

void ssd1306_draw_pixel(uint8_t x, uint8_t y, bool color) {
    if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) return;
    if (color) {
        buffer[x + (y / 8) * SSD1306_WIDTH] |= (1 << (y % 8));
    } else {
        buffer[x + (y / 8) * SSD1306_WIDTH] &= ~(1 << (y % 8));
    }
}

void ssd1306_draw_string(uint8_t x, uint8_t y, const char *str) {
    while (*str) {
        for (uint8_t i = 0; i < 8; i++) {
            buffer[x + (y / 8) * SSD1306_WIDTH + i] = font[*str * 8 + i];
        }
        x += 8;
        str++;
    }
}

void ssd1306_display() {
    for (uint8_t page = 0; page < 8; page++) {
        uint8_t cmds[] = {0xB0 + page, 0x00, 0x10};
        i2c_write_blocking(i2c_instance, SSD1306_I2C_ADDRESS, cmds, sizeof(cmds), false);
        i2c_write_blocking(i2c_instance, SSD1306_I2C_ADDRESS, &buffer[SSD1306_WIDTH * page], SSD1306_WIDTH, false);
    }
}
