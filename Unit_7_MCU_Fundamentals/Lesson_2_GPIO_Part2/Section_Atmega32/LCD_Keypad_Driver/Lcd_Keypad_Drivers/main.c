/*
 * Lcd_Keypad_Drivers.c
 *
 * Created: 7/25/2022 5:08:27 PM
 * Author : KHLOUD MOHAMED
 */ 

#include <avr/io.h>
#include "LCD_Driver/LCD.h"
#include "Keypad_Driver/Keypad.h"


int main(void)
{
   LCD_INIT();
   KEYPAD_INIT();
   char pressed_key;
   
    while (1) 
    {
		pressed_key = KEYPAD_GET_KEY();
		switch(pressed_key)
		{
		   case '!':
				 LCD_clear_screen();
	             break;
		   case'A':
				 break;
		   default:
				 LCD_WRITE_CHAR(pressed_key);
				 break;
		}
		
		
    }
}

