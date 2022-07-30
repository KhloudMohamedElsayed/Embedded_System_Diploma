/*
 * LCD.c
 *
 * Created: 7/25/2022 5:09:08 PM
 *  Author: KHLOUD MOHAMED
 */ 

#include "LCD.h"

void LCD_KICK()
{
   LCD_CTRL &= ~(1<<ENABLE_SWITCH);
   _delay_ms(50);
   LCD_CTRL |= (1<<ENABLE_SWITCH);
}

void LCD_GOTO_XY(int line , int position)
{
	if(line == 1)
	{
		if(position < 16 && position >=0)
		{	
		LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	else if(line == 2)
	{
		if(position < 32 && position >=0)
		{
		LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}

void LCD_isbusy()
{
   DataDir_LCD_PORT = 0x00 ;
   LCD_CTRL |= (1<<RW_SWITCH); //read mode
   LCD_CTRL &= ~(1<<RS_SWITCH);
   LCD_KICK();
   DataDir_LCD_PORT = 0xFF;
   LCD_CTRL &= ~(1<<RW_SWITCH);
}

void LCD_INIT()
{
	
	_delay_ms(20);
	LCD_isbusy();
	DataDir_LCD_CTRL |=((1<<ENABLE_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH));
	LCD_CTRL &= ~((1<<ENABLE_SWITCH) | (1<<RS_SWITCH) | (1<<RW_SWITCH));
	DataDir_LCD_PORT = 0xFF;
	_delay_ms(15);
	LCD_clear_screen();
	
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
	LCD_isbusy();
	
	#ifdef EIGHT_BIT_MODE
	LCD_PORT = command;
	LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	LCD_KICK();
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	_delay_ms(1);
	LCD_KICK();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	_delay_ms(1);
	LCD_KICK();
	#endif
	
}

void LCD_WRITE_CHAR(unsigned char data)
{
	LCD_isbusy();
	#ifdef EIGHT_BIT_MODE
	
	LCD_CTRL |= (1<<RS_SWITCH);
	LCD_PORT = data ;
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	
	LCD_KICK();
	
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_KICK();
	LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_KICK();
	#endif
}

void LCD_WRITE_STRING(char *data)
{
	int count = 0;
	
	while(*data > 0)
	{
		count++;
		LCD_WRITE_CHAR(*data++);
		if(count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
	}
}

void LCD_CUSTOM_CHARACTER()
{
	LCD_WRITE_COMMAND(64);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(2);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_CHAR(0);
	_delay_ms(10);
}