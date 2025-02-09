#ifndef BUTTONS_H
#define BUTTONS_H

#include "pico/stdlib.h"

#define BUTTON_A_PIN 5
#define BUTTON_B_PIN 6

void buttons_init();
bool button_a_pressed();
bool button_b_pressed();

#endif // BUTTONS_H
