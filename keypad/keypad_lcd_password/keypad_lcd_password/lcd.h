/*
 * lcd.h
 *
 * Created: 8/24/2017 5:58:28 AM
 *  Author: mahmoud
 */ 


#ifndef lcd.h
#define lcd.h

#include <avr/io.h>
#include <util/delay.h>
void opening_message(void) ;
void ending_message_if_safe_opened(void);

void LCD_Init(void);
void LCD_SendData(unsigned char);
void LCD_Send_Command(unsigned char);
void LCD_Clear(void);
void LCD_GotoXY(unsigned char , unsigned char );
void LCD_SendString(char * );
void LCD_SendString_XY(char * , unsigned char , unsigned char );
char* int_to_str(unsigned int var);
void LCD_Clr() ;
void LCD_Send_number(unsigned char) ;

#define LCD_DATA_PORT PORTA
#define RS_LOC  2

#define enable_signal 	PORTB = PORTB & 0xFE;\
                        _delay_ms(1);\
                         PORTB = PORTB | 0x01;\
                         _delay_ms(100);\
						 
#endif 