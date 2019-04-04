/*
 * LED_3.cpp
 *
 * Created: 2/24/2019 5:36:53 PM
 * Author : Amin
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	
	while(1){
	DDRA = 0b00011111; 
	PORTA = 0b00000001;
	
	for(long i = 0 ; i < 10000 ; i++);
	
	PORTA = 0b00000010; 
	
	for(long i = 0 ; i < 10000 ; i++);
	
	PORTA = 0b00000100;
	
	for(long i = 0 ; i < 10000 ; i++);
	
	PORTA = 0b00001000;
	
	for(long i = 0 ; i < 10000 ; i++);
	
	PORTA = 0b00010000;
	
	for(long i = 0 ; i < 10000 ; i++);
	
	}
}

