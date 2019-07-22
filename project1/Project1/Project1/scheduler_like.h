/*
 * scheduler_like.h
 *
 * Created: 01/04/2019 06:04:23 AM
 *  Author: Hussam Elsayed Kh
 */ 


#ifndef SCHEDULER_LIKE_H_
#define SCHEDULER_LIKE_H_


#include "MACROS.h"
#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#include "lcd.h"
#include <string.h>
#include "adc.h"

void proj_init(void);
unsigned char get_pin(void);
void start_schedule(void);


#endif /* SCHEDULER_LIKE_H_ */