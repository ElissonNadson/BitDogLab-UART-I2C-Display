#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/uart.h"
#include "hardware/i2c.h"
#include "ws2812.h"
#include "ssd1306.h"
#include "led.h"
#include "buttons.h"
#include "menu.h"
#include "fonts/numeros.h"

// Configurações do UART
#define UART_ID uart0
#define BAUD_RATE 115200
#define UART_TX_PIN 0
#define UART_RX_PIN 1

// Configurações do PIO e WS2812
#define WS2812_PIN 2
#define IS_RGBW true  // Se for RGBW, defina como true, caso contrário, false
#define NUM_PIXELS 8  // Número de LEDs

// Configurações do I2C e SSD1306
#define I2C_PORT i2c0
#define I2C_SDA_PIN 4
#define I2C_SCL_PIN 5

void configure_uart() {
    // Inicializa o UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

void configure_ws2812(PIO pio, uint sm, uint offset) {
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
}

void configure_i2c() {
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);
}

void handle_uart_input(PIO pio, uint sm) {
    char c = uart_receive_char();
    if (c >= '0' && c <= '9') {
        bool *number;
        switch (c) {
            case '0': number = numeroZero; break;
            case '1': number = numeroUm; break;
            case '2': number = numeroDois; break;
            case '3': number = numeroTres; break;
            case '4': number = numeroQuatro; break;
            case '5': number = numeroCinco; break;
            case '6': number = numeroSeis; break;
            case '7': number = numeroSete; break;
            case '8': number = numeroOito; break;
            case '9': number = numeroNove; break;
        }
        ws2812_display_number(pio, sm, number);
        display_message(&c);
    }
}

void handle_button_a() {
    if (button_a_pressed()) {
        led_rgb_verde_toggle();
        display_message("LED Verde Toggle");
        uart_puts(UART_ID, "LED Verde Toggle\n");
    }
}

void handle_button_b() {
    if (button_b_pressed()) {
        led_rgb_azul_toggle();
        display_message("LED Azul Toggle");
        uart_puts(UART_ID, "LED Azul Toggle\n");
    }
}

void BitDogLab_UART_I2C_Display() {
    // Inicializa a biblioteca padrão
    stdio_init_all();
    
    // Configura UART
    configure_uart();
    
    // Mensagem inicial via UART
    uart_puts(UART_ID, "UART initialized.\n");

    // Configura WS2812
    PIO pio = pio0;
    uint offset = pio_add_program(pio, &ws2812_program);
    uint sm = pio_claim_unused_sm(pio, true);
    configure_ws2812(pio, sm, offset);
    
    // Mensagem inicial via LED
    uint32_t color = 0x00FF00;  // Verde
    for (int i = 0; i < NUM_PIXELS; ++i) {
        pio_sm_put_blocking(pio, sm, color << 8u);
    }

    // Configura I2C e SSD1306
    configure_i2c();
    ssd1306_init(I2C_PORT);
    ssd1306_clear();
    ssd1306_draw_pixel(10, 10, true);
    ssd1306_display();

    // Inicializa LEDs e botões
    led_init();
    buttons_init();

    // Exibe o menu principal
    main_menu();

    // Loop principal
    while (true) {
        handle_uart_input(pio, sm);
        handle_button_a();
        handle_button_b();
        sleep_ms(100);
    }
}

int main() {
    printf("Iniciando BitDogLab_UART_I2C_Display...\n");
    BitDogLab_UART_I2C_Display();
    return 0;
}