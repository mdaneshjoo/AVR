/*
* T4.cpp
*
* Created: 16/12/1397 04:37:42 PM
* Author : M.Daneshjo
*/

#include <avr/io.h>



int main()
{
	
	
	/* Replace with your application code */
	while (1)
	{
		DDRC=0xff;
		DDRD=0xff;
		int y=0b00001000;
		int x=0b11110111;
		PORTC=y;
		
		PORTD=x;
		
		while (1)
		{
			
				if((PINA & 0b00000001)>0)//up
				{
					
					PORTC=y>>1;
				
				}
			
			
			
		}
	}
}




