/*
 * Project1.c
 *
 * Created: 01/04/2019 05:40:27 AM
 *  Author: Hussam Elsayed Kh
 */ 


#include <avr/io.h>
#include "adc.h"
#include "keypad.h"
#include "lcd.h"
#include "scheduler_like.h"

int main(void)
{
	proj_init();
	while(1)
    {
		start_schedule();
    }
}