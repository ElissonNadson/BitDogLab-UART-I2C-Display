#ifndef WS2812_PIO_H
#define WS2812_PIO_H

#include "hardware/pio.h"

void ws2812_program_init(PIO pio, uint sm, uint offset, uint pin, float freq, bool rgbw);

extern const struct pio_program ws2812_program;

#endif // WS2812_PIO_H