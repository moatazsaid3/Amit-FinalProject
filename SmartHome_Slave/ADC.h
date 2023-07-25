/*
 * ADC.h
 *
 *  Created on: Jun 14, 2023
 *      Author: moata
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define degree_sysmbol 0xdf


int ADC_Read(char channel);
void ADC_Init();






#endif /* ADC_H_ */
