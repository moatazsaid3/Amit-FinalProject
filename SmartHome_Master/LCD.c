#include "LCD.h"

#define SetBit(PortName,PinNumber)  PortName|=(1<<PinNumber)
#define ClearBit(PortName,PinNumber) PortName&=~(1<<PinNumber)
#define ToggleBit(PortName,PinNumber) PortName^=(1<<PinNumber)
#define GetBit(PortName,PinNumber) (PortName&(1<<PinNumber))

void LCD_init(void){
	SetBit(DDRC,5);
	SetBit(DDRC,6);
	SetBit(DDRC,7);
	DDRD=0xFF;
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
	LCD_sendCommand(CURSOR_OFF); /* cursor off */
		LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */
}
void LCD_sendCommand(char command){
	ClearBit(PORTC,5);
	ClearBit(PORTC,6);
	SetBit(PORTC,7);
	_delay_ms(1);
	PORTD=command;
	_delay_ms(1);
	ClearBit(PORTC,7);
	_delay_ms(1);
}

void LCD_displayCharacter(uint8 data){
	SetBit(PORTC,5);
	ClearBit(PORTC,6);
	SetBit(PORTC,7);
	_delay_ms(1);
	PORTD=data;
	_delay_ms(1);
	ClearBit(PORTC,7);
	_delay_ms(1);
}

void LCD_goToRowColumn(uint8 row,uint8 col){
		/* first of all calculate the required address */
		switch(row)
		{
			case 0:
					LCD_sendCommand(col | SET_CURSOR_LOCATION);

					break;
			case 1:
					LCD_sendCommand(col+0x40 | SET_CURSOR_LOCATION);
		}
		/* to write to a specific address in the LCD
		 * we need to apply the corresponding command 0b10000000 + Address */
}
void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}
void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); //clear display
}

