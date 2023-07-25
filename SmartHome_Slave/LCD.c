#include "LCD.h"



void LCD_init(void){
	LCD_CTRL_PORT_DIR |= (1<<E) | (1<<RW) | (1<<RS); /* Configure the control pins(E,RS,RW) as output pins */
	LCD_DATA_PORT_DIR = 0xFF; /* Configure the data port as output port */
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(CURSOR_OFF);
}

void LCD_sendCommand(uint8 command){
	CLR_bit(LCD_CTRL_PORT,RS); //configure lcd RS control to command
	CLR_bit(LCD_CTRL_PORT,RW); /* write data to LCD so RW=0 */
	SET_bit(LCD_CTRL_PORT,E);  //set the enable to 1
	_delay_ms(1);
	LCD_DATA_PORT = command; //send command
	_delay_ms(1);
	CLR_bit(LCD_CTRL_PORT,E);//disable lcd E
	_delay_ms(1);
}

void LCD_displayCharacter(uint8 data){
	SET_bit(LCD_CTRL_PORT,RS);//configure lcd RS control to data
	CLR_bit(LCD_CTRL_PORT,RW); /* write data to LCD so RW=0 */

	SET_bit(LCD_CTRL_PORT,E);
	_delay_ms(5);
	LCD_DATA_PORT = data;
	_delay_ms(5);
	CLR_bit(PORTD,E);
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

