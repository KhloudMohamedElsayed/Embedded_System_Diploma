/*
 * Atmega32_GPIO.h
 *
 * Created: 9/1/2022 5:15:54 PM
 *  Author: KHLOUD MOHAMED
 */ 


#ifndef ATMEGA32_GPIO_H_
#define ATMEGA32_GPIO_H_


/* ================================================================ */
/*                             Includes                             */
/* ================================================================ */

#include "Atmega32_Header.h"

/* ================================================================ */
/*                             Structure                            */
/* ================================================================ */

typedef struct
{
	 uint8 GPIO_PinNumber;
	 uint8 GPIO_PinMode;
	
}GPIO_PinConfig_t;

/* ================================================================ */
/*                             Macros                               */
/* ================================================================ */

// GPIO_PIN_NUMBERS

#define GPIO_PIN_0					0
#define GPIO_PIN_1					1
#define GPIO_PIN_2					2
#define GPIO_PIN_3					3
#define GPIO_PIN_4					4
#define GPIO_PIN_5					5
#define GPIO_PIN_6					6
#define GPIO_PIN_7					7

#define GPIO_PORT					8

// GPIO_PIN_MODES

#define GPIO_MODE_INPUT_Hiz			0
#define GPIO_MODE_INPUT_PU			1
#define GPIO_MODE_OUTPUT_PP			2

// GPIO_PIN_STATE

#define GPIO_PIN_HIGH				0b1
#define GPIO_PIN_LOW				0b0

#define GPIO_PIN_SET				1
#define GPIO_PIN_RESET				0


/* ================================================================ */
/*                             APIs                                 */
/* ================================================================ */

void MCAL_GPIO_Init(GPIO_Typedef_t *GPIOx , GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_Typedef_t *GPIOx );

uint8 MCAL_GPIO_ReadPin(GPIO_Typedef_t *GPIOx ,uint8 PinNumber);
uint8 MCAL_GPIO_ReadPort(GPIO_Typedef_t *GPIOx );

void MCAL_GPIO_WritePin(GPIO_Typedef_t *GPIOx ,uint8 PinNumber , uint8 Value);
void MCAL_GPIO_WritePort(GPIO_Typedef_t *GPIOx ,uint8 Value );

void MCAL_GPIO_TogglePin(GPIO_Typedef_t *GPIOx ,uint8 PinNumber);




#endif /* ATMEGA32_GPIO_H_ */