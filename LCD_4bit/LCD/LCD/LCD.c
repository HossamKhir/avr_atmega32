
#include "lcd.h"

void LCD_Init(void)
{
	DDRA = 0xFF;// Set Data Port to be O/P
	PORTA = 0x00;// out 0's on port
	DDRB = 0x07;// Set Control Port to be OP

	SET_BIT(PORTB,0);// enable LCD

	// 4 bit mode
	PORTA = 0x28;

	CLR_BIT(PORTB,1) ;

	CLR_BIT(PORTB,2) ;

	enable_signal();

	LCD_write_Command(0x0C); // turn on LCD
}

void LCD_write_char(unsigned char data)
{
	// Put Data on Port
	PORTA = (data>>4);

	// R/W to W
	CLR_BIT(PORTB,1) ;

	// Set RS to Data
	SET_BIT(PORTB,2) ;

	enable_signal();

	PORTA = (data & 0x0F);

	enable_signal();
}

void LCD_write_Command(unsigned char Command)
{
	// Put Command on Port
	PORTA = (Command>>4);

	// R/W to W
	CLR_BIT(PORTB,1) ;

	// Set RS to Command
    CLR_BIT(PORTB,2) ;

	enable_signal();

	PORTA = (Command & 0x0F);

	enable_signal();

	/*
	Commands you can write
	0x0c    Display on
	0x38    8 bit mode
	0x28    4 bit mode
	0x01    Clear display screen
	0x80    Force cursor to beginning ( 1st line)
	0xc0    Force cursor to beginning ( 2nd line)
	*/
}

void LCD_Clear(void)
{
	// write Clr command to LCD
	LCD_write_Command(0x01);
}

void LCD_Goto_col_row(unsigned char col, unsigned char row)
{
	if(row== 0)
	{
		LCD_write_Command(0x80 + col);
	}
	else
	{
		LCD_write_Command(0xc0+ col);
	}

}

void LCD_writeString(char *str)
{
	while(*str != '\0')
	{
		LCD_write_char(*str);
		str++;
	}
}

void LCD_writeString_col_row(char *str, unsigned char col, unsigned char row)
{
	LCD_Goto_col_row(col, row);
	LCD_writeString(str);
}

char* LCD_int_to_str(unsigned long int var)
{
	static char data[17];
	char* arr = &data[16];

	*arr = '\0';

	while(var != 0)
	{
		arr--;
		*arr = (var%10) + '0';
		var = var / 10;
	}
	return arr;
}

void LCD_write_number(unsigned long int data)
{
	char * myData ;
	myData = LCD_int_to_str(data);
	LCD_writeString(myData);
}


enable_signal()
{
   	CLR_BIT(PORTB,0);
	_delay_ms(1);
	SET_BIT(PORTB,0);
	_delay_ms(100);

	// E to be 0
	// Delay
	// E to be 1
	// Delay to let LCD Display Data
}

/*
//https://electronicsforu.com/resources/learn-electronics/16x2-LCD-pinout-diagram
01 	Clear display screen
02 	Return home
04 	Decrement cursor (shift cursor to left)
06 	Increment cursor (shift cursor to right)
05 	Shift display right
07 	Shift display left
08 	Display off, cursor off
0A 	Display off, cursor on
0C 	Display on, cursor off
0E 	Display on, cursor blinking
0F 	Display on, cursor blinking
10 	Shift cursor position to left
14 	Shift cursor position to right
18 	Shift the entire display to the left
1C 	Shift the entire display to the right
80 	Force cursor to beginning ( 1st line)
C0 	Force cursor to beginning ( 2nd line)
38 	2 lines and 5×7 matrix
*/
