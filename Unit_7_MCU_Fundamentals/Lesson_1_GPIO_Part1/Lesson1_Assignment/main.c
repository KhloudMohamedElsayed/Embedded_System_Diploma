/*
 * Lesson1_Assignment.c
 *
 * Created: 7/30/2022 2:25:43 PM
 * Author : MAHMOUD ABDALHADY
 */ 

#define F_CPU  1000000UL
#include <util/delay.h>
#include "MemoryMap.h"
#include "Utils.h"

#define PC0     0
#define PC1     1
#define PC2     2
#define PC3     3

#define LED0    PC0 
#define LED1    PC1
#define LED2    PC2
#define BUZZER  PC3

int main(void)
{
    DDRC |= Set_Bit(DDRC,0) | Set_Bit(DDRC,1) | Set_Bit(DDRC,2) | Set_Bit(DDRC,3);
	
    while (1) 
    {
		Set_Bit(PORTC,LED0);
		Clear_Bit(PORTC,LED1);
		Clear_Bit(PORTC,LED2);
		Clear_Bit(PORTC,BUZZER);
		_delay_ms(1000);
		
		Clear_Bit(PORTC,LED0);
		Set_Bit(PORTC,LED1);
		_delay_ms(1000);
		
		Clear_Bit(PORTC,LED1);
		Set_Bit(PORTC,LED2);
		_delay_ms(1000);
		
		Clear_Bit(PORTC,LED2);
		Set_Bit(PORTC,BUZZER);
		_delay_ms(1000);
		
    }
	return 0 ;
}

