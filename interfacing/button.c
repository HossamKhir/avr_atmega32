//button.c

#include <avr/io.h>
#include<util/delay.h>

 main(void)
{
	DDRC=255 ;
	DDRD=0 ;

    while(1)
	{
	if(GET_BIT(PIND,0)==0)
    { PORTC=0; }

	else { PORTC=255;}
	}
}

