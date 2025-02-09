#include "pico/stdlib.h"
#include "led.h"

// *********************** Lib padrão ***********************

// Inicializa um LED
void inicializar_led(uint8_t LED) {
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    // Inicia apagado
    desligar_led(LED);
}

// Liga um LED
void ligar_led(uint8_t LED) {
    gpio_put(LED, true);
}

// Desliga um LED
void desligar_led(uint8_t LED) {
    gpio_put(LED, false);
}

// Realiza um piscar em um LED
// Recebe o intervalo e a quantidade de piscadas que devem ser realizadas
void piscar_led(uint8_t LED, uint32_t ms, uint8_t ciclos) {
    for(int i = 0; i < ciclos; i++) {
        ligar_led(LED);
        sleep_ms(ms);
        desligar_led(LED);
        sleep_ms(ms);
    }
}