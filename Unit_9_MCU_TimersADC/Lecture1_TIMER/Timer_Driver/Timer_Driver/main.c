/*
 * Timer_Driver.c
 *
 * Created: 9/1/2022 5:15:08 PM
 * Author : KHLOUD MOHAMED
 */ 

#define F_CPU	8000000UL

#include "Atmega32_GPIO.h"
#include "Atmega32_Timer.h"

void Timer_OverFlow_Interrupt_Handler(void);

uint32 counter = 0;

int main(void)
{
    SET_BIT(DDRB,0);
	
	MCAL_TIMER0_SetCompareValue(100);
	
	TIMER0_Config_t TIMER0_Config;
	
	TIMER0_Config.Timer_Mode = TIMER_MODE_CTC;
	TIMER0_Config.Clock_Source = TIMER_CLOCK_SOURCE_INTERNAL_PRESCALER_8;
	TIMER0_Config.IRQ_Enable = TIMER0_IRQ_ENABLE_TOIE0;
	TIMER0_Config.P_IRQ_CallBack = Timer_OverFlow_Interrupt_Handler;
	
	MCAL_TIMER0_Init(&TIMER0_Config);
    while (1) 
    {
    }
}

void Timer_OverFlow_Interrupt_Handler(void)
{
	counter++;
	if(counter == 3921)
	{
		TOGGLE_BIT(PORTB,0);
		
		counter=0;
	}
}
