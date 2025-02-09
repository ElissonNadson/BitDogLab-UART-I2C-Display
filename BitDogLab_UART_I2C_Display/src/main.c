// *********************** Includes *******************************
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/uart.h"
#include "hardware/i2c.h"
#include "pico/bootrom.h"

// ************************* LIBS ******************************
#include "lib/matrix.h"
#include "lib/button.h"
#include "lib/led.h"
#include "lib/interrupt.h"
#include "lib/menu.h"
#include "Inc/ws2812.pio.h"
#include "Inc/ssd1306.h"

// *********************** MACROS *******************************
// Configurações da UART
#define UART_ID uart0
#define UART_TX 0
#define UART_RX 1
#define BAUD_RATE 115200
// Configuração da I2C
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C

// *********************** Main  *******************************
int main() {
    // Habilita o uso da comunicação UART
    stdio_init_all();

    // Configuração da UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX, GPIO_FUNC_UART);
    gpio_set_function(UART_RX, GPIO_FUNC_UART);

    // Inicialização da I2C. Usando a 400Khz.
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C); // Define a função do pino GPIO para I2C
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C); // Define a função do pino GPIO para I2C
    gpio_pull_up(I2C_SDA); // Puxa a linha de dados para cima
    gpio_pull_up(I2C_SCL); // Puxa a linha de clock para cima
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
    ssd1306_config(&ssd); // Configura o display
    ssd1306_send_data(&ssd); // Envia os dados para o display
  
    // Limpa o display. O display inicia com todos os pixels apagados.
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);

    // Inicializa os LEDs
    inicializar_led(LED_VERDE);
    inicializar_led(LED_AZUL);
    // Inicialização dos botões e configuração de eventos de interrupção
    inicializar_botao_com_interrupcao(BUTTON_A, GPIO_IRQ_EDGE_FALL, true);
    inicializar_botao_com_interrupcao(BUTTON_B, GPIO_IRQ_EDGE_FALL, true);

    // Configuração da matriz de LEDs
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    // Aguarda pressionar Enter para exibir o menu pela primeira vez
    getchar();
    char input;
    // Rotina principal
    while(true) {
        // Só vai entrar nessa rotina se a USB estiver conectada
        if(stdio_usb_connected()) {
            menu_principal();
            puts("");
            while(true) {
                printf("Escolha uma opcao: ");
                scanf("%c", &input);
                // Encerra o loop se pressionar
                // um caractere entre 0 e 9
                // um caractere entre A-Z
                // um caractere entre a-z
                // /: para finalizar o programa
                if((input>= '0' && input <= '9')
                    || (input >= 'A' && input <= 'Z')
                    || (input >= 'a' && input <= 'z')
                    || input == '/')
                    break;
                printf("Caractere inválido!\n");
            }
            // Exibe o caractere digitado no display (se for alfanumérico)
            if((input >= 'A' && input <= 'Z') || 
            (input >= 'a' && input <= 'z') || 
            (input>= '0' && input <= '9')) {
                char input_string[20];
                // Limpa o display
                ssd1306_fill(&ssd, false);
                ssd1306_send_data(&ssd);
                ssd1306_draw_string(&ssd, "caractere", 10, 20);
                snprintf(input_string, sizeof(input_string), "digitado %c", input);
                ssd1306_draw_string(&ssd, input_string, 10, 30);
                ssd1306_send_data(&ssd);
            }
            if(!(input>= '0' && input <= '9'))
                printf("\nCaractere digitado: %c\n", input);
            switch (input) {
                case '0':
                    if(numero_atual != 0) {
                        numero_atual = 0;
                        definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    }
                    printf("\nExibindo o numero %d na matriz\n", numero_atual);
                    break;
                case '1':
                    if(numero_atual != 1) {
                        numero_atual = 1;
                        definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    }
                    printf("\nExibindo o numero %d na matriz\n", numero_atual);
                    break;
                case '2':
                    if(numero_atual != 2) {
                        numero_atual = 2;
                        definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    }
                    printf("\nExibindo o numero %d na matriz\n", numero_atual);
                    break;
                case '3':
                    if(numero_atual != 3) {
                        numero_atual = 3;
                        definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    }
                    printf("\nExibindo o numero %d na matriz\n", numero_atual);
                    break;
                case '4':
                    if(numero_atual != 4) {
                        numero_atual = 4;
                        definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    }
                    printf("\nExibindo o numero %d na matriz\n", numero_atual);
                    break;
                case '5':
                    if(numero_atual != 5) {
                        numero_atual = 5;
                        definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    }
                    printf("\nExibindo o numero %d na matriz\n", numero_atual);
                    break;   
                case '6':
                    if(numero_atual != 6) {
                        numero_atual = 6;
                        definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    }
                    printf("\nExibindo o numero %d na matriz\n", numero_atual);
                    break;  
                case '7':
                    if(numero_atual != 7) {
                        numero_atual = 7;
                        definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    }
                    printf("\nExibindo o numero %d na matriz\n", numero_atual);
                    break; 
                case '8':
                    if(numero_atual != 8) {
                        numero_atual = 8;
                        definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    }
                    printf("\nExibindo o numero %d na matriz\n", numero_atual);
                    break; 
                case '9':
                    if(numero_atual != 9) {
                        numero_atual = 9;
                        definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    }
                    printf("\nExibindo o numero %d na matriz\n", numero_atual);
                    break;   
                // ESCAPE para finalizar o programa
                case '*':
                    // Posição da matriz de reset
                    numero_atual = 10;
                    // Desliga os LEDs da matriz
                    definir_um_led(numeros[numero_atual], led_r, led_g, led_b);
                    // Entra no modo BOOTSELL e encerra o programa
                    reset_usb_boot(0,0);
                    printf("\nFinalizando o programa...\n");
                    break;
                default:
                    break;
            }
        }
        // Para evitar que o loop seja executado muito rapidamente
        sleep_ms(100);
    }
}