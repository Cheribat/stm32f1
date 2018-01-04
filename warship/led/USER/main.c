#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"

int main(void)
{		
    u8 t=0;
    
    delay_init();	    	  //延时函数初始化	  
    NVIC_Configuration(); 	  //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
    uart_init(9600);	      //串口初始化为9600
    LED_Init();
    BEEP_Init();
    
    while(1)
    {
        printf("t:%d\n",t);
        LED0 = 1;
//        BEEP = 1;
        delay_ms(300);
        LED0 = 0;
        BEEP = 0;
        LED1 = 1;
        delay_ms(300);
        LED1 = 0;
        t++;
    }
}

/* END OF FILE */
