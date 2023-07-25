/*
 * eeprom.c
 *
 *  Created on: Jul 8, 2023
 *      Author: batma
 */

#include "eeprom.h"
	void EEPROM_Write(int location_Address,unsigned char Copy_Data)
	{
		// data is 10 bit bec EEPROM 8 K
		// 1010 000 --> 1010 A2 B10 B9
		unsigned char location_Address_Packet=EEPROM_FIXED_ADDRESS | (0<<2) |(unsigned char)(location_Address>>8); // from location add we need the first 3 bit for add location
		//send start condition
		TWI_SendStartCondition();
		//send the addressPacket
		TWI_SendSlaveAddressWithWrite(location_Address_Packet);
		// send the rest 8bit of the location address
		TWI_MasterWriteDataByte((unsigned char)location_Address);
		// send the data
		TWI_MasterWriteDataByte(Copy_Data);
		//stop the condition of TWI
		TWI_SendStopCondition();
		//delay for 10 ms to write in the memory
		_delay_ms(10);
	}


	unsigned char EEPROM_Read(int location_Address)
	{
		unsigned char data ;
		unsigned char local_AddressPacket=EEPROM_FIXED_ADDRESS | (0<<2) |(unsigned char)(location_Address>>8);
		TWI_SendStartCondition();
		// 7 bit slave with write to can be able to send the rest 8 bit of location address
		TWI_SendSlaveAddressWithWrite(local_AddressPacket);
		// send the rest of 8 bits
		TWI_MasterWriteDataByte((unsigned char)location_Address);
		// send repeated start
		TWI_SendRepeatedStart();
		// send slave add with read
		TWI_SendSlaveAddressWithRead(local_AddressPacket);
		// read the send data
		TWI_MasterReadDataByte(&data);
		//send stop condition
		TWI_SendStopCondition();
		return data;
	}
