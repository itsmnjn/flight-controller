#include "motors.h"

void initMotors() {
  // turn on the GPIOA, GPIOB peripheral and TIM2, TIM4 peripheral
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
  RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

  // enable auto-reload preload
  TIM2->CR1 |= TIM_CR1_ARPE;
  TIM4->CR1 |= TIM_CR1_ARPE;

  // set prescaler and auto-reload values to set frequency
  // frequency = clock / (PSC * ARR); 320,000 = 16,000,000 / (5 * 10)
  TIM2->PSC = 0;
  TIM2->ARR = ARR_VAL;

  initM1();
  initM2();

  // update and reinitialize TIM2, TIM4
  TIM2->EGR |= TIM_EGR_UG;
  // TIM4->EGR |= TIM_EGR_UG;

  // enable TIM2, TIM4 counter
  TIM2->CR1 |= TIM_CR1_CEN;
  // TIM4->CR1 |= TIM_CR1_CEN;
}

// PA1 (TIM2_CH2) -> M1
void initM1() {
  // set PA1 mode to AF
  GPIOA->MODER |= GPIO_MODER_MODER1_1;
  // set PA1 speed very high
  GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED1_0 | GPIO_OSPEEDR_OSPEED1_1;
  // set PA1 OType to push-pull
  GPIOA->OTYPER &= ~GPIO_OTYPER_OT1;
  // set PA1 AF to AF1 aka TIM2 channel 2
  GPIOA->AFR[0] |= GPIO_AFRL_AFSEL1_0;

  // enable TIM2 capture/compare output 2
  TIM2->CCER |= TIM_CCER_CC2E;
  // enable PWM mode 1 and preload
  TIM2->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;

  // set duty cycle to 0 initially
  TIM2->CCR2 = DUTY(0);
}

// PB11 (TIM2_CH4) -> M2
void initM2() {
  // set PB11 mode to AF
  GPIOB->MODER |= GPIO_MODER_MODER11_1;
  // set PB11 speed very high
  GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED11_0 | GPIO_OSPEEDR_OSPEED11_1;
  // set PB11 OType to push-pull
  GPIOB->OTYPER &= ~GPIO_OTYPER_OT11;
  // set PB11 AF to AF1 aka TIM2 channel 4
  GPIOB->AFR[1] |= GPIO_AFRH_AFSEL11_0;

  // enable TIM2 capture/compare output 2
  TIM2->CCER |= TIM_CCER_CC4E;
  // enable PWM mode 1 and preload
  TIM2->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4PE;

  // set duty cycle to 0 initially
  TIM2->CCR4 = DUTY(0);
}

// PA15 (TIM2_CH1) -> M3
void initM3() {}

// PB9 (TIM4_CH4) -> M4
void initM4() {}