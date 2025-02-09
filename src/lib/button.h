#ifndef BUTTON_H
#define BUTTON_H

#include "pico/stdlib.h"

#define BUTTON_A 5
#define BUTTON_B 6

void inicializar_botao(uint8_t botaoGPIO);
bool botao_pressionado(uint8_t botaoGPIO);
void inicializar_botao_com_interrupcao(uint botaoGPIO, uint32_t evento, bool habilitado);
bool debouncing(uint32_t ms);

#endif