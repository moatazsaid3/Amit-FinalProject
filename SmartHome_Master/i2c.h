/*
 * i2c.h
 *
 *  Created on: Jul 8, 2023
 *      Author: batma
 */

#ifndef I2C_H_
#define I2C_H_
#include"regsAndResponses.h"
#include "errStat.h"
#include "bitMath.h"
void TWI_voidInitMaster(unsigned char Copy_Address);
void TWI_voidInitSlave(unsigned char Copy_address);
TWI_ErrStatus TWI_SendStartCondition();
TWI_ErrStatus TWI_SendRepeatedStart();
TWI_ErrStatus TWI_SendSlaveAddressWithWrite(unsigned char copy_Slaveaddress);
TWI_ErrStatus TWI_SendSlaveAddressWithRead(unsigned char copy_Slaveaddress);
TWI_ErrStatus TWI_MasterWriteDataByte(unsigned char copy_DataByte);
TWI_ErrStatus TWI_MasterReadDataByte(unsigned char *copy_DataByte);
void TWI_SendStopCondition(void);
#endif /* I2C_H_ */
