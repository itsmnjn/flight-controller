#include "bmi088.h"
#include "bmi08x.h"
#include "motors.h"

int main(void) {
  initMotors();

  // int8_t rslt;

  // struct bmi08x_dev dev = {.accel_id = BMI08X_ACCEL_I2C_ADDR_PRIMARY,
  //                          .gyro_id = BMI08X_GYRO_I2C_ADDR_PRIMARY,
  //                          .intf = BMI08X_I2C_INTF,
  //                          .read = (void *)0,
  //                          .write = (void *)0,
  //                          .delay_ms = (void *)0};

  /* Initialize the I2C */

  /* Initializing the bmi085 sensors the below function will Initialize both
   * accel and gyro sensors */
  // rslt = bmi088_init(&dev);

  while (1) {
    // testMotors();
  }

  // should never reach this point
  return 0;
}
