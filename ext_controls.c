/******************************************************************************************************/
/*                       External controls and other support functions                                */
/******************************************************************************************************/
#include "Gyro_Final_Firmware_defs.h"

// Variable delay function (used for keyboard ring rejection)
void delay(long delay_cycles)
{
  long count = 0;

  while(count++<delay_cycles);
}
