#ifndef I2C_H
#define I2C_H

#include "hardware/i2c.h"
#include "pico/stdlib.h"

#define I2C_PORT i2c0
#define I2C_SDA_PIN 4
#define I2C_SCL_PIN 5

void i2c_init_custom();

#endif // I2C_H
