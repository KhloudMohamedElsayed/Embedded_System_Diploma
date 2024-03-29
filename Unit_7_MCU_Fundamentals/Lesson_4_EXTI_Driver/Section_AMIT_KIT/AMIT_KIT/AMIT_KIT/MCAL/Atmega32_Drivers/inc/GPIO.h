/*
 * GPIO.h
 *
 * Created: 7/30/2022 5:58:00 PM
 *  Author: KHLOUD MOHAMED
 */ 


#ifndef GPIO_H_
#define GPIO_H_


/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "Atmega32_MemoryMap.h"

/* ================================================================ */
/* =================== User type definitions  ===================== */
/* ================================================================ */

typedef struct{
	uint8_t GPIO_PinNumber;             // Specifies The GPIO Pin To Be Configured
	                                   // This Parameter Can Be a Value of @ref GPIO_PIN_define / GPIO_PORT_define

	uint8_t GPIO_PinMode;               // Specifies The Mode For Selected Pin
	                                    // This Parameter Can Be a value of @ref GPIO_MODE_define
}GPIO_PinConfig_t;

/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

#define GPIO_PIN_0		0
#define GPIO_PIN_1		1
#define GPIO_PIN_2		2
#define GPIO_PIN_3		3
#define GPIO_PIN_4		4
#define GPIO_PIN_5		5
#define GPIO_PIN_6		6
#define GPIO_PIN_7		7

#define GPIO_PORT		8


//@ref GPIO_MODE_define
 
#define GPIO_MODE_INPUT_Hiz			0	
#define GPIO_MODE_INPUT_PU			1	
#define GPIO_MODE_OUTPUT_PP			2	

//@ref GPIO_PIN_STATE_define
 
#define GPIO_HIGH					1
#define GPIO_LOW					0

/* ================================================================ */
/* ============== APIs Supported by "MCAL GPIO DRIVER" ============ */
/* ================================================================ */


void MCAL_GPIO_Init (GPIO_Typedef_t * GPIOx, GPIO_PinConfig_t * cfg);
void MCAL_GPIO_DeInit (GPIO_Typedef_t * GPIOx);

uint8_t MCAL_GPIO_ReadPin (GPIO_Typedef_t * GPIOx, uint8_t PinNumber);
uint8_t MCAL_GPIO_ReadPort (GPIO_Typedef_t * GPIOx);

void MCAL_GPIO_WritePin (GPIO_Typedef_t * GPIOx, uint8_t PinNumber, uint8_t data);
void MCAL_GPIO_WritePort (GPIO_Typedef_t * GPIOx, uint8_t data);

void MCAL_GPIO_TogglePin (GPIO_Typedef_t * GPIOx, uint8_t PinNumber);




#endif /* GPIO_H_ */