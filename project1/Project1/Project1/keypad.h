/*
 * keypad.h
 *
 * Created: 01/04/2019 05:47:04 AM
 *  Author: Hussam Elsayed Kh
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "MACROS.h"
#include <util/delay.h>
#include <avr/io.h>

const char get_button (void);
void keypad_init (void);


#endif /* KEYPAD_H_ */