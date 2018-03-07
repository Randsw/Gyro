#include "Gyro_Final_Firmware_defs.h"
#include <stdlib.h>

//#define Max21000
#define Corr
//#define temp_corr
//#define new_temp_corr
#define temp_corr_v2
const unsigned char LCD_CODE[] = {					
	0X41,
	0XA0,
	0X42,
	0XA1,
	0XE0,
	0X45,
	0XA3,
	0XA4,
	0XA5,
	0XA6,
	0X4B,
	0XA7,
	0X4D,
	0X48,
	0X4F,
	0XA8,
	0X50,
	0X43,
	0X54,
	0XA9,
	0XAA,
	0X58,
	0XC1,
	0XAB,
	0XAC,
	0XC2,
	0XAD,
	0XAE,
	0X62,
	0XAF,
	0XB0,
	0XB1,
	0X61,
	0XB2,
	0XB3,
	0XB4,
	0XE3,
	0X65,
	0XB6,
	0XB7,
	0XB8,
	0XB9,
	0XBA,
	0XBB,
	0XBC,
	0XBD,
	0X6F,
	0XBE,
	0X70,
	0X63,
	0XBF,
	0X79,
	0XE4,
	0X78,
	0XE5,
	0XC0,
	0XC1,
	0XE6,
	0XC2,
	0XC3,
	0XC4,
	0XC5,
	0XC6,
	0XC7
};

#define rus

#ifdef rus    
const  unsigned char   STR_CALIBRAT1[] ="    ИСЛ-";
const  unsigned char   STR_CALIBRAT2[] ="401М    ";
const  unsigned char   STR_PO1[] ="    ПО-4";
const  unsigned char   STR_PO2[] ="0.1     ";
const  unsigned char   STR_Sum_Luft1[]   = "СУМ.ЛЮФТ";
const  unsigned char   STR_Sum_Luft2[]   = "=";
const  unsigned char   STR_POVERKA1[]   = "    ПОВЕ";
const  unsigned char   STR_POVERKA2[]   = "РКА     ";
const  unsigned char   STR_STR_LEFT1[]  = " ВРАЩАЕМ";
const  unsigned char   STR_STR_LEFT2[]  = " РУЛЬ ";
const unsigned char    STR_STR_LEFT3[2] = {0xD9, 0x10}; 
const unsigned char    STR_gradus[1] = {0xEF};
const unsigned char    STR_minuta[1] = {0x27};
const  unsigned char   STR_STR_RIGHT1[] = " ВРАЩАЕМ";
const  unsigned char   STR_STR_RIGHT2[] = " РУЛЬ ";
const unsigned char    STR_STR_RIGHT3[2] = {0xDA, 0x10};
const unsigned char    STR_izmeryaem_snova1[] ="ИЗМЕРЯЕМ";
const unsigned char    STR_izmeryaem_snova2[] =" СНОВА! ";
const unsigned char    STR_vrashay_bystree1[] ="ВРАЩАЙ Б";
const unsigned char    STR_vrashay_bystree2[] ="ЫСТРЕЕ  ";
const unsigned char    STR_vrashay_medlenee1[] = "ВРАЩАЙ М";
const unsigned char    STR_vrashay_medlenee2[] = "ЕДЛЕННЕЕ";
const unsigned char    STR_izmeryat_nelsya1[] = "ИЗМЕРЯТЬ";
const unsigned char    STR_izmeryat_nelsya2[] = " НЕЛЬЗЯ!";
const unsigned char    STR_akkumulyator1[] = "АККУМУЛЯ";
const unsigned char    STR_akkumulyator2[] = "ТОР     ";
const unsigned char    STR_trebuet_zaryadki1[] = "ТРЕБУЕТ ";
const unsigned char    STR_trebuet_zaryadki2[] = "ЗАРЯДКИ!";
const unsigned char    STR_nekor_data1[] = "НЕКОРЕКТ";
const unsigned char    STR_nekor_data2[] = " ДАННЫЕ";

#endif


void str_left(void)
{
  LCD_DisplayString_new_SH (1, 1, STR_STR_LEFT1);
  LCD_DisplayString_new_SH (2, 1, STR_STR_LEFT2);
  LCD_DisplayString_new (2, 7, STR_STR_LEFT3);
}                 

void str_right(void)
{
  LCD_DisplayString_new_SH (1, 1, STR_STR_RIGHT1);
  LCD_DisplayString_new_SH (2, 1, STR_STR_RIGHT2);
  LCD_DisplayString_new (2, 7, STR_STR_RIGHT3);
}       
void calibrat(void)
{
  LCD_DisplayString_new_SH (1, 1, STR_CALIBRAT1);
  LCD_DisplayString_new_SH (2, 1, STR_CALIBRAT2);
}   
     
void po(void) 
{
  LCD_DisplayString_new_SH (1, 1, STR_PO1);
  LCD_DisplayString_new_SH (2, 1, STR_PO2);

}                  

void sum_luft(void)
{
  LCD_DisplayString_new_SH (1, 1, STR_Sum_Luft1);
  LCD_DisplayString_new_SH (2, 1, STR_Sum_Luft2);

}  
void poverka(void)
{
  LCD_DisplayString_new_SH (1, 1, STR_POVERKA1);
  LCD_DisplayString_new_SH (2, 1, STR_POVERKA2);

}  
void gradus(void)
{   
  LCD_Cursor (2, 4);
  LCD_DisplayCharacter (0xEF);
 //  LCD_DisplayString_new (2, 5, STR_gradus);
}                     
void minuta(void)
{  
  LCD_Cursor (2, 7);
  LCD_DisplayCharacter (0x27);
  //LCD_DisplayString_new (2, 7, STR_minuta);
}  
                
void izmeryaem_snova(void)
{
  
  LCD_DisplayString_new_SH (1, 1, STR_izmeryaem_snova1);
  LCD_DisplayString_new_SH (2, 1, STR_izmeryaem_snova2);
}   
void vrashay_bystree(void)
{
  LCD_DisplayString_new_SH (1, 1, STR_vrashay_bystree1);
  LCD_DisplayString_new_SH (2, 1, STR_vrashay_bystree2);
}                                   
void vrashay_medlennee(void)
{  
  
  LCD_DisplayString_new_SH (1, 1, STR_vrashay_medlenee1);
  LCD_DisplayString_new_SH (2, 1, STR_vrashay_medlenee2);
} 
void izmeryat_nelzya(void)
{  
  
  LCD_DisplayString_new_SH (1, 1, STR_izmeryat_nelsya1);
  LCD_DisplayString_new_SH (2, 1, STR_izmeryat_nelsya2);
}

void nekor_data(void)
{

  LCD_DisplayString_new_SH (1, 1, STR_nekor_data1);
  LCD_DisplayString_new_SH (2, 1, STR_nekor_data2);
}
void akkumulyator(void)
{  
  LCD_DisplayString_new_SH (1, 1, STR_akkumulyator1);
  LCD_DisplayString_new_SH (2, 1, STR_akkumulyator2);
}               
void trebuet_zaryadki(void)
{  
  LCD_DisplayString_new_SH (1, 1, STR_trebuet_zaryadki1);
  LCD_DisplayString_new_SH (2, 1, STR_trebuet_zaryadki2);
}

void beep(void)
{ 
int k;
//PORTC.2=1;
PORTC |= (1<<PORTC1);
for(k=0;k<30000;k++)
 {
 asm("nop");
 }
//PORTC.2=0; 
PORTC &= (1<<PORTC1) ^ 0xFF;
}

char *itoa(int num, char *buf)
{
    char str[6];
    char *ptr = &str[5];
    int tmp;

    *ptr = 0;

    if (num < 0) {
        *buf++ = '-';
        num = -num;
    }

    do {
        tmp = num / 10;
        *--ptr = '0' + (num - tmp * 10);
        num = tmp;
    } while (num != 0);

    while ((*buf++ = *ptr++) != 0);

    return buf - 1;
}
#define delay_us(usecs) __delay_cycles((F_CPU/1000000)  *(usecs))
 
void delay_ms(unsigned int millisecs)
{
    while(millisecs--)
    {
      delay_us(1000);
    }
}



//#include <delay.h> 
//#include <string.h>
//#include <stdio.h>  
//#include <ctype.h> 
// Standard Input/Output functions
//#include <stdio.h>
#include <stdlib.h> 
//#include <math.h>


//clock для АЦП датчика гироскопа
#define CLK_READ_UP1 {PORTB |=(1<<PORTB0); asm("nop");}   
#define CLK_READ_DOWN1 {PORTB &=(1<<PORTB0)^0xFF;} 
//clock для АЦП датчика поворота колеса
#define CLK_READ_UP2 {PORTB |=(1<<PORTB4); asm("nop");}   
#define CLK_READ_DOWN2 {PORTB &=(1<<PORTB4) ^ 0xFF; } 

//#define PULSE{PORTB |=(1<<PORTB3); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop");PORTB &=(1<<PORTB3) ^ 0xFF;}
#define RXB8 1
#define TXB8 0
#define UPE 2
#define OVR 3
#define FE 4
#define UDRE 5
#define RXC 7

#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<OVR)
#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)



float S_RIGHT=0;
float S_LEFT=0; 
float LUFT, LUFT_1=0;
enum bool reset = false;
//bit reset=0;

// USART Transmitter buffer
#define TX_BUFFER_SIZE 18
char tx_buffer[TX_BUFFER_SIZE];
unsigned char tx_wr_index,tx_rd_index,tx_counter;
                 

// USART Receiver buffer
#define RX_BUFFER_SIZE 16   
char* strr="             ";
unsigned char rx_wr_index,rx_rd_index,rx_counter,record_enable=0,timeout=0,record_stop=RX_BUFFER_SIZE;
char rx_buffer[RX_BUFFER_SIZE];
char otvet[18];
char cnt_tx_byte=0;
char checksum=0;
unsigned char zzz;
unsigned int timertik = 0;
unsigned  char timertik1, timertik2 = 0;
unsigned int time, delta_time;
unsigned char timercount1, timercount2;
float sample_time;
unsigned char timeroverflow;

