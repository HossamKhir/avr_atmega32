// led_battern.c

#include <avr/io.h>
#include"MACROS.h"
#include <util/delay.h>
int main(void)
{
	// led.c


	DDRC=0Xff ;
	PORTC=0x00;
	int i ;

	//PORTC=255 ;
    while(1)
    {
		PORTC=0x00 ;_delay_ms(300) ;
		for(i=0;i<=7;i++)	{ PORTC=(1<<i) ; _delay_ms(300) ; }

	 	PORTC=0x00 ;_delay_ms(300) ;
	 for(i=7;i>=0;i--)	{  PORTC=(1<<i) ; _delay_ms(300) ; }

		PORTC=0 ;_delay_ms(300) ;
	   for(i=7;i>=0;i--)	{  PORTC=(PORTC*2)+1 ; _delay_ms(300) ; }

	 PORTC=0xff ;_delay_ms(300) ;
	     for(i=7;i>=0;i--)	{  PORTC=(PORTC/2) ; _delay_ms(300) ; }

	/*
	00000000=0
	00000001=1
	00000011=3
	00000111=7
    00001111=15
	00011111=31
	*/


	}

}

