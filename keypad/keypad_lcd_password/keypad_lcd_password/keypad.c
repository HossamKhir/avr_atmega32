

#include "keypad.h"
void keypad_init()
{
	keypad_DDR =0xf0; //A0....A3 are inputs and A4....A7 are outputs
	KEYPAD_PORT=0xff;//A0....A3 are pull up and A4....A7 are initialized by 5 volt
}

unsigned char KeyPad_getpressedkey(void)
{
	unsigned char col_index = 0; // counter  For loop
	unsigned char rows_val = 0; // get the value of rows in this variable
	unsigned char key = NO_PRESSED_KEY; // 0xff

	for(col_index=0;col_index<4;col_index++)
	{  //1 - clear 1 col
		// 2- read rows
	  // 3-a-if (lower nibble of rows !=0x0f){braek and go to for check}
	 //  3-b-else { there is no pressed so continue in for loop of cols to chech another col


		//KEYPAD_PORT=(KEYPAD_PORT | 0xf0);//check c0 c1 c2 c3 are 1111

    CLR_BIT(KEYPAD_PORT,(col_index+4));//clear col c0 on bit4 -  c1 on bit5

		//_delay_ms(1);//delay

		rows_val= GET_LOWER_NIBBLE(KEYPAD_ROWS); // KEYPAD_ROWS == PIND

		if(rows_val != 0x0F) // not equal 1111  // that means there is switch pressed
		{
			while((GET_LOWER_NIBBLE(KEYPAD_ROWS)) != 0x0F);// single pressing // wait till user let the switch
			break; // breaking for loop and going to  if(col_index == 4)
		}

SET_BIT(KEYPAD_PORT,(col_index+4));//set col  // if occurred : that means there is no pressing so go to for loop to complete it c0:c3
	}


	if(col_index == 4)
	{
		return NO_PRESSED_KEY;
	}
	else
	{
		switch(col_index)
		{
			// Col_index = 0
			case 0:
			switch(rows_val)
			{
				case 0x0E:   // 0000 1110
				 key = 7;
				break;
				case 0x0D:  //  0000 1101
				key = 4;
				break;
				case 0x0B:  //  0000 1011
				key = 1;
				break;
				case 0x07:   // 0000 0111 // on
				key = 100;
				break;
				default:
				break;
			}
			break;

			// Col_index = 1
			case 1:
			switch(rows_val)
			{
				case 0x0E:   // 1110
				key = 8;
				break;
				case 0x0D:   //1101
				key = 5;
				break;
				case 0x0B:
				key = 2;
				break;
				case 0x07:
				key = 0;
				break;
				default:
				break;
			}
			break;

			// Col2
			case 2:
			switch(rows_val)
			{
				case 0x0E:  // 1110
				key = 9;
				break;
				case 0x0D:  // 1101
				key = 6;
				break;
				case 0x0B:  // 1011
				key = 3;
				break;
				case 0x07:  // 0111
				key = 100;
				break;
				default:
				break;
			}
			break;

			// Col3
			case 3:
			switch(rows_val)
			{
				case 0x0E:
				key = 100;
				break;
				case 0x0D:
				key = 100;
				break;
				case 0x0B:
				key =100;
				break;
				case 0x07:
				key =100;
				break;
				default:
				break;
			}
			break;

			default:
			break;
		} // switch case
	} // else
	return key;
}