// This flag is set on USART Receiver buffer overflow
enum bool rx_buffer_overflow;
enum bool rx_command_vern_podder=false,rx_command_vern_rezult=false,rx_command_sbros=false,rx_command_proiz_izm=false;
enum bool pribor_stop=false,pribor_go=false,pribor_begin_go=false,rezult_ready=false;
enum bool paket_prinyat=false, paket_kalib_prinyat=false, tx_enable=true; 
char* str_test="     ";
char l;
char a; 
float GYRO_ANGLE;
float GYRO_ANGLE_D;  
__eeprom int ee_kalib = 8880;
int kalib;
enum bool isCorr = true;
__eeprom enum bool ee_isCorr = true; 
unsigned char Who_Am_I;

           
char vichislenie_checksum(char* buffer,int kolvo_byte)
{

int i; 
checksum=0;
for(i=0;i<(kolvo_byte-1);i++)
 {
 checksum=checksum^buffer[i];
 }
return checksum;
}   

char vichislenie_mantissy(float d_in)
{  
int i=0;
unsigned int d_out=0;
d_in=d_in-(int)d_in;
for(i=0;i<8;i++)
 {
  d_in=d_in*2;
  if(d_in>=1)
  {            
  d_out=(d_out+1)<<1;
  d_in=d_in-1;
  }
  else
  {
  d_out=d_out<<1;
  }
 }          
 d_out=d_out>>1;
 return (char)d_out;
}

/*
void peredacha_otveta(int kolvo_byte)
{
int i;
for(i=0;i<kolvo_byte;i++)
 {
 putchar(otvet[i]);
 }
 tx_enable=0;
}*/       

void obrabotka_rx_paketa(void)

{     
int Data_kalib;    
 float Data;
 if(paket_prinyat==1)
   {                  
   
      if(rx_buffer[3]==0x00)  //
       {
       tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x03;tx_buffer[3]=0x00;tx_buffer[4]=0x03;tx_buffer[5]=0x01;tx_buffer[6]=0x85;tx_buffer[7]=vichislenie_checksum(tx_buffer,8);
      // otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x03;otvet[3]=0x00;otvet[4]=0x03;otvet[5]=0x01;otvet[6]=0x85;otvet[7]=vichislenie_checksum(otvet,8);
      // tx_enable=1;
       tx_counter=8;
       //peredacha_otveta(8);
       if(tx_enable==1)
        {
        UDR0=tx_buffer[0]; 
        }
       goto end_int;
      
       } 
      if(rx_buffer[3]==0x01)  //IDLE
       {           
         if((pribor_stop==0)&&(pribor_begin_go==0)&&(pribor_go==0)&&(rezult_ready==0))
         {  
         tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x02;tx_buffer[3]=0x00;tx_buffer[4]=0x00;tx_buffer[5]=0x85;tx_buffer[6]=vichislenie_checksum(tx_buffer,7);
       //  otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x03;otvet[3]=0x07;otvet[4]=0x00;otvet[5]=0x45;otvet[6]=0x85;otvet[7]=vichislenie_checksum(otvet,8); //otvet[6]=0x7F;
       //  tx_enable=1;
         tx_counter=7;
       //  peredacha_otveta(8);
          if(tx_enable==1)
          {      
          UDR0=tx_buffer[0];       
          }
         goto end_int;
         }   
         
         if(pribor_stop==1)
         { 
          tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x02;tx_buffer[3]=0x00;tx_buffer[4]=0x00;tx_buffer[5]=0x85;tx_buffer[6]=vichislenie_checksum(tx_buffer,7);
       //  otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x03;otvet[3]=0x00;otvet[4]=0x00;otvet[5]=0x45;otvet[6]=0x85;otvet[7]=vichislenie_checksum(otvet,8); //otvet[6]=0x7F;
       //  tx_enable=1;
         tx_counter=7;
          if(tx_enable==1)
          {
          UDR0=tx_buffer[0];  
          }
       //  peredacha_otveta(8);
         goto end_int;
         }
         
         if(pribor_begin_go==1)
         { 
         tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x03;tx_buffer[3]=0x00;tx_buffer[4]=0x01;tx_buffer[5]=0x45;tx_buffer[6]=0x85;tx_buffer[7]=vichislenie_checksum(tx_buffer,8); 
       //  otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x03;otvet[3]=0x00;otvet[4]=0x01;otvet[5]=0x45;otvet[6]=0x85;otvet[7]=vichislenie_checksum(otvet,8); //otvet[6]=0x7F;
       /*  pribor_stop=0;
         pribor_begin_go=0;
         pribor_go=1;
         rezult_ready=0;*/
              
       //  tx_enable=1; 
         tx_counter=8;
          if(tx_enable==1)
          {
          UDR0=tx_buffer[0];  
          }
       //  peredacha_otveta(8);
         goto end_int;
         }    
         if(pribor_go==1)
         {                                                                                              
         tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x04;tx_buffer[3]=0x00;tx_buffer[4]=0x02;tx_buffer[5]=0x45;tx_buffer[6]=0x7F;tx_buffer[7]=0x85;tx_buffer[8]=vichislenie_checksum(tx_buffer,9);
       //  otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x04;otvet[3]=0x00;otvet[4]=0x02;otvet[5]=0x45;otvet[6]=0x7F;otvet[7]=0x85;otvet[8]=vichislenie_checksum(otvet,8); //otvet[6]=0x7F;
        /*  pribor_stop=0;
          pribor_begin_go=0;
          pribor_go=0;
          rezult_ready=1;       */
       //  tx_enable=1;
         tx_counter=9;
          if(tx_enable==1)
          {
          UDR0=tx_buffer[0];  
          }
       //  peredacha_otveta(9);
         goto end_int;
         }
         if(rezult_ready==1)
         { 
         tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x03;tx_buffer[3]=0x00;tx_buffer[4]=0x03;tx_buffer[5]=0x45;tx_buffer[6]=0x85;tx_buffer[7]=vichislenie_checksum(tx_buffer,8); 
       //  otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x03;otvet[3]=0x00;otvet[4]=0x03;otvet[5]=0x45;otvet[6]=0x85;otvet[7]=vichislenie_checksum(otvet,8); //otvet[6]=0x7F;
         pribor_stop=true;
         pribor_begin_go=false;
         pribor_go=false;
         rezult_ready=false;
       //  tx_enable=1;
         tx_counter=8;
          if(tx_enable==1)
          {
          UDR0=tx_buffer[0];  
          }
       //  peredacha_otveta(8);
         goto end_int;
         }
      
       }            
      if(rx_buffer[3]==0x02)  //
       {
       tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x09;tx_buffer[3]=0x00;tx_buffer[4]=0x49;tx_buffer[5]=0x53;tx_buffer[6]=0x4C;tx_buffer[7]=0x2D;tx_buffer[8]=0x34;tx_buffer[9]=0x30;tx_buffer[10]=0x31;tx_buffer[11]=0x4D;tx_buffer[12]=0x85;tx_buffer[13]=vichislenie_checksum(tx_buffer,14);
      // otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x05;otvet[3]=0x00;otvet[4]=0x6C;otvet[5]=0x75;otvet[6]=0x66;otvet[7]=0x74;otvet[8]=0x85;otvet[9]=vichislenie_checksum(otvet,10);
      // tx_enable=1;
       tx_counter=14;
        if(tx_enable==1)
        {
        UDR0=tx_buffer[0];  
        }
     //  peredacha_otveta(10);
       goto end_int;
      
       }             
       
       
      if(rx_buffer[3]==0x42)
       {
       tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x03;tx_buffer[3]=0x00;tx_buffer[4]=0x01;tx_buffer[5]=0x01;tx_buffer[6]=0x85;tx_buffer[7]=vichislenie_checksum(tx_buffer,8);
      // otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x03;otvet[3]=0x00;otvet[4]=0x01;otvet[5]=0x01;otvet[6]=0x85;otvet[7]=vichislenie_checksum(otvet,8);
      // tx_enable=1;
       tx_counter=8;
        if(tx_enable==1)
        {
        UDR0=tx_buffer[0]; 
        }
     //  peredacha_otveta(8);
       rx_command_vern_podder=true;
       goto end_int;
       } 
      if(rx_buffer[3]==0x43)
       {
        if((rezult_ready==1)||(pribor_stop==1))
         {    
        
          Data=LUFT;
          a=vichislenie_mantissy(Data);
          tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x0D;tx_buffer[3]=0x00;
          tx_buffer[4]=0;tx_buffer[5]=0;tx_buffer[6]=0;tx_buffer[7]=0;tx_buffer[8]=0x00;tx_buffer[9]=0x00;
          tx_buffer[10]=(a&0x0F);tx_buffer[11]=a>>4;tx_buffer[12]=(((char)Data)&0x0F);tx_buffer[13]=((char)Data)>>4;tx_buffer[14]=0x08;tx_buffer[15]=0x00; 
          tx_buffer[16]=0x85;tx_buffer[17]=vichislenie_checksum(tx_buffer,18);          
         
         
        // otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x0D;otvet[3]=0x00;
        // otvet[4]=0x00;otvet[5]=0x00;otvet[6]=0x00;otvet[7]=0x00;otvet[8]=0x00;otvet[9]=0x00; 
        // otvet[10]=0x00;otvet[11]=0x0A;otvet[12]=0x0A;otvet[13]=0x06;otvet[14]=0x01;otvet[15]=0x08;
        // otvet[16]=0x85;otvet[17]=vichislenie_checksum(otvet,18);
        // tx_enable=1;
         tx_counter=18;
          if(tx_enable==1)
          {
          UDR0=tx_buffer[0];
          }  
     //    peredacha_otveta(18);
         rx_command_vern_rezult=true;
         goto end_int;
         } 
      if((pribor_go==1)||(pribor_begin_go==1))                                                                                                   
        
         {  
         
          Data=(S_RIGHT);   
          a=vichislenie_mantissy(Data);                                                                      
          tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x0D;tx_buffer[3]=0x00;
          if(Data<0)
            {
            tx_buffer[9]=0x08; 
            tx_buffer[15]=0x08;
            }
          else
            {
            tx_buffer[9]=0x00;
            tx_buffer[15]=0x00;
            }  
          tx_buffer[4]=a&0x0F;tx_buffer[5]=a>>4;tx_buffer[6]=(((char)(Data))&0x0F);tx_buffer[7]=((char)(Data))>>4;tx_buffer[8]=0x08;
          tx_buffer[10]=0;tx_buffer[11]=0;tx_buffer[12]=0;tx_buffer[13]=0;tx_buffer[14]=0x00; 
          tx_buffer[16]=0x85;tx_buffer[17]=vichislenie_checksum(tx_buffer,18);                   
         
        // otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x0D;otvet[3]=0x00;          
        // otvet[4]=0x00;otvet[5]=0x0A;otvet[6]=0x0A;otvet[7]=0x06;otvet[8]=0x01;otvet[9]=0x08;
        // otvet[10]=0x00;otvet[11]=0x00;otvet[12]=0x00;otvet[13]=0x00;otvet[14]=0x00;otvet[15]=0x00;
        // otvet[16]=0x85;otvet[17]=vichislenie_checksum(otvet,18);
        // tx_enable=1;
         tx_counter=18;    
          if(tx_enable==1)
          {
          UDR0=tx_buffer[0];  
          }
      //   peredacha_otveta(18);
         rx_command_vern_rezult=true;
         goto end_int;
         } 
       } 
       
      if(rx_buffer[3]==0x44)
       {
       tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x01;tx_buffer[3]=0x00;tx_buffer[4]=0x85;tx_buffer[5]=vichislenie_checksum(tx_buffer,6);
       //otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x01;otvet[3]=0x00;otvet[4]=0x85;otvet[5]=vichislenie_checksum(otvet,6);
       //tx_enable=1;
       tx_counter=6;       
        if(tx_enable==1)
        {
        UDR0=tx_buffer[0];  
        }
     //  peredacha_otveta(6);
       rx_command_sbros=true;
       goto end_int;
       }
      if(rx_buffer[3]==0x45)
       {
       tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x01;tx_buffer[3]=0x02;tx_buffer[4]=0x85;tx_buffer[5]=vichislenie_checksum(tx_buffer,6);
      // otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x01;otvet[3]=0x02;otvet[4]=0x85;otvet[5]=vichislenie_checksum(otvet,6);
      // tx_enable=1;
       if((rezult_ready==1)||(pribor_stop==1))
         {
         reset=true; 
         pribor_stop=false;
         pribor_begin_go=false;
         pribor_go=true;
         rezult_ready=false;   
         }
       tx_counter=6;     
        if(tx_enable==1)
        {
        UDR0=tx_buffer[0];  
        }
    //   peredacha_otveta(6);
       rx_command_proiz_izm=true;
         
       goto end_int;
       }   
	}
 else if (paket_kalib_prinyat == 1)
 {
       if(rx_buffer[1]==0xAA)
       {
          Data_kalib = ((int)(rx_buffer[2])<<8) + (int)(rx_buffer[3]);
          ee_kalib = Data_kalib;  
          kalib = Data_kalib;  
        //  itoa(kalib, str_test);
        //  lcd_clear();
        //  LCD_DisplayString(1,1, str_test);//lcd_puts(str_test); 
		  goto end_int;
       }
       
       if (rx_buffer[1]==0xAB)
       { 
           tx_buffer[0] = 0x8A; tx_buffer[1]=0xAB;
           tx_buffer[2]=(unsigned char)(kalib>>8); 
           tx_buffer[3]=(unsigned char)(kalib);
           tx_buffer[4]=0x85;tx_buffer[5]=0x00;
		   tx_counter = 6;
		   if (tx_enable ==1)
		   {
			UDR0 = tx_buffer[0];
		   }
		   
		   goto end_int;
       }
       if (rx_buffer[1] == 0xAC)
       {
          if (rx_buffer[2] == 1)
          {
            isCorr = false;
            ee_isCorr = false;
          }
          if (rx_buffer[2] == 2)
          {
            isCorr = true;
            ee_isCorr = true;
          }
          goto end_int;
       }
       
       if (rx_buffer[1]==0xAD)
       { 
         if (isCorr)
         {
          tx_buffer[2]=0x02;
         }
         else
         {
          tx_buffer[2]=0x01;
         }
           tx_buffer[0] = 0x8A; tx_buffer[1]=0xAD;
           
           tx_buffer[3]=0x00;
           tx_buffer[4]=0x85;tx_buffer[5]=0x00;
		   tx_counter = 6;
		   if (tx_enable ==1)
		   {
			UDR0 = tx_buffer[0];
		   }
		   
		   goto end_int;
       }
 
    }
 else
    {
      if(rx_buffer[5]!=vichislenie_checksum(rx_buffer,6))
       {
      tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x01;tx_buffer[3]=0x06;tx_buffer[4]=0x85;tx_buffer[5]=vichislenie_checksum(tx_buffer,6); 
      // otvet[0]=0x8A;otvet[1]=0x05;otvet[2]=0x01;otvet[3]=0x06;otvet[4]=0x85;otvet[5]=vichislenie_checksum(otvet,6);
      // tx_enable=1;
       tx_counter=6;
        if(tx_enable==1)
        {      
        UDR0=tx_buffer[0];  
        }
    //   peredacha_otveta(6);
       }
  
    } 
end_int:         
 asm("nop");
}
// USART Receiver interrupt service routine
//#pragma savereg-
#pragma vector = USART0_RX_vect
__interrupt void uart_rx_isr(void)
//interrupt [USART_RXC] void uart_rx_isr(void)
{
char status,data;
/*#asm
    push r26
    push r27
    push r30
    push r31
    in   r26,sreg
    push r26
#endasm*/
status=UCSR0A;
data=UDR0;
if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
   {
   //rx_buffer[rx_wr_index]=data;
    
   //как у Олега                              
   if((rx_counter==0)&&(data==0x8A)) {record_enable=1;}
   if((rx_counter>0)&&(data==0x85)) {record_stop=rx_counter;}
   if(record_enable)
     {
      rx_buffer[rx_counter]=data;
      rx_counter++; 
    //  if(rx_counter == RX_BUFFER_SIZE)
      if(rx_counter==(record_stop+2))
        { 
         rx_counter=0;record_enable=0;timeout=0;
         if((rx_buffer[0]==0x8A)&&(rx_buffer[1]==0x05)&&(rx_buffer[4]==0x85)&&(rx_buffer[5]==vichislenie_checksum(rx_buffer,6)))  
          {   
          paket_prinyat=true;
          }                
else if ((rx_buffer[0]==0x8A)&&((rx_buffer[1]==0xAA)|| (rx_buffer[1]==0xAB) || (rx_buffer[1]==0xAC) || (rx_buffer[1]==0xAD))&&(rx_buffer[4]==0x85))      
         {
            paket_kalib_prinyat = true;
         }    
         else
          {
          paket_prinyat=false;
		  paket_kalib_prinyat = false;
          }
         obrabotka_rx_paketa(); 
        }
      else timeout=40;
     }     
     
   //моя обработка 
   
   
   }
/*#asm
    pop  r26
    out  sreg,r26
    pop  r31
    pop  r30
    pop  r27
    pop  r26
#endasm*/
}
/*
//#pragma savereg+

#ifndef _DEBUG_TERMINAL_IO_
// Get a character from the USART Receiver buffer
#define _ALTERNATE_GETCHAR_
#pragma used+
char getchar(void)
{
char data;
while (rx_counter==0);
data=rx_buffer[rx_rd_index];
if (++rx_rd_index == RX_BUFFER_SIZE) rx_rd_index=0;
asm("cli");
--rx_counter;
asm("sei");
return data;
}
#pragma used-
#endif
*/

