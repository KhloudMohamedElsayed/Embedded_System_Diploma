/*
 * Stm32_F103C6_GPIO_Driver.c
 *
 *  Created on: Jul 23, 2022
 *      Author: KHLOUD MOHAMED
 */

#include "Stm32_F103C6_GPIO_Driver.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{

	case GPIO_PIN_0:
		return 0;
		break;

	case GPIO_PIN_1:
		return 4;
		break;

	case GPIO_PIN_2:
		return 8;
		break;

	case GPIO_PIN_3:
		return 12;
		break;

	case GPIO_PIN_4:
		return 16;
		break;

	case GPIO_PIN_5:
		return 20;
		break;

	case GPIO_PIN_6:
		return 24;
		break;

	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;

	case GPIO_PIN_9:
		return 4;
		break;

	case GPIO_PIN_10:
		return 8;
		break;

	case GPIO_PIN_11:
		return 12;
		break;

	case GPIO_PIN_12:
		return 16;
		break;

	case GPIO_PIN_13:
		return 20;
		break;

	case GPIO_PIN_14:
		return 24;
		break;

	case GPIO_PIN_15:
		return 28;
		break;

	}
	return 0;
}

/**================================================================
 * @Fn-					-MCAL_GPIO_Init
 * @brief -				-Initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in] -			-GPIOx : where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] -			-PinCongig pointer to a GPIO_PinConfig_t structure that contains
 *  						 the configuration information for the specified GPIO PIN
 * @retval -				-none
 * Note-					-Stm32F103C6 MCU has GPIO A,B,C,E Modules
 *  						But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the Module
 */


void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx , GPIO_PinConfig_t *PinConfig )
{


   volatile uint32_t *configregister = NULL ;
   uint8_t PIN_Config = 0;

   configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8 ) ? &GPIOx->CRL : &GPIOx->CRH ;


   (*configregister) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber));


   if( (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD))
   {

	   PIN_Config = ( (((PinConfig->GPIO_MODE -4 ) << 2) |(PinConfig->GPIO_Output_Speed)) & 0x0F);

   }


   else
   {
	   if( (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG ) || (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO))
	   {

		   PIN_Config = ( (((PinConfig->GPIO_MODE) << 2) | 0x0 ) & 0x0F);
	   }

	   else if(PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT) //consider it as input floating
	   {
		   PIN_Config = ( (((GPIO_MODE_INPUT_FLO) << 2) | (0x0) ) & 0x0F);
	   }
	   else
	   {
		   PIN_Config = ((((GPIO_MODE_INPUT_PU) << 2 ) |(0x0) ) & 0x0F );

		   if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
		   {


			 GPIOx->ODR |= PinConfig->GPIO_PinNumber;
		   }
		   else
		   {


			  GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
		   }
	   }
   }
   (*configregister) |= ((PIN_Config) << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
}

/**================================================================
* @Fn-					-MCAL_GPIO_DeInit
* @brief -				-reset all the GPIO Registers
* @param [in] -			-GPIOx : where x can be (A..E depending on device used) to select the GPIO peripheral
* @retval -				-none
* Note-					-none
*/

void MCAL_GPIO_DeInit (GPIO_TypeDef * GPIOx )
{

	//	GPIOx->CRL = 0x44444444;
	//	GPIOx->CRH = 0x44444444;
	//  GPIOx->IDR = ; (Read only)
	//	GPIOx->ODR = 0x00000000;
	//	GPIOx->BSRR = 0x00000000;
	//	GPIOx->BRR = 0x00000000;
	//	GPIOx->LCKR = 0x00000000;


	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}
}

/**================================================================
 * @Fn-					-MCAL_GPIO_ReadPin
 * @brief -				-Read Specific PIN
 * @param [in] -			-GPIOx : where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] -			-PinNumber : Set Pin Number according ref GPIO_PINS_define
 * @retval -				-the input pin value (two values based on ref GPIO_PIN_state)
 * Note-					-none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	uint8_t bitstatus ;
	if(((GPIOx->IDR) & PinNumber ) != GPIO_PIN_RESET)
	{
		bitstatus = GPIO_PIN_SET;
	}
	else
	{
		bitstatus = GPIO_PIN_RESET;
	}
	return bitstatus;
}

/* @Fn-					-MCAL_GPIO_ReadPin
 * @brief -				-Read the input port Value
 * @param [in] -			-GPIOx : where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval -				-the input port value
 * Note-					-none
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef * GPIOx )
{
  uint16_t port_value;
  port_value = (uint16_t)(GPIOx->IDR);
  return port_value;
}

/**================================================================
 * @Fn				- MCAL_GPIO_WritePin
 * @brief			- Write on Specific pin
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		- PinNumber: specific the port bit to read @ref GPIO_PINS_define
 * @param [in] 		- Value: Pin value
 * @retval 			- None
 * Note				- None
 */

void MCAL_GPIO_WritePin(GPIO_TypeDef * GPIOx , uint16_t PinNumber , uint8_t Value )
{
   if(Value != GPIO_PIN_RESET )
   {
	   //GPIOx->ODR |= PinNumber;
	   //or
	   //Bits 15:0 BSy: Port x Set bit y (y=0 .. 15)
	   //These bits are write-only and can be accessed in Word mode only.
	   //0: No action on the corresponding ODRx bit
	   //1: Set the corresponding ODRx bit

	   GPIOx->BSRR = (uint32_t)PinNumber;
   }
   else
   {
	   //Bits 31:16 BSy: Port x Set bit y (y=0 .. 15)
	   //These bits are write-only and can be accessed in Word mode only.
	   //0: No action on the corresponding ODRx bit
	   //1: Reset the corresponding ODRx bit

	   GPIOx->BRR = (uint32_t)PinNumber;
   }
}

/**================================================================
 * @Fn				- MCAL_GPIO_WritePort
 * @brief			- Write on Specific PORT
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		- Value: Port value
 * @retval 			- None
 * Note				- None
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef * GPIOx , uint16_t Value   )
{
	GPIOx->ODR = (uint32_t)Value;
}

/**================================================================
 * @Fn				- MCAL_GPIO_TogglePin
 * @brief			- Toggle Specific pin
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		- PinNumber: specific the port bit to read @ref GPIO_PINS_define
 * @retval 			- None
 * Note				- None
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
    GPIOx->ODR ^= (PinNumber);
}

/**================================================================
 * @Fn				- MCAL_GPIO_LockPin
 * @brief			- The locking mechanism allows the IO configuration to be frozen
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		- PinNumber: specific the port bit to read @ref GPIO_RETURN_LOCK
 * @retval 			- OK if pin configure is locked Or ERROR if pin is not locked (OK & ERROR are defined @ref GPIO_RETURN_LOCK)
 * Note				- None
 */

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef * GPIOx , uint16_t PinNumber)
{

	volatile uint32_t temp = 1<<16;

	temp |= PinNumber;


	GPIOx->LCKR = temp;

	GPIOx->LCKR = PinNumber;

	GPIOx->LCKR = temp;


	temp = GPIOx->LCKR;

	if( (uint32_t) (GPIOx->LCKR & 1<<16 ))
	{
		return GPIO_RETURN_LOCK_Enabled;
	}
	else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}

}
