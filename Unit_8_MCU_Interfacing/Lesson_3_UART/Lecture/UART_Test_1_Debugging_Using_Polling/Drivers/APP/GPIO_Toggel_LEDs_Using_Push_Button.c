/*
 * GPIO_Toggel_LEDs_Using_Push_Button.c
 *
 *  Created on: Jul 30, 2022
 *      Author: KHLOUD MOHAMED
 */

#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO_Driver.h"


void clock_init()
{
	//Enable Clock GPIOA
	RCC_GPIOA_CLK_EN();

	//Enable Clock GPIOB
	RCC_GPIOB_CLK_EN();

}

void GPIO_Init()
{
	 GPIO_PinConfig_t PinConfig;

	 //Configure PA1 as Input Floating
	 PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	 PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	 MCAL_GPIO_Init(GPIOA, &PinConfig);

	 //Configure PA13 as Input Floating
	 PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	 PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	 MCAL_GPIO_Init(GPIOA, &PinConfig);

     //Configure PB1 as Output Push_Pull
	 PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	 PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	 PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	 MCAL_GPIO_Init(GPIOB, &PinConfig);

	 //Configure PB13 as Output Push_Pull
	 PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	 PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	 PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	 MCAL_GPIO_Init(GPIOB, &PinConfig);

}

void my_wait(int delay)
{
	uint32_t i , j ;
	for(i=0 ; i<delay; i++)
	{
		for(j=0 ; j<255 ; j++);
	}
}

void GPIO_Toggel_LEDs_Using_Push_Button(void)
{
	clock_init();
	GPIO_Init();

	while(1)
	{

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0 )
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);

			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0 );
		}

		if(MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN_13) == 1)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		my_wait(100);
	}
}