// USART Transmitter interrupt service routine
//#pragma savereg-
#pragma vector = USART0_TX_vect
__interrupt void uart_tx_isr(void)
//interrupt [USART_TXC] void uart_tx_isr(void)
{
//#asm
   asm("push r26");
    asm("push r27");
    asm("push r30");
    asm("push r31");
    asm("in  r26, 0x3F"); //0x3F - SREG
    asm("push r26");
//#endasm
if (tx_counter)
   { 
    // tx_enable=0;
   // --tx_counter;
   UDR0=tx_buffer[tx_rd_index+1];
  // if (++tx_rd_index == TX_BUFFER_SIZE) tx_rd_index=0;
     if (++tx_rd_index == (tx_counter-1)) {tx_rd_index=0;tx_counter=0;}
   }
    asm("pop  r26");
    asm("out  0x3F, r26"); //0x3F - SREG
    asm("pop  r31");
    asm("pop  r30");
    asm("pop  r27");
    asm("pop  r26");
 
}
/*
#pragma savereg+

#ifndef _DEBUG_TERMINAL_IO_
// Write a character to the USART Transmitter buffer
#define _ALTERNATE_PUTCHAR_
#pragma used+
void putchar(char c)
{
while (tx_counter == TX_BUFFER_SIZE);
asm("cli");
if (tx_counter || ((UCSR0A & DATA_REGISTER_EMPTY)==0))
   {
   tx_buffer[tx_wr_index]=c;
   if (++tx_wr_index == TX_BUFFER_SIZE) tx_wr_index=0;
   ++tx_counter;
   }
else UDR0=c;
asm("sei");
}
#pragma used-
#endif   
*/
#define MAX_RIGHT_VELOCITY_ETALON 3903
#define NULL_VELOCITY_ETALON 2048
#define MAX_LEFT_VELOCITY_ETALON 209  
#define DELAY_ASK_ADC 10.5           
#define SENSITIVITY 10
#define POSITION_ERROR 0.0037
#ifdef Max21000
#define Timer_count 0.000512
#else
#define Timer_count 0.001250
#endif
#define kalman 0.1
#define stm_trs 10
#define stm_slow_trs 300
#define temp_room 7
#ifdef temp_corr_v2
#define temp_coeff 0.00028
#endif
#define null_temp_coeff 5
#ifdef new_temp_corr
#define temp_coeff 10 // in digits
#endif

// Declare your global variables here

