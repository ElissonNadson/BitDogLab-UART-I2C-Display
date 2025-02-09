#ifndef DISPLAY_H
#define DISPLAY_H

#include "ssd1306.h"

void display_init(i2c_inst_t *i2c);
void display_clear();
void display_draw_pixel(uint8_t x, uint8_t y, bool color);
void display_update();

#endif // DISPLAY_H
