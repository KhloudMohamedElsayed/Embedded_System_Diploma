/*
 * GccApplication1.c
 *
 * Created: 7/20/2022 3:27:23 PM
 * Author : KHLOUD MOHAMED
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{
	   // PORTD direction to output
        DDRD |= (1<<PD5)|(1<<PD6)|(1<<PD7);
	  
	  // Global Interrupt Enable
	  //SREG |= (1<<7);
	  sei();
	  // INT0 : Any logical change
	  // INT1 : Rising edge
	  // INT2 : Falling edge
      MCUCR |= (1<<ISC00) | (1<< ISC10) | (1<< ISC11);
	  // External Interrupt Enable
	  GICR |= (1<< INT2 ) | (1<< INT0 ) | (1<< INT1);
	  
	  
    while (1) 
    {
		// Turn off LEDs
		PORTD &= ~((1<<PD5)|(1<<PD6)|(1<<PD7));
    }
}

ISR(INT0_vect)
{
	
	PORTD |= (1<<PD5);
	_delay_ms(1000);
	PORTD &= ~(1<<PD5);
}

ISR(INT1_vect)
{
	
	PORTD |= (1<<PD6);
	_delay_ms(1000);
	PORTD &= ~(1<<PD6);
}
ISR(INT2_vect)
{
	
	PORTD |= (1<<PD7);
	_delay_ms(1000);
	PORTD &= ~(1<<PD7);
}