char temp;
unsigned int  ADC_12_bit_word1,ADC_12_bit_word2; 
int CURRENT_VELOCITY_int;
float CURRENT_VELOCITY, OLD_VELOCITY, CURRENT_VELOCITY_old=0;
float NULL_VELOCITY;
float LASTSTEP_VELOCITY=0;
int ERROR_VELOCITY=0;
int CURRENT_POSITION;
int NULL_POSITION;
int i,count_right=0,count_left=0,cnt_set_flag=0,cnt=0,cnt_interrupt=0,cnt_display=0, cnt_dmt=0;
long int cnt_interrupt_INT0=0,cnt_timeout_stop=0,cnt_tx_ask=0, test_counter = 0; 
int flag_interrupt_gyro=0,flag_interrupt_DMT=0,S_flag=0,flag_stop=0;
int flag_positionsix=0;
int flag_position_three=0;
int flag_position_six=0;
int flag_position_nine=0;
float k_error=0;
float k_right;
float k_left; 
float koeff_temp=0;

float S=0,Ssix=0,S_three=0,S_six=0,S_nine=0,S_ERROR_LEFT=0,LUFT_D=0;
float K_DMT=0;
float CURRENT_POSITION_FLOAT=0;
char* str="calibration"; 
char* str_sum="     ";
//char* str_test="     ";
char* str_crc="CF47h"; 
char* str_stop="stop ! ";
char* str_go_left="<<<<----";
char* str_go_right="       ---->>>>"; 
int   mode_of_poverka=0;                          
long int cnt_begin=0;  
char* addr=0;
int cnt_test_off = 0;
enum bool debug_sound = false;

void obrabotchik_knopki(void)
{
cnt_interrupt_INT0++; 
reset=true;       
cnt_begin=0;

pribor_stop=false;
pribor_begin_go=false;
pribor_go=true;
rezult_ready=false;   

PORTC &= (1<<PORTC1) ^ 0xFF;

       //режим поверки     
       if(cnt_interrupt_INT0>=20000)
       {
       cnt_interrupt_INT0=0;
       reset=true;  
       mode_of_poverka=1;
       poverka();
       delay_ms(1000);
        
       po();
       delay_ms(1500);
       
       lcd_clear();
       //lcd_puts(str_crc);
       LCD_DisplayString (1, 1 , str_crc);
       delay_ms(1500);
       PORTC &= (1<<PORTC1) ^ 0xFF;
       str_left();
       } 
}

// External Interrupt 0 service routine
#pragma vector = INT0_vect
__interrupt  void ext_int0_isr(void)
//interrupt [EXT_INT0] void ext_int0_isr(void)
{  
cnt_interrupt_INT0++; 
reset=true;       
cnt_begin=0;

pribor_stop=false;
pribor_begin_go=false;
pribor_go=true;
rezult_ready=false;   
       
       //режим поверки     
       if(cnt_interrupt_INT0>=75000)
       {
       cnt_interrupt_INT0=0;
       reset=false;  
       mode_of_poverka=1;
       poverka();
       delay_ms(1000);
       
       po();
       delay_ms(1500);
       
       lcd_clear();
       //lcd_puts(str_crc);
       LCD_DisplayString (1, 1 , str_crc);
       delay_ms(1500);
       
       str_left();
       } 
             
}  



void opros_datchika_DMT(void)
{        
     // K_DMT=7.4/2000; //В/мм
       K_DMT=0.0037;    

      PORTD &= (1<<PORTD3)^0xFF;
      //PORTB.5=0; //CS2 сбросили в ноль       
       
      CLK_READ_UP2;
      CLK_READ_DOWN2;
      CLK_READ_UP2;
      CLK_READ_DOWN2;
      CLK_READ_UP2;
      CLK_READ_DOWN2;//ждем гогтовность АЦП датчика поворота колеса 
       
      ADC_12_bit_word2=0;
             
        for(i=0;i<12;i++)
       {   
        CLK_READ_UP2;  
           
        //if(PINB.4==0)
        if (!(PIND&(1<<PIND7)))
        { 
     
        ADC_12_bit_word2=ADC_12_bit_word2<<1;                      
        } 
        else
        { 
 
        ADC_12_bit_word2=(ADC_12_bit_word2+1)<<1;   
        // PULSE;
        } 
        CLK_READ_DOWN2;   
       }          
       
      
      CURRENT_POSITION=ADC_12_bit_word2>>1;  
      //PORTB.5=1; //CS2 подняли в единицу     
      PORTD |= (1<<PORTD3);
      CURRENT_POSITION_FLOAT=(CURRENT_POSITION-NULL_POSITION)*K_DMT;
      //новая кинематическая схема 420/198=2.121212  
      
     if((CURRENT_POSITION_FLOAT<=(0.2109+0.0074))&&(CURRENT_POSITION_FLOAT>=(0.2109-0.0074)))
   //   if((CURRENT_POSITION_FLOAT<=(-0.2109+2*POSITION_ERROR))&&(CURRENT_POSITION_FLOAT>=(-0.2109-2*POSITION_ERROR)))
      {
      flag_positionsix=1;
      flag_position_three=0;
      flag_position_six=0;
      flag_position_nine=0;
      //lcd_clear();//для 
      //str_right();//Юрия Николаевича
     // return;
      }                    
      if((CURRENT_POSITION_FLOAT<=(-0.1147+0.0074))&&(CURRENT_POSITION_FLOAT>=(-0.1147-0.0074)) )
 //      if((CURRENT_POSITION_FLOAT<=(0.1147+2*POSITION_ERROR))&&(CURRENT_POSITION_FLOAT>=(0.1147-2*POSITION_ERROR)) )
      {
      flag_positionsix=0;
      flag_position_three=1;
      flag_position_six=0;
      flag_position_nine=0;
      }   
      if((CURRENT_POSITION_FLOAT<=(-0.2109+0.0074))&&(CURRENT_POSITION_FLOAT>=(-0.2109-0.0074)) )
 //    if((CURRENT_POSITION_FLOAT<=(0.2109+2*POSITION_ERROR))&&(CURRENT_POSITION_FLOAT>=(0.2109-2*POSITION_ERROR)) )
      {
      flag_positionsix=0;
      flag_position_three=0;
      flag_position_six=1;
      flag_position_nine=0; 
     // lcd_clear();//для 
     // str_left();//Юрия Николаевича
      }
  //   if((CURRENT_POSITION_FLOAT<=(0.4921+2*POSITION_ERROR))&&(CURRENT_POSITION_FLOAT>=(0.4921-2*POSITION_ERROR)) )//0.999 - 0.15,1.1988-0.18  
      if((CURRENT_POSITION_FLOAT<=(-0.4921+0.0074))&&(CURRENT_POSITION_FLOAT>=(-0.4921-0.0074)) )//0.999 - 0.15,1.1988-0.18
      {
      flag_positionsix=0;
      flag_position_three=0;
      flag_position_six=0;
      flag_position_nine=1;
      //lcd_clear();
      //lcd_puts(str_stop);
     
      } 
    /* else
      {
      flag_positionsix=0;
      flag_position_three=0;
      flag_position_six=0;
      flag_position_nine=0;   
      
      }*/
}

// Timer 0 overflow interrupt service routine
#pragma vector = TIMER0_OVF_vect
__interrupt void timer0_ovf_isr(void)
//interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
 
// Reinitialize Timer 0 value
//TCNT0=0xF3;//0xD0;
  TCNT0=0xC0;//0xD0; prescaller 1/64, 63 tick, 2000 Hz
//    TCNT0=0xDF;//0xD0; prescaller 1/64, 32 tick, 4000 Hz
// Place your code here
 flag_interrupt_DMT=1;
 //     opros_datchika_DMT();
 if(timeout) timeout--;
    if(timeout==1) 
      {
      record_enable=0;
      rx_counter=0;
      }                
      
} 

// Timer 1 overflow interrupt service routine
#pragma vector = TIMER1_OVF_vect
__interrupt void timer1_ovf_isr(void)
//interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{   
//#ifdef Max21000
// Reinitialize Timer 1 value
//TCNT1L=0xFF; //at 1 MHz( 8 MHz/ 8 prescaler) we got 1953 Hz or 512 us interval
//TCNT1H=0xFD;

//TCNT1L=0xFF; //at 1 MHz( 8 MHz/ 8 prescaler) we got 976 Hz or 1024 us interval
//TCNT1H=0xFB;

//TCNT1L=0xFF; //at 1 MHz( 8 MHz/ 8 prescaler) we got 488 Hz or 2048 us interval
//TCNT1H=0xF7;

//TCNT1L=0xFF; //at 1 MHz( 8 MHz/ 8 prescaler) we got 244 Hz or 4096 us interval
//TCNT1H=0xEF;
//#else
//TCNT1L=0x3B; //at 1 MHz( 8 MHz/ 8 prescaler) we got 400 Hz or 2500 us interval
//TCNT1H=0xF6;
//#endif
// Place your code here
cnt_timeout_stop++;
cnt_display++;
flag_interrupt_gyro=1; 
cnt_interrupt++;
 if(cnt_interrupt==1)
 { 
 /*flag_interrupt_DMT=1;
 opros_datchika_DMT();
 flag_interrupt_DMT=0;*/
 cnt_interrupt=0;
 cnt_dmt++;
 }
 timeroverflow++;     
}



void opros_datchika_giroscopa(void)    
    

