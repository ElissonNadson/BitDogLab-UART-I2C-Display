#include "buttons.h"

// Implementação das funções dos botões

void buttons_init() {
    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);

    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);
}

bool button_a_pressed() {
    return !gpio_get(BUTTON_A_PIN);
}

bool button_b_pressed() {
    return !gpio_get(BUTTON_B_PIN);
}
