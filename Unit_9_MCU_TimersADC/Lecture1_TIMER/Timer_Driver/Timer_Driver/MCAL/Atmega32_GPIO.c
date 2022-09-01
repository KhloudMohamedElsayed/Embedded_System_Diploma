/*
 * Atmega32_GPIO.c
 *
 * Created: 9/1/2022 6:33:16 PM
 *  Author: KHLOUD MOHAMED
 */ 

/* ================================================================ */
/*                             Includes                             */
/* ================================================================ */

#include "Atmega32_GPIO.h"
/* ================================================================ */
/*                             APIs                                 */
/* ================================================================ */

void MCAL_GPIO_Init(GPIO_Typedef_t *GPIOx , GPIO_PinConfig_t *PinConfig)
{
     switch(PinConfig->GPIO_PinNumber)
	 {
	    case GPIO_PIN_0:
		{
			switch(PinConfig->GPIO_PinMode)
			{
			     case GPIO_MODE_INPUT_Hiz:
				 {
				    GPIOx->DDR.bits.DD0 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT0 = GPIO_PIN_LOW;
					break;
				 }	
				 case GPIO_MODE_INPUT_PU:
				 {
				    GPIOx->DDR.bits.DD0 = GPIO_PIN_LOW;
				    GPIOx->PORT.bits.PORT0 = GPIO_PIN_HIGH;
				    break;
				 }
				 case GPIO_MODE_OUTPUT_PP:
				 {
				    GPIOx->DDR.bits.DD0 = GPIO_PIN_HIGH;
				    GPIOx->PORT.bits.PORT0 = GPIO_PIN_LOW;
				    break;
				 }
	        }
			break;
		}
		case GPIO_PIN_1:
		{
			switch(PinConfig->GPIO_PinMode)
			{
				case GPIO_MODE_INPUT_Hiz:
				{
					GPIOx->DDR.bits.DD1 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT1 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD1 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT1 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD1 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT1 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PIN_2:
		{
			switch(PinConfig->GPIO_PinMode)
			{
				case GPIO_MODE_INPUT_Hiz:
				{
					GPIOx->DDR.bits.DD2 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT2 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD2 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT2 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD2 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT2 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PIN_3:
		{
			switch(PinConfig->GPIO_PinMode)
			{
				case GPIO_MODE_INPUT_Hiz:
				{
					GPIOx->DDR.bits.DD3 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT3 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD3 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT3 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD3 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT3 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PIN_4:
		{
			switch(PinConfig->GPIO_PinMode)
			{
				case GPIO_MODE_INPUT_Hiz:
				{
					GPIOx->DDR.bits.DD4 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT4 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD4 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT4 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD4 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT4 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PIN_5:
		{
			switch(PinConfig->GPIO_PinMode)
			{
				case GPIO_MODE_INPUT_Hiz:
				{
					GPIOx->DDR.bits.DD5 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT5 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD5 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT5 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD5 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT5 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PIN_6:
		{
			switch(PinConfig->GPIO_PinMode)
			{
				case GPIO_MODE_INPUT_Hiz:
				{
					GPIOx->DDR.bits.DD6 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT6 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD6 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT6 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD6 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT6 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PIN_7:
		{
			switch(PinConfig->GPIO_PinMode)
			{
				case GPIO_MODE_INPUT_Hiz:
				{
					GPIOx->DDR.bits.DD7 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT7 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD7 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT7 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD7 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT7 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PORT:
		{
		   switch(PinConfig->GPIO_PinMode)
		   {
		        case GPIO_MODE_INPUT_Hiz:
				{
				   GPIOx->DDR.DDR = 0x00;
				   GPIOx->PORT.PORT=0x00;
				   break;
				}
			   case GPIO_MODE_INPUT_PU:
			   {
				   GPIOx->DDR.DDR = 0x00;
				   GPIOx->PORT.PORT=0xFF;
				   break;
			   }
			   case GPIO_MODE_OUTPUT_PP:
			   {
				    GPIOx->DDR.DDR = 0xFF;
				    GPIOx->PORT.PORT=0x00;
				    break;
			   }
			   
		   }
		   break;
		}
	 }
}
void MCAL_GPIO_DeInit(GPIO_Typedef_t *GPIOx )
{
    GPIOx->DDR.DDR = 0x00;
	GPIOx->PORT.PORT = 0x00;
}

uint8 MCAL_GPIO_ReadPin(GPIO_Typedef_t *GPIOx ,uint8 PinNumber)
{
	uint8 PinState = 0;
	switch(PinNumber)
	{
		case GPIO_PIN_0:
		{
			PinState = (uint8)(GPIOx->PIN.bits.PIN0);
			break;
		}
		case GPIO_PIN_1:
		{
			PinState = (uint8)(GPIOx->PIN.bits.PIN1);
			break;
		}
		case GPIO_PIN_2:
		{
			PinState = (uint8)(GPIOx->PIN.bits.PIN2);
			break;
		}
		case GPIO_PIN_3:
		{
			PinState = (uint8)(GPIOx->PIN.bits.PIN0);
			break;
		}
		case GPIO_PIN_4:
		{
			PinState = (uint8)(GPIOx->PIN.bits.PIN4);
			break;
		}
		case GPIO_PIN_5:
		{
			PinState = (uint8)(GPIOx->PIN.bits.PIN5);
			break;
		}
		case GPIO_PIN_6:
		{
			PinState = (uint8)(GPIOx->PIN.bits.PIN6);
			break;
		}
		case GPIO_PIN_7:
		{
			PinState = (uint8)(GPIOx->PIN.bits.PIN7);
			break;
		}
	}
	return PinState;
}
uint8 MCAL_GPIO_ReadPort(GPIO_Typedef_t *GPIOx )
{
	uint8 PortState = 0x00;
	PortState = ((uint8)(GPIOx->PIN.PIN));
	return PortState;
	
}

void MCAL_GPIO_WritePin(GPIO_Typedef_t *GPIOx ,uint8 PinNumber , uint8 Value)
{
	switch(PinNumber)
	{
		case GPIO_PIN_0:
		{
			if(Value)
			    GPIOx->PORT.bits.PORT0 = GPIO_PIN_HIGH;
			else
			   	GPIOx->PORT.bits.PORT0 = GPIO_PIN_LOW;
			break;	   
		}
		case GPIO_PIN_1:
		{
			if(Value)
			GPIOx->PORT.bits.PORT1 = GPIO_PIN_HIGH;
			else
			GPIOx->PORT.bits.PORT1 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_2:
		{
			if(Value)
			GPIOx->PORT.bits.PORT2 = GPIO_PIN_HIGH;
			else
			GPIOx->PORT.bits.PORT2 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_3:
		{
			if(Value)
			GPIOx->PORT.bits.PORT3 = GPIO_PIN_HIGH;
			else
			GPIOx->PORT.bits.PORT3 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_4:
		{
			if(Value)
			GPIOx->PORT.bits.PORT4 = GPIO_PIN_HIGH;
			else
			GPIOx->PORT.bits.PORT4 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_5:
		{
			if(Value)
			GPIOx->PORT.bits.PORT5 = GPIO_PIN_HIGH;
			else
			GPIOx->PORT.bits.PORT5 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_6:
		{
			if(Value)
			GPIOx->PORT.bits.PORT6 = GPIO_PIN_HIGH;
			else
			GPIOx->PORT.bits.PORT6 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_7:
		{
			if(Value)
			GPIOx->PORT.bits.PORT7 = GPIO_PIN_HIGH;
			else
			GPIOx->PORT.bits.PORT7 = GPIO_PIN_LOW;
			break;
		}
		
	}
	
}
void MCAL_GPIO_WritePort(GPIO_Typedef_t *GPIOx ,uint8 Value )
{
	GPIOx->PORT.PORT = Value;
}

void MCAL_GPIO_TogglePin(GPIO_Typedef_t *GPIOx ,uint8 PinNumber)
{
	switch(PinNumber)
	{
		case GPIO_PIN_0:
		{
			 GPIOx->PORT.bits.PORT0 ^= GPIO_PIN_HIGH;
			 break;
		}
		case GPIO_PIN_1:
		{
			GPIOx->PORT.bits.PORT1 ^= GPIO_PIN_HIGH;
			break;
		}
		case GPIO_PIN_2:
		{
			GPIOx->PORT.bits.PORT2 ^= GPIO_PIN_HIGH;
			break;
		}
		case GPIO_PIN_3:
		{
			GPIOx->PORT.bits.PORT3 ^= GPIO_PIN_HIGH;
			break;
		}
		case GPIO_PIN_4:
		{
			GPIOx->PORT.bits.PORT4 ^= GPIO_PIN_HIGH;
			break;
		}
		case GPIO_PIN_5:
		{
			GPIOx->PORT.bits.PORT5 ^= GPIO_PIN_HIGH;
			break;
		}
		case GPIO_PIN_6:
		{
			GPIOx->PORT.bits.PORT6 ^= GPIO_PIN_HIGH;
			break;
		}
		case GPIO_PIN_7:
		{
			GPIOx->PORT.bits.PORT7 ^= GPIO_PIN_HIGH;
			break;
		}
	}
}