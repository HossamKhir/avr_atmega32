
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> // to use delay function

#define SET_BIT(REG,INDEX) REG|=(1<<INDEX)
#define CLEAR_BIT(REG,INDEX) REG&=(~(1<<INDEX))

int j=0 , k=0 ;
int tmrr0=0 ;

#define F_CPU 1000000UL



ISR(TIMER0_OVF_vect)  //TCNT0=255:256  there is overflow so INT Occur each 256 tick , INT Occur 
{ TCNT0=6 ; tmrr0++ ; 
	
	if(tmrr0==4) {tmrr0=0 ;
			         if(PORTC<9) { PORTC++ ;}
			        	else { PORTC=0 ; }
		        }
	
	
	//TCNT0 & OCR0 A match will set the Output Compare Flag (OCF0) at the next timer clock cycle.
}


int main(void)
{ int i ;
	
	
	DDRC=0XFF ; PORTC=0X00 ;
	
	DDRA=0XFF;PORTA=0X00 ;
		
	SET_BIT(SREG, 7) ; // Enable GIE
	
	// Timer INT
	
	SET_BIT(TIMSK,0); //Enable Timer INT

	CLEAR_BIT(TCCR0,3);CLEAR_BIT(TCCR0,6); // Timer normal Mode

	CLEAR_BIT(TCCR0,4);CLEAR_BIT(TCCR0,5); //  Normal port operation, OC0 disconnected.

	SET_BIT(TCCR0,0);CLEAR_BIT(TCCR0,1);SET_BIT(TCCR0,2); // clk/1024 (prescaler)
	
	TCNT0=6 ;

	
	while(1)
	{
	for(i=0;i<=9;i++) {	PORTA=i; _delay_ms(1000); }
		
	}
	
	
}