/*
 * Keypad.c
 *
 * Created: 7/26/2022 1:42:16 PM
 *  Author: KHLOUD MOHAMED
 */ 
#include "Keypad.h"

int Keypad_R[] = {R0 , R1 , R2 , R3};
int Keypad_C[] = {C0, C1 , C2 , C3};
	
void KEYPAD_INIT(void)
{
DataDir_KEYPAD_PORT &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3)); //Set Row as input
DataDir_KEYPAD_PORT |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3)); //Set Col as output
KEYPAD_PORT = 0xFF;
}

char KEYPAD_GET_KEY(void)
{
	int i , j ;
	for(i=0 ; i<4 ; i++)
	{
		KEYPAD_PORT |= ((1<<Keypad_C[0]) |(1<<Keypad_C[1]) | (1<<Keypad_C[2]) | (1<<Keypad_C[3]));
		KEYPAD_PORT &= ~(1<<Keypad_C[i]);
		for(j=0 ; j<4 ; j++)
		{
			if(!(KEYPAD_PIN & (1<<Keypad_R[j]))) //check if is key is pressed
			{
				while(!(KEYPAD_PIN & (1<<Keypad_R[j]))); // wait for the key to be released
				
				switch(i)
				{
					case 0:
						if (j == 0) return '7';
						else if(j == 1) return '4';
						else if(j == 2) return '1';
						else if(j == 3) return '!';
						break;
					case 1:
						if (j == 0) return '8';
						else if(j == 1) return '5';
						else if(j == 2) return '2';
						else if(j == 3) return '0';
						break;
					case 2:
						if (j == 0) return '9';
						else if(j == 1) return '6';
						else if(j == 2) return '3';
						else if(j == 3) return '=';
						break;
					case 3:
						if (j == 0) return '/';
						else if(j == 1) return '*';
						else if(j == 2) return '-';
						else if(j == 3) return '+';
						break;
				}
			}
		}
			
		}
	return 'A'; //If no key is pressed
}

