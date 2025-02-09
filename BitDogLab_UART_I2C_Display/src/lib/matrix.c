#include "matrix.h"
#include "pico/stdlib.h"
#include <stdio.h>

// **************** NÚMEROS NA MATRIZ *************************
bool numeroZero[] = {
    0, 1, 1, 1, 0, 
    0, 1, 0, 1, 0, 
    0, 1, 0, 1, 0, 
    0, 1, 0, 1, 0, 
    0, 1, 1, 1, 0
};
bool numeroUm[] = {
    0, 1, 1, 1, 0, 
    0, 0, 1, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 1, 1, 0, 0, 
    0, 0, 1, 0, 0
};
bool numeroDois[] = {
    0, 1, 1, 1, 0, 
    0, 1, 0, 0, 0, 
    0, 1, 1, 1, 0, 
    0, 0, 0, 1, 0, 
    0, 1, 1, 1, 0
};
bool numeroTres[] = {
    0, 1, 1, 1, 0, 
    0, 0, 0, 1, 0, 
    0, 0, 1, 1, 0, 
    0, 0, 0, 1, 0, 
    0, 1, 1, 1, 0
};
bool numeroQuatro[] = {
    0, 1, 0, 0, 0, 
    0, 0, 0, 1, 0, 
    0, 1, 1, 1, 0, 
    0, 1, 0, 1, 0, 
    0, 1, 0, 1, 0
};
bool numeroCinco[] = {
    0, 1, 1, 1, 0, 
    0, 0, 0, 1, 0, 
    0, 1, 1, 1, 0, 
    0, 1, 0, 0, 0, 
    0, 1, 1, 1, 0
};
bool numeroSeis[] = {
    0, 1, 1, 1, 0, 
    0, 1, 0, 1, 0, 
    0, 1, 1, 1, 0, 
    0, 1, 0, 0, 0, 
    0, 1, 1, 1, 0
};
bool numeroSete[] = {
    0, 0, 0, 1, 0, 
    0, 1, 0, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 0, 0, 1, 0, 
    0, 1, 1, 1, 0
};
bool numeroOito[] = {
    0, 1, 1, 1, 0, 
    0, 1, 0, 1, 0, 
    0, 1, 1, 1, 0, 
    0, 1, 0, 1, 0, 
    0, 1, 1, 1, 0
};
bool numeroNove[] = {
    0, 1, 1, 1, 0, 
    0, 0, 0, 1, 0, 
    0, 1, 1, 1, 0, 
    0, 1, 0, 1, 0, 
    0, 1, 1, 1, 0
};
bool reset[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0
};
// **************************************************************
// ************************* MACROS *****************************

// Ponteiro para a matriz que está atualmente sendo exibida
bool *numeros[] = {numeroZero, numeroUm, numeroDois, 
                    numeroTres, numeroQuatro, numeroCinco,
                    numeroSeis, numeroSete, numeroOito,
                    numeroNove, reset};
// Variável global que controla o número a ser exibido
volatile uint numero_atual = 0;

// Controla a intensidade da cor dos LEDs
uint8_t led_r = 0;  // Vermelho
uint8_t led_g = 0;  // Verde
uint8_t led_b = 255;  // Azul 

// ************ FUNÇÕES PARA CONTROLE DA MATRIZ *****************
void colocar_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | (uint32_t)(b);
}

void definir_um_led(bool *buffer_led, uint8_t r, uint8_t g, uint8_t b) {
    // Define a cor com base nos parâmetros fornecidos
    uint32_t cor = urgb_u32(r, g, b);

    // Define todos os LEDs com a cor especificada
    for (int i = 0; i < NUM_PIXELS; i++) {
        if (buffer_led[i])
            colocar_pixel(cor); // Liga o LED com um no buffer
        else
            colocar_pixel(0);  // Desliga os LEDs com zero no buffer
    }
}

