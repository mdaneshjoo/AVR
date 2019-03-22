/*
* T3.cpp
*
* Created: 16/12/1397 03:11:01 PM
* Author : M.Daneshjo
*/

#include <avr/io.h>
void turnLEDon(int x ,int y){
	PORTC= 1 << (x-1) ;
	PORTD=~(1<<(y-1));
}

int main(void)
{
	DDRC=0xff;
	DDRD=0xff;
	
	int x_ball=2 ;
	int y_ball=6 ;
	int  x_step= +1;
	int  y_step= +1;
	int  x_max=8;
	int y_max=8;
	
	while (1)
	{
		if (x_ball==x_max)
		{
			x_step=-1;
		}
		if (x_ball==1)
		{
			x_step=+1;
		}
		//--y-------------------------------
		if (y_ball==y_max)
		{
			y_step=-1;
		}
		if (y_ball==1)
		{
			y_step=+1;
		}
		//-----------------------------------------
		x_ball+=x_step;
		y_ball+=y_step;
		turnLEDon(x_ball,y_ball);
		for (long d=0;d<10000;d++){}
		
	}
}

