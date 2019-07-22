



#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> // to use delay function

#define SET_BIT(REG,INDEX) REG|=(1<<INDEX)
#define CLEAR_BIT(REG,INDEX) REG&=(~(1<<INDEX))

void PWM_DUTY(unsigned int) ;
void init_freq(unsigned int) ;

int main(void)
{ 
	//  OCF0 : Output Compare Flag 0
	//  TOV0 : Timer/Counter0 Overflow Flag
	
	SET_BIT(DDRB,3) ; // you must configure OC0 as o/p
	
	CLEAR_BIT(TCCR0,WGM01);SET_BIT(TCCR0,WGM00); // phase correct PWM Mode
	
	SET_BIT(TCCR0,COM01);CLEAR_BIT(TCCR0,COM00); //  (non inverting)
	
	SET_BIT(TCCR0,0);CLEAR_BIT(TCCR0,1);SET_BIT(TCCR0,2); // clk/1024 (prescaler)  // you can decrese prescaller to increase freq as here 
	//Freq=Ftimer / 510
	

	

	
	while(1)
	{
			OCR0=0 ; // 0 %
			_delay_ms(3000) ;
			
		PWM_DUTY(10) ;  //10%
		_delay_ms(3000) ;
		PWM_DUTY(20) ;  //20%
		_delay_ms(3000) ;
		PWM_DUTY(50) ;  //50%
		_delay_ms(3000) ;
		PWM_DUTY(75) ;  //75%
		_delay_ms(3000) ;
		PWM_DUTY(100) ;  //100 %
		_delay_ms(3000) ;
		
	}
	
	
}


void PWM_DUTY(unsigned int duty)
{ // put value from 0 : 100  %
	
	OCR0=(duty*255)/100;
	
}