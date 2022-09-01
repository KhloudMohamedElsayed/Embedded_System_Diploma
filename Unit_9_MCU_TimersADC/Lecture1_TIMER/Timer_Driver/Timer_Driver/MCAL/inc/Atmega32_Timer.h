/*
 * Atmega32_Timer.h
 *
 * Created: 9/1/2022 5:16:11 PM
 *  Author: KHLOUD MOHAMED
 */ 


#ifndef ATMEGA32_TIMER_H_
#define ATMEGA32_TIMER_H_

/* ================================================================ */
/*                             Includes                             */
/* ================================================================ */

#include "Atmega32_Header.h"
#include "avr/interrupt.h"

/* ================================================================ */
/*                             Structure                            */
/* ================================================================ */

typedef struct
{
	uint8 Timer_Mode;
	uint8 Clock_Source;
	uint8 IRQ_Enable;
	void(*P_IRQ_CallBack)(void);
	
}TIMER0_Config_t;


/* ================================================================ */
/*                             Macros                               */
/* ================================================================ */

// TIMER_MODE

#define TIMER_MODE_NORMAL						((uint8)(0))
#define TIMER_MODE_CTC							((uint8)(1<<3))
#define TIMER_MODE_FAST_PWM_INVERTING			((uint8)(0x78)) //WGM00=1 , WGM01=1,COM00=1,CMO01=1
#define TIMER_MODE_FAST_PWM_NONINVERTING        ((uint8)(0x68)) //WGM00=1 , WGM01=1,COM00=0,CMO01=1

// TIMER_CLOCK_SOURCE

#define TIMER_CLOCK_SOURCE_INTERNAL_NO_PRESCALER				((uint8)(1<<0))
#define TIMER_CLOCK_SOURCE_INTERNAL_PRESCALER_8					((uint8)(1<<1))
#define TIMER_CLOCK_SOURCE_INTERNAL_PRESCALER_64				((uint8)(0x03))
#define TIMER_CLOCK_SOURCE_INTERNAL_PRESCALER_256				((uint8)(0x04))
#define TIMER_CLOCK_SOURCE_INTERNAL_PRESCALER_1024				((uint8)(0x05))
#define TIMER_CLOCK_SOURCE_EXTERNaL_FALLING_EDGE				((uint8)(0x06))
#define TIMER_CLOCK_SOURCE_EXTERNaL_RISING_EDGE				    ((uint8)(0x07))

// TIMER_IRQ_ENABLE

#define TIMER0_IRQ_ENABLE_NONE								((uint8)(0))
#define TIMER0_IRQ_ENABLE_TOIE0								((uint8)(1<<0)) // Timer Overflow Interrupt Enable
#define TIMER0_IRQ_ENABLE_OCIE0								((uint8)(1<<1)) // Output Compare Match Interrupt Enable


/* ================================================================ */
/*                             APIs                                 */
/* ================================================================ */

void MCAL_TIMER0_Init(TIMER0_Config_t *TIMER0_Config);
void MCAL_TIMER0_DeInit();

void MCAL_TIMER0_GetCompareValue(uint8* TicksNumber);
void MCAL_TIMER0_SetCompareValue(uint8 TicksNumber);

void MCAL_PWM_DutyCycle(uint8 Duty_Cycle);



#endif /* ATMEGA32_TIMER_H_ */