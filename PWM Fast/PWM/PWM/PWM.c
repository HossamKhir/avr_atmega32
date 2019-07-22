

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
	
	SET_BIT(TCCR0,WGM01);SET_BIT(TCCR0,WGM00); // Fast PWM Mode
	
	SET_BIT(TCCR0,COM01);CLEAR_BIT(TCCR0,COM00); //  Clear OC0 on compare match, set OC0 at BOTTOM, (non-inverting mode)
	
    SET_BIT(TCCR0,0);CLEAR_BIT(TCCR0,1);SET_BIT(TCCR0,2); // clk/1024 (prescaler)
	//Freq=Ftimer / 256	


	
	while(1)
	{
		
		OCR0=0 ;  //to be  0%   but in real impossible as dutycycle = [(OCR0+1)/256]*100  SO ALWAYS Duty cycle will be value , can not be ZERO
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
	
	//OCR0=(duty*255)/100;
	
	OCR0=( (duty*256.0)/100.0) -1 ;
	// the correctest duty=((OCR0+1)/256)*100    IN NON Inverting 
	//the correctest duty=((255- OCR0)/256)*100  IN Inverting 
	
}
