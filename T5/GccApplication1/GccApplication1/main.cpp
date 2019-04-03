/*
* GccApplication1.cpp
* Created: 3/14/2019 1:40:27 PM
* Author : M.Daneshjoo
*/

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRC=0xff;
	
	MCUCR =0b00000001;
	GIFR = 0b01000000;
	GICR = 0b01000000;
	
	sei();
	while (1)
	{
		PORTC = 0b00000001;
		for(long i = 0; i < 100000; i++){}
	}
}
ISR(INT0_vect){
	while (1)
	{
		PORTC = 0b00000010;
		for(long i = 0; i < 10000; i++){}
	}
}


