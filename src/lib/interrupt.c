#include "interrupt.h"
#include "button.h"
#include "led.h"
#include "pico/bootrom.h"
#include "pico/stdlib.h"
#include "ssd1306.h"
#include <stdio.h>

// Função que lida com eventos de interrupção
void manipulador_irq_gpio(uint gpio, uint32_t eventos) {
    // Eventos de acionamento de botões
    if(gpio == BUTTON_A || gpio == BUTTON_B) {
        // Tratamento de debouncing dos botões
        if(!debouncing(300))
            return;

        // Interação com o Botão A
        if(gpio == BUTTON_A) {
            if(gpio_get(LED_VERDE)) {
                puts("\nLED verde desligado.");
                // Mensagem no display
                // Limpa o display
                ssd1306_fill(&ssd, false);
                ssd1306_send_data(&ssd);
                ssd1306_draw_string(&ssd, "LED VERDE", 10, 20);
                ssd1306_draw_string(&ssd, "DESLIGADO", 10, 30);
                ssd1306_send_data(&ssd);
                desligar_led(LED_VERDE);
            }
            else {
                puts("\nLED verde ligado.");
                // Mensagem no display
                // Limpa o display
                ssd1306_fill(&ssd, false);
                ssd1306_send_data(&ssd);
                ssd1306_draw_string(&ssd, "LED VERDE", 10, 20);
                ssd1306_draw_string(&ssd, "LIGADO", 10, 30);
                ssd1306_send_data(&ssd);
                ligar_led(LED_VERDE);
            }
        }
        // Interação com o Botão B
        if(gpio == BUTTON_B) {
            if(gpio_get(LED_AZUL)) {
                puts("\nLED azul desligado.");
                // Mensagem no display
                // Limpa o display
                ssd1306_fill(&ssd, false);
                ssd1306_send_data(&ssd);
                ssd1306_draw_string(&ssd, "LED AZUL", 10, 20);
                ssd1306_draw_string(&ssd, "DESLIGADO", 10, 30);
                ssd1306_send_data(&ssd);
                desligar_led(LED_AZUL);
            }
            else {
                puts("\nLED azul ligado.");
                // Mensagem no display
                // Limpa o display
                ssd1306_fill(&ssd, false);
                ssd1306_send_data(&ssd);
                ssd1306_draw_string(&ssd, "LED AZUL", 10, 20);
                ssd1306_draw_string(&ssd, "LIGADO", 10, 30);
                ssd1306_send_data(&ssd);
                ligar_led(LED_AZUL);
            }
        }
    }
}