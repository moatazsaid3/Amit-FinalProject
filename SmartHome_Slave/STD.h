#include <avr/io.h>
#include <util/delay.h>

#define SET_bit(Reg,Bit_No)			Reg|=(1<<Bit_No)
#define CLR_bit(Reg,Bit_No)			Reg&=~(1<<Bit_No)
#define TOG_bit(Reg,Bit_No)			Reg^=(1<<Bit_No)
#define GET_bit(Reg,Bit_No)			Reg=((Reg<<Bit_No)&1)

#define STD

typedef unsigned int uint8;
typedef char Int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;


