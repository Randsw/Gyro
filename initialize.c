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

  

  //DDRE = 0x9F;
 // DDRE = 0x04;
 // PORTE = 0x08;  // Pull-up pins

//  DDRF  = 0xFB;
//  PORTF = 0x08;

//  DDRG  = 0x1F;
//  PORTG = 0x06;
}
  
  





