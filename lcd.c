/******************************************************************************/
/*  File: LCD.c, 4.02.2008, 9:49                                             */
/*  This fuckin file contains lcd procedure: initialisation, putdata etc      */
/******************************************************************************/

#include "Gyro_Final_Firmware_defs.h"


//глобальные настройки драйвера
#define LCD_CHECK_FL_BF             1
#define LCD_BUS_4_8_BIT             0

//настройки инициализации дисплея
#define LCD_ONE_TWO_LINE            1
#define LCD_FONT58_FONT511          0
#define LCD_DEC_INC_DDRAM           1
#define LCD_SHIFT_RIGHT_LEFT        0
#define LCD_DISPLAY_OFF_ON          1
#define LCD_CURSOR_OFF_ON           0
#define LCD_CURSOR_BLINK_OFF_ON     1
#define LCD_CURSOR_DISPLAY_SHIFT    0

#define SWAP(data)  data = __swap_nibbles(data);
#define LCD_COM_ENTRY_MODE_SET     (1<<2)|(LCD_DEC_INC_DDRAM<<1)|(LCD_SHIFT_RIGHT_LEFT<<0)
#define LCD_COM_DISPLAY_CONTR      (1<<3)|(LCD_DISPLAY_OFF_ON<<2)|(LCD_CURSOR_OFF_ON<<1)|(LCD_CURSOR_BLINK_OFF_ON<<0)
#define LCD_COM_FUNCTION_SET       (1<<5)|(LCD_BUS_4_8_BIT<<4)|(LCD_ONE_TWO_LINE<<3)|(LCD_FONT58_FONT511<<2)
#define LCD_CURS_ON 0x0E
#define LCD_ON      0x0C

#define rus

//макросы для работы с битами
#define ClearBit(reg, bit)       reg &= (~(1<<(bit)))
#define SetBit(reg, bit)         reg |= (1<<(bit))	
#define FLAG_BF 7

//макросы для задержек
#define _delay_us(us) 	__delay_cycles((F_CPU / 1000000) * (us));
#define _delay_ms(ms) 	__delay_cycles((F_CPU / 1000) * (ms));

void lcd_init_old (void)
{
  //clear control pins
  LCD_CTRL_PORT &=(1<<LCD_E)^0xFF;
  LCD_CTRL_PORT &=(1<<LCD_RW)^0xFF;
  LCD_CTRL_PORT &=(1<<LCD_RS)^0xFF;
  
  unsigned char init = 0x30;
  //wait 30 ms
  delay(350000);
  putcmd_init (init);
  //wait 5 ms
  delay(90000);
  putcmd_init (init);
  //wait 1 ms
  delay(9000);
  putcmd_init(init);
  
  delay(1000);
  //4 bit interface
  unsigned char init_4_bit = 0x20;
  putcmd_init(init_4_bit);
  delay(2000);
  //4 bit interface, 5x10font, 2 line
  init_4_bit = 0x2C;
  putcmd(init_4_bit);
  delay(2000);
  //display off
  init_4_bit = 0x08;
  putcmd (init_4_bit);
  delay(2000);
 // display on, cursor off, blinking off;  
  init_4_bit =0x0C;
  putcmd (init_4_bit);
  delay(2000);
  //diplay clear
  init_4_bit = 0x01;
  putcmd (init_4_bit);
  delay(2000);
 // enter entry mode
  init_4_bit =0x06;
  putcmd (init_4_bit);
}

void putchar_LCD (unsigned char data)
{
  unsigned char temp;
   LCD_CTRL_PORT |=(1<<LCD_RS);
   LCD_CTRL_PORT &=(1<<LCD_RW)^0xFF;
   LCD_CTRL_PORT &=(1<LCD_E)^0xFF;

   temp = data & 0xF0;
   LCD_OP_PORT &= 0x0F;
   //Load data to LCD
   LCD_OP_PORT |= temp;
    delay (100);
   lcd_enable();
    delay (100);
   
   SWAP(data);
   
   temp = data & 0xF0;
   LCD_OP_PORT &= 0x0F;
   //Load data to LCD
   LCD_OP_PORT |= temp;
    delay (100);
   lcd_enable();
    delay (100);
}

void putcmd (unsigned char cmd) //4 bit interface
{
  delay (2000);
  unsigned char temp;
   LCD_CTRL_PORT &=(1<<LCD_RS)^0xFF;
   LCD_CTRL_PORT &=(1<<LCD_RW)^0xFF;
   LCD_CTRL_PORT &=(1<LCD_E)^0xFF;

   temp = cmd & 0xF0;
   LCD_OP_PORT &= 0x0F;
   //Load data to LCD
   LCD_OP_PORT |= temp;
    delay (100);
   lcd_enable();
    delay (100);
   
   SWAP(cmd);
   
   temp = cmd & 0xF0;
   LCD_OP_PORT &= 0x0F;
   //Load data to LCD
   LCD_OP_PORT |= temp;
    delay (100);
   lcd_enable(); 
    delay (100);
}

