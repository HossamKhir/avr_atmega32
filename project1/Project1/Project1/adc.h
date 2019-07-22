/*
 * adc.h
 *
 * Created: 01/04/2019 05:45:09 AM
 *  Author: Hussam Elsayed Kh
 */ 


#ifndef ADC_H_
#define ADC_H_


#include "MACROS.h"
#include <util/delay.h>
#include <avr/io.h>

#define F_CPU 8000000UL

void adc_init (void);
void adc_start_conv (void);
unsigned int adc_read (void);
int get_temp (void);


#endif /* ADC_H_ */