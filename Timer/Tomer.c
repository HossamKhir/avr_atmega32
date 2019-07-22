
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> // to use delay function

#define SET_BIT(REG,INDEX) REG|=(1<<INDEX)
#define CLEAR_BIT(REG,INDEX) REG&=(~(1<<INDEX))

int j=0 , k=0 ;
int tmr0=0 ;

ISR(INT0_vect){
	PORTC = j ;
	_delay_ms(2000);
	j++ ;
}

ISR(INT1_vect){
	SET_BIT(SREG, 7) ; // Enable GIE
	//AS controller Automatic Disable All Interrupts (By put GIE by 0 )  in start of any ISR And ReEnable it in end of ISR 
	// But here we want Nested INT So We Must Enable GIE At start of Lower Priority To allow Higher priority to Interrupt it 
	
	PORTC = k;
	_delay_ms(2000);
	k++;
}

ISR(TIMER0_OVF_vect)
{ TCNT0=6 ; tmr0++ ;
	
	if(tmr0==4) {tmr=0 ;
	PORTC++ ; }
	
	
	//TCNT0 & OCR0 A match will set the Output Compare Flag (OCF0) at the next timer clock cycle.
}


int main(void)
{ int i ;
	
	
	DDRC=0XFF ;
	PORTC=0X00 ;
	
	PORTD=0XFF ;
	
	SET_BIT(SREG, 7) ; // Enable GIE
	
	//External INT
	SET_BIT(GICR,6) ; // Enable INT0
	SET_BIT(GICR,7) ; // Enable INT1
	SET_BIT(MCUCR,0); SET_BIT(MCUCR,1);  // Rising edge
	SET_BIT(MCUCR,2);SET_BIT(MCUCR,3);  // Rising edge
	
// Timer INT
CLEAR_BIT(TCCR0,3);CLEAR_BIT(TCCR0,6); // Timer normal Mode
CLEAR_BIT(TCCR0,4);CLEAR_BIT(TCCR0,5); //  Normal port operation, OC0 disconnected.
SET_BIT(TCCR0,0);CLEAR_BIT(TCCR0,1);SET_BIT(TCCR0,2); // clkI/O/1024 (From prescaler)
	TCNT0=6 ; 

	
	while(1)
	{
		for(i=0;i<=9;i++) {	PORTC=i; _delay_ms(500); }	
		
	}
	
	
}