void putcmd_init (unsigned char cmd)
{
   LCD_CTRL_PORT &=(1<<LCD_RS)^0xFF;
   LCD_CTRL_PORT &=(1<<LCD_RW)^0xFF;
   
   cmd &= 0xF0;
   
   LCD_OP_PORT &= 0x0F;
   LCD_OP_PORT |= cmd;
    delay (200);
   lcd_enable();
    delay (200);
}

void lcd_enable (void)
{
   LCD_CTRL_PORT &=(1<<LCD_E)^0xFF;
   delay(100);
   LCD_CTRL_PORT |=(1<<LCD_E);
   delay(100);
   LCD_CTRL_PORT &=(1<<LCD_E)^0xFF;
}

void lcd_clear (void)
{
  unsigned char cls = 0x01;
   putcmd (cls);
   delay (30000);
}

//общая функция
#pragma inline = forced
void LCD_CommonFunc(unsigned char data)
{
#ifdef BUS_4BIT  
  unsigned char tmp; 
  tmp  = PORT_DATA & 0x0f;
  tmp |= (data & 0xf0);

  PORT_DATA = tmp;		//вывод старшей тетрады 
  SetBit(PORT_SIG, EN);	        
  _delay_us(2);
  ClearBit(PORT_SIG, EN);	

  data = __swap_nibbles(data);
  tmp  = PORT_DATA & 0x0f;
  tmp |= (data & 0xf0);
 
  PORT_DATA = tmp;		//вывод младшей тетрады 
  SetBit(PORT_SIG, EN);	        
  _delay_us(2);
  ClearBit(PORT_SIG, EN);	 
#else 
  PORT_DATA = data;		//вывод данных на шину индикатора 
  SetBit(PORT_SIG, EN);	        //установка E в 1
  _delay_us(2);
  ClearBit(PORT_SIG, EN);	//установка E в 0 - записывающий фронт
#endif
}

// ****************************************************************** //
// *** Display a single character, at the current cursor location *** //
// ****************************************************************** //

void LCD_DisplayCharacter (char Char)
{
      #ifndef rus 
   LCD_CTRL_PORT |=(1<<LCD_RS);
	 LCD_CommonFunc(Char);
 //  putchar_LCD (Char);
      #endif
      #ifdef rus
      unsigned char x;
        x = Char;

	if((x >= 192) && (x != 0xD9) && (x != 0xDA) && (x != 0xEF))
        {
          if (x==0xFF)
          {
            x = 0xFF;
          }
          else
          {
          x = LCD_CODE[Char - 192];
          }
	}
         LCD_CTRL_PORT |=(1<<LCD_RS);
        LCD_CommonFunc(x);
	//putchar_LCD (x);
        delay(200);
      #endif
}


void LCD_DisplayCharacter_SH (char Char)
{
      #ifndef rus 
   LCD_CTRL_PORT |=(1<<LCD_RS);
	 LCD_CommonFunc(Char);
 //  putchar_LCD (Char);
      #endif
      #ifdef rus
      unsigned char x;
        x = Char;

	if(x >= 192) 
        {
          if (x==0xFF)
          {
            x = 0xFF;
          }
          else
          {
          x = LCD_CODE[Char - 192];
          }
	}
        if (x==0xC2) x = 0xE2;
         LCD_CTRL_PORT |=(1<<LCD_RS);
        LCD_CommonFunc(x);
	//putchar_LCD (x);
        delay(200);
      #endif
}


// ******************************************************************* //
// *** Display a string at the specified row and column, using RAM *** //
// ******************************************************************* //

void LCD_DisplayString (char row, char column , char *string)
{
	LCD_Cursor (row, column);
        delay(200);
	while (*string)
		LCD_DisplayCharacter (*string++);
}
void LCD_DisplayString_new (char row, char column ,const  unsigned char  *string)
{
	LCD_Cursor (row, column);
        delay(200);
	while (*string)
		LCD_DisplayCharacter (*string++);
}


void LCD_DisplayString_new_SH (char row, char column ,const  unsigned char  *string)
{
	LCD_Cursor (row, column);
        delay(200);
	while (*string)
		LCD_DisplayCharacter_SH (*string++);
}

// *************************************************** //
// *** Position the LCD cursor at "row", "column". *** //
// *************************************************** //

void LCD_Cursor (char row, char column)
{
	switch (row) {
		case 1: putcmd (0x80 + column - 1); break;
		case 2: putcmd (0xc0 + column - 1); break;
		case 3: putcmd (0x94 + column - 1); break;
		case 4: putcmd (0xd4 + column - 1); break;
		default: break;
	}
}


// *************************** //
// *** Turn the cursor on *** //
// *************************** //

void LCD_Cursor_ON (void)
{
	putcmd (LCD_CURS_ON);
}

// *************************** //
// *** Turn the cursor off *** //
// *************************** //
void LCD_Cursor_Off (void)
{
	putcmd (LCD_ON);
}
