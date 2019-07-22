
#include "main.h"
char sev_seg[10]={0,1,2,3,4,5,6,7,8,9} ;
int count=0 ;

 int main(void)
{   

//7SEG

DDRC=0XFF ;   // O/P
PORTC=0X00 ; // OUT 00000000	
PORTC=0;
int g=0,o=0; 		
				

	keypad_init() ;  int keyy ;
	
   while(1)
	{
		
	keyy=KeyPad_getpressedkey()  ;
		
		if ((keyy>=0) && (keyy<=9)) 
		{	PORTC=sev_seg[keyy] ;	
		}
		
		else  ;    
		          
				  
				          
		
		}
		}