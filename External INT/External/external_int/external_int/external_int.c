
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> // to use delay function

#define SET_BIT(REG,INDEX) REG|=(1<<INDEX)
#define CLEAR_BIT(REG,INDEX) REG&=(~(1<<INDEX))

int j=0 , k=0 ;

#define F_CPU 1000000UL

ISR(INT0_vect){
     if(j<9){j++ ;	PORTA = j ;}
     else {j=0; }
}


 main(void)
{ int i ;
	
	DDRC=0XFF ; DDRA=0XFF ;
	PORTC=0X00 ;PORTA=0X00 ;
	
	PORTD=0XFF ;
	
	//step1 enable GIE bit
	SET_BIT(SREG, 7) ; // Enable GIE
	
	//step2 enable interrupt bit (external - timer - ...)
	//External INT
	SET_BIT(GICR,6) ; // Enable INT0	
	
   //step3 setting of interrupt	
	SET_BIT(MCUCR,0); SET_BIT(MCUCR,1);  // Rising edge  
	
 //SET_BIT(MCUCR,0); CLEAR_BIT(MCUCR,1);//try it 
	
	
	while(1)
	{
		for(i=0;i<=9;i++) {	PORTC=i; _delay_ms(1000); }
		
	}
	
	
}