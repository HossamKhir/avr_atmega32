#include <avr/io.h>
#include <util/delay.h>

int main()
{
    // commom anode 7 segment  // without decoder
	unsigned char sev_seg[10]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001, 0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};
	DDRC=0XFF ;   // O/P

	PORTC=0b11000000 ; // OUT 00000000

int i ;
	while(1)
	{
	for(i=0;i<10 ;i++) {PORTC=sev_seg[i] ; _delay_ms(500);}
                            	}
}

