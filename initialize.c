/******************************************************************************************************/
/*                           Initialization functions for Kvant                                */
/******************************************************************************************************/
#include "Gyro_Final_Firmware_defs.h"

void  conf_ports(void)
{
  
  DDRD = 0x7A; //4a//7a
  PORTD = 0x08;
  
  DDRC = 0xD2;
  PORTC = 0x00;
  
  DDRA = 0xFF;
  PORTA = 0x00;

  DDRB = 0x5B;
  PORTB = 0x02; //
}
  
  





