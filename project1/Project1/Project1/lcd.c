/*
 * lcd.c
 *
 * Created: 01/04/2019 05:45:32 AM
 *  Author: Hussam Elsayed Kh
 */ 

#include "lcd.h"

char rows[4] = { 0x80, 0xC0, 0x94, 0xD4 };

void
LCD_Init (void)
{
  DDRD |= 0xFF;				//set port D as o/p
  PORTD &= ~0xFF;			//out 0's on port D
  DDRA |= 0x0E;				//set pins 1~3 as o/p on port A

  SET_BIT (PORTA, 3);		//enable LCD

  LCD_write_Command (0x38);	//8-bit mode
  
  LCD_write_Command (0x0C);	//turn on LCD
  
  LCD_write_Command(0x0E);	//blink the cursor
}

void
LCD_write_char (unsigned char data)
{
	PORTD = data;		//send the data
	
	CLR_BIT(PORTA,2);	//set the LCD to write
	
	SET_BIT (PORTA, 1);	//set the LCD to data

	enable_signal ();	//enable the LCD to read
}

void
LCD_write_Command (unsigned char Command)
{
	PORTD = Command;	//send the command
	
	CLR_BIT(PORTA,2);	//set the LCD to write
	
	CLR_BIT (PORTA, 1);	//set the LCD to command 
	
	enable_signal ();	//enable the LCD to read
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

void
LCD_Clear (void)
{
  // write Clr command to LCD
  LCD_write_Command (0x01);
}

void
LCD_Goto_col_row (unsigned char col, unsigned char row)
{
  LCD_write_Command (rows[row] + col);
}

void
LCD_writeString (char *str)
{
  while (*str != '\0')
    {
      LCD_write_char (*str);
      str++;
    }
}

void
LCD_writeString_col_row (char *str, unsigned char col, unsigned char row)
{
  LCD_Goto_col_row (col, row);
  LCD_writeString (str);
}

char *
LCD_int_to_str (unsigned long int var)
{
  static char data[21];
  char *arr = &data[20];

  *arr = '\0';

  while (var != 0)
    {
      arr--;
      *arr = (var % 10) + '0';
      var = var / 10;
    }
  return arr;
}

void
LCD_write_number (unsigned long int data)
{
  char *myData;
  myData = LCD_int_to_str (data);
  LCD_writeString (myData);
}

void
enable_signal()
{
	CLR_BIT(PORTA,3);
	_delay_ms(1);
	SET_BIT(PORTA,3);
	_delay_ms(100);
	
	// E to be 0
	// Delay
	// E to be 1
	// Delay to let LCD Display Data
}

