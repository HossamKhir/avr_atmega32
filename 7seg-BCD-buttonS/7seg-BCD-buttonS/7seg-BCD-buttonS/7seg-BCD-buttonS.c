
#include <avr/io.h>
#include"MACROS.h"
#include <util/delay.h> // to use delay function

// 7segment with BCD single and multi press

int main(void)
{ 
	char g=1 , d=1;
    char sev_seg[10]={0,1,2,3,4,5,6,7,8,9} ;
	int flag=0 ;
	DDRC=0XFF ;   // O/P
	PORTC=0X00 ; // OUT 00000000
	CLR_BIT(DDRB,0);  CLR_BIT(DDRB,1) ; // I/P
	SET_BIT(PORTB,0);  	SET_BIT(PORTB,1); // PULL UP RESISTOR
	
	PORTC=0;
	flag=0 ;

	while(1)
	{
		
	 //single press for PIN B 0
		
			if(GET_BIT(PINB,0)==0) { if(g<=9) {PORTC=sev_seg[g] ; g++ ; _delay_ms(300);d=g;}
			
			                               else     {g=0; }   
			                        }
			
		
		
	//	Multi  Press for PIN B 1
		
		
		if((GET_BIT(PINB,1)==0)&&(flag==0)) { flag=1 ; if(d<=9) {PORTC=sev_seg[d] ; d++ ;g=d; }
			
		                                               else     {d=1;PORTC=sev_seg[0] ; }
								        
							                 }
											 
		else if(GET_BIT(PINB,1)==1)	{	    flag=0 ;}
		
	
		
		
			
		
		
	}
	
	
}