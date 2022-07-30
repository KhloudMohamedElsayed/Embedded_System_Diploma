/*
 * lcd.c
 *
 * Created: 7/30/2022 6:13:04 PM
 *  Author: KHLOUD MOHAMED
 */ 

#include "lcd.h"

void LCD_INIT(void)
{
	_delay_ms(20);
	LCD_ISBUSY();
	DataDir_LCD_CTRL |= ((1<<E_PIN)|(1<<RW_PIN)|(1<<RS_PIN)); 
	LCD_CTRL &= ~((1<<E_PIN)|(1<<RW_PIN)|(1<<RS_PIN)); 
	DataDir_LCD_PORT = 0xFF; 
	_delay_ms(15);
	LCD_CLEAR_SCREEN();
	
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0x02); 
	LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
	
}

void LCD_WRITE_COMMAND(unsigned char command)
{
	#ifdef EIGHT_BIT_MODE
	LCD_ISBUSY();
	LCD_PORT = command;
	LCD_CTRL &= ~(1<<RW_PIN)|(1<<RS_PIN); 
	LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_ISBUSY();
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~ ((1<<RW_PIN)|(1<<RS_PIN));
	LCD_KICK();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	LCD_CTRL &= ~ ((1<<RW_PIN)|(1<<RS_PIN));
	LCD_KICK();
	#endif
}
void LCD_WRITE_CHAR(unsigned char data)
{
	#ifdef EIGHT_BIT_MODE
	LCD_ISBUSY();
	LCD_CTRL |= (1<<RS_PIN); 
	LCD_PORT = (((data) << DATA_SHIFT));
	LCD_CTRL |= (1<<RS_PIN);
	LCD_CTRL &= ~(1<<RW_PIN); 
	LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
	LCD_CTRL |= (1<<RS_PIN); 
	LCD_CTRL &= ~(1<<RW_PIN); 
	LCD_KICK();
	LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
	LCD_CTRL |= (1<<RS_PIN); 
	LCD_CTRL &= ~(1<<RW_PIN); 
	LCD_KICK();
	#endif
}

void LCD_WRITE_STRING(char* data)
{
	int count = 0; 
	
	while (*data > 0)
	{
		count++;
		LCD_WRITE_CHAR(*data++);
		if (count == 16) 
		{
			LCD_GOTOXY(1,0); 
		}
		else if (count == 32 || count == 33) 
		{
			LCD_CLEAR_SCREEN();
			LCD_GOTOXY(0,0); 
			count = 0;
		}
	}
}

void LCD_CLEAR_SCREEN(void)
{
	LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}

void LCD_KICK(void)
{
	LCD_CTRL &= ~(1<<E_PIN);
	_delay_ms(50);
	LCD_CTRL |=(1<<E_PIN);
}

void LCD_ISBUSY(void)
{
	DataDir_LCD_PORT = 0x00; 
	LCD_CTRL |= (1<<RW_PIN); 
	LCD_CTRL &= ~(1<<RS_PIN);
	LCD_KICK();
	DataDir_LCD_PORT = 0xFF;
	LCD_CTRL &= ~(1<<RW_PIN);
}

void LCD_GOTOXY(unsigned char line, unsigned char position)
{
	if (line == 0)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	else if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}