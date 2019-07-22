/*
 * scheduler_like.c
 *
 * Created: 01/04/2019 06:04:13 AM
 *  Author: Hussam Elsayed Kh
 */ 
#include "scheduler_like.h"

static unsigned char password[]="295050";
volatile unsigned char pass[6];

void
proj_init(void)
{
	adc_init();
	LCD_Init();
	keypad_init();
	SET_BIT(DDRA,4);	//set pin 4 as o/p for led
}

unsigned char
get_pin(void)
{
	LCD_writeString_col_row("Please, enter PIN:", 0, 0);
	LCD_Goto_col_row(0,1);	//get ready to display * in place of PIN
	
	unsigned int i = 0;
	for(i = 0;i<6;i++)
	{
		pass[i]=get_button();
		_delay_ms(100);
		LCD_write_char('*');	//displays PIN as ******
	}
	
	LCD_Goto_col_row(0,2);
	
	//compare pin
	if(!strcmp(password,pass))
	{
		LCD_writeString("Congratulations\t:)");
		return 1;	//success
	}
	else
	{
		LCD_writeString("YOU FAILED\t:(");
		_delay_ms(1500);
		LCD_Clear();
		return 0;	//failure
	}
}

void
start_schedule(void)
{
	while(!get_pin()){}
		SET_BIT(PORTA,4);	//turn led on
		_delay_ms(2000);
		CLR_BIT(PORTA,4);	//turn led off
		
		if('*'==get_button())
		{
			adc_start_conv();
			LCD_writeString_col_row("Temperature= ", 0, 3);
			LCD_writeString(LCD_int_to_str(get_temp()));
			_delay_ms(2000);
		}
		
		LCD_Clear();		//clear display to start over
}
