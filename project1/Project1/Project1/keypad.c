/*
 * keypad.c
 *
 * Created: 01/04/2019 05:46:52 AM
 *  Author: Hussam Elsayed Kh
 */ 
#include "keypad.h"

const char keypad_elements[4][4] = {
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'#', '0', '=', '+'}
};

void
keypad_init (void) {
	DDRC=0xF0;	//set lower nibble as i/p & higher nibble as o/p
	PORTC=0xFF;	//set high volt on columns & activate pull up resistors
}

const char
get_button (void)
{
	unsigned int r = 4, c;	//declare variables -not war- for row & column
	unsigned char input = 0;
	
	//check for i/p
	c = 0;
	while (GET_LOWER_NIBBLE(PINC)==0x0F)
	{
		if(c==4)
		{
			c=0;
		}
		PORTC = 0xFF & ~(1<<(4+c));	//0111 1111
		c++;
	}
	c--;

	//get the row order
	input = GET_LOWER_NIBBLE (PINC);
	switch (input)
	{
		case 0x0E:
		r = 0;
		break;
		case 0x0D:
		r = 1;
		break;
		case 0x0B:
		r = 2;
		break;
		case 0x07:
		r = 3;
		break;
	}

	//get the button
	return keypad_elements[r][c];

}
