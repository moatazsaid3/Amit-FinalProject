/*
 * errStat.h
 *
 *  Created on: Jul 8, 2023
 *      Author: batma
 */

#ifndef ERRSTAT_H_
#define ERRSTAT_H_

typedef enum
{
	NoError,
	StartconditionERR,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddresswithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
	}TWI_ErrStatus;

#endif /* ERRSTAT_H_ */
