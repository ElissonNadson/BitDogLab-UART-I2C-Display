#ifndef WS2812_H
#define WS2812_H

#include "hardware/pio.h"
#include "ws2812.pio.h"

#define WS2812_PIN 2
#define IS_RGBW true
#define NUM_PIXELS 8

void ws2812_init(PIO pio, uint sm, uint offset);
void ws2812_set_color(PIO pio, uint sm, uint32_t color);
void ws2812_display_number(PIO pio, uint sm, bool *number);

#endif // WS2812_H
