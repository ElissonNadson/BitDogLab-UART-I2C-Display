#include "display.h"

// Implementação das funções do display

void display_init(i2c_inst_t *i2c) {
    ssd1306_init(i2c);
}

void display_clear() {
    ssd1306_clear();
}

void display_draw_pixel(uint8_t x, uint8_t y, bool color) {
    ssd1306_draw_pixel(x, y, color);
}

void display_update() {
    ssd1306_display();
}
