#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "exti.h"

int main(void)
{		
	delay_init();	    	 
	NVIC_Configuration(); 	 
	uart_init(9600);	 
	LED_Init();		  		
	BEEP_Init();         	
	KEY_Init();         	
	EXTIX_Init();
	
	LED0 = 0;		
	
	while(1)
	{	    
		printf("OK\r\n");	
		delay_ms(1000);	  
	}
}

/* END OF FILE */
