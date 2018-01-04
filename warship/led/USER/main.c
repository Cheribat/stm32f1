#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"

int main(void)
{		
    u8 t=0;
    u8 len;	
	u16 times=0;
    
    delay_init();	    	  //延时函数初始化	  
    NVIC_Configuration(); 	  //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
    uart_init(9600);	      //串口初始化为9600
    LED_Init();
    BEEP_Init();
    KEY_Init();
    
	while(1)
	{
        if(USART_RX_STA&0x8000)
            {					   
                len=USART_RX_STA&0x3fff;
                printf("\r\nHello:\r\n\r\n");
                for(t=0;t<len;t++)
                {
                    USART_SendData(USART1, USART_RX_BUF[t]);
                    while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
                }
                printf("\r\n\r\n");
                USART_RX_STA=0;
            }else
            {
                times++;
                if(times%5000==0)
                {
                    printf("\r\nSTM32\r\n");
                    printf("Good\r\n\r\n");
                }
                if(times%200==0)
                    printf("See you\n");  
                if(times%30==0)
                    LED0=!LED0;
                delay_ms(10);   
            }
	}	
}

/* END OF FILE */
