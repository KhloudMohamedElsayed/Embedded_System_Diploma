/*
 * LCD.c
 *
 *  Created on: Jul 28, 2022
 *      Author: KHLOUD MOHAMED
 *
 */


#include "includes/lcd.h"

/* ========================================== */
/* ========== Private Functions ============= */
/* ========================================== */

static void HAL_LCD_KICK(void);


static void delay_ms(uint32_t delay)
{
	uint32_t i, j;
	for (i = 0; i < delay; i++)
	{
		for (j = 0; j < 255; j++);
	}
}

static void LCD_GPIO_INIT(void)
{
	// ======================= Set CTRL Switches to Output ===================


	PinConfig.GPIO_PinNumber = RS_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed  = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);


	PinConfig.GPIO_PinNumber = RW_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed  = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);


	PinConfig.GPIO_PinNumber = EN_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed  = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	// =================== Set LCD Port to Output with Speed 10 MHz (push-pull) mode ==============


	PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed  = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed  = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_2;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed  = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_3;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed  = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed  = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed  = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed  = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);


	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);

	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);

}

/* ========================================== */
/* ========== Functions Definitions ========= */
/* ========================================== */


void HAL_LCD_CLEAR_SCREEN(void)
{
	HAL_LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}


static void HAL_LCD_KICK(void)
{

	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
}

void HAL_LCD_GOTO_XY(uint8_t line, uint8_t position)
{
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void HAL_LCD_INIT(void)
{

	delay_ms(20);
	LCD_GPIO_INIT();
	delay_ms(15);

	HAL_LCD_CLEAR_SCREEN();

#ifdef EIGHT_BIT_MODE
	HAL_LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
#endif

#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0x02); // As data sheet
	LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES);
#endif

	HAL_LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
}


void HAL_LCD_ISBUSY(void)
{


    // DataDir_LCD_PORT &= ~(0xFF << DATA_shift);


	PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_2;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_3;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);


	// LCD_CTRL |= (1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);
	// LCD_CTRL &= ~(1 << RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	HAL_LCD_KICK();
	// DataDir_LCD_PORT |= (0xFF << DATA_shift);
	// LCD_CTRL &= ~(1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
}


void HAL_LCD_WRITE_COMMAND(uint8_t command)
{
#ifdef EIGHT_BIT_MODE

	MCAL_GPIO_WritePort(LCD_CTRL, command);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);


	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);

	delay_ms(1);
	HAL_LCD_KICK();
#endif

#ifdef FOUR_BIT_MODE

	delay_ms(15);


	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	uint8_t temp_cmd;
	temp_cmd = (command & 0xF0);
	MCAL_GPIO_WritePort(LCD_CTRL, temp_cmd);
	HAL_LCD_KICK();


	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	temp_cmd = (command << 4);
	MCAL_GPIO_WritePort(LCD_CTRL, temp_cmd);
	HAL_LCD_KICK();
#endif

}

void HAL_LCD_WRITE_CHAR(uint8_t character)
{
#ifdef EIGHT_BIT_MODE

	//MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);


	MCAL_GPIO_WritePort(LCD_CTRL, character);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);


	delay_ms(1);
	HAL_LCD_KICK();
#endif

#ifdef FOUR_BIT_MODE


	delay_ms(15);


	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	uint8_t temp_cmd;
	temp_cmd = (character & 0xF0);
	MCAL_GPIO_WritePort(LCD_CTRL, temp_cmd);
	HAL_LCD_KICK();


	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	temp_cmd = (character << 4);
	MCAL_GPIO_WritePort(LCD_CTRL, temp_cmd);
	HAL_LCD_KICK();
#endif

}

void HAL_LCD_WRITE_STRING(char* string)
{

	int count = 0;
	while (*string > 0)
	{
		count++;
		HAL_LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			HAL_LCD_GOTO_XY(2, 0);
		} else if (count == 32)
		{
			HAL_LCD_CLEAR_SCREEN();
			HAL_LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}
}

/*
void HAL_LCD_custom_characters(void)
{
	HAL_LCD_WRITE_COMMAND(64);
	HAL_LCD_WRITE_CHAR(0);
	HAL_LCD_WRITE_CHAR(14);
	HAL_LCD_WRITE_CHAR(17);
	HAL_LCD_WRITE_CHAR(2);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_CHAR(0);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_CHAR(0);
	delay_ms(10);
}
*/
