#ifndef MOTORS_H
#define MOTORS_H

#include "stm32f4xx.h"

#define ARR_VAL 50
#define DUTY(x) (uint16_t)(((float)x / 100) * (ARR_VAL))

void initMotors();

void initM1();
void initM2();
void initM3();
void initM4();

#endif