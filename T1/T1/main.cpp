/*
 * T1.cpp
 *
 * Created: 06/12/1397 02:08:41 PM
 * Author : M.Daneshjo
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA=0b11111111;
	int n=255;
	
	for (int i=0;i<8;i++)
	{
		PORTA=n;
		n=n<<1;
		for (long d=0;d<100000;d++)
		{
		}
	}
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