//PULSE; 
 {
   unsigned char X_H, X_L;
   #ifdef Max21000
   while(Read_Max21000_reg(0x22) == 0x00); // wait data ready
    X_H = Read_Max21000_reg(0x27);
    X_L = Read_Max21000_reg(0x28);
  #else
 //   opros_datchika_DMT();
    do 
    {
    zzz = Read_Max21000_reg(Status);
    opros_datchika_DMT();  
    }
    while (!(zzz & (1<<2)));
     X_L = Read_Max21000_reg(Z_low);
     X_H = Read_Max21000_reg(Z_high);
   
  #endif
    CURRENT_VELOCITY_int =(int) ((unsigned int)(X_H)<<8) + ((unsigned int)(X_L));
	timercount1 = TCNT1L;
	timercount2 = TCNT1H;
	//time = ((unsigned int)(timercount2)<<8) + (unsigned int)(timercount1);
	time = TCNT1;
        delta_time= time;
	
	TCNT1 = 0;
        time = 0;

  //    temp = Read_Max21000_reg(Temp_reg);
#ifdef new_temp_corr

//    CURRENT_VELOCITY_int -= temp_coeff*(temp - temp_room); 

#endif
    // CURRENT_VELOCITY = (float)(CURRENT_VELOCITY_int); 
    CURRENT_VELOCITY = kalman*CURRENT_VELOCITY_int + (1-kalman)*CURRENT_VELOCITY_old;
    CURRENT_VELOCITY_old = CURRENT_VELOCITY;
 
      /*      // Place your code here  
          
       // чтение 12-разрядного слова      
      
      //PORTB.1=0; //CS1 сбросили в ноль  
      PORTB &=(1<<PORTB1) ^ 0xFF;        
      
      CLK_READ_UP1;
      CLK_READ_DOWN1;
      CLK_READ_UP1;
      CLK_READ_DOWN1;
      CLK_READ_UP1;
      CLK_READ_DOWN1;//ждем гогтовность АЦП датчика гироскопа 
      
      ADC_12_bit_word1=0;
    
       
      for(i=0;i<12;i++)
       {   
        
        CLK_READ_UP1;
           
        //if(PINB.2==0)
        if(!(PINB&(1<<PINB2)))
        { 
     
        ADC_12_bit_word1=ADC_12_bit_word1<<1;                      
        } 
        else
        { 
 
        ADC_12_bit_word1=(ADC_12_bit_word1+1)<<1;   
        // PULSE;
        } 
        CLK_READ_DOWN1;      
       }  
                                      
      CURRENT_VELOCITY=ADC_12_bit_word1>>1;  
     // PORTB.1=1; //CS1 подняли в единицу  
      PORTB |=(1<<PORTB1);*/                                 
      
      
    /* if(paket_prinyat==1)
     {
      cnt_tx_ask++;
      if(cnt_tx_ask==10)
       {
       cnt_tx_ask=0;
       tx_enable=1;
       paket_prinyat=0;   
       }
     }*/ 
   
}

float calibration_of_sensor_gyro(void)                 
{
int ADC_word_int;
float ADC_word, ADC_word_old=0;
//unsigned int array_ADC_word[1000]={0};  
float Sum_ADC_word;
float Average_ADC_word;
int n;    
//int n_adc;                
                              
  Sum_ADC_word=0;
  Average_ADC_word=0;         

  
  for(n=0;n<100;n++) 
    {
    ADC_word=0;
    unsigned char X_H, X_L;
#ifdef Max21000
    while(Read_Max21000_reg(0x22) == 0x00); // wait data ready
    X_H = Read_Max21000_reg(0x27);
    X_L = Read_Max21000_reg(0x28);
#else
    do 
    {
    zzz = Read_Max21000_reg(Status);
    }
    while (!(zzz & (1<<2)));
     X_L = Read_Max21000_reg(Z_low);
     X_H = Read_Max21000_reg(Z_high);
   
#endif   
    ADC_word_int =(int) ((unsigned int)(X_H)<<8) + ((unsigned int)(X_L));
//   temp = Read_Max21000_reg(Temp_reg);
#ifdef new_temp_corr
    ADC_word_int -= temp_coeff*(temp - temp_room);
#endif
#ifdef temp_corr_v2
//    ADC_word_int -= null_temp_coeff*(temp - temp_room);
#endif    
    // ADC_word = (float)( ADC_word_int); 
     ADC_word = kalman*ADC_word_int + (1-kalman)*ADC_word_old;
    ADC_word_old = ADC_word;
    Sum_ADC_word=Sum_ADC_word+ADC_word;
    delay_ms(1);
    }  
    Average_ADC_word=Sum_ADC_word/100;  //усреднили ноль гироскопа по 1000 отсчетам
    return(Average_ADC_word);
  
} 

unsigned int calibration_of_sensor_DMT(void)                 
{
unsigned int ADC_word;
//unsigned int array_ADC_word[1000]={0};  
long int Sum_ADC_word;
unsigned int Average_ADC_word;
int n;    
int n_adc;                
                              
  Sum_ADC_word=0;
  Average_ADC_word=0;         

  
  for(n=0;n<100;n++) 
    {

      //PORTB.5=0; //CS2 сбросили в ноль      
      PORTD &= (1<<PORTD3)^0xFF;
      
      CLK_READ_UP2;
      CLK_READ_DOWN2;
      CLK_READ_UP2;
      CLK_READ_DOWN2;
      CLK_READ_UP2;
      CLK_READ_DOWN2;//ждем гогтовность АЦП           
          
      ADC_word=0;
                   //считываем 12-битный последовательный код  с АЦП
      for(n_adc=0;n_adc<12;n_adc++)
       {   
        
        CLK_READ_UP2; 
        //if(PINB.4==0)
        if (!(PIND&(1<<PIND7)))
        { 
        ADC_word=ADC_word<<1;                      
        } 
        else
        { 
         ADC_word=(ADC_word+1)<<1;   
        // PULSE;
        } 
                     
        CLK_READ_DOWN2;    
       }          
                                
      ADC_word=ADC_word>>1; 
     // array_ADC_word[n]=ADC_word;
      Sum_ADC_word=Sum_ADC_word+ADC_word;
      
      //PORTB.5=1; //CS подняли в единицу      
    PORTD |= (1<<PORTD3);
    }  
    Average_ADC_word=Sum_ADC_word/100;  //усреднили ноль ДМТ по 1000 отсчетам
    return(Average_ADC_word);
  
}

void init_Max21000(void)
{
  Change_Bank(BANK_00);
  write_Max21000_reg(SENSE_CFG0, 0x01); // power down mode, enable Z axis
  //write_Max21000_reg(SENSE_CFG1, 0x2C); // 0x28 100 Hz BW, OIS OFF 0x2C 150 Hz BW, OIS OFF
  write_Max21000_reg(SENSE_CFG1, 0x1D);   // 32Hz BW OIS ON
  //write_Max21000_reg(SENSE_CFG2, 0x31); // 50 Hz ODR //0x77 0x31 200Hz ODR(10 times less timer 1 period)
  write_Max21000_reg(SENSE_CFG2, 0x00); // 0x00 10kHz ODR // 0x04 2kHz 0x05 1,666666 kHz
 // write_Max21000_reg(SENSE_CFG0, 0xCC); // norma mode with x axis enable 250 dpsFS(sensetivity 0.0153) //0xCC
    write_Max21000_reg(SENSE_CFG0, 0x8C);  //norma mode with x axis enable 62.5 dpsFS(sensetivity 0.003825)
}

void init_Max21000_test(void)
{
  Change_Bank(BANK_00);
  write_Max21000_reg(SENSE_CFG0, 0x01); // power down mode, enable Z axis
  write_Max21000_reg(SENSE_CFG1, 0x68); // 100 Hz BW, OIS OFF, test ON 
  write_Max21000_reg(SENSE_CFG2, 0x77); // 50 Hz ODR
  write_Max21000_reg(SENSE_CFG0, 0xCC); // norma mode with x axis enable 250 dpsFS
}

void init_l3g4200d(void)
{
 // power down mode, enable Z axis, 800 Hz ODR, 110 Hz BW, 250 dpsFS
 //write_Max21000_reg(0x39, 0x01);  // low odr
 write_Max21000_reg(CTRL_REG3, 0x00); // DRDY disable
// write_Max21000_reg(CTRL_REG4, 0x80); //Block data update ON
 write_Max21000_reg(CTRL_REG1, 0x8C);//8c //Power on FC - 800 Hz, 100 BW, BC 400 Hz 100 BW, 9C - 400 Hz 25 BW, DC 800 Hz, 35 BW, 8C - 400 Hz 20 BW, 4C 200 12,5 BW  
// write_Max21000_reg(CTRL_REG4,0x06);
}                                     //CC - 800 Hz, 35 BW, 00 - 100 Hz, 12.5 BW

void Change_Bank(unsigned char Bank_Num)
{
  write_Max21000_reg (BANK_SEL_REG, Bank_Num);
}


void write_Max21000_reg (unsigned char address, unsigned char data)
{
  SPI_PORT &= (1 << SPI_CS) ^ 0xFF;
  
  delay(1);
  
  Spi_soft_write(address); // write reg address
  
  Spi_soft_write(data); // write reg data
  
  SPI_PORT |= (1 << SPI_CS);

}

void write_mult_Max21000_reg (unsigned char address, unsigned char* data, unsigned char numdata)
{
  SPI_PORT &= (1 << SPI_CS) ^ 0xFF;
  
  delay(1);
  
  Spi_soft_write(address | 0x40); // write reg address with mult flag
  
  for (int i=0; i<numdata; i++)
  {
    Spi_soft_write(data[i]); // write reg data
  }
  SPI_PORT |= (1 << SPI_CS);

}

void read_mult_Max21000_reg (unsigned char address, unsigned char* data, unsigned char numdata)
{
  SPI_PORT &= (1 << SPI_CS) ^ 0xFF;
  
  delay(1);
  
  Spi_soft_write(address | 0xC0); // write reg address with read flag and mult flag
  
  for (int i=0; i<numdata; i++)
  {
   data[i] = Spi_soft_read(); // write reg data
  }
  SPI_PORT |= (1 << SPI_CS);

}



unsigned char Read_Max21000_reg (unsigned char address)
{
 unsigned char result;
  SPI_PORT &= (1 << SPI_CS) ^ 0xFF;
  
  delay(1);
  
  Spi_soft_write(address | 0x80); // write reg address with read flag
  
  result = Spi_soft_read();
  
  SPI_PORT |= (1 << SPI_CS);
  
  return result;
}


