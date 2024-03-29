/*
 * Stm32_F103C6_RCC_Driver.h
 *
 *  Created on: Aug 4, 2022
 *      Author: KHLOUD MOHAMED
 */

#ifndef INC_STM32_F103C6_RCC_DRIVER_H_
#define INC_STM32_F103C6_RCC_DRIVER_H_

//Includes
#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO_Driver.h"

#define HSE_CLK 		(uint32_t)16000000
#define HSI_RC_CLK 		(uint32_t)8000000

uint32_t MCAL_RCC_GetSYS_CLCKFreq(void);

uint32_t MCAL_RCC_GetHCLKFreq(void);

uint32_t MCAL_RCC_GetPCLK1Freq(void);

uint32_t MCAL_RCC_GetPCLK2Freq(void);


#endif /* INC_STM32_F103C6_RCC_DRIVER_H_ */
