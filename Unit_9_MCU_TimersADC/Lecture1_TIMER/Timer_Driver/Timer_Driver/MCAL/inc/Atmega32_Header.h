/*
 * Atmega32_Header.h
 *
 * Created: 9/1/2022 5:17:09 PM
 *  Author: KHLOUD MOHAMED
 */ 


#ifndef ATMEGA32_HEADER_H_
#define ATMEGA32_HEADER_H_

/* ================================================================ */
/*                             Includes                             */
/* ================================================================ */

#include "Platform_Types.h"
#include "Util.h"

/* ================================================================ */
/*                       Address Of Memories                        */
/* ================================================================ */

#define FLASH_MEMORY		0x00
#define SRAM				0x60


/* ================================================================ */
/*                       Peripheral Base Address                    */
/* ================================================================ */

/* The Constant Difference between Memory Mapped Register Address  and  IO Mapped Register Address */

#define IO_MAPPING_OFFSET	0x20

#define GPIOA_Base			0x19	/* GPIOA address */
#define GPIOB_Base			0x16	/* GPIOB address */
#define GPIOC_Base			0x13	/* GPIOC address */
#define GPIOD_Base			0x10	/* GPIOD address */

#define TIMER0_Base			0x23	/* TIMER0 address */

#define TIFR_Base			0x36	/* Timer/Counter Interrupt Flag Register address */
#define TIMSK_Base			0x37	/* Timer/Counter Interrupt Mask Register address */


/* ================================================================ */
/*                             GPIO                                 */
/* ================================================================ */

typedef struct  
{
	volatile union
	{
		vuint8_t PIN;
		struct  
		{
			  vuint8_t PIN0 : 1;
			  vuint8_t PIN1 : 1;
			  vuint8_t PIN2 : 1;
			  vuint8_t PIN3 : 1;
			  vuint8_t PIN4 : 1;
			  vuint8_t PIN5 : 1;
			  vuint8_t PIN6 : 1;
			  vuint8_t PIN7 : 1;
		}bits;
	}PIN;
	
	volatile union
	{
		 vuint8_t DDR;
		 struct  
		 {
			  vuint8_t DD0 : 1;
			  vuint8_t DD1 : 1;
			  vuint8_t DD2 : 1;
			  vuint8_t DD3 : 1;
              vuint8_t DD4 : 1;
			  vuint8_t DD5 : 1;
			  vuint8_t DD6 : 1;
			  vuint8_t DD7 : 1;
		 }bits;
	}DDR;
	
	volatile union
	{
		vuint8_t PORT;
		struct  
		{
			 vuint8_t PORT0 : 1;
			 vuint8_t PORT1 : 1;
			 vuint8_t PORT2 : 1;
			 vuint8_t PORT3 : 1;
             vuint8_t PORT4 : 1;
			 vuint8_t PORT5 : 1;
			 vuint8_t PORT6 : 1;
			 vuint8_t PORT7 : 1;
		}bits;
	}PORT;
}GPIO_Typedef_t;


/* ================================================================ */
/*                             TIMER                                */
/* ================================================================ */

typedef struct
{
   vuint8_t OCR0;
   vuint8_t TCNT0;
   
   volatile union
   {
	   vuint8_t TCCR0_;
	   struct  
	   {
		   vuint8_t CS0n_  : 3;    // Clock select
		   vuint8_t WGM01  : 1;   // Waveform generation mode 
		   vuint8_t COM0n  : 2;   // Compare match output mode
		   vuint8_t WGM00  : 1;  // Waveform generation mode
		   vuint8_t F0C0   : 1;  // Force output compare
	   }bits;
   
	}TCCR0_;	
}TIMER0_Typedef_t;


// Timer/Counter Interrupt Mask Register_TIMSK

#define TIMSK					(*(vuint8_t*)(TIMSK_Base + IO_MAPPING_OFFSET))

#define TOIE0					0
#define OCIE0					1

// Timer/Counter Interrupt Flag Register_TIFR

#define TIFR					(*(vuint8_t*)(TIFR_Base + IO_MAPPING_OFFSET))

#define TOV0					0
#define OCF0					1



#define GPIOA			((GPIO_Typedef_t*) (GPIOA_Base + IO_MAPPING_OFFSET))
#define GPIOB			((GPIO_Typedef_t*) (GPIOB_Base + IO_MAPPING_OFFSET))
#define GPIOC			((GPIO_Typedef_t*) (GPIOC_Base + IO_MAPPING_OFFSET))
#define GPIOD			((GPIO_Typedef_t*) (GPIOD_Base + IO_MAPPING_OFFSET))

#define TIMER0			((TIMER0_Typedef_t*) (TIMER0_Base + IO_MAPPING_OFFSET))		


#define SREG_Base		0x3F
#define SREG			(*(vuint8_t*)(SREG_Base + IO_MAPPING_OFFSET))
#define I_Bit			7

#define Enable_G_Interrupt()	SREG |= (1 << I_Bit)
#define Disable_G_Interrupt()	SREG &= ~(1 << I_Bit)


#endif /* ATMEGA32_HEADER_H_ */