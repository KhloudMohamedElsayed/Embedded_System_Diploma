/*
 * MemoryMap.h
 *
 * Created: 7/25/2022 3:03:00 AM
 *  Author: KHLOUD MOHAMAED
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

#define DDRA			(*(volatile unsigned char*)0x3A)
#define PORTA			(*(volatile unsigned char*)0x3B)
#define PINA			(*(volatile unsigned char*)0x39)

#define DDRB			(*(volatile unsigned char*)0x37)
#define PORTB			(*(volatile unsigned char*)0x38)
#define PINB			(*(volatile unsigned char*)0x36)

#define DDRC			(*(volatile unsigned char*)0x34)
#define PORTC			(*(volatile unsigned char*)0x35)
#define PINC			(*(volatile unsigned char*)0x33)



#endif /* MEMORYMAP_H_ */