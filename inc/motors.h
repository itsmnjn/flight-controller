#ifndef MOTORS_H
#define MOTORS_H

#include "stm32f4xx.h"

#define ARR_VAL 49
#define DUTY(x) (uint16_t)(((float)x / 100) * (ARR_VAL))

typedef enum { M1, M2, M3, M4 } MotorName;

void initMotors(void);
void setMotorDuty(MotorName motorName, uint16_t duty);

void initM1(void);
void initM2(void);
void initM3(void);
void initM4(void);

void testMotors(void);

#endif