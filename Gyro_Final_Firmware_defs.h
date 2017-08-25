#ifndef ENABLE_BIT_DEFINITIONS
#define ENABLE_BIT_DEFINITIONS
#endif

#include "iom164p.h"
#include "intrinsics.h"
#include "MAX21000.h"
#include "MAX21000_map.h"
#include "lcd_lib.h"
#define F_CPU 8000000


#define LCD_OP_PORT PORTA
#define LCD_CTRL_PORT PORTA
#define LCD_E         PORTA2
#define LCD_RW        PORTA1
#define LCD_RS        PORTA0

#define SPI_PORT PORTB
#define SPI_PIN PINB
#define SPI_CS   PORTB1
#define SPI_SCK  PORTB0
#define SPI_SDI  PORTB3
#define SPI_SDO  PINB2

#define CTRL_REG1 0x20
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define Who_am_I  0x0F
#define Z_low     0x2C
#define Z_high    0x2D
#define Status    0x27

enum bool {true = 1, false = 0};



extern const  unsigned char   STR_CALIBRAT1[];
extern const  unsigned char   STR_CALIBRAT2[];
extern const  unsigned char   STR_PO1[];
extern const  unsigned char   STR_PO2[];
extern const  unsigned char   STR_Sum_Luft1[];
extern const  unsigned char   STR_Sum_Luft2[];
extern const  unsigned char   STR_POVERKA1[];
extern const  unsigned char   STR_POVERKA2[];
extern const  unsigned char   STR_STR_LEFT1[];
extern const  unsigned char   STR_STR_LEFT2[];
extern const unsigned char    STR_STR_LEFT3[2]; 
extern const unsigned char    STR_gradus[1];
extern const unsigned char    STR_minuta[1];
extern const  unsigned char   STR_STR_RIGHT1[];
extern const  unsigned char   STR_STR_RIGHT2[];
extern const unsigned char    STR_STR_RIGHT3[2];
extern const unsigned char    STR_izmeryaem_snova1[];
extern const unsigned char    STR_izmeryaem_snova2[];
extern const unsigned char    STR_vrashay_bystree1[];
extern const unsigned char    STR_vrashay_bystree2[];
extern const unsigned char    STR_vrashay_medlenee1[];
extern const unsigned char    STR_vrashay_medlenee2[];
extern const unsigned char    STR_izmeryat_nelsya1[];
extern const unsigned char    STR_izmeryat_nelsya2[];
extern const unsigned char    STR_akkumulyator1[];
extern const unsigned char    STR_akkumulyator2[];
extern const unsigned char    STR_trebuet_zaryadki1[];
extern const unsigned char    STR_trebuet_zaryadki2[];
extern const unsigned char LCD_CODE[];

char *itoa(int num, char *buf);
void LCD_DisplayString_new (char row, char column ,const  unsigned char  *string);
void lcd_clear (void);
void delay_ms(unsigned int millisecs);
void delay_us(unsigned long usecs);
void lcd_init_old (void);
void LCD_DisplayString (char row, char column ,char *string);
void putchar_old (unsigned char data);
void putchar_LCD (unsigned char data);
void putcmd (unsigned char cmd);
void putcmd_init (unsigned char cmd);
void putcmd_old (unsigned char cmd);
void lcd_enable (void);
void lcd_clear (void);
void LCD_DisplayCharacter (char Char);
void LCD_Cursor (char row, char column);
void LCD_Cursor_ON (void);
void LCD_Cursor_Off (void);
void LCD_CommonFunc(unsigned char data);
void LCD_DisplayString_new_SH (char row, char column ,const  unsigned char  *string);
void LCD_DisplayCharacter_SH (char Char);

void init_Max21000(void);
void init_Max21000_test(void);
void Change_Bank(unsigned char Bank_Num);
void write_Max21000_reg (unsigned char address, unsigned char data);
void write_mult_Max21000_reg (unsigned char address, unsigned char* data, unsigned char numdata);
void read_mult_Max21000_reg (unsigned char address, unsigned char* data, unsigned char numdata);
unsigned char Read_Max21000_reg (unsigned char address);
void Spi_soft_write(unsigned char d);
unsigned char Spi_soft_read(void);
void  conf_ports(void);
void delay(long delay_cycles);
unsigned char ftoa(float fnum, unsigned char *str);
void mystrcpy(unsigned char *dst, unsigned char *src);