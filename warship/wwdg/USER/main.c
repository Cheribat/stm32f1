#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "wdg.h"

int main(void)
{		
    delay_init();	    	 //��ʱ������ʼ��	  
    NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    uart_init(9600);	     //���ڳ�ʼ��Ϊ9600
    LED_Init();
    KEY_Init();              //������ʼ��	 
    LED0=0;
    delay_ms(300);	  
    WWDG_Init(0X7F,0X5F,WWDG_Prescaler_8);//������ֵΪ7f,���ڼĴ���Ϊ5f,��Ƶ��Ϊ8	

    printf("system start...\r\n");
    
    while(1)
    {
        LED0=1;			  	   
    }   
}

/* END OF FILE */