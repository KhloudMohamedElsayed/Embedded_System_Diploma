/*
 * AMIT_KIT.c
 *
 * Created: 7/30/2022 5:55:59 PM
 * Author : KHLOUD MOHAMED
 */ 


#define F_CPU 1000000UL

#include "MCAL/Atmega32_Drivers/inc/Atmega32_MemoryMap.h"
#include "MCAL/Atmega32_Drivers/inc/GPIO.h"
#include "HAL/LCD_Driver/lcd.h"

GPIO_PinConfig_t * PinConfig_A;
GPIO_PinConfig_t * PinConfig_B;

int main(void)
{
    /*
	* LCD_D4 -> PORTA.4
    * LCD_D5 -> PORTA.5
    * LCD_D6 -> PORTA.6
    * LCD_D7 -> PORTA.7 
	*/
	
	
	PinConfig_A->GPIO_PinNumber = GPIO_PIN_4;
	PinConfig_A->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	PinConfig_A->GPIO_PinNumber = GPIO_PIN_5;
	PinConfig_A->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	PinConfig_A->GPIO_PinNumber = GPIO_PIN_6;
	PinConfig_A->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	PinConfig_A->GPIO_PinNumber = GPIO_PIN_7;
	PinConfig_A->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	MCAL_GPIO_Init(GPIOA, PinConfig_A);
	
    /*
	* LCD_RS -> PORTB.1
	* LCD_RW -> PORTB.2
	* LCD_E  -> PORTB.3
	*/
	
	PinConfig_B->GPIO_PinNumber = GPIO_PIN_1;
	PinConfig_B->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	PinConfig_B->GPIO_PinNumber = GPIO_PIN_2;
	PinConfig_B->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	PinConfig_B->GPIO_PinNumber = GPIO_PIN_3;
	PinConfig_B->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	MCAL_GPIO_Init(GPIOB, PinConfig_B);
	
	LCD_INIT();
	
	LCD_WRITE_STRING("Learn in Depth");
	
	while (1)
	{
		
	}
	return 0;

}

