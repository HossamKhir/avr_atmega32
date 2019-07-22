/*
 * lcd.h
 *
 * Created: 01/04/2019 05:46:05 AM
 *  Author: Hussam Elsayed Kh
 */ 


#ifndef LCD_H_
#define LCD_H_


#include <avr/io.h>
#include <util/delay.h>
#include "MACROS.h"

void LCD_Init(void);

void LCD_write_Command(unsigned char);

void LCD_write_char(unsigned char);
void LCD_writeString(char * );
void LCD_writeString_col_row(char * , unsigned char , unsigned char );

void LCD_write_number(unsigned long int);

void LCD_Clear(void);
void LCD_Goto_col_row(unsigned char , unsigned char );

char* LCD_int_to_str(unsigned long int var);
void enable_signal() ;


#endif /* LCD_H_ */