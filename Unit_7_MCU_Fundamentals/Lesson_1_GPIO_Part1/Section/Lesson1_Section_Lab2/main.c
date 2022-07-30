/*
 * Unit7_Lesson1_Section_Lab2.c
 *
 * Created: 7/25/2022 3:50:09 AM
 * Author : KHLOUD MOHAMED
 */ 

#define F_CPU 8000000UL

#include <util/delay.h>
#include "MemoryMap.h"
#include "Utils.h"

static unsigned char SegmentNumber[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F} ;

int main(void)
{
    DDRA = 0xFF ;
	Clear_Bit(DDRC,0);
	Set_Bit(PORTC,0);
	
	unsigned char i ;
	
    while (1) 
    {
		if(Read_Bit(PINC,0) == 0)
		{
			while(Read_Bit(PINC,0) == 0)
			{
			  for(i=0 ; i<10 ; i++)
			  {
				  PORTA = SegmentNumber[i];
				  _delay_ms(500);
			  }
			  
			}
		}
    }
}

