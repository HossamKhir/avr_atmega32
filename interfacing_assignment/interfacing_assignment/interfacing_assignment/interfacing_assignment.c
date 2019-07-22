/*
 * GccApplication1.c
 *
 * Created: 19/03/2019 07:02:33 AM
 *  Author: Hussam Elsayed Kh
 */ 


#include <avr/io.h>
#include <util/delay.h>

//declare the 7-segment outputs in an array
int seven_segment[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

int main(void)
{
	DDRC = 0xFF;	//set port C as o/p
	DDRD = 0x7E;	//set pins 0 & 7 of port D as i/p
	PORTD = 0x81;	//activate PUR on pins 0 & 7 of port D
	int i = 0, mask_continous = 0x01, mask_event = 0x80, last_time = 0x00;	//declare counter, masks, flag
	PORTC = 0xC0;	//display 0
    while(1)
    {
        //reset condition
		if(i > 9)
		{
			i = 0;
		}
		
		//reading status for event based increment
		last_time = PIND & mask_event;
		
		//allow the input to change within a while
		_delay_ms(100);
		
		//check the i/p, and execute the o/p
		if ((mask_continous & ~PIND) || ((mask_event & ~PIND) & last_time))
		{
			PORTC = seven_segment[i++];	
		}
    }
}