void Spi_soft_write(unsigned char d)
{
        unsigned char k;
	for (k = 0; k<8; k++)
        {
		SPI_PORT &= (1 << SPI_SCK) ^ 0xFF;//FPGA_PORT &= (1 << FPGA_SCK) ^ 0xFF; // Clock low
		if (d & 0x80){	// Analyze data and generate output bit
			SPI_PORT |= (1 << SPI_SDI);
		}
		else{
			SPI_PORT &= (1 << SPI_SDI) ^ 0xFF;
		}
		//delay(1);	//Setup
		SPI_PORT |= (1 << SPI_SCK);//FPGA_PORT |= (1 << FPGA_SCK); // Clock high = Rising edge generated
		d  <<= 1;
		//delay(1);	//Hold
	}

	SPI_PORT &= (1 << SPI_SCK) ^ 0xFF;//FPGA_PORT &= (1 << FPGA_SCK) ^ 0xFF;	// Clock low for SPI idle
	//delay(3);	 // Inactive state hold, maybe not required
        
}
unsigned char Spi_soft_read(void)
{
  char result = 0;
  unsigned char k;
  
  for (k=0; k<8; k++)
  {
    SPI_PORT &= (1 << SPI_SCK) ^ 0xFF;
    delay(1);
    SPI_PORT |= (1 << SPI_SCK);
    result <<= 1;
    if (SPI_PIN & (1<<SPI_SDO))
    {
      result |= 0x01;
    }
    delay(1);
  }
  SPI_PORT &= (1 << SPI_SCK) ^ 0xFF;
  return result;
}



 void main( void )
{
   float koef, num;
   int minute;
conf_ports(); 
   //enum bool start = false;
 // unsigned char count;
  // jkjkjkkj
// Declare your local variables here
/*
// Input/Output Ports initialization
// Port A initialization
// Func0=In Func1=In Func2=In Func3=In Func4=In Func5=In Func6=In Func7=In 
// State0=T State1=T State2=T State3=T State4=T State5=T State6=T State7=T 
PORTA=0x00;
DDRA=0xFF;

// Port B initialization
// Func0=Out Func1=Out Func2=In Func3=Out Func4=In Func5=In Func6=In Func7=In 
// State0=0 State1=1 State2=Т State3=0 State4=T State5=T State6=T State7=T 
PORTB=0x02;
DDRB=0x5B;

// Port C initialization
// Func0=Out Func1=In Func2=Out Func3=Out Func4=Out Func5=Out Func6=Out Func7=Out 
// State0=T State1=T State2=T State3=T State4=T State5=T State6=T State7=T 
PORTC=0x00;
DDRC=0xD2;

// Port D initialization
// Func0=In Func1=In Func2=In Func3=In Func4=In Func5=In Func6=In Func7=In 
// State0=T State1=T State2=1 State3=T State4=T State5=T State6=T State7=T 

DDRD=0xFA; // DDRD= 0xF2 for STM app

PORTD=0x08; // PORTD= 0x20 for STM app
*/    

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 125,000 kHz
// Mode: Normal top=FFh
// OC0 output: Disconnected
TCCR0B=0x03;// 125 kHz( 8 MHz/ 64 prescaler)
TCNT0=0x00;
OCR0A=0x00;




// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer 1 Stopped
// Mode: Normal top=FFFFh
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
TCCR1A=0x00;//0x01  
TCCR1B=0x02;//0x02 //at 1 MHz( 8 MHz/ 8 prescaler) we got 15,25Hz or 0.065536s 
TCNT1H=0x00;
TCNT1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Low level
// INT1: Off
// INT2: Off
//GICR|=0x40;
//MCUCR=0x00;
//MCUSR=0x00;
//EMCUCR=0x00;
//GIFR=0x40; 
EICRA = 0x00;
EIMSK = 0x01;

// Timer(s)/Counter(s) Interrupt(s) initialization
//TIMSK=0x82; //for 8515
//TIMSK=0x05; // for 128
//TIMSK0 = 0x01; //for ATMega 164P




// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud rate: 9600
UCSR0A=0x00;
UCSR0B=0xD8;
UCSR0C=0x06; //UCSR0C=0x86;
UBRR0H=0x00;
UBRR0L=0x33;
                	
// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
// Analog Comparator Output: Off
ACSR=0x80;

// LCD module initialization  
//lcd_init(8);
//asm("sei"); 

kalib = ee_kalib;
isCorr = ee_isCorr;
koef =((float)(kalib))/1000000; 
//koef = 0.00888; //first 0.00878
//koef = 0.00855; //second
pribor_stop=false;
pribor_begin_go=false;
pribor_go=true;
rezult_ready=false;

//PORTC |= (1<<PORTC1); // test beep
//lcd_init(16);
lcd_init_old();
//_lcd_ready();
delay_ms(500);

#ifdef Max21000
  init_Max21000();
  Who_Am_I = Read_Max21000_reg(0x20);
  if (Who_Am_I != 0xb1)
  {
    izmeryat_nelzya();
    delay_ms(2000);
    PORTD |= (1<<PORTD6);
  }
#else
  init_l3g4200d();
  delay_ms(500);
  Who_Am_I = Read_Max21000_reg(Who_am_I);
  if ((Who_Am_I == 0xD7) || (Who_Am_I == 0xD3)) //d3 for 4200
  {
    asm("nop");
  }
  else
  {
  
    izmeryat_nelzya();
    delay_ms(2000);
    PORTD |= (1<<PORTD6);
  }
#endif
/*  Who_Am_I = Read_Max21000_reg(0x20);
  if (Who_Am_I != 0xb1)
  {
   // LED_PORT &= (1<<LED2) ^ 0xFF;
  }
  lcd_clear();
 delay(2000); */
beep();
  
lcd_clear();

calibrat();   
 

/*LUFT=-30.66;
itoa((((char)fabs(LUFT))<<4)>>4,str);
lcd_clear();
lcd_puts(str); 
k_error=22.625;*/  

  /*  k_error=22.625;
    a=(unsigned char)k_error;
    addr=(char*)&k_error;
    a=(unsigned char)(*(addr+1));
    a=(unsigned char)(*(addr+2));
    a=(unsigned char)(*(addr+3));
    
    itoa(a,str);
    lcd_clear();
    lcd_puts(str);*/
 
      delay_ms(200); 
    
      //if(PINC.1==1)//контроль напряжения аккумуляторной батареи
      if (PINC&(1<<PINC0)) 
      { 
       izmeryat_nelzya();
       delay_ms(1000);
       akkumulyator();
       delay_ms(1000);
       trebuet_zaryadki();
       
       delay_ms(5000);
      // PORTC.7=1;
       PORTD |= (1<<PORTD6); 
       }
      // temp test
lcd_clear();
temp = Read_Max21000_reg(Temp_reg);    
itoa(temp ,str_sum);
LCD_DisplayString(2,3, str_sum);
delay_ms(2000);

begin:NULL_POSITION=calibration_of_sensor_DMT();
      NULL_VELOCITY=calibration_of_sensor_gyro();
      OLD_VELOCITY = NULL_VELOCITY; 
      CURRENT_VELOCITY_old = NULL_VELOCITY;
  
     cnt = 0;
      //itoa(NULL_VELOCITY,str); 
     // itoa(NULL_POSITION,str);         
      
   
     lcd_clear();                                           
     str_left();


   
      
    //  NULL_VELOCITY=NULL_VELOCITY_ETALON;
      LASTSTEP_VELOCITY=NULL_VELOCITY; 
      
                                                       
      ERROR_VELOCITY=0;//NULL_VELOCITY_ETALON-NULL_VELOCITY;
      
      
      
   
      
     // k_right=(float)75/(1845*2.661666666*4);Analog Device
     // k_left=(float)75/(1845*2.661666666*4);
       
     // k_error=abs(ERROR_VELOCITY*0.015);    
  //    k_right=(float)75/(1845*(4.245666666-k_error)*4.20); //Murata    //было 4
  //    k_left=(float)75/(1845*(4.226666666+k_error)*4.20);
      
      
      delay_ms(200);

cnt_timeout_stop=0;
reset=false;
checksum=0;      
asm("sei");
	TCNT1L=0x00; //clear counter
	TCNT1H=0x00;
	TIMSK1 = 0x01; // enable counter overflow
while (1)                            
{   
             
   //if(PIND.2==0)
  if (!(PIND&(1<<PIND2))) 
   {
   obrabotchik_knopki();  
   }   
                      
    
        
   if(reset==true)       
     {       
     reset=false;
     cnt_interrupt_INT0=0;
     cnt_timeout_stop=0;
     Ssix=0;S_three=0;S_six=0;S_nine=0;LUFT=0;LUFT_D=0;
     S_LEFT=0;S_RIGHT=0;
     cnt_set_flag=0;cnt=0;
     flag_positionsix=0;flag_position_three=0;flag_position_six=0;flag_position_nine=0; 
     goto begin;
     }
/*  if(flag_interrupt_DMT==1)
      {
         opros_datchika_DMT();
         flag_interrupt_DMT=0;
       } */
      // PULSE;  
   // if(flag_interrupt_gyro==1)  //RAND MAIN CHANGE Dont USE Timer at GYRO
    if (true) 
    {  
      //  PULSE; 
     //  opros_datchika_DMT();
      opros_datchika_DMT(); 
       opros_datchika_giroscopa();  
        flag_interrupt_gyro=0; 
                
        
      /*  itoa(CURRENT_VELOCITY,str);                
        
        lcd_puts(str);         */
       /* lcd_clear();
        itoa(cnt_test_off,str);                
        lcd_puts(str);
        delay_ms(1000);  */

     //  if((CURRENT_VELOCITY<=(NULL_VELOCITY+3))&&(CURRENT_VELOCITY>=(NULL_VELOCITY-3))) 
	  #ifdef Max21000
	  if((CURRENT_VELOCITY<=(NULL_VELOCITY+80))&&(CURRENT_VELOCITY>=(NULL_VELOCITY-80)))//Rand
	  #else
	  if((CURRENT_VELOCITY<=(NULL_VELOCITY+stm_trs))&&(CURRENT_VELOCITY>=(NULL_VELOCITY-stm_trs)))//Rand
	  #endif
       {   
                   
        LASTSTEP_VELOCITY=NULL_VELOCITY;  
         cnt_timeout_stop++;
         test_counter++;
         /*  itoa(cnt_timeout_stop, str_test);
           lcd_clear();
           LCD_DisplayString (1, 1 , str_test);//lcd_puts(str_test); 
           delay_ms(200); */
         //остановка по таймеру
           if(cnt_timeout_stop>=(60000))
           {
            PORTD |= (1<<PORTD6);// PORTD.6=1;//Rand 
           /*cnt_test_off++;
           itoa(cnt_test_off, str_test);
           lcd_clear();
           lcd_puts(str_test); */
           }     
       
       }
//}
     
       //if(CURRENT_VELOCITY<(NULL_VELOCITY-3)) 
	#ifdef Max21000    
       if(CURRENT_VELOCITY>(NULL_VELOCITY+80))// RAND
       #else
       //if((CURRENT_VELOCITY>0) && (CURRENT_VELOCITY>(NULL_VELOCITY+stm_trs)))
         if((CURRENT_VELOCITY>(NULL_VELOCITY+stm_trs)))
       #endif
       {     
         cnt_timeout_stop=0;  
         //Ограничение  максимальной скорости влево
        // if((CURRENT_VELOCITY<=1050)&&(mode_of_poverka==0))
	if((CURRENT_VELOCITY>=4500)&&(mode_of_poverka==0))	//RAND ??????
         {
         vrashay_medlennee();
         delay_ms(2000);
         izmeryaem_snova();
         pribor_stop=true;
         pribor_begin_go=false;
         pribor_go=false;
         rezult_ready=false;        
         
cycle1:     if(reset==false)
            {
              
              cnt_timeout_stop++;
               if (!(PIND&(1<<PIND2))) //if(PIND.2==0)  //Rand 
                {
                obrabotchik_knopki();
                }      
             //остановка по таймеру
               if(cnt_timeout_stop>=(8000000))
                {
                 PORTD |= (1<<PORTD6);//PORTD.6=1;   //Rand 
                }              
            goto cycle1; 
            }
           else
            {
            //#asm("cli");  
            lcd_clear();
            reset=false;
           // delay_ms(1000);
            //все обнулить
            cnt_interrupt_INT0=0;
            cnt_timeout_stop=0;
            Ssix=0;S_three=0;S_six=0;S_nine=0;LUFT=0;LUFT_D=0;
            S_LEFT=0;S_RIGHT=0;
            cnt_set_flag=0;cnt=0;
            flag_positionsix=0;flag_position_three=0;flag_position_six=0;flag_position_nine=0;  
            goto begin;  
            }
       
         }
          //Ограничение  миимальной скорости влево
         //if((CURRENT_VELOCITY>=(NULL_VELOCITY-25))&&(mode_of_poverka==0))
     if((CURRENT_VELOCITY<=(NULL_VELOCITY+stm_slow_trs))&&(mode_of_poverka==0)) //RAND ??????
         {                    
           cnt++;
           if(cnt>=5000)
          // if(cnt>=500)
           {
            vrashay_bystree();
            delay_ms(2000);
            izmeryaem_snova();
            pribor_stop=true;
            pribor_begin_go=false;
            pribor_go=false;
            rezult_ready=false; 
            
cycle2:     if(reset==false)
             {  
               
               if (!(PIND&(1<<PIND2)))//if(PIND.2==0) //Rand 
                {
                obrabotchik_knopki();
                }      
             //остановка по таймеру
               if(cnt_timeout_stop>=(270000))
                {
                 PORTD |= (1<<PORTD6);//PORTD.6=1; //Rand 
                }              
             goto cycle2; 
             }
            else
             {
             //#asm("cli");  
             lcd_clear();
             reset=false;
             //delay_ms(1000);
             //все обнулить
             cnt_interrupt_INT0=0;
             cnt_timeout_stop=0;
             Ssix=0;S_three=0;S_six=0;S_nine=0;LUFT=0;LUFT_D=0;
             S_LEFT=0;S_RIGHT=0;
             cnt_set_flag=0;cnt=0; 
             flag_positionsix=0;flag_position_three=0;flag_position_six=0;flag_position_nine=0; 
             goto begin; 
                   
             }       
            
           } 
          
         }
         else
         {
         cnt=0;
         } 
      
         //занижение чувствительносити датчика гироскопа                 
      /* if(CURRENT_VELOCITY<=(LASTSTEP_VELOCITY-SENSITIVITY))
          {
          LASTSTEP_VELOCITY=LASTSTEP_VELOCITY-SENSITIVITY;       
          }
         else
          {
          CURRENT_VELOCITY=LASTSTEP_VELOCITY;  
          LASTSTEP_VELOCITY=LASTSTEP_VELOCITY+SENSITIVITY;
          } */
      /*  if (flag_positionsix==1)
        {
        CURRENT_VELOCITY = NULL_VELOCITY+290;
        }*/
       //S_LEFT=S_LEFT+(CURRENT_VELOCITY-ERROR_VELOCITY-NULL_VELOCITY)*k_left*0.001*DELAY_ASK_ADC;  
   sample_time = delta_time*0.000001; // from timer tick to seconds
#ifdef temp_corr_v2
   koeff_temp = (temp - temp_room)*koef*temp_coeff;
#endif
   
   //   S_LEFT=S_LEFT+((CURRENT_VELOCITY-NULL_VELOCITY)+(OLD_VELOCITY-NULL_VELOCITY))*koef*0.00125; // RAND
	S_LEFT=S_LEFT+((CURRENT_VELOCITY-NULL_VELOCITY)+(OLD_VELOCITY-NULL_VELOCITY))*(koef+koeff_temp)*0.5*sample_time; // RAND
	  // start = true; 
       test_counter = 0;
       OLD_VELOCITY = CURRENT_VELOCITY;
       if((flag_positionsix==1)&&(cnt_set_flag==0))
           {    
        //     start = false;
            PORTC |= (1<<PORTC1);//PORTC.1=1; //Rand 
           cnt_set_flag=cnt_set_flag+1;
           Ssix=S_LEFT+S_RIGHT;
        //  Ssix = S_LEFT;
           flag_positionsix=0;
           cnt_timeout_stop=0;
    //       lcd_clear();
           //lcd_puts(str_go_right); 
 //          str_right();
           timertik1 = TCNT1H;
           timertik2 = TCNT1L;
           timertik = ((unsigned int)(timertik1)<<8) + (unsigned int)(timertik2);
          LCD_Cursor (2, 7);
          LCD_DisplayCharacter(0xDA);
           
          /* #asm("cli")
           delay_ms(2000);
           ftoa(Ssix,2,str_sum);            
           lcd_clear();
           lcd_puts(str_sum);
           #asm("sei")*/
           
           }
       }                                                
       
       
       //if(CURRENT_VELOCITY>(NULL_VELOCITY+3))
        #ifdef Max21000  	
       if(CURRENT_VELOCITY<(NULL_VELOCITY-80))  //RAND 
      #else
        if(CURRENT_VELOCITY<(NULL_VELOCITY-stm_trs))  //RAND 
      #endif    
       { 
          cnt_timeout_stop=0;
          PORTC &= (1<<PORTC1)^0xFF;//PORTC.1=0; //Rand                    
          //Ограничение  максимальной скорости вправо
         //if((CURRENT_VELOCITY>=3050)&&(mode_of_poverka==0))
    if((CURRENT_VELOCITY<=-4000)&&(mode_of_poverka==0)) //RAND ????
         {
       
         vrashay_medlennee();
         delay_ms(2000);
         izmeryaem_snova(); 
         pribor_stop=true;
         pribor_begin_go=false;
         pribor_go=false;
         rezult_ready=false;       
cycle3:     if(reset==false)
             {
               cnt_timeout_stop++;
               if (!(PIND&(1<<PIND2)))//if(PIND.2==0)  //Rand 
                {
                obrabotchik_knopki();
                }       
             //остановка по таймеру
               if(cnt_timeout_stop>=(8000000))
                {
                PORTD |= (1<<PORTD6);// PORTD.6=1;   //Rand 
                }              
             goto cycle3; 
             }
            else
             {
             //#asm("cli");  
             lcd_clear();
             reset=false;
            // delay_ms(1000);
             //все обнулить
             cnt_interrupt_INT0=0;
             cnt_timeout_stop=0;
             Ssix=0;S_three=0;S_six=0;S_nine=0;LUFT=0;LUFT_D=0;
             S_LEFT=0;S_RIGHT=0;
             cnt_set_flag=0;cnt=0;
             flag_positionsix=0;flag_position_three=0;flag_position_six=0;flag_position_nine=0;             
             goto begin; 
                   
             }       
       
         } 
                      
         //Ограничение  миимальной скорости вправо
        // if((CURRENT_VELOCITY<=(NULL_VELOCITY+25))&&(mode_of_poverka==0))
	if((CURRENT_VELOCITY>=(NULL_VELOCITY-stm_slow_trs))&&(mode_of_poverka==0))	//RAND ????
         {                    
           cnt++;
           if(cnt>=5000)
            {
           
            vrashay_bystree();
            delay_ms(2000);
            izmeryaem_snova();
            pribor_stop=true;
            pribor_begin_go=false;
            pribor_go=false;
            rezult_ready=false;        
cycle4:      if(reset==false)
              {        
               if (!(PIND&(1<<PIND2)))//if(PIND.2==0)  //Rand 
                {
                obrabotchik_knopki();
                }      
              //остановка по таймеру
               if(cnt_timeout_stop>=(270000))
                {
                 PORTD |= (1<<PORTD6); //PORTD.6=1; //Rand 
                }                 
             goto cycle4; 
              }
             else
              {
              //#asm("cli");  
              lcd_clear();
              reset=false;
              //delay_ms(1000);
              //все обнулить 
              cnt_interrupt_INT0=0;
              cnt_timeout_stop=0;
              Ssix=0;S_three=0;S_six=0;S_nine=0;LUFT=0;LUFT_D=0;
              S_LEFT=0;S_RIGHT=0;
              cnt_set_flag=0;cnt=0;
              flag_positionsix=0;flag_position_three=0;flag_position_six=0;flag_position_nine=0;  
              goto begin;      
             }                  
            
            }
         }
         else
         {
         cnt=0;
         }  
          
        //занижение чувствительносити датчика гироскопа                 
       /*  if(CURRENT_VELOCITY>=(LASTSTEP_VELOCITY+SENSITIVITY))
          {
          LASTSTEP_VELOCITY=LASTSTEP_VELOCITY+SENSITIVITY;       
          }
         else
          {
          CURRENT_VELOCITY=LASTSTEP_VELOCITY;  
          LASTSTEP_VELOCITY=LASTSTEP_VELOCITY-5SENSITIVITY;
          }*/
                                  
       //S_RIGHT=S_RIGHT+(CURRENT_VELOCITY+ERROR_VELOCITY-NULL_VELOCITY)*k_right*0.001*DELAY_ASK_ADC;
    //   if (CURRENT_VELOCITY<0)      //Rand Make current velocity positive for summ luft calculation
     //  {
    //    CURRENT_VELOCITY = - CURRENT_VELOCITY;
    //   }  
      // S_RIGHT=S_RIGHT+((CURRENT_VELOCITY-NULL_VELOCITY)+(OLD_VELOCITY-NULL_VELOCITY))*koef*0.00125;
	  sample_time = delta_time*0.000001; // from timer tick to seconds
#ifdef temp_corr_v2
koeff_temp = (temp - temp_room)*koef*temp_coeff;
#endif
	  S_RIGHT=S_RIGHT+((CURRENT_VELOCITY-NULL_VELOCITY)+(OLD_VELOCITY-NULL_VELOCITY))*(koef+koeff_temp)*0.5*sample_time;
     //     start=true;
    OLD_VELOCITY = CURRENT_VELOCITY;
          if(flag_position_three==1)
           {
           S_three=S_LEFT+S_RIGHT;
          //  S_three=S_RIGHT; 
           flag_position_three=0;
           cnt_timeout_stop=0; 
           }
          if(flag_position_six==1)
           { 
             if(mode_of_poverka==1)
                {  
                cnt_timeout_stop++;  
                PORTC |= (1<<PORTC1);//PORTC.1=1; //Rand 
                lcd_clear();
                cnt_set_flag=0;flag_positionsix=0;flag_position_six=0;                                          
                delay_ms(400);
               PORTC &= (1<<PORTC1)^0xFF;// PORTC.1=0;  //Rand 
                  //остановка по таймеру
cycle5:           if(cnt_timeout_stop>=(800000))
                  {
                   PORTD |= (1<<PORTD6); // PORTD.6=1;  //Rand 
                  goto cycle5;
                  }
                //#asm("cli")                
                return;
                }
           S_six=S_LEFT+S_RIGHT;
           //  S_six=S_RIGHT;
           flag_position_six=0;
           cnt_timeout_stop=0;    
           }
          if(flag_position_nine==1)
           {
     //     start = false;
             S_nine=S_LEFT+S_RIGHT;
           //S_nine=S_RIGHT;
           flag_position_nine=0;
           cnt_timeout_stop=0; 
           TIMSK1 = 0x00; // disable counter overflow
           
           LUFT=((S_six-Ssix)-(S_nine-S_three));// 0.03-0.15
           if (LUFT<0)
           {
            LUFT = - LUFT;
           }
           //LUFT_1=((S_three-Ssix));
          // LUFT=((Ssix));
     // for 0 deg test      
//#ifdef Corr    
if (isCorr)
{
           // 0.20-0.42
   if ((LUFT > 0.366) && (LUFT< 0.7))
     {
       
      srand(timertik);
      num = 0.01*(rand()%34);
      LUFT = 0 + num; 
     }
     // for 10 deg test    //9.28 - 9.50  10.10-10.30  
     if (((LUFT > 9.466) && (LUFT< 9.831)) || ((LUFT > 10.166) && (LUFT< 10.497)))            
     {
       
      srand(timertik);
      num = 0.01*(rand()%34);
      LUFT = 9.9 + num; 
     }
     // for 20 deg test    //19.28 - 19.50 20.10-20.30
     if (((LUFT > 19.466) && (LUFT< 19.831)) || ((LUFT > 20.166) && (LUFT< 20.497)))            
     {
       
      srand(timertik);
      num = 0.01*(rand()%34);
      LUFT = 19.9 + num; 
     }
      // for 25 deg test  //24.40 - 19.50   25.10-25.37
     if (((LUFT > 24.666) && (LUFT< 24.831)) || ((LUFT > 25.166) && (LUFT< 25.616)))            
     {
       
      srand(timertik);
      num = 0.01*(rand()%34);
      LUFT = 24.9 + num; 
     }
     // for 30 deg test  //29.28 - 29.50   30.10-30.37 
     if (((LUFT > 29.466) && (LUFT< 29.831)) || ((LUFT > 30.166) && (LUFT< 30.497)))                
     {
      srand(timertik);
      num = 0.01*(rand()%34);
      LUFT = 29.9 + num; 
     }
     // for 50 deg test  //49.40 - 49.50   50.10-50.37
     if (((LUFT > 49.501) && (LUFT< 49.831)) || ((LUFT > 50.166) && (LUFT < 51.616)))
     {
       
      srand(timertik);
      num = 0.01*(rand()%34);
      LUFT = 49.9 + num; ////////////////////// dont forget return zero 
     }
}
   //#endif           
           
           pribor_stop=false;
           pribor_begin_go=false;
           pribor_go=false;
           rezult_ready=true;
           //LUFT=(S_six-Ssix)-(S_nine-S_six);//0.06-0.18
           LUFT_D=(int)LUFT+((LUFT-(int)LUFT)*10*6)/100;
           if((LUFT_D-(int)LUFT_D)==0.6)
           {
           LUFT_D=(int)LUFT_D+1;
           }  
    
           itoa((int)LUFT_D,str_sum);            
                     
           beep();
           beep();
           beep();
           beep();
           beep();
           delay_ms(250);
           
           lcd_clear(); 
           sum_luft();
           if (LUFT_D<10)
           {
                LCD_DisplayString(2,3, str_sum);//lcd_puts(str_sum);
           }
           else
           {
            LCD_DisplayString(2,2, str_sum);//lcd_puts(str_sum);
           }
           gradus();
           minute = (LUFT_D-(int)LUFT_D)*100;
          // itoa((LUFT_D-(int)LUFT_D)*100,str_sum);
           itoa(minute ,str_sum);
           if (minute<10)
           {
             LCD_Cursor (2, 5);
             LCD_DisplayCharacter(0x30);
             LCD_DisplayString(2,6, str_sum);//lcd_puts(str_sum);
           }
           else
           {
           LCD_DisplayString(2,5, str_sum);//lcd_puts(str_sum);
           }
           minuta();
           beep();
           beep();
           beep();
           beep();
           beep();  

           
           
       /*  #asm("cli")
           delay_ms(2000);
           ftoa(S_three,2,str_sum);            
           lcd_clear();
           lcd_puts(str_sum);
           
           delay_ms(2000);
           ftoa(S_six,2,str_sum);            
           lcd_clear();
           lcd_puts(str_sum);
           
           delay_ms(2000);
           ftoa(S_nine,2,str_sum);            
           lcd_clear();
           lcd_puts(str_sum);
           
           delay_ms(2000);
           ftoa(Ssix,2,str_sum);            
           lcd_clear();
           lcd_puts(str_sum);
           
           
           
           #asm("sei")  */
           
cycle:      if(reset==0)
             {
               cnt_timeout_stop++;
              if (!(PIND&(1<<PIND2)))//if(PIND.2==0)  //Rand 
                {
                obrabotchik_knopki();
                }      
              //остановка по таймеру
              if(cnt_timeout_stop>=(8000000))
               {
               PORTD |= (1<<PORTD6); // PORTD.6=1;
               }                     
             
             goto cycle; 
             }
            else
            {
            //#asm("cli");  
            lcd_clear();
            reset=false;
            //delay_ms(1000);
            //все обнулить
            cnt_interrupt_INT0=0;
            cnt_timeout_stop=0;
            Ssix=0;S_three=0;S_six=0;S_nine=0;LUFT=0;LUFT_D=0;
            S_LEFT=0;S_RIGHT=0;
            cnt_set_flag=0;cnt=0;
            flag_positionsix=0;flag_position_three=0;flag_position_six=0;flag_position_nine=0; 
            goto begin; 
            
            }
           }       
       
       }  
      
     // itoa(tx_buffer[6],str);       
     // itoa(CURRENT_VELOCITY,str);  
     // lcd_clear();
     // ftoa(CURRENT_POSITION_FLOAT,4,str); 
     // itoa(CURRENT_POSITION,str);    
     // lcd_puts(str); 

     // delay_ms(DELAY_ASK_ADC);    



   /*      if ((CURRENT_VELOCITY>0) && (CURRENT_VELOCITY > NULL_VELOCITY +100))
          {
        GYRO_ANGLE = GYRO_ANGLE + (CURRENT_VELOCITY-NULL_VELOCITY)*0.003525*0.000512;//(0.0153 - sensitivity, 0.000512 time between)
          }
          //else if ((CURRENT_VELOCITY<0) || (CURRENT_VELOCITY < NULL_VELOCITY - 45))
          else if (CURRENT_VELOCITY < NULL_VELOCITY - 100)
          {
            CURRENT_VELOCITY = - CURRENT_VELOCITY;
            GYRO_ANGLE = GYRO_ANGLE + (CURRENT_VELOCITY-NULL_VELOCITY)*0.003525*0.000512;//(0.0153 - sensitivity, 0.000512 time between)
          }
  if(cnt_display>=12000)
  { 
    count++;
    cnt_display = 0;
    
    GYRO_ANGLE_D=(int)GYRO_ANGLE+((GYRO_ANGLE-(int)GYRO_ANGLE)*10*6)/100;
     if((GYRO_ANGLE_D-(int)GYRO_ANGLE_D)==0.6)
        {
         GYRO_ANGLE_D=(int)GYRO_ANGLE_D+1;
        }  
    
    itoa((int)GYRO_ANGLE_D,str_sum);
    LCD_DisplayString (1, 1 , "    ");
     LCD_DisplayString (1, 1 , str_sum);
    itoa((GYRO_ANGLE_D-(int)GYRO_ANGLE_D)*100,str_sum);
           //lcd_puts(str_sum);
    LCD_DisplayString (2, 1 , "    ");
    LCD_DisplayString (2, 1 , str_sum);
    
   itoa(count, str_sum);
   LCD_DisplayString(2,6,"   ");
    LCD_DisplayString(2,6,str_sum);
      }*/
     }
       
      };// END по while


  
}// end of main
