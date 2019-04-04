/*
 * Seven_Seg.cpp
 *
 * Created: 3/10/2019 5:30:16 PM
 * Author : Amin
 */ 

#include <avr/io.h>

int main(void)
{
    int numbers[] = {0b01000000,0b01111001,0b00100100,0b00110000,0b00011001,0b0010010,0b00000010,0b01111000,0b00000000,0b00010000};
	DDRC = 0xFF; 
	
	int i ;
	bool pause = false ;  
    while (1) 
    {
		if((PINA & 0b00000001 ) >0)
		{
			pause = true; 
		}
		if((PINA & 0b00000010 ) >0)
		{
			pause = false;
		}
		if(pause)
		{
			continue;
		}
		if(i > 9 )
			i=0 ; 
		PORTC = numbers[i];
		i++;
		for(long d = 0 ; d < 100000 ; d++);
    }
}

