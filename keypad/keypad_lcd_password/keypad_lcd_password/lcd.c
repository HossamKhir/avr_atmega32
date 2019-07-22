
#include "lcd.h"

void ending_message_if_safe_opened()
{
	LCD_Clear() ;
	LCD_SendString_XY("safe will lock ", 0, 0);// print welcome board at X,Y
	LCD_SendString_XY("After 1 min ",0, 1);// print welcome board at X,Y
	LCD_Clear() ;
	LCD_SendString_XY("1 min passed ", 0, 0);// print welcome board at X,Y
	LCD_SendString_XY("safe locked ",0, 1);// print welcome board at X,Y
	LCD_Clear() ;
	opening_message();


}
void opening_message(void)
{
		LCD_SendString_XY("please password", 0, 0);// print welcome board at X,Y
		LCD_SendString_XY("enter & press on", 0, 1);// print welcome board at X,Y
		_delay_ms(300);
		LCD_Clr() ;
		LCD_SendString_XY("please password", 0, 0);
		LCD_GotoXY(0, 1 );
}

void LCD_Init(void)
{
	// Set Data Port to be OP
	DDRA = 0xFF;
	PORTA = 0x00;

	// Set Control Port to be OP
	DDRB = 0x07;
	PORTB = 0x01; // enable LCD

	// Init LCD
	LCD_Send_Command(0x38); // 8 bit mode
	// LCD_on
	LCD_Send_Command(0x0C); // turn on LCD
}

void LCD_SendData(unsigned char data)
{
	// Put Data on Port
	PORTA = data;
	// Set R/W to W
	PORTB = PORTB & 0xFD; // ~(1<<RS_LOC)
	// Set RS to Data
	PORTB = PORTB | 0x04;

	// E to be 0
	// Delay
	// E to be 1
	// Delay to let LCD Display Data
	enable_signal
}

void LCD_Send_Command(unsigned char cmd)
{
	// Put Cmd on Port
	PORTA = cmd;
	// Set R/W to W
	PORTB = PORTB & 0xFD;
	// Set RS to Command
	PORTB = PORTB & 0xFB;

		enable_signal
}

void LCD_Clear(void)
{
	// Send Clr command to LCD
	LCD_Send_Command(0x01);
}

void LCD_GotoXY(unsigned char col, unsigned char row)
{
	if(row== 0)
	{
		LCD_Send_Command(0x80 + col);
	}
	else
	{
		LCD_Send_Command(0xc0+ col);
	}
}

void LCD_SendString(char *str)
{
	while(*str != '\0')
	{
		LCD_SendData(*str);
		str++;
	}
}

void LCD_SendString_XY(char *str, unsigned char x, unsigned char y)
{
	LCD_GotoXY(x, y);
	LCD_SendString(str);
}

char* int_to_str(unsigned int var)
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

void LCD_Send_number(unsigned char data)
{ int myData ; // must be char * mydata ; as it recieve address
	myData = int_to_str(data);// convert 102 to string then mycdata is pointer to string
	LCD_SendString(myData);
}

void LCD_Clr()
{LCD_Send_Command(0x01);
}

/*
0x0c    turn on lcd
0x38    8 bit mode
0x28    4 bit mode
0x01    clear lcd
0x80    1st row
0xc0    2nd row
*/
