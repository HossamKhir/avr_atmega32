
#include <avr/io.h>
#include"MACROS.h"
#include <util/delay.h> // to use delay function

int main(void)
{ int i ;
  int sev_seg[10]={0 ,1,2,3,4,5,6,7,8,9};
		
	 DDRC=0XFF ;
	 PORTC=0X00 ;
	 
    while(1)
    {
        for(i=0;i<=9;i++) {	PORTC=i; _delay_ms(200); }
		

	//    for(PORTC=0;PORTC<=9;PORTC++) {	_delay_ms(300); }
			
	//	for(i=0;i<=9;i++) {	PORTC=sev_seg[i]; _delay_ms(400); }
			
	//   PORTC=0;
	//   while(PORTC<10) {_delay_ms(500); PORTC++ ;} PORTC=0;
			
		}
		
		
	}