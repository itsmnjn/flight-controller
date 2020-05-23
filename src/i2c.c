#include "i2c.h"

// PA8 AF4 -> I2C3_SCL
// PC9 AF4 -> I2C3_SDA
void initI2C(void) {
  // turn on the I2C3 peripheral clock
  RCC->APB1ENR |= RCC_APB1ENR_I2C3EN;
  // turn on the GPIOA, GPIOC peripheral clock
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

  // set PA8, PC9 mode to AF
  GPIOA->MODER |= GPIO_MODER_MODER8_1;
  GPIOC->MODER |= GPIO_MODER_MODER9_1;
  // set PA8, PC9 speed very high
  GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED8_0 | GPIO_OSPEEDR_OSPEED8_1;
  GPIOC->OSPEEDR |= GPIO_OSPEEDR_OSPEED9_0 | GPIO_OSPEEDR_OSPEED9_1;
  // set PA8, PC9 OType to open drain
  GPIOA->OTYPER |= GPIO_OTYPER_OT8;
  GPIOC->OTYPER |= GPIO_OTYPER_OT9;
  // enable on PA8, PC9 pull-up resistor
  GPIOA->PUPDR |= GPIO_PUPDR_PUPD8_0;
  GPIOC->PUPDR |= GPIO_PUPDR_PUPD9_0;
  // set PA8 AF to AF4 aka I2C3_SCL
  // set PC9 AF to AF4 aka I2C3_SDA
  GPIOA->AFR[1] |= GPIO_AFRH_AFSEL8_2;
  GPIOC->AFR[1] |= GPIO_AFRH_AFSEL9_2;

  // set CR2 to APB1 frequency (16 MHz)
  I2C3->CR2 |= 16;
  // set CCR value (H_time / APB1_T = 5 us / 62.5 ns = 80)
  I2C3->CCR |= 80;
  I2C3->TRISE |= 17;
  // enable I2C3!
  I2C3->CR1 |= I2C_CR1_PE;
}

void readI2C(uint32_t data, uint32_t reg, uint32_t addr) {}

void writeI2C(uint32_t data, uint32_t reg, uint32_t addr) {}