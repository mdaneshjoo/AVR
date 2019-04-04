/*
 * Motor.cpp
 *
 * Created: 3/10/2019 5:58:37 PM
 * Author : Amin
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; 
	DDRC = 0xFF;
	
	int speed = 0 ; 
	bool hit_speed = false; 
    /* Replace with your application code */
    while (1) 
    {
		if((PINA & 0b00000001 ) > 0 && hit_speed == true)
		{
			if(speed < 200)
				speed += 20; 
		}
		if((PINA & 0b00000001 ) > 0)
		{
			hit_speed = true;
		}
		for(int i = 0 ; i < 200 ; i++)
		{
			if(speed > i )
				PORTC = 0 ; 
			else
				PORTC = 1;
		}
    }
}

