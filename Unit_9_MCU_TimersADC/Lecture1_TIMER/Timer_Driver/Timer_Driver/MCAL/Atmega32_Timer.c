/*
 * Atmega32_Timer.c
 *
 * Created: 9/1/2022 7:24:43 PM
 *  Author: KHLOUD MOHAMED
 */ 

/* ================================================================ */
/*                             Includes                             */
/* ================================================================ */

#include "Atmega32_Timer.h"

/* ================================================================ */
/*                         Generic Macros                           */
/* ================================================================ */

void (*GP_IRQ_CallBack)(void) = NULL;

TIMER0_Config_t G_TIMER0_Config_t;


/* ================================================================ */
/*                             APIs                                 */
/* ================================================================ */

void MCAL_TIMER0_Init(TIMER0_Config_t *TIMER0_Config)
{
	G_TIMER0_Config_t = *TIMER0_Config;
	
	TCCR0 |= TIMER0_Config->Timer_Mode;
	
	if(TIMER0_Config->Timer_Mode == TIMER_MODE_FAST_PWM_INVERTING || TIMER0_Config->Timer_Mode == TIMER_MODE_FAST_PWM_NONINVERTING)
	{
		DDRB |= (1<<3);
	}
	 
	TCCR0 |= TIMER0_Config->Clock_Source;
	if(TIMER0_Config->Clock_Source == TIMER_CLOCK_SOURCE_EXTERNaL_FALLING_EDGE || TIMER0_Config->Clock_Source == TIMER_CLOCK_SOURCE_EXTERNaL_RISING_EDGE) 
	{
		DDRB &= ~(1<<0);
	}
	
	TIMSK |= TIMER0_Config->IRQ_Enable;
	if(TIMER0_Config->IRQ_Enable != TIMER0_IRQ_ENABLE_NONE)
	{
		Enable_G_Interrupt();
	}
	else
	{
		Disable_G_Interrupt();
	}
	
	GP_IRQ_CallBack = TIMER0_Config->P_IRQ_CallBack;
}
void MCAL_TIMER0_DeInit()
{
	TCCR0 &= ~((1<<0) | (1<<1) | (1<<2));  // Timer/Counter stopped
}

void MCAL_TIMER0_GetCompareValue(uint8* TicksNumber)
{
	*TicksNumber = TCNT0;
}
void MCAL_TIMER0_SetCompareValue(uint8 TicksNumber)
{
	OCR0 = TicksNumber;
}

void MCAL_PWM_DutyCycle(uint8 Duty_Cycle)
{
	if(G_TIMER0_Config_t.Timer_Mode == TIMER_MODE_FAST_PWM_NONINVERTING)
	{
		OCR0 = Duty_Cycle;
	}
	else if(G_TIMER0_Config_t.Timer_Mode == TIMER_MODE_FAST_PWM_INVERTING)
	{
		OCR0 = (uint8)(255 - Duty_Cycle);
	}
}

ISR(TIMER0_OVF_vect)
{
	GP_IRQ_CallBack();
}

ISR(TIMER0_COMP_vect)
{
	GP_IRQ_CallBack();
}