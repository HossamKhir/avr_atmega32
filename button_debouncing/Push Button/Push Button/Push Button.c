#define SET_BIT(REG,INDEX) (REG|=(1<<INDEX))
#define CLR_BIT(REG,INDEX) (REG&=(~(1<<INDEX)))
#define TOG_BIT(REG,INDEX) (REG^=(1<<INDEX))
#define GET_BIT(REG,INDEX) ((REG>>INDEX)&0X01)
#define SET_HIGHER_NIBBLE(REG) (REG|=0X0F)
#define SET_LOWER_NIBBLE(REG) (REG|=0XF0)
#define CLR_HIGHER_NIBBLE(REG) (REG&=0X0F)
#define CLR_LOWER_NIBBLE(REG) (REG&=0XF0)
#define GET_HIGHER_NIBBLE(REG) (REG>>4)
#define GET_LOWER_NIBBLE(REG) (REG&=0X0F)
#define PUT_VAL_HIGHER_NIBBLE(REG,VAL) (REG=((REG&0X0F)|(VAL<<4)))
#define PUT_VAL_LOWER_NIBBLE(REG,VAL) (REG=((REG&0XF0)|(VAL&0X0F)))
#define SET_REGISTER_NIBBLE(REG) (REG=0XFF)

#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
	int i=0 ,j=0; 
	DDRC=255 ;
	DDRA=255 ;
	DDRD=0 ;

    int flag= 0 ;
	
    while(1)
	{
	// first solution 
	if(GET_BIT(PIND,0)==0)
    {    PORTC=(1<<i) ; 
		 if(i<4) {i++;}
		 else {i=0;}	  
		_delay_ms(1000); 
	}
 
	else ;
	
	
	// second solution 
		
		
		if((GET_BIT(PIND,1)==0)&&(flag==0))
		{   PORTA=(1<<j) ;
			if(j<4) {j++;}  else {j=0;}
			flag=1 ;
		}
		else if ((GET_BIT(PIND,1)==1)&&(flag==1)) {flag=0 ;}
		
		
		
		
		
		
	}
}