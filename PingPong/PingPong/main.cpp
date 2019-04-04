/*
 * PingPong.cpp
 *
 * Created: 3/5/2019 10:22:10 AM
 * Author : Amin Yousefnejad 
 */ 

#include <avr/io.h>

void TurnLEDon(int x, int y);
void ShowRockets(int y);
int hit_fail(int x ,int y ,  int Player); // checks if the rockets hits the ball or not 

int main(void)
{
	DDRC = 0xFF;
	DDRA = 0xFF;//col
	DDRB = 0xFF;//col
	DDRD = 0b11110000;//4 out 4 in 
	int X_ball;
	int Y_ball;
	int X_step;
	int Y_step;
	int X_max = 16;
	int Y_max = 8;
	
	int Y_1_Player; 
	int Y_2_Player; 
	
	int hit = 0; 
	
	int win_P1 = 0 ;
	int win_P2 = 0 ;
	
	
	while(win_P1 <= 2 || win_P2 <= 2 )
	{
		//reset the values if ball hit the wall 
		Y_1_Player = 2 ;
		Y_2_Player = 2 ;
		X_ball = 4;
		Y_ball = 6;
		X_step = +1 ;
		Y_step = +1 ;
		
		PORTA = PORTB = PORTD = 0;
		while (1)
		{
			if (X_ball == X_max){
				X_step = -1;
			}
			if (X_ball == 1){
				X_step = +1;
			}
			if (Y_ball == Y_max){
				Y_step = -1;
			}
			if (Y_ball == 1){
				Y_step = +1;
			}
			X_ball += X_step;
			Y_ball += Y_step;
			
			TurnLEDon(X_ball, Y_ball);
		
			for(long i = 0 ; i < 3000; i++);
			
			if(X_ball<=8)
			{
				if((PIND & 0b00000001) == 1 && Y_1_Player<5)
					Y_1_Player ++;
				if((PIND & 0b00000010) == 2 && Y_1_Player>0)
					Y_1_Player --;
			
				ShowRockets(Y_1_Player);
				hit = hit_fail(X_ball ,Y_ball, Y_1_Player);
					if (hit == -1  )
					{
						win_P2++;
						PORTD += 0b00010000;
						if(win_P2 == 2 )
							PORTC += 0b00100000;
						break;
					}
			}
			else
			{
				if((PIND & 0b00000100) == 4 && Y_2_Player<5)
					Y_2_Player ++;
				if((PIND & 0b00001000) == 8 && Y_2_Player>0)
					Y_2_Player --;
			
				ShowRockets(Y_2_Player);
				hit = hit_fail(X_ball ,Y_ball, Y_2_Player);
				if (hit == -1 )
				{
					win_P1++;
					PORTD += 0b01000000;
					if(win_P1 == 2 )
						PORTC += 0b10000000;
					break;
				}
			}
			for(long i = 0 ; i < 3000; i++);
			//if(win_P1 >= 2 || win_P2 >= 2)
				//break;
		}
	}
		
}

void TurnLEDon(int x, int y){
	//PORTA = PORTB = PORTC = 0 ;
	if(x<0)
		x = -x;
	if(x <= 8)
	{
		PORTB = 0 ;//col
		PORTA = (1 << (x - 1));//col
	}
	if (x > 8 )
	{	
		PORTA = 0;	//col
		PORTB = (1 << (x - 1) - 8);//col
	}
	PORTC = ~(1 << (y - 1));//row
	
	
	
}
void ShowRockets(int y)
{
	int rocket = 0;
	for(int i = y ; i < y+3 ; i++)//this for creates a rocket with 3 length 
		rocket += (1 << i );
	PORTC = ~rocket ;
	PORTA = 1 ;
	PORTB = 128 ;				// the second rocket 
}
int hit_fail(int x,int y , int Player)
{
	if(x == 1 || x == 16){
		if(y == Player || y == Player+1 || y == Player+2 || y == Player+3)
		{
			return 1 ; // rocket hit the ball 
		}
		else 
		{
			return -1 ; // rocket doesn't hit the ball 
		}
	}else
		return 0;  // ball is not close to the rocket 
		
	
}