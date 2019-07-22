
#include"MACROS.h"

#include <avr/io.h>

void uart_init(){
	//UART Initialization 3 steps 
	
	//1- set baud rate  
	UBRRL=51; UBRRH=0; // 9600 at 8MHZ 
	
	//2-  frame format and Synch or Asynch 

	 CLR_BIT(UCSRC,UMSEL) ;                                                     // Asynch mode
	 CLR_BIT(UCSRC,UPM0)  ;  CLR_BIT(UCSRC,UPM1) ;                             // Parity Mode Disabled
	 CLR_BIT(UCSRC,USBS)  ;                                                   // one bit stop
	 SET_BIT(UCSRC,UCSZ0) ;  SET_BIT(UCSRC,UCSZ1) ;  CLR_BIT(UCSRB,UCSZ2) ;  // DATA 8 bits
	
	//3- enable RX,TX
	   SET_BIT(UCSRB,RXEN)  ; // ENABLE RX
	   SET_BIT(UCSRB,TXEN) ; // ENABLE TX                                                                     
}

void uart_sendchar(unsigned char data){  // transmission depend on polling not interrupts
	
// you can polling check on  UDRE Flag or TXC Flag  for transmission   to  ensure that transmit buffer ready to receive new data to send it
	
    while(GET_BIT(UCSRA,UDRE) == 0) ; // if == 1   so   the transmit buffer (UDR) is ready to receive new data
	
// or 	while(GET_BIT(UCSRA,TXC) == 0) ;
	
	UDR=data;   // become 1 so outed from while loop above as means buffer ready to receive new data to transmit it

}


unsigned char uart_receivechar(){
	
	// Receiving depend on polling not interrupts
	
	while(GET_BIT(UCSRA,RXC) == 0) ; // wait until receiving complete Flag is equal 1
	return UDR;
		
}


int main(void)
{

	DDRB = 0xff;
	PORTB = 0x00;

	uart_init();
	
	while(1)
	{
		PORTB=uart_receivechar() ;
	}
	
	
}