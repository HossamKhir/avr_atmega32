
#include <avr/io.h>
#include"MACROS.h"
#include <util/delay.h>


void SPI_MasterInit(void)
{   DDRB=0B10110000;   // MASTER Pins 
   	
    SET_BIT(SPCR,MSTR) ; //This bit selects Master SPI mode when written to one

    SET_BIT(SPCR,SPE) ; // When the SPE bit is written to one, the SPI is enabled
	
	CLR_BIT(SPCR,DORD) ;                        //(optional )When the DORD bit is written to zero, the MSB of the data word is transmitted first - Master&slave must be similar
    CLR_BIT(SPCR,SPR0) ; CLR_BIT(SPCR,SPR1) ;  // (optional ) Prescaller fosc/4  // you can not write any thing as they are ZEROSs as Default clK -For master only 	
	CLR_BIT(SPCR,CPOL) ; CLR_BIT(SPCR,CPHA) ; //  (optional ) if you want adjust clock phase and polarity - Master&slave must be similar
}



void SPI_SendChar(unsigned char data)
{
	SPDR = data;
	while( GET_BIT(SPSR,SPIF)==0); 

}


void SPI_SendString(unsigned char *str)
{
	while(*str != '\0')
	{
		SPI_SendChar(*str);
		str++;
	}
}


void main()
{
unsigned int c = 0;

SPI_MasterInit();

while(1)
{
	for(c=0;c<=9;c++) { SPI_SendChar(c);_delay_ms(500) ;}
		
		}

	}
