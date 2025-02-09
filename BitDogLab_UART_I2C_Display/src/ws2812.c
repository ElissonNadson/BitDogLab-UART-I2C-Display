#include "ws2812.h"

// Implementação das funções WS2812

void ws2812_init(PIO pio, uint sm, uint offset) {
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
}

void ws2812_set_color(PIO pio, uint sm, uint32_t color) {
    for (int i = 0; i < NUM_PIXELS; ++i) {
        pio_sm_put_blocking(pio, sm, color << 8u);
    }
}

void ws2812_display_number(PIO pio, uint sm, bool *number) {
    for (int i = 0; i < 25; ++i) {
        uint32_t color = number[i] ? 0xFFFFFF : 0x000000;  // Branco para 1, Preto para 0
        pio_sm_put_blocking(pio, sm, color << 8u);
    }
}
