
#include"MACROS.h"

#include <avr/io.h>

#include <util/delay.h>

		
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

void uart_sendchar(unsigned char data){

	while(GET_BIT(UCSRA,UDRE) == 0) ;  // 
	 // if == 1   so   the transmit buffer (UDR) is ready to receive new data to send it 
	
	UDR=data;  
	// become 1 so outed from while loop above as means buffer ready to receive new data to transmit it

    // transmission here depend on polling not interrupts	
}


unsigned char uart_receivechar(){
	while(GET_BIT(UCSRA,RXC) == 0) ; // wait until receiving complete Flag is equal 1
	return UDR;
	// Receiving depend on polling not interrupts	
}


int main(void)
{
	
	// 7 segment
	char sev_seg[10]={0,1,2,3,4,5,6,7,8,9} ;
	int d=0 ;
	DDRB=0XFF ;   // O/P
	PORTB=0X00 ; // OUT 00000000
	
	uart_init();

	while(1)
	{  
		
		
	for(d=0;d<=9;d++){uart_sendchar(d) ; _delay_ms(500);
}
			
		}
			
	}