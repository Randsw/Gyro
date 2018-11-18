#include "Gyro_Final_Firmware_defs.h"
#include <stdlib.h>
#define Corr
//#define temp_corr
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


//clock для АЦП датчика поворота колеса
#define CLK_READ_UP2 {PORTB |=(1<<PORTB4); asm("nop");}   
#define CLK_READ_DOWN2 {PORTB &=(1<<PORTB4) ^ 0xFF; } 
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
enum bool isCorr = false;
__eeprom enum bool ee_isCorr = false; 
unsigned int  cnt_left, cnt_right;
           
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

void obrabotka_rx_paketa(void)
{     
int Data_kalib;    
 float Data;
 if(paket_prinyat==1)
   {                  
   
      if(rx_buffer[3]==0x00)  //
       {
       tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x03;tx_buffer[3]=0x00;tx_buffer[4]=0x03;tx_buffer[5]=0x01;tx_buffer[6]=0x85;tx_buffer[7]=vichislenie_checksum(tx_buffer,8);
       tx_counter=8;
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
         tx_counter=7;
         if(tx_enable==1)
          {      
			UDR0=tx_buffer[0];       
          }
         goto end_int;
         }   
         
         if(pribor_stop==1)
         { 
          tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x02;tx_buffer[3]=0x00;tx_buffer[4]=0x00;tx_buffer[5]=0x85;tx_buffer[6]=vichislenie_checksum(tx_buffer,7);
          tx_counter=7;
          if(tx_enable==1)
          {
			UDR0=tx_buffer[0];  
          }
         goto end_int;
         }
         
         if(pribor_begin_go==1)
         { 
         tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x03;tx_buffer[3]=0x00;tx_buffer[4]=0x01;tx_buffer[5]=0x45;tx_buffer[6]=0x85;tx_buffer[7]=vichislenie_checksum(tx_buffer,8); 
         tx_counter=8;
         if(tx_enable==1)
          {
			UDR0=tx_buffer[0];  
          }
         goto end_int;
         }    
         if(pribor_go==1)
         {                                                                                              
         tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x04;tx_buffer[3]=0x00;tx_buffer[4]=0x02;tx_buffer[5]=0x45;tx_buffer[6]=0x7F;tx_buffer[7]=0x85;tx_buffer[8]=vichislenie_checksum(tx_buffer,9);
         tx_counter=9;
          if(tx_enable==1)
          {
			UDR0=tx_buffer[0];  
          }
         goto end_int;
         }
         if(rezult_ready==1)
         { 
         tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x03;tx_buffer[3]=0x00;tx_buffer[4]=0x03;tx_buffer[5]=0x45;tx_buffer[6]=0x85;tx_buffer[7]=vichislenie_checksum(tx_buffer,8); 
         pribor_stop=true;
         pribor_begin_go=false;
         pribor_go=false;
         rezult_ready=false;
         tx_counter=8;
          if(tx_enable==1)
          {
			UDR0=tx_buffer[0];  
          }
         goto end_int;
         }
      
       }            
      if(rx_buffer[3]==0x02)  //
       {
       tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x09;tx_buffer[3]=0x00;tx_buffer[4]=0x49;tx_buffer[5]=0x53;tx_buffer[6]=0x4C;tx_buffer[7]=0x2D;tx_buffer[8]=0x34;tx_buffer[9]=0x30;tx_buffer[10]=0x31;tx_buffer[11]=0x4D;tx_buffer[12]=0x85;tx_buffer[13]=vichislenie_checksum(tx_buffer,14);
       tx_counter=14;
        if(tx_enable==1)
        {
			UDR0=tx_buffer[0];  
        }
       goto end_int;
      
       }             
       
       
      if(rx_buffer[3]==0x42)
       {
       tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x03;tx_buffer[3]=0x00;tx_buffer[4]=0x01;tx_buffer[5]=0x01;tx_buffer[6]=0x85;tx_buffer[7]=vichislenie_checksum(tx_buffer,8);
       tx_counter=8;
        if(tx_enable==1)
        {
			UDR0=tx_buffer[0]; 
        }
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
          tx_counter=18;
          if(tx_enable==1)
          {
          UDR0=tx_buffer[0];
          }  
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
          tx_counter=18;    
          if(tx_enable==1)
          {
			UDR0=tx_buffer[0];  
          }
         rx_command_vern_rezult=true;
         goto end_int;
         } 
       } 
       
      if(rx_buffer[3]==0x44)
       {
       tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x01;tx_buffer[3]=0x00;tx_buffer[4]=0x85;tx_buffer[5]=vichislenie_checksum(tx_buffer,6);
       tx_counter=6;       
        if(tx_enable==1)
        {
			UDR0=tx_buffer[0];  
        }
       rx_command_sbros=true;
       goto end_int;
       }
      if(rx_buffer[3]==0x45)
       {
       tx_buffer[0]=0x8A;tx_buffer[1]=0x05;tx_buffer[2]=0x01;tx_buffer[3]=0x02;tx_buffer[4]=0x85;tx_buffer[5]=vichislenie_checksum(tx_buffer,6);
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
       rx_command_proiz_izm=true;
         
       goto end_int;
       }   
	}
 else if (paket_kalib_prinyat == 1)
 {
       if(rx_buffer[1]==0xAA) // write kalib
       {
          Data_kalib = ((int)(rx_buffer[2])<<8) + (int)(rx_buffer[3]);
          ee_kalib = Data_kalib;  
          kalib = Data_kalib;  
        //  itoa(kalib, str_test);
        //  lcd_clear();
        //  LCD_DisplayString(1,1, str_test);//lcd_puts(str_test); 
		  goto end_int;
       }
       
       if (rx_buffer[1]==0xAB) // Read kalib
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
       if (rx_buffer[1] == 0xAC) //Write isCorr
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
       
       if (rx_buffer[1]==0xAD) // Read isCorr
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
      tx_counter=6;
        if(tx_enable==1)
        {      
			UDR0=tx_buffer[0];  
        }
       }
  
    } 
