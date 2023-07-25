

#ifndef STD
#define	STD
#include "STD.h"
#endif



#define LCD

/* LCD HW Pins */
#define RS 5
#define RW 6
#define E  7
#define LCD_CTRL_PORT PORTC
#define LCD_CTRL_PORT_DIR DDRC
#define LCD_DATA_PORT PORTD
#define LCD_DATA_PORT_DIR DDRD

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80







void LCD_init(void);
void LCD_sendCommand(char command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_intgerToString(int data);
