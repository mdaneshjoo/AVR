/*
 * src.c
 *
 * Created: 03/03/2019 09:39:13 AM
 * Author: M.Daneshjo
 */

#include <io.h>

void main()
{
DDRC=0xff;

while (1)
    {  
    if((PINA &0b00000100)>0)
    {  
    PORTC=0b00111111;
    }
    if((PINA &0b00000100)==0)
    {
      PORTC=0b00000000;
    }
      

    }
}
