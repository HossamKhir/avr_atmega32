#include "main.h"

main()
{	
	LCD_Init();
	while(1){
	LCD_write_char('a');    // write just one character 
	                   _delay_ms(500); 
					   
	LCD_write_char(97);    // write just one character
	                   _delay_ms(500);
					   
	LCD_write_char('5');    // write just one number (but you must write as character) 
		               _delay_ms(500); 
					   
	LCD_write_char(53);    
	                   _delay_ms(500);
					
	//LCD_write_char(5);    // Xxxxx 
	
	LCD_Clear() ;
	
	LCD_writeString("hello world");
		               _delay_ms(500); 
	
	LCD_Clear() ;
	
	LCD_writeString_col_row("hello world",0,1);// write string
		               _delay_ms(500); 
	
	LCD_Clear() ;
	
	LCD_write_number(123456789) ;  // write number 
		               _delay_ms(500); 
	
	LCD_Clear(); 
	
		}
		
}