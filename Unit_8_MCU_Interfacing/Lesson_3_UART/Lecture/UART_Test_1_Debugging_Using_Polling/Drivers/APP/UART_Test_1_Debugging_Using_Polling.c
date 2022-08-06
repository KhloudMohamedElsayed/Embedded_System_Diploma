/*
 * UART_Test_1_Debugging_Using_Polling.c
 *
 *  Created on: Aug 6, 2022
 *      Author: KHLOUD MOHAMED
 */


/* ======================================================= */
/* ======================= Includes ====================== */
/* ======================================================= */

#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO_Driver.h"
#include "Stm32_F103C6_EXTI_Driver.h"
#include "Stm32_F103C6_USART_Driver.h"
#include "UART_Test_1_Debugging_Using_Polling.h"

/***********************************************************/

static void clock_init()
{
	//Enable Clock for GPIO
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();

	//Enable AFIO
	AFIO_CLK_EN();
}

uint16_t ch;

void UART_Test_1_Debugging_Using_Polling(void)
{
	UART_Config uartCFG;

	clock_init();
	uartCFG.BaudRate = UART_BaudRate_115200;
	uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE;
	uartCFG.IRQ_Enable = UART_IRQ_Enable_NONE;
	uartCFG.P_IRQ_CallBack = NULL;
	uartCFG.Parity = UART_Parity_NONE;
	uartCFG.Payload_Length = UART_Payload_Length_8B;
	uartCFG.StopBits = UART_StopBits_1;
	uartCFG.USART_Mode = UART_Mode_TX_RX;

	MCAL_UART_Init(USART1, &uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART1);

	while(1)
	{

		MCAL_UART_ReceiveData(USART1, &ch, enable);
		MCAL_UART_SendData(USART1, &ch, enable);

	}
}



