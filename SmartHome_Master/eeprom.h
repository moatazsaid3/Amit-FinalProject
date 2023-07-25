/*
 * eeprom.h
 *
 *  Created on: Jul 8, 2023
 *      Author: batma
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include"regsAndResponses.h"
#include <util\delay.h>
void EEPROM_Write(int location_Address,unsigned char Copy_Data);

unsigned char EEPROM_Read(int location_Address);
#endif /* EEPROM_H_ */
