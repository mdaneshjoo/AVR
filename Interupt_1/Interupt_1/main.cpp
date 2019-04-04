/*
 * Interupt_1.cpp
 *
 * Created: 3/12/2019 2:37:07 PM
 * Author : Amin Yousefnejad
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
	DDRA = 0xFF;
	PORTA = 0;
	GICR = 0b01000000;
	MCUCR = 0b00000011;
	GIFR = 0b01000000;
	sei();
    while (1) 
    {
    }
}
ISR(INT0_vect)
{
	PORTA = ~PORTA;
}

