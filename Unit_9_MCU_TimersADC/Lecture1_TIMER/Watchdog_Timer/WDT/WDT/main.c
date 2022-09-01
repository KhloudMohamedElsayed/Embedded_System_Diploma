/*
 * WDT.c
 *
 * Created: 8/30/2022 2:12:13 AM
 * Author : KHLOUD MOHAMED
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(PORT,BIT)			(PORT |= (1<<BIT))
#define RESET_BIT(PORT,BIT)			(PORT &= ~(1<<BIT))
#define TOG_BIT(PORT,BIT)			(PORT ^= (1<<BIT))
#define GET_BIT(PORT,BIT)			(PORT & (1<<BIT))

#define LED_DDR				DDRC
#define LED_PORT			PORTC
#define LED_PIN				0

void WDT_OFF()
{
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	WDTCR = 0x00;
}

void WDT_ON()
{
	WDTCR |= (1<<WDE) | (1<<WDP1) | (1<<WDP2);
	RESET_BIT(WDTCR,WDP0);
}

int main(void)
{
    SET_BIT(LED_DDR,LED_PIN);
	_delay_ms(500);
    while (1) 
    {
		WDT_ON();
		TOG_BIT(LED_PORT,LED_PIN);
		_delay_ms(2000);
		WDT_OFF();
    }
}

