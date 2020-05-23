#ifndef I2C_H
#define I2C_H

#include "stm32f4xx.h"

void initI2C(void);
void readI2C(uint32_t data, uint32_t reg, uint32_t addr);
void writeI2C(uint32_t data, uint32_t reg, uint32_t addr);

#endif