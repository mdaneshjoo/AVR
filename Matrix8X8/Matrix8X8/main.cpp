/*
 * Matrix8X8.cpp
 *
 * Created: 2/24/2019 5:49:26 PM
 * Author : Amin Yousefnejad 
 */ 

#include <avr/io.h>


int main(void)
{
    DDRC = 0b11111111; 
	DDRD = 0b11111111; 
	
	
	PORTC = 0b00000001; // y start point
	PORTD = 0b11110111;	// x start point 
	long d ;
	bool goUp = false ;  // ball goes up or down ? 
	bool goRight = false ; // ball goes left or right ? 
	while(1)
	{
		for(d = 0 ; d < 20000 ; d++);
		if(!goUp)
		{
			PORTC = PORTC << 1 ;	
		}else
			PORTC = PORTC >> 1 ;
		if(!goRight)
		{
			PORTD = PORTD >> 1 ; // shift to right 
			PORTD = PORTD + 0b10000000 ; // add with 128 to add binary 1 from left 
		}
		else 
		{
			PORTD = PORTD << 1 ; // shift to left 
			PORTD = PORTD + 1 ;  // add with 1 to add 1 from right 
		}
		if(PORTC == 0b10000000  )// if reach the bottom of panel go up 
			goUp=true; 
		else if(PORTC == 0b00000001)//same thing but reverse
			goUp = false ;

		if(PORTD == 0b11111110 )//if reach the left side of panel go right 
			goRight = true ; 
		else if(PORTD == 0b01111111)
			goRight = false ; 
	}
}

