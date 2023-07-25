
#ifndef STD
#define	STD
#include "STD.h"
#endif

#include "LED_rooms.h"

void LED_rooms_init(void){
	LED_PORT_DIR |= (1<< ROOM4) | (1<<ROOM3) | (1<<ROOM2) | (1<<ROOM1);
}
