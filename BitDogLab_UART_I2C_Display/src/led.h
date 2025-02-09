#ifndef LED_H
#define LED_H

#include "pico/stdlib.h"

#define LED_VERDE_PIN 11
#define LED_AZUL_PIN 12
#define LED_RGB_R_PIN 13
#define LED_RGB_G_PIN 14
#define LED_RGB_B_PIN 15

void led_init();
void led_verde_toggle();
void led_azul_toggle();
void led_rgb_set_color(bool r, bool g, bool b);

#endif // LED_H
