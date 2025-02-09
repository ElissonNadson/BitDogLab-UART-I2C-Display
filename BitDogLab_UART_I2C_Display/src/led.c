#include "led.h"

// Implementação das funções dos LEDs

void led_init() {
    gpio_init(LED_VERDE_PIN);
    gpio_set_dir(LED_VERDE_PIN, GPIO_OUT);

    gpio_init(LED_AZUL_PIN);
    gpio_set_dir(LED_AZUL_PIN, GPIO_OUT);

    gpio_init(LED_RGB_R_PIN);
    gpio_set_dir(LED_RGB_R_PIN, GPIO_OUT);

    gpio_init(LED_RGB_G_PIN);
    gpio_set_dir(LED_RGB_G_PIN, GPIO_OUT);

    gpio_init(LED_RGB_B_PIN);
    gpio_set_dir(LED_RGB_B_PIN, GPIO_OUT);
}

void led_verde_toggle() {
    gpio_put(LED_VERDE_PIN, !gpio_get(LED_VERDE_PIN));
}

void led_azul_toggle() {
    gpio_put(LED_AZUL_PIN, !gpio_get(LED_AZUL_PIN));
}

void led_rgb_set_color(bool r, bool g, bool b) {
    gpio_put(LED_RGB_R_PIN, r);
    gpio_put(LED_RGB_G_PIN, g);
    gpio_put(LED_RGB_B_PIN, b);
}

void led_rgb_verde_toggle() {
    gpio_put(LED_RGB_G_PIN, !gpio_get(LED_RGB_G_PIN));
}

void led_rgb_azul_toggle() {
    gpio_put(LED_RGB_B_PIN, !gpio_get(LED_RGB_B_PIN));
}