end_int:  asm("nop");
}
// USART Receiver interrupt service routine
#pragma vector = USART0_RX_vect
__interrupt void uart_rx_isr(void)
{
char status,data;
status=UCSR0A;
data=UDR0;
if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
   {
   //как у Олега                              
   if((rx_counter==0)&&(data==0x8A)) {record_enable=1;}
   if((rx_counter>0)&&(data==0x85)) {record_stop=rx_counter;}
   if(record_enable)
     {
      rx_buffer[rx_counter]=data;
      rx_counter++; 
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
   }
}

// USART Transmitter interrupt service routine
#pragma vector = USART0_TX_vect
__interrupt void uart_tx_isr(void)
{
    asm("push r26");
    asm("push r27");
    asm("push r30");
    asm("push r31");
    asm("in  r26, 0x3F"); //0x3F - SREG
    asm("push r26");
if (tx_counter)
   { 
	 UDR0=tx_buffer[tx_rd_index+1];
     if (++tx_rd_index == (tx_counter-1)) {tx_rd_index=0;tx_counter=0;}
   }
    asm("pop  r26");
    asm("out  0x3F, r26"); //0x3F - SREG
    asm("pop  r31");
    asm("pop  r30");
    asm("pop  r27");
    asm("pop  r26");
 
}
#define POSITION_ERROR 0.0037

// Declare your global variables here
unsigned int  ADC_12_bit_word2; 
char temp;
int CURRENT_VELOCITY_int;
float CURRENT_VELOCITY=0;
float NULL_VELOCITY;
int CURRENT_POSITION;
int NULL_POSITION;
int i,cnt_set_flag=0,cnt=0,cnt_interrupt=0,cnt_display=0, cnt_dmt=0;
long int cnt_interrupt_INT0=0,cnt_timeout_stop=0; 
int flag_interrupt_gyro=0,flag_interrupt_DMT=0;
int flag_positionsix=0;
int flag_position_three=0;
int flag_position_six=0;
int flag_position_nine=0;
float koeff_temp=0;

float Ssix=0,S_three=0,S_six=0,S_nine=0, LUFT_D=0;
float K_DMT=0;
float CURRENT_POSITION_FLOAT=0;
char* str="calibration"; 
char* str_sum="     ";
char* str_crc="CF47h"; 
int   mode_of_poverka=0;                          
long int cnt_begin=0;  



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
          
      CLK_READ_UP2;
      CLK_READ_DOWN2;
      CLK_READ_UP2;
      CLK_READ_DOWN2;
      CLK_READ_UP2;
      CLK_READ_DOWN2;//ждем готовность АЦП датчика поворота колеса 
       
      ADC_12_bit_word2=0;
             
        for(i=0;i<12;i++)
       {   
        CLK_READ_UP2;  
           
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
      }
  //   if((CURRENT_POSITION_FLOAT<=(0.4921+2*POSITION_ERROR))&&(CURRENT_POSITION_FLOAT>=(0.4921-2*POSITION_ERROR)) )//0.999 - 0.15,1.1988-0.18  
      if((CURRENT_POSITION_FLOAT<=(-0.4921+0.0074))&&(CURRENT_POSITION_FLOAT>=(-0.4921-0.0074)) )//0.999 - 0.15,1.1988-0.18
      {
		flag_positionsix=0;
		flag_position_three=0;
		flag_position_six=0;
		flag_position_nine=1;
      } 
}

