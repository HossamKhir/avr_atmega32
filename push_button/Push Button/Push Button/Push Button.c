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
	
	main(void)
	{
		DDRC=255 ;
		DDRD=0 ;

		while(1)
		{
			if(GET_BIT(PIND,0)==1)
			{ CLR_BIT(PORTC,0); }
			
			else { SET_BIT(PORTC,0) ;}
		}
	}


