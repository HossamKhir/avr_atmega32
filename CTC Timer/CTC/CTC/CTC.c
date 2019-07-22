
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> // to use delay function

#define SET_BIT(REG,INDEX) REG|=(1<<INDEX)
#define CLEAR_BIT(REG,INDEX) REG&=(~(1<<INDEX))

int j=0 , k=0 ;
int tmrr0=0 ;

#define F_CPU 1000000UL


int main(void)
{ int i ;
	
	
	
	SET_BIT(DDRB,3) ; // you must configure OC0 as o/p 
	
	// SET_BIT(SREG, 7) ; SET_BIT(TIMSK,0);  // We dont need interrupt GIE OR Timer INT
	
	SET_BIT(TCCR0,WGM01);CLEAR_BIT(TCCR0,WGM00); // CTC Mode
	
	CLEAR_BIT(TCCR0,COM01);SET_BIT(TCCR0,COM00); //  Toggle OC0 on compare match
	
	SET_BIT(TCCR0,0);CLEAR_BIT(TCCR0,1);SET_BIT(TCCR0,2); // clk/1024 (prescaler)
	
OCR0=0;
_delay_ms(3000) ;
OCR0=50;
_delay_ms(3000) ;
OCR0=100;
_delay_ms(3000) ;
OCR0=150;
_delay_ms(3000) ;
OCR0=200;
_delay_ms(3000) ;
OCR0=255;	//last value so it continue outing pulses with this freq

	
	while(1)
	{
		
		
	}
	
	
}