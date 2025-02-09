#ifndef LED_H
#define LED_H

#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13

// Funções padrão
void inicializar_led(uint8_t ledGPIO);
void ligar_led(uint8_t ledGPIO);
void desligar_led(uint8_t ledGPIO);
void piscar_led(uint8_t ledGPIO, uint32_t ms, uint8_t ciclos);

#endif