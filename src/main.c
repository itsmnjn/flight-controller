#include "motors.h"

// Quick and dirty delay
static void delay(unsigned int time) {
  for (unsigned int i = 0; i < time; i++)
    for (volatile unsigned int j = 0; j < 2000; j++)
      ;
}

int main(void) {
  while (1) {
    initMotors();
  }

  // should never reach this point
  return 0;
}
