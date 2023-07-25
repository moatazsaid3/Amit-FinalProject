
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */

#include <avr/interrupt.h>
#include"STD.h"

#include"SPI.h"
#include"LCD.h"
#include"LED_rooms.h"
#include"ADC.h"


#define AC_DCMOTOR_PORT_DIR	DDRA
#define AC_DCMOTOR_PORT	PORTA
#define AC_DCMOTOR	7
int dim = 255;


void timer0_pwm(int dim){
	static int init = 0;
	SET_bit(DDRB,3);
	if(!init){
		SET_bit(TCCR0,WGM00);
		SET_bit(TCCR0,WGM01);
		SET_bit(TCCR0,COM01);
		SET_bit(TCCR0,COM00);
		SET_bit(TCCR0,CS01);
		init = 1;
	}
	OCR0 = dim;
}

void timer1_wave_fastPWM_A(double value)
{

	/* set OC1A as output pin */
	SET_bit(DDRD,5);
	/* select fast PWM mode*/
	SET_bit(TCCR1A,WGM11);
	SET_bit(TCCR1B,WGM12);

	SET_bit(TCCR1B,WGM13);
	/* load a value in OCR1A,ICR1 */
	OCR1A=value*1000;
	ICR1=19999;
	/* select timer clock, no prescaling */
	SET_bit(TCCR1B,CS10);
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_bit(TCCR1A,COM1A1);
}


ISR(SPI_STC_vect){
//	CLEAR_BIT(SREG,7);
	unsigned char chr = SPI_recieveByte();
	LCD_displayCharacter(chr);
	if(chr){
		switch(chr){
		case '1': TOG_bit(LED_PORT,ROOM1)	; 	break;
		case '2': TOG_bit(LED_PORT,ROOM2)	;	break;
		case '3': TOG_bit(LED_PORT,ROOM3)	;	break;
		case '4': TOG_bit(LED_PORT,ROOM4)	;	break;
		case '5': timer1_wave_fastPWM_A(0.9999)	;	break;
		case '6': timer1_wave_fastPWM_A(1.499999)	;	break;
		case '7':
			if (dim == 0) {dim =255;}
			else if (dim == 65) {dim = 0;}
			else if (dim == 125) {dim = 65;}
			else {dim = 125;}
			timer0_pwm(dim);
			break;
		default:break;
		}
	}
//	SET_bit(SREG,7);
}

void main(){

	SET_bit(AC_DCMOTOR_PORT_DIR, AC_DCMOTOR);// set the data directiopn of the air conditioner motor to output
	int temp;

	sei();

	ADC_Init();
	LCD_init();		/* Initialization of LCD */
	SPI_initSlave();
	LED_rooms_init();

	//timer_CTC_init_interrupt();
//			LCD_displayString( "Slave Device");
//			LCD_goToRowColumn(1, 0);
//			LCD_displayString( "Rcv Data: ");


	while(1)
	{


		//LCD_displayCharacter(SPI_recieveByte());
		temp = ((ADC_Read(0)/2)-1);	/* Read ADC channel 0 */
		if(temp>28 ){
			SET_bit(AC_DCMOTOR_PORT, AC_DCMOTOR);
		}
		if(temp<20 ){
			CLEAR_BIT(AC_DCMOTOR_PORT,AC_DCMOTOR);
		}
	}
}








//	temp sensor
//	char String[5];
//	int value;
//
//	ADC_Init();
//	LCD_init();		/* Initialization of LCD */
//
//	while(1)
//	{
//		value = ADC_Read(0);	/* Read ADC channel 0 */
//		itoa(value,String,10);	/* Integer to string conversion */
//		LCD_displayString(String);
//	}

	//code before adc(kepad/spi/rooms)
//int main(void)
//{
//		LCD_init();
//		SPI_initSlave();
//		LED_rooms_init();
//
////		LCD_displayString( "Slave Device");
////		LCD_goToRowColumn(1, 0);
////		LCD_displayString( "Rcv Data: ");
//
//
//	    while(1)
//	    {
//
//	    	unsigned char chr = SPI_recieveByte();
//	    	LCD_displayCharacter(chr);
//	    	if(chr){
//	    		switch(chr){
//	    			case '1': TOG_bit(LED_PORT,ROOM1)	; 	break;
//	    			case '2': TOG_bit(LED_PORT,ROOM2)	;	break;
//	    			case '3': TOG_bit(LED_PORT,ROOM3)	;	break;
//					case '4': TOG_bit(LED_PORT,ROOM4)	;	break;
//	    			default:break;
//	    		}
//	    	}
//		}
//}

