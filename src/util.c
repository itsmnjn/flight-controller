#include "util.h"

void delay(uint32_t time) {
  for (unsigned int i = 0; i < time; i++)
    for (volatile unsigned int j = 0; j < 2000; j++)
      ;
}