// Timer 0 overflow interrupt service routine
#pragma vector = TIMER0_OVF_vect
__interrupt void timer0_ovf_isr(void)
{
// Reinitialize Timer 0 value
TCNT0=0xF3;
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
{   
// Reinitialize Timer 1 value
TCNT1L=0xFF; //at 1 MHz( 8 MHz/ 8 prescaler) we got 1953 Hz or 512 us interval
//TCNT1H=0xFD;
TCNT1H=0xFB;
cnt_timeout_stop++;
cnt_display++;
flag_interrupt_gyro=1; 
cnt_interrupt++;
 if(cnt_interrupt==1)
 { 
	flag_interrupt_DMT=1;
	cnt_interrupt=0;
 }
}



void opros_datchika_giroscopa(void)    
{
    CURRENT_VELOCITY_int = Read_spi_MCP3201();
    CURRENT_VELOCITY = CURRENT_VELOCITY_int;
}

float calibration_of_sensor_gyro(void)                 
{
int ADC_word_int;
float ADC_word=0;
float Sum_ADC_word;
float Average_ADC_word;
int n;    
Sum_ADC_word=0;
Average_ADC_word=0;         
ADC_word_int = 0;
 for(n=0;n<200;n++) 
{
    ADC_word_int = Read_spi_MCP3201();
    ADC_word = ADC_word_int;
    Sum_ADC_word=Sum_ADC_word+ADC_word;
    delay_ms(3);
}  
    Average_ADC_word=Sum_ADC_word/200;  //усреднили ноль гироскопа по 200 отсчетам
    return(Average_ADC_word);
} 

unsigned int calibration_of_sensor_DMT(void)                 
{
unsigned int ADC_word;
long int Sum_ADC_word;
unsigned int Average_ADC_word;
int n;    
int n_adc;                
                              
  Sum_ADC_word=0;
  Average_ADC_word=0;         

  
for(n=0;n<100;n++) 
    {

      PORTD &= (1<<PORTD3)^0xFF;
      
      CLK_READ_UP2;
      CLK_READ_DOWN2;
      CLK_READ_UP2;
      CLK_READ_DOWN2;
      CLK_READ_UP2;
      CLK_READ_DOWN2;//ждем готовность АЦП           
          
      ADC_word=0;
      //считываем 12-битный последовательный код  с АЦП
      for(n_adc=0;n_adc<12;n_adc++)
       {   
        CLK_READ_UP2; 
        if (!(PIND&(1<<PIND7)))
        { 
			ADC_word=ADC_word<<1;                      
        } 
        else
        { 
			ADC_word=(ADC_word+1)<<1;   
        } 
                     
        CLK_READ_DOWN2;    
       }          
      ADC_word=ADC_word>>1; 
      Sum_ADC_word=Sum_ADC_word+ADC_word;
    PORTD |= (1<<PORTD3);
    }  
    Average_ADC_word=Sum_ADC_word/100;  //усреднили ноль ДМТ по 100 отсчетам
    return(Average_ADC_word);
  
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
unsigned int Read_spi_MCP3201(void)
{
	unsigned int result;
	SPI_PORT &= (1 << SPI_CS) ^ 0xFF;
	
	//3 dumb clk cycles
	 
	SPI_PORT &= (1 << SPI_SCK) ^ 0xFF;
    SPI_PORT |= (1 << SPI_SCK);
	delay(1);
	SPI_PORT &= (1 << SPI_SCK) ^ 0xFF;
	SPI_PORT |= (1 << SPI_SCK);
	delay(1);
	SPI_PORT &= (1 << SPI_SCK) ^ 0xFF;
	SPI_PORT |= (1 << SPI_SCK);
	delay(1);
	SPI_PORT &= (1 << SPI_SCK) ^ 0xFF;
	
	result = Spi_soft_read_12bit();
	
	
	SPI_PORT |= (1 << SPI_CS);
	
	return result;
} 

unsigned int Spi_soft_read_12bit(void)
{
  unsigned int result = 0;
  unsigned char k;
  
  for (k=0; k<12; k++)
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

void Periph_init (void)
{
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
EICRA = 0x00;
EIMSK = 0x01;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK0 = 0x00; //for ATMega 164P
TIMSK1 = 0x01; //for ATMega 164P

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
}


void All_clear_reset(void)
{
	lcd_clear();
	reset=false;
	cnt_interrupt_INT0=0;
	cnt_timeout_stop=0;
	Ssix=0;S_three=0;S_six=0;S_nine=0;LUFT=0;LUFT_D=0;
	S_LEFT=0;S_RIGHT=0;
	cnt_set_flag=0;cnt=0;
	flag_positionsix=0;flag_position_three=0;flag_position_six=0;flag_position_nine=0;  
	
}

void TooSlow(void)
{
	vrashay_bystree();
	delay_ms(2000);
	izmeryaem_snova();
	pribor_stop=true;
	pribor_begin_go=false;
	pribor_go=false;
	rezult_ready=false;
}

void TooFast(void)
{
	vrashay_medlennee();
	delay_ms(2000);
	izmeryaem_snova();
	pribor_stop=true;
	pribor_begin_go=false;
	pribor_go=false;
	rezult_ready=false; 
}

void main( void )
{
float koef, num;
int minute;
conf_ports(); 
Periph_init();
kalib = ee_kalib;
isCorr = false;
koef =((float)(kalib))/1000000; 
pribor_stop=false;
pribor_begin_go=false;
pribor_go=true;
rezult_ready=false;
lcd_init_old();
delay_ms(500);
beep();
lcd_clear();
calibrat();   
 
delay_ms(200); 
    
//контроль напряжения аккумуляторной батареи
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
	
begin:TCNT1L=0x00; 
TCNT1H=0x00;
NULL_POSITION=calibration_of_sensor_DMT();
NULL_VELOCITY=calibration_of_sensor_gyro();

cnt = 0;
lcd_clear();                                           
str_left();
cnt_timeout_stop=0;
reset=false;
checksum=0;      
asm("sei");
// Endless Cycle
while (1)                            
{   
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
 if (flag_interrupt_gyro==1)  
 {  
		opros_datchika_giroscopa();  
		flag_interrupt_gyro =0;
		if (flag_interrupt_DMT==1)
        {
			opros_datchika_DMT();
			flag_interrupt_DMT=0;
        }    
		if ((CURRENT_VELOCITY<=(NULL_VELOCITY+5))&&(CURRENT_VELOCITY>=(NULL_VELOCITY-5))) 
		{   
			cnt_timeout_stop++;
			if(cnt_timeout_stop>=(60000))
			{
				PORTD |= (1<<PORTD6);
			}     
		}
		if (CURRENT_VELOCITY<(NULL_VELOCITY-5)) 
		{
                  cnt_left++;
				cnt_timeout_stop=0;  
				//Ограничение  максимальной скорости влево
				if ((CURRENT_VELOCITY<=1750)&&(mode_of_poverka==0))
				{
					TooFast();
cycle1:     		if(reset==false)
					{
						cnt_timeout_stop++;
						if (!(PIND&(1<<PIND2))) 
						{
							obrabotchik_knopki();
						}      
						//остановка по таймеру
						if (cnt_timeout_stop>=(8000000))
						{
							PORTD |= (1<<PORTD6);
						}              
						goto cycle1; 
					}
						else
						{
							All_clear_reset();
							goto begin;  
						}
				}
				//Ограничение  миимальной скорости влево
				if ((CURRENT_VELOCITY>=(NULL_VELOCITY-20))&&(mode_of_poverka==0))
				{                    
					cnt++;
					if (cnt>=5000)
					{
						TooSlow(); 
cycle2:     			if(reset==false)
						{  
							if (!(PIND&(1<<PIND2)))
							{
								obrabotchik_knopki();
							}      
							//остановка по таймеру
							if (cnt_timeout_stop>=(270000))
							{
								PORTD |= (1<<PORTD6);
							}              
							goto cycle2; 
						}
						else
						{
							All_clear_reset();
							goto begin; 
						}       
					} 
				}
				else
				{
					cnt=0;
				} 
				S_LEFT=S_LEFT+(CURRENT_VELOCITY-NULL_VELOCITY)*0.1740553*0.000514*2;//000512
				if ((flag_positionsix==1)&&(cnt_set_flag==0))
				{    
					PORTC |= (1<<PORTC1);
					cnt_set_flag=cnt_set_flag+1;
					Ssix=S_LEFT+S_RIGHT;
					flag_positionsix=0;
					cnt_timeout_stop=0;
					LCD_Cursor (2, 7);
					LCD_DisplayCharacter(0xDA);
				}
		}                                                
		if (CURRENT_VELOCITY>(NULL_VELOCITY+5))
		{ 
                   cnt_right++;
			cnt_timeout_stop=0;
			PORTC &= (1<<PORTC1)^0xFF;                  
			//Ограничение  максимальной скорости вправо
			if ((CURRENT_VELOCITY>=2350)&&(mode_of_poverka==0))
			{
				TooFast();       
cycle3:     	if (reset==false)
				{
					cnt_timeout_stop++;
					if (!(PIND&(1<<PIND2)))
					{
						obrabotchik_knopki();
					}       
					//остановка по таймеру
					if(cnt_timeout_stop>=(8000000))
					{
						PORTD |= (1<<PORTD6);
					}	              
					goto cycle3; 
				}
				else
				{
					All_clear_reset();             
					goto begin; 
				}       
       
			} 
        //Ограничение  миимальной скорости вправо
			if((CURRENT_VELOCITY<=(NULL_VELOCITY+5))&&(mode_of_poverka==0))
			{                    
				cnt++;
				if(cnt>=5000)
				{
					TooSlow();        
cycle4:      		if(reset==false)
					{        
						if (!(PIND&(1<<PIND2)))
						{
							obrabotchik_knopki();
						}      
						//остановка по таймеру
						if(cnt_timeout_stop>=(270000))
						{
							PORTD |= (1<<PORTD6);
						}                 
						goto cycle4; 
					}
					else
					{
						All_clear_reset();
						goto begin;      
					}	                  
            
				}
			}
			else
			{
				cnt=0;
			}  
			S_RIGHT=S_RIGHT+(CURRENT_VELOCITY-NULL_VELOCITY)*0.1740553*0.000514*2; //000512
			if(flag_position_three==1)
			{
				S_three=S_LEFT+S_RIGHT;
				flag_position_three=0;
				cnt_timeout_stop=0; 
			}
			if(flag_position_six==1)
			{ 
				if(mode_of_poverka==1)
                {  
					cnt_timeout_stop++;  
					PORTC |= (1<<PORTC1);
					lcd_clear();
					cnt_set_flag=0;flag_positionsix=0;flag_position_six=0;                                          
					delay_ms(400);
					PORTC &= (1<<PORTC1)^0xFF;
					//остановка по таймеру
cycle5:           	if(cnt_timeout_stop>=(800000))
					{
						PORTD |= (1<<PORTD6);
						goto cycle5;
					}
					return;
                }
				S_six=S_LEFT+S_RIGHT;
				flag_position_six=0;
				cnt_timeout_stop=0;    
            }
			if(flag_position_nine==1)
			{
				S_nine=S_LEFT+S_RIGHT;
				flag_position_nine=0;
				cnt_timeout_stop=0; 
				LUFT=((S_six-Ssix)-(S_nine-S_three));// 0.03-0.15
				if (LUFT<0)
				{
					LUFT = - LUFT;
				}
			/*	if (isCorr)
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
			}*/
				pribor_stop=false;
				pribor_begin_go=false;
				pribor_go=false;
				rezult_ready=true;
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
					LCD_DisplayString(2,3, str_sum);
				}
				else
				{
					LCD_DisplayString(2,2, str_sum);
				}
				gradus();
				minute = (LUFT_D-(int)LUFT_D)*100;
				itoa(minute ,str_sum);
				if (minute<10)
				{
					LCD_Cursor (2, 5);
					LCD_DisplayCharacter(0x30);
					LCD_DisplayString(2,6, str_sum);
				}
				else
				{
					LCD_DisplayString(2,5, str_sum);
				}
				minuta();
				beep();
				beep();
				beep();
				beep();
				beep();  
cycle:      	if(reset==0)
				{
					cnt_timeout_stop++;
					if (!(PIND&(1<<PIND2)))
					{
						obrabotchik_knopki();
					}	      
					//остановка по таймеру
					if(cnt_timeout_stop>=(8000000))
					{
						PORTD |= (1<<PORTD6);
					}                     
					goto cycle; 
				}
				else
				{
					All_clear_reset();
					goto begin; 
				}
			}
        }       
       
 }  
}// END по while
       
}// end of main


  

