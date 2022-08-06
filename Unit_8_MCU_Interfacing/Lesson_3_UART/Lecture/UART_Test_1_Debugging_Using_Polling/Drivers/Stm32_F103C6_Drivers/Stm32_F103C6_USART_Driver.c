/*
 * Stm32_F103C6_USART_Driver.c
 *
 *  Created on: Aug 5, 2022
 *      Author:KHLOUD MOHAMED
 */

#include "Stm32_F103C6_USART_Driver.h"

/* ================================================================ */
/* ====================== Generic Function ======================== */
/* ================================================================ */

UART_Config* Global_UART_Config[3] = {NULL};

/* ================================================================ */
/* ============================ APIs ============================== */
/* ================================================================ */


/* ================================================================
 * @Fn				- MCAL_UART_Init
 * @brief			- Initialize UART Asynchronous  only
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @param [in] 		- UART_Config: All UART configuration
 * @retval 			- none
 * Note				- support for now Asynchronous mode & clock 8 MHz
 */
void MCAL_UART_Init(USART_TypeDef* USARTx , UART_Config* UART_Config)
{
	uint32_t pclk , BRR;

	if(USARTx == USART1)
	{
		RCC_USART1_CLK_EN();
		Global_UART_Config[0] = UART_Config;
	}
	else if(USARTx == USART2)
	{
		RCC_USART2_CLK_EN();
		Global_UART_Config[1] = UART_Config;
	}
	else if(USARTx == USART3)
	{
		RCC_USART3_CLK_EN();
		Global_UART_Config[2] = UART_Config;

	}

	//Enable USART Module
	//Bit 13 UE: USART enable
	USARTx->CR1 |= 1<<13;

	//Enable USART Tx and Rx engines according to the USART_mode configuration item
	//USART_CR1 Bit 3 TE: Transmitter enable & Bit 2 RE : Receiver enable
	USARTx->CR1 |= UART_Config->USART_Mode;

	//PAYLOAD Width
	//USARTx->CR1  Bit 12 M: Word length
	USARTx->CR1 |= UART_Config->Payload_Length;

	//Configuration of parity control bit fields
	//USARTx->CR1  Bit 10 PCE:Parinty control enable
	// Bit 9 PS: parity selection
	USARTx->CR1 |= UART_Config->Parity;

	//Configure the number of stop bits
	//USART_CR2 Bit 13:12 STOP : stop bits
	USARTx->CR2 |= UART_Config->StopBits;

	//USART hardware flow control
	//USART_CR3  Bit 9 CTSE : CTS enable
	//Bit 8 RTSE : RTS enable
	USARTx->CR3 |= UART_Config->HwFlowCtl;

	//Configuration of BRR(BaudRate Register)
	//PCLK1 for USART2 , 3
	//PCLK2 for USART1

	if(USARTx == USART1)
	{
		pclk = MCAL_RCC_GetPCLK2Freq();
	}
	else
	{
		pclk = MCAL_RCC_GetPCLK1Freq();
	}

	BRR = UART_BRR_Register(pclk,UART_Config->BaudRate);
	USARTx->BRR = BRR;

	//ENABLE / DISABLE Interrupt
	//USART_CR1
	if(UART_Config->IRQ_Enable != UART_IRQ_Enable_NONE)
	{
		USARTx->CR1 |= (UART_Config->IRQ_Enable);

		//Enable NVIC for USARTx IRQ

		if(USARTx == USART1)
			NVIC_IRQ37_USART1_Enable();
		else if(USARTx == USART2)
			NVIC_IRQ38_USART2_Enable();
		else if(USARTx == USART3)
			NVIC_IRQ39_USART3_Enable();
	}


}

/* ================================================================
 * @Fn				- MCAL_UART_DeInit
 * @brief			- DEInit UART Asynchronous only
 * @param [in] 		- USARTx where x can be (1..3 depending on device used)
 * @param [in] 		- pTxBuffer buffer
 * @param [in] 		- Polling Enable or disable
 * @retval 			- none
 * Note				- Reset the model By RCC
 */
void MCAL_UART_DInit(USART_TypeDef* USARTx)
{
	if(USARTx == USART1)
	{
		RCC_USART1_Reset();
		NVIC_IRQ37_USART1_Disable();
	}
	else if(USARTx == USART2)
	{
		RCC_USART2_Reset();
		NVIC_IRQ38_USART2_Disable();
	}
	else if(USARTx == USART3)
	{
		RCC_USART3_Reset();
		NVIC_IRQ39_USART3_Disable();
	}

}

/* ================================================================
 * @Fn				- MCAL_UART_GPIO_Set_Pins
 * @brief			- Initializes GPIO Pins
 * @param[in]		- USARTx: where x can be (1..3 depending on device used)
 * @retval 			- None
 * @Notes			- Should enable the corresponding ALT & GPIO in RCC clock . Also called after MCAL_UART_Init()
 */

