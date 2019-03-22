/*
* TClass.cpp
*
* Created: 19/12/1397 10:21:48 AM
* Author : M.Daneshjo
*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF;
	DDRA = 0;
	int num[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	int i=0;
	bool a ;
	/* Replace with your application code */
	while (1)
	{
		
		
		if((PINA&0b00000001)>0)
		{
			a=true;
			
			
			
			_delay_ms(500);
			if (i==10) i=0;
			PORTC=num[i];
			i++;
			
			
			
			
			
		}if((PINA&0b00000001)>0){
			a=false;
			PORTC=num[1];
		}
		
		
		
		
	}
}

