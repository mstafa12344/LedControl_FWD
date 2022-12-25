
#include "SYSTIC.h"
#include "GPIO.h"
#include "NVIC.h"


void GPIOF_Handler (void);


uint32 volatile time_on= 1000;

int main(void){
	
	SYSTIC_voidInit();
	
	GPIO_port_init(PORTF);
	
	
	GPIO_pin_init(PORTF,0,1);
	GPIO_pin_init(PORTF,1,0);
	GPIO_pin_init(PORTF,2,0);
	
	NVIC_Init(NVIC_GPIO_PORT_F) ;
	GPIO_pin_EN_interrupt(1 ,PORTF, 0, 0 , 0);
	GPIO_pin_EN_interrupt(2 ,PORTF, 0, 0 , 0);
	
	while(1){
		
		GPIO_pin_write(PORTF, 0,1);
		SYSTICK_delay_ms(time_on );
		GPIO_pin_write(PORTF, 0,0);
		SYSTICK_delay_ms(time_on );
		
	}
}

void GPIOF_Handler (void){
	
	uint8 temp = 0;
	GPIO_pin_read(PORTF, 1, &temp);
	
	if(temp){

		while(temp){GPIO_pin_read(PORTF, 1, &temp);}
			
			time_on += 1000;
	}	

	GPIO_pin_read(PORTF, 2, &temp);
	if(temp){

	while(temp){GPIO_pin_read(PORTF, 2, &temp);}
		
		time_on -= 1000;
	}
	
}





