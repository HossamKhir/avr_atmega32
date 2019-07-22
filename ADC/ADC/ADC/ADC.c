#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include"MACROS.h"

int main(void)
{	
	
	unsigned int y=0;
	float volt=0 ;
	float temp=0 ;

    DDRC=0xff;
    PORTC=0x00;

		SET_BIT(ADCSRA,ADEN) ;
		
		
		SET_BIT(ADCSRA, ADPS2) ;SET_BIT(ADCSRA, ADPS1) ;CLR_BIT(ADCSRA, ADPS0) ;  //freq of ADC must be less than 200khz // prescaller 64 as 8MHZ/64=125KHZ<200KHZ FOR ACCURACY

        SET_BIT(ADMUX,ADLAR) ; 

	    //or//  CLR_BIT(ADMUX,ADLAR) ; 

		CLR_BIT(ADMUX,REFS1) ;  CLR_BIT(ADMUX,REFS0) ;  // AREF voltage without any H/W  So put 5v on vref

		CLR_BIT(ADMUX,3) ;	CLR_BIT(ADMUX,2) ;	CLR_BIT(ADMUX,1) ;	CLR_BIT(ADMUX,0) ; // Channel 0 without any differential op amp

	   SET_BIT(ADCSRA,ADSC) ; //Start Conversion

	while(1)
	{

	while(GET_BIT(ADCSRA,ADIF)==0);   // when become 1 so conversion completed so you can read

	
	y=(ADCL>>6)|(ADCH<<2);     //if// SET_BIT(ADMUX,ADLAR) ;// y contains value of ADC 0:1023

    //y=(ADCL)|(ADCH<<8) ;    //if// CLR_BIT(ADMUX,ADLAR)
	  
	volt=(5.0*y)/1023; // vlot contains value of volt 0 : 5 v
	
	temp=100 * volt    ; // temp contains temperature value 

   if(temp>=25) {SET_BIT(PORTC,0) ; }
   else {CLR_BIT(PORTC,0) ;}
	   	   
	SET_BIT(ADCSRA,ADSC) ; // (((Must)))Start Conversion again , must be set after each conversion
	
	// CLR_BIT(ADMUX,3) ;	CLR_BIT(ADMUX,2) ;	CLR_BIT(ADMUX,1) ;	CLR_BIT(ADMUX,0) ;// ((( Optional ))) if you want change the channel
	
		}
}