void MCAL_UART_GPIO_Set_Pins(USART_TypeDef* USARTx )
{
	GPIO_PinConfig_t PinCfg;

    if(USARTx == USART1)
    {
    	//PA9 TX
    	//PA10 RX
    	//PA11 CTS
    	//PA12 RTS

    	//PA9 TX
    	PinCfg.GPIO_PinNumber = GPIO_PIN_9;
    	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
    	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    	MCAL_GPIO_Init(GPIOA , &PinCfg);

    	//PA10 RX
    	PinCfg.GPIO_PinNumber = GPIO_PIN_10;
    	PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
    	MCAL_GPIO_Init(GPIOA, &PinCfg);

    	if(Global_UART_Config[0]->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config[0]->HwFlowCtl == UART_HwFlowCtl_RTS_CTS )
    	{
    		//PA11 CTS
    		PinCfg.GPIO_PinNumber = GPIO_PIN_11;
    		PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    		MCAL_GPIO_Init(GPIOA, &PinCfg);
    	}
    	if(Global_UART_Config[0]->HwFlowCtl == UART_HwFlowCtl_RTS || Global_UART_Config[0]->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
    	{
    		//PA12 RTS
    		PinCfg.GPIO_PinNumber = GPIO_PIN_12;
    		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
    		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    		MCAL_GPIO_Init(GPIOA, &PinCfg);
    	}

    }
    else if(USARTx == USART2)
    {
    	// PA2 Tx
    	// PA3 Rx
    	// PA0 CTS
    	// PA1 RTS

    	// PA2 Tx
    	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
    	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
    	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    	MCAL_GPIO_Init(GPIOA, &PinCfg);

    	// PA3 Rx
    	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
    	PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
    	MCAL_GPIO_Init(GPIOA, &PinCfg);

    	if (Global_UART_Config[1]->HwFlowCtl || Global_UART_Config[1]->HwFlowCtl == UART_HwFlowCtl_CTS)
    	{
    		// PA0 CTS
    		PinCfg.GPIO_PinNumber = GPIO_PIN_0;
    		PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    		MCAL_GPIO_Init(GPIOA, &PinCfg);
    	}



    	if (Global_UART_Config[1]->HwFlowCtl == UART_HwFlowCtl_RTS || Global_UART_Config[1]->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
    	{
    		// PA1 RTS
    		PinCfg.GPIO_PinNumber = GPIO_PIN_1;
    		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
    		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    		MCAL_GPIO_Init(GPIOA, &PinCfg);
    	}
    }
    else if(USARTx == USART3)
    {
    	// PB10 Tx
    	// PB11 Rx
    	// PB13 CTS
    	// PB14 RTS

    	// PB10 Tx
    	PinCfg.GPIO_PinNumber = GPIO_PIN_10;
    	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
    	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    	MCAL_GPIO_Init(GPIOB, &PinCfg);

    	// PB11 Rx
    	PinCfg.GPIO_PinNumber = GPIO_PIN_11;
    	PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
    	MCAL_GPIO_Init(GPIOB, &PinCfg);

    	if (Global_UART_Config[2]->HwFlowCtl || Global_UART_Config[2]->HwFlowCtl == UART_HwFlowCtl_CTS)
    	{
    		// PB13 CTS
    		PinCfg.GPIO_PinNumber = GPIO_PIN_13;
    		PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    		MCAL_GPIO_Init(GPIOB, &PinCfg);
    	}



    	if (Global_UART_Config[2]->HwFlowCtl == UART_HwFlowCtl_RTS || Global_UART_Config[2]->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
    	{
    		// PB14 RTS
    		PinCfg.GPIO_PinNumber = GPIO_PIN_14;
    		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
    		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    		MCAL_GPIO_Init(GPIOB, &PinCfg);
    	}
    }

}

/* ================================================================
 * @Fn				- MCAL_UART_SendData
 * @brief			- Send buffer on UART
 * @param [in] 		- USARTx where x can be (1..3 depending on device used)
 * @param [in] 		- pTxBuffer buffer
 * @param [in] 		- Polling Enable or disable
 * @retval 			- none
 * Note				- Initialize UART first
 * 					- when transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register)
 * 					- the value written in the MSB ( bit 7 or bit 8 depending on the data length ) has no effect
 * 					- because it is replaced by the parity
 * 					- when receiving with the parity enabled the value read in the MSB bit is the received parity bit
 */
void MCAL_UART_SendData(USART_TypeDef* USARTx , uint16_t* pTXBuffer, enum Polling_mechism PollingEn)
{
	// wait until TXE flag is set in the SR
	if(PollingEn == enable)
		while(!(USARTx->SR & 1<<7) );

	//Check the USART_WordLength item for 9BIT or 8BIT in a frame

	/* When Transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
	 * the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
	 * because it is replaced by the parity.
	 * When receiving with the parity enabled, the value read in the MSB bit is the received parity
	 *  bit.
	 */
	if(USARTx == USART1)
	{
		if(Global_UART_Config[0]->Payload_Length == UART_Payload_Length_9B)
		{
			USARTx->DR = (*pTXBuffer & (uint16_t)0x01FF);
		}
		else if(Global_UART_Config[0]->Payload_Length == UART_Payload_Length_8B)
		{
			//This is 8bit data transfer
			USARTx->DR = (*pTXBuffer & (uint8_t)0xFF);
		}
	}
	else if(USARTx == USART2)
	{
		if(Global_UART_Config[1]->Payload_Length == UART_Payload_Length_9B)
		{
			USARTx->DR = (*pTXBuffer & (uint16_t)0x01FF);
		}
		else if(Global_UART_Config[1]->Payload_Length == UART_Payload_Length_8B)
		{
			//This is 8bit data transfer
			USARTx->DR = (*pTXBuffer & (uint8_t)0xFF);
		}

	}
	else if(USARTx == USART3)
	{
		if(Global_UART_Config[2]->Payload_Length == UART_Payload_Length_9B)
		{
			USARTx->DR = (*pTXBuffer & (uint16_t)0x01FF);
		}
		else if(Global_UART_Config[2]->Payload_Length == UART_Payload_Length_8B)
		{
			//This is 8bit data transfer
			USARTx->DR = (*pTXBuffer & (uint8_t)0xFF);
		}
	}

}
void MCAL_UART_ReceiveData(USART_TypeDef* USARTx , uint16_t* pTXBuffer, enum Polling_mechism PollingEn)
{
	//wait until RXNE flag is set in the SR
	if(PollingEn == enable)
	{
		while (! (USARTx->SR & 1<<5));
	}

	//Check the USART_WordLength item for 9BIT or 8BIT in a frame

	if(USARTx == USART1)
	{
		if(Global_UART_Config[0]->Payload_Length == UART_Payload_Length_9B)
		{
			if(Global_UART_Config[0]->Parity == UART_Parity_NONE)
			{
				// no parity so all 9bit are considered data
				*((uint16_t*) pTXBuffer) = USARTx->DR;

			}
			else
			{
			    //Parity is used, so , 8bits will be of user data and 1 bit is parity
				*((uint16_t*)pTXBuffer) = (USARTx->DR & (uint8_t)0xFF);
			}
		}
		else
		{
			//this is 8bit data
			if(Global_UART_Config[0]->Parity == UART_Parity_NONE)
			{
				//no parity so all 8bit are considered data
				*((uint16_t*)pTXBuffer) = (USARTx->DR & (uint8_t)0xff);
			}
			else
			{
				//Parity is used so, 7 bits will be of user data and 1 bit is parity
				*((uint16_t*)pTXBuffer) = (USARTx->DR & (uint8_t)0x7F);
			}
		}

	}
	else if(USARTx == USART2)
	{
		if(Global_UART_Config[1]->Payload_Length == UART_Payload_Length_9B)
		{
			if(Global_UART_Config[1]->Parity == UART_Parity_NONE)
			{
				// no parity so all 9bit are considered data
				*((uint16_t*) pTXBuffer) = USARTx->DR;

			}
			else
			{
				//Parity is used, so , 8bits will be of user data and 1 bit is parity
				*((uint16_t*)pTXBuffer) = (USARTx->DR & (uint8_t)0xFF);
			}
		}
		else
		{
			//this is 8bit data
			if(Global_UART_Config[1]->Parity == UART_Parity_NONE)
			{
				//no parity so all 8bit are considered data
				*((uint16_t*)pTXBuffer) = (USARTx->DR & (uint8_t)0xff);
			}
			else
			{
				//Parity is used so, 7 bits will be of user data and 1 bit is parity
				*((uint16_t*)pTXBuffer) = (USARTx->DR & (uint8_t)0x7F);
			}
		}
	}
	else if(USARTx == USART3)
	{
		if(Global_UART_Config[2]->Payload_Length == UART_Payload_Length_9B)
		{
			if(Global_UART_Config[2]->Parity == UART_Parity_NONE)
			{
				// no parity so all 9bit are considered data
				*((uint16_t*) pTXBuffer) = USARTx->DR;

			}
			else
			{
				//Parity is used, so , 8bits will be of user data and 1 bit is parity
				*((uint16_t*)pTXBuffer) = (USARTx->DR & (uint8_t)0xFF);
			}
		}
		else
		{
			//this is 8bit data
			if(Global_UART_Config[2]->Parity == UART_Parity_NONE)
			{
				//no parity so all 8bit are considered data
				*((uint16_t*)pTXBuffer) = (USARTx->DR & (uint8_t)0xff);
			}
			else
			{
				//Parity is used so, 7 bits will be of user data and 1 bit is parity
				*((uint16_t*)pTXBuffer) = (USARTx->DR & (uint8_t)0x7F);
			}
		}
	}

}

void MCAL_UART_WAIT_TC(USART_TypeDef* USARTx)
{

	//wait till TC flag is set in the SR
	while(! (USARTx->SR & 1<<6));
}

//ISR

void USART1_IRQHandler(void)
{
	Global_UART_Config[0]->P_IRQ_CallBack();
}
void USART2_IRQHandler(void)
{
	Global_UART_Config[1]->P_IRQ_CallBack();
}
void USART3_IRQHandler(void)
{
	Global_UART_Config[2]->P_IRQ_CallBack();
}
