#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "pico/stdlib.h"

// Manipulador de interrupção GPIO
void manipulador_irq_gpio(uint gpio, uint32_t eventos);

#endif