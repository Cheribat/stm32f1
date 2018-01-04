#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"

int main(void)
{		
    u8 t=0;
    
    delay_init();	    	  //延时函数初始化	  
    NVIC_Configuration(); 	  //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
    uart_init(9600);	      //串口初始化为9600
    LED_Init();
    BEEP_Init();
    KEY_Init();
    
	while(1)
	{
 		t=KEY_Scan(0);		
        
	   	if(t)
		{						   
			switch(t)
			{				 
				case KEY_UP:	
					BEEP=!BEEP;
					break;
				case KEY_LEFT:	
					LED0=!LED0;
					break;
				case KEY_DOWN:
					LED1=!LED1;
					break;
				case KEY_RIGHT:
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}else 
            delay_ms(10); 
	}	
}

/* END OF FILE */
