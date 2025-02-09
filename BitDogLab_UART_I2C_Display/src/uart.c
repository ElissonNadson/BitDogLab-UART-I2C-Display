#include "uart.h"

// Implementação das funções UART

void uart_init_custom() {
    // Inicializa o UART com configurações personalizadas
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

void uart_send_string(const char *str) {
    // Envia uma string via UART
    uart_puts(UART_ID, str);
}

char uart_receive_char() {
    while (!uart_is_readable(UART_ID));
    return uart_getc(UART_ID);
}
