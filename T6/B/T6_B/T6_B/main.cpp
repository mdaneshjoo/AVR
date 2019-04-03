/*
* T6_B.cpp
*
* Created: 4/3/2019 7:11:08 PM
* Author : M.Daneshjoo
*/

#include <avr/io.h>


int main(void)
{
	DDRC=0xFF;
	/* Replace with your application code */
	while (1)
	{
		int down=9;
		int up=15;
		
		for (int i=0;i<153;i++)// 16
		{
			
			if (i>down&&i<=up)
			{
				if (i==up)
				{
					
					up+=16;
					down+=16;
				}
				continue;
			}
			
			
			PORTC=i;
			
			
			for (long d=0;d<100000;d++){}
		}
		
		
	}
}

