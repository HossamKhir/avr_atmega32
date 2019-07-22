
#include <avr/io.h>
#include"MACROS.h"

void SPI_SlaveInit(void)
{

DDRB = 0x40;  //slave Pins	
SET_BIT(SPCR,SPE) ;  // When the SPE bit is written to one, the SPI is enabled

CLR_BIT(SPCR,DORD) ;                        //(optional )When the DORD bit is written to zero, the MSB of the data word is transmitted first - Master&slave must be similar
CLR_BIT(SPCR,CPOL) ; CLR_BIT(SPCR,CPHA) ; //  (optional ) if you want adjust clock phase and polarity - Master&slave must be similar
}

unsigned char SPI_READ(void)
{
	
	while (GET_BIT(SPSR,SPIF)==0) ; 
	return SPDR;
	
}


main()

{
	 DDRC = 0xFF;
	 PORTC = 0x00;
	 SPI_SlaveInit();
	 while(1)
	 {
		PORTC= SPI_READ();
		  
	 }
}