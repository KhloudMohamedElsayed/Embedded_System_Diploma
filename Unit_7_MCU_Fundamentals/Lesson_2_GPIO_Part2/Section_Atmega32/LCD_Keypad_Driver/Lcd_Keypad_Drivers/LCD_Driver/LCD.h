/*
 * LCD.h
 *
 * Created: 7/25/2022 5:09:18 PM
 *  Author: KHLOUD MOHAMED
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU    1000000UL

#include <avr/io.h>
#include <util/delay.h>


#define LCD_PORT				PORTA
#define DataDir_LCD_PORT		DDRA
#define LCD_CTRL				PORTB
#define DataDir_LCD_CTRL		DDRB

#define RS_SWITCH		1
#define RW_SWITCH		2
#define ENABLE_SWITCH	3

#define DATA_SHIFT		4

//#define EiGHT_BIT_MODE
#define FOUR_BIT_MODE
// Commands of LCD
#define LCD_CMD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_CMD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_CMD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_CMD_MOVE_DISP_LEFT   						(0x18)
#define LCD_CMD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_CMD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_CMD_DISP_OFF   								(0x08)
#define LCD_CMD_DISP_ON_CURSOR   						(0x0E)
#define LCD_CMD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_CMD_DISP_ON_BLINK   						(0x0D)
#define LCD_CMD_DISP_ON   								(0x0C)
#define LCD_CMD_ENTRY_DEC   							(0x04)
#define LCD_CMD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_CMD_ENTRY_INC_   							(0x06)
#define LCD_CMD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_CMD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_CMD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CMD_CLEAR_SCREEN							(0x01)
#define LCD_CMD_ENTRY_MODE								(0x06)

void LCD_INIT(void);
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char data);
void LCD_WRITE_STRING(char *data);
void LCD_isbusy(void);
void LCD_clear_screen(void);
void LCD_GOTO_XY(int line , int position);
void LCD_CUSTOM_CHARACTER();


#endif /* LCD_H_ */