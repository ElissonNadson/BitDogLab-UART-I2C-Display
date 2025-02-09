#ifndef UART_H
#define UART_H

#include "hardware/uart.h"
#include "pico/stdlib.h"

#define UART_ID uart0
#define BAUD_RATE 115200
#define UART_TX_PIN 0
#define UART_RX_PIN 1

void uart_init_custom();
void uart_send_string(const char *str);

#endif // UART_H
