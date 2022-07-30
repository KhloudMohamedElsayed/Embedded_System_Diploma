/*
 * Unit7_Lesson1_Section_Lab1.c
 *
 * Created: 7/25/2022 2:56:25 AM
 * Author : KHLOUD MOHAMED
 */ 

#define F_CPU 8000000UL

#include <util/delay.h>
#include "MemoryMap.h"
#include "Utils.h"


int main(void)
{
    DDRA |= Set_Bit(DDRA,0) | Set_Bit(DDRA,2) | Set_Bit(DDRA,4);
	Clear_Bit(DDRC,0);
	Set_Bit(PORTC,0);
	
    while (1) 
    {
		if(Read_Bit(PINC,0) == 0)
		{
			while(Read_Bit(PINC,0) == 0)
			{
				Set_Bit(PORTA,0);
				_delay_ms(500);
				Set_Bit(PORTA,2);
				_delay_ms(500);
				Set_Bit(PORTA,4);
				_delay_ms(500);
				
			}
		}
		
		Clear_Bit(PORTA,4);
		_delay_ms(500);
		Clear_Bit(PORTA,2);
		_delay_ms(500);
		Clear_Bit(PORTA,0);
		_delay_ms(500);
	}
  }


