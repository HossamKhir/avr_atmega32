
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> // to use delay function

#define SET_BIT(REG,INDEX) REG|=(1<<INDEX)
#define CLEAR_BIT(REG,INDEX) REG&=(~(1<<INDEX))

int j=0 , k=0;

#define F_CPU 1000000UL

ISR(INT0_vect){
	PORTB =255 ;
	_delay_ms(1000);
	PORTB =0 ;
	_delay_ms(1000);
	
}

ISR(INT1_vect){
	SET_BIT(SREG, 7) ; // Enable GIE
	//AS controller Automatic Disable All Interrupts (By put GIE by 0 )  in start of any ISR And ReEnable it in end of ISR
	// But here we want Nested INT So We Must Enable GIE At start of Lower Priority To allow Higher priority to Interrupt it
    static int g=0 ;
	if(g>9){g=0;}
	for( ;g<=9;g++) {	PORTA=g; _delay_ms(400); }
	
}




int main(void)
{ int i ;
	
	
	DDRC=0XFF ; DDRA=0XFF ;DDRB=0XFF ;
	
	PORTC=0X00 ;PORTA=0X00 ;
	
	PORTD=0XFF ;
	

	
	SET_BIT(SREG, 7) ; // Enable GIE
	
	//External INT
	SET_BIT(GICR,6) ; // Enable INT0
	SET_BIT(GICR,7) ; // Enable INT1
	
	SET_BIT(MCUCR,0); SET_BIT(MCUCR,1);  // Rising edge
	SET_BIT(MCUCR,2);SET_BIT(MCUCR,3);  // Rising edge
	
	

	
	while(1)
	{
	for(i=0;i<=9;i++) {	PORTC=i; _delay_ms(400); }
		
	}
	
	
}