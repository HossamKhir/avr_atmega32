/*
 * interfacing_assignment_1.c
 *
 * Created: 20/03/2019 06:32:17 AM
 *  Author: Hussam Elsayed Kh
 */ 


#include <avr/io.h>
#include <util/delay.h>

//declare the 7-segment outputs in an array
int seven_segment[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
int swapper[4] = {0x01, 0x02, 0x04, 0x08};

int main(void)
{
	DDRD = 0xFF;	//unlock port D for o/p
	DDRC = 0x0F;	//unlock pins 0~3 in port C for o/p
	int time[4] = {0, 0, 0, 0}, i = 0, j = 0;
    while(1)
    {
		if(time[0] > 9)
		{
			time[0] = 0;
			time[1]++;
		}
		if (time[1] > 5)
		{
			time[1] = 0;
			time[2]++;
		}
		if (time[2] > 9)
		{
			time[2] = 0;
			time[3]++;
		}
		if (time[3] > 5)
		{
			time[3] = 0;
		}
		for(j = 0; j < 5; j++)
		{
			for(i = 0; i < 4; i++)
			{
				PORTC = swapper[i];
				PORTD = seven_segment[time[i]];
				_delay_ms(66);
			}
		}
		time[0]++;
    }
}