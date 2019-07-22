/*
 * keypad.h
 *
 * Created: 8/24/2017 5:58:10 AM
 *  Author: mahmoud
 */ 


#ifndef keypad.h
#define keypad.h


#include <avr/io.h>
#include <util/delay.h>
#include "MACROS.h"

#define NO_PRESSED_KEY      0xff
#define keypad_DDR          DDRD
#define KEYPAD_PORT         PORTD
#define KEYPAD_ROWS         PIND


void keypad_init(void) ;
unsigned char KeyPad_getpressedkey(void);

#endif