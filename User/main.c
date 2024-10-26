
#include <main.h>

unsigned short M_VOL=25;
	
unsigned char buf[64];
/****������****/
int main(void)
{
	unsigned char i;

	RCC_Configuration();	//��ʼ��ϵͳʱ��

	
	NVIC_Configuration();	//�жϳ�ʼ��
	TimCounterInit();		//TIM��ʼ��
	USART1_Init(9600);
	
  KEY_Init();
	
	LCD_Init3();
 
	for(i=0;i<5;i++)
	{
	  //���ֲ�����
		OLED_ShowGBK(24+16*i,0,i,16,1);
	}
	
	
	OLED_ShowGBK(0 ,16,5,16,1); //״̬:
	OLED_ShowGBK(16,16,6,16,1);
	OLED_ShowGBK(32,16,7,16,1);
	
	//ֹͣ
	OLED_ShowGBK(64,16,8,16,1);
	OLED_ShowGBK(80,16,9,16,1);
//	
//	//����
//	OLED_ShowGBK(64,16,10,16,1);
//	OLED_ShowGBK(80,16,11,16,1);
	
	//����
	OLED_ShowGBK(0 ,32,12,16,1);
	OLED_ShowGBK(16,32,13,16,1);
	OLED_ShowGBK(32,32,7,16,1);
	
	
	M_VOL = 25;	   //Ĭ������25
	
	sprintf(buf,"%d",(short)M_VOL);
	OLED_ShowString(64,32,buf);
	
	OLED_Refresh_Gram();
	
  while(1)
	{
		
		if(Time_100ms_Flag)
		{
			Time_100ms_Flag = 0;
			
			OLED_Refresh_Gram();
			
			
//			if(flag==1)
//			{
//				if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0))
//				{
//					
//					Music_DOWN();
//					OLED_ShowGBK(64,16,10,16,1);
//					OLED_ShowGBK(80,16,11,16,1);
//					OLED_ShowGBK(96,16,18,16,1);
//					OLED_Refresh_Gram();
//				}
//			}
		}
		KEY_Processing();
			//sprintf(buf,"%ld V",12345);
		//	OLED_ShowString(40,0,buf);
			



		 
	}
}

