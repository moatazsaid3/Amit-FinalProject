
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */

#include <avr/interrupt.h>
#include"SPI.h"
#include "Keypad.h"
#include "LCD.h"

#include "includes.h"
#include"bitMath.h"
#include"errStat.h"
#include "regsAndResponses.h"
#include"i2c.h"
#include"eeprom.h"


unsigned char access = '0';
unsigned char mode = '0';

void main(){

//    TWI_voidInitMaster(0);
//    LCD_init();
//        //EEPROM send data with location 100
//        EEPROM_Write(100,'m');
//        char data=0;
//        data = EEPROM_Read(100); // read the value that take from user
//        while (1){
//
//        	LCD_displayCharacter(data);
//        }


		TWI_voidInitMaster(0);
		EEPROM_Write(104,'w');

		LCD_init();

		_delay_ms(200);

		SPI_initMaster();

		LCD_displayString("for admin mode 1");
		LCD_goToRowColumn(1,0);
		LCD_displayString("for user mode 2");
		if(access == '0'){
			access = KEYPAD_GetPressedKey();
		}
		//SPI_sendByte(KEYPAD_GetPressedKey());
		if(access == '1'){
			LCD_clearScreen();
			LCD_displayString("admin");

			access = '3';
		    mode = '1';
		}
		if(access  == '2'){
			LCD_clearScreen();
			LCD_displayString("user");
			access = '3';
			mode = '2';
		}


	    while(1)
	    {

	    	char input= KEYPAD_GetPressedKey();
	    	if(mode == '1'){

	    		SPI_sendByte(input);
	    	}
	    	else if(mode == '2'){
	    		if(input!='5' && input != '6'){
	    			SPI_sendByte(input);
	    		}else{
	    			LCD_clearScreen();
	    			LCD_displayString("Access Denied");
	    		}
	    		//if(KEYPAD_GetPressedKey()!='5'&& KEYPAD_GetPressedKey()!='6'){

	    		//}else{

	    		//}
	    	}
		}


}

//SPI_sendByte(EEPROM_Read(101));
    	//SPI_sendByte(EEPROM_Read(102));
    	//display "enter id"
    	//take the input and wait for the ok
    	// on the ok check the memory  if the id exists
    	// if exists give access if not prompt an error


    	//if(pressed ok ){
    	//}


