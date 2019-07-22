
#include <avr/io.h>
#include"MACROS.h"
#include <util/delay.h> // to use delay function

// 7segment with BCD single and multi press

int main(void)
{
	
	unsigned char g=1 , d=1;
	unsigned char sev_seg[10]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001, 0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};
    unsigned char flag=0 ;
	DDRC=0XFF ;   // O/P
	
	PORTC=0b11000000 ; // OUT 00000000
	
	CLR_BIT(DDRB,0);  CLR_BIT(DDRB,1) ; // I/P
	SET_BIT(PORTB,0);  	SET_BIT(PORTB,1); // PULL UP RESISTOR
	

	flag=0 ;

	while(1)
	{
		
		
		if(GET_BIT(PINB,0)==0) { if(g<=9) {PORTC=sev_seg[g] ; g++ ; _delay_ms(300);d=g;}
		
		                          else     {g=0; }
                            	}
	
	
	
	if((GET_BIT(PINB,1)==0)&&(flag==0)) { flag=1 ; if(d<=9) {PORTC=sev_seg[d] ; d++ ;g=d; }
	
	                                                  else     {d=1;PORTC=sev_seg[0]  ; }
	
                                        }

   else if(GET_BIT(PINB,1)==1)	{	    flag=0 ;}







}


}