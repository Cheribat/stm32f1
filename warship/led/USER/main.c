#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"

int main(void)
{		
    u8 t=0;
    
    delay_init();	    	  //��ʱ������ʼ��	  
    NVIC_Configuration(); 	  //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    uart_init(9600);	      //���ڳ�ʼ��Ϊ9600
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
