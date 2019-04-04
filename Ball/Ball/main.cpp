/*
 * Ball.cpp
 *
 * Created: 3/4/2019 5:58:43 PM
 * Author : Amin
 */ 

#include <avr/io.h>

void showball(int x, int y );
int main(void)
{
    /* Replace with your application code */
	DDRC = 0xFF;
	DDRD = 0xFF;
	DDRA = 0x00;
	int x = 0 ;
	int y = 0 ;
	long d ;  
	showball(x,y);
	
    while (1) 
    {
		for(d = 0 ; d < 20000 ; d++);
		if((PINA & 0b00000001) > 0)
			x++;
		//showball(x,y);
		if((PINA & 0b00000010) == 2)
			x--;
		//showball(x,y);
		if((PINA & 0b00000100) == 4)
			y++;
		//showball(x,y);
		if((PINA & 0b00001000) == 8)
			y--;
		if(x>8)
			x=0;
		else if(x<0) 
			x=8;
		if(y>8)
			y=0;
		else if(y<0)
			y=8;
		showball(x,y);	

    }
}

void showball(int x, int y )
{
	PORTC = 1<<x ; 
	PORTD = ~(1<<y) ; 
}

