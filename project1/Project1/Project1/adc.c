/*
 * adc.c
 *
 * Created: 01/04/2019 05:44:58 AM
 *  Author: Hussam Elsayed Kh
 */ 
#include "ADC.h"

void 
adc_init (void)
{
  //set PA0 as i/p 
  CLR_BIT (DDRA, 0);

  //set a prescaler to 64:    110
  CLR_BIT (ADCSRA, ADPS0);
  SET_BIT (ADCSRA, ADPS1);
  SET_BIT (ADCSRA, ADPS2);

  //deactivate left shift, to use 8 bit ADCL with 2 bit ADCH
  CLR_BIT (ADMUX, ADLAR);

  //acitvate internal Vref:   11
  SET_BIT (ADMUX, REFS0);
  SET_BIT (ADMUX, REFS1);

  //use ADC0 for i/p 
  CLR_LOWER_NIBBLE (ADMUX);
  CLR_BIT (ADMUX, 4);

  //enable ADC
  SET_BIT (ADCSRA, ADEN);
}

void
adc_start_conv (void)
{
  SET_BIT (ADCSRA, ADSC);
}

unsigned int
adc_read (void)
{
  //polling
  while (!(GET_BIT (ADCSRA, ADIF)))
    {

    }

  //lower the flag
  CLR_BIT (ADCSRA, ADIF);

  //start conversion
  adc_start_conv ();

  return ADCL | (ADCH << 8);
}

int
get_temp (void)
{
  return 100 * (2.56 * adc_read()) / 1023;
}
