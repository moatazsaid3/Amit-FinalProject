/*
 * bitMath.h
 *
 *  Created on: Jul 8, 2023
 *      Author: batma
 */

#ifndef BITMATH_H_
#define BITMATH_H_


#define  Set_Bit(PORT_ID,PIN_ID)          PORT_ID |= (1<<PIN_ID)
#define  Clear_Bit(PORT_ID,PIN_ID)        PORT_ID &= ~(1<<PIN_ID)
#define  Toggle_Bit(PORT_ID,PIN_ID)       PORT_ID ^= (1<<PIN_ID)
#define  Get_Bit(PORT_ID,PIN_ID)		  (((PORT_ID)>>(PIN_ID)) & 0x01)

#endif /* BITMATH_H_ */
