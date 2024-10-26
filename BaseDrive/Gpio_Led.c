/******************************************************************
**	  ���������壨V1.0��
**	  Gpio�����ļ�
**
**	  ��    ̳��bbs.openmcu.com
**	  ��    ����www.openmcu.com
**	  ��    �䣺support@openmcu.com
**
**    ��    ����V1.0
**	  ��    �ߣ�FXL
**	  �������:	2012.7.20
********************************************************************/
#include "stm32f10x.h"
#include "Gpio_Led.h"

Key_Info key_info;

/********************************************************************************************
*�������ƣ�void GpioLed_Init(void)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵����led�Ƴ�ʼ������
*******************************************************************************************/
void GpioLed_Init(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;
  
	RCC_APB2PeriphClockCmd(LED1_RCC_APB2Periph , ENABLE);// ʹ��APB2����LED1ʱ��
	RCC_APB2PeriphClockCmd(LED2_RCC_APB2Periph , ENABLE);// ʹ��APB2����LED2ʱ��
	RCC_APB2PeriphClockCmd(LED3_RCC_APB2Periph , ENABLE);// ʹ��APB2����LED3ʱ��

  	GPIO_InitStructure.GPIO_Pin	= LED1_GPIO_Pin;         //ѡ��led1
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //�ܽ�Ƶ��Ϊ50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 //ģʽΪ�������
  	GPIO_Init(LED1_GPIO, &GPIO_InitStructure);           //��ʼ��led1�Ĵ���

  	GPIO_InitStructure.GPIO_Pin	= LED2_GPIO_Pin;         //ѡ��led2
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //�ܽ�Ƶ��Ϊ50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 //ģʽΪ�������
  	GPIO_Init(LED2_GPIO, &GPIO_InitStructure);           //��ʼ��led2�Ĵ���

	GPIO_InitStructure.GPIO_Pin	= LED3_GPIO_Pin;         //ѡ��led3
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	 //�ܽ�Ƶ��Ϊ50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 //ģʽΪ�������
  	GPIO_Init(LED3_GPIO, &GPIO_InitStructure);           //��ʼ��led3�Ĵ���
}

/********************************************************************************************
*�������ƣ�static void Delay(u32 counter)
*
*��ڲ�����u32 counter����������
*
*���ڲ�������
*
*����˵������ʱ����
*******************************************************************************************/
static void Delay(u32 counter)
{
	while(counter--);
}

/********************************************************************************************
*�������ƣ�void LED_Disply(void)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵����LED��˸
*******************************************************************************************/
void LED_Display(void)
{
    GPIO_SetBits(LED1_GPIO,LED1_GPIO_Pin);
	Delay(0xfffff);
	GPIO_ResetBits(LED1_GPIO,LED1_GPIO_Pin);

	GPIO_SetBits(LED2_GPIO,LED2_GPIO_Pin);
	Delay(0xfffff);
	GPIO_ResetBits(LED2_GPIO,LED2_GPIO_Pin);

	GPIO_SetBits(LED3_GPIO,LED3_GPIO_Pin);
	Delay(0xfffff);
	GPIO_ResetBits(LED3_GPIO,LED3_GPIO_Pin);
}

/********************************************************************************************
*�������ƣ�void Key_Init(void)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵����������ʼ������
*******************************************************************************************/
void Key_Init(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;
  
	RCC_APB2PeriphClockCmd(KEY1_RCC_APB2Periph , ENABLE);// ʹ��APB2����KEY1ʱ��
	RCC_APB2PeriphClockCmd(KEY2_RCC_APB2Periph , ENABLE);// ʹ��APB2����KEY2ʱ��
	RCC_APB2PeriphClockCmd(KEY3_RCC_APB2Periph , ENABLE);// ʹ��APB2����KEY3ʱ��

  	GPIO_InitStructure.GPIO_Pin	= KEY1_GPIO_Pin;         //ѡ��KEY1
  	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //�ܽ�Ƶ��Ϊ50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//ģʽΪ���븡��
  	GPIO_Init(KEY1_GPIO, &GPIO_InitStructure);           //��ʼ��KEY1�Ĵ���

  	GPIO_InitStructure.GPIO_Pin	= KEY2_GPIO_Pin;         //ѡ��KEY2
  	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //�ܽ�Ƶ��Ϊ50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//ģʽΪ���븡��
  	GPIO_Init(KEY2_GPIO, &GPIO_InitStructure);           //��ʼ��KEY2�Ĵ���

	GPIO_InitStructure.GPIO_Pin	= KEY3_GPIO_Pin;         //ѡ��KEY3
  	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	 //�ܽ�Ƶ��Ϊ50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//ģʽΪ���븡��
  	GPIO_Init(KEY3_GPIO, &GPIO_InitStructure);           //��ʼ��KEY3�Ĵ���
}

/********************************************************************************************
*�������ƣ�void Key_Test(void)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵����key����
*******************************************************************************************/
void Key_Test(void)
{
    /***************����1�Ĳ���********************/
	if(GPIO_ReadInputDataBit(KEY1_GPIO,KEY1_GPIO_Pin) == Bit_RESET)
	{
	    GPIO_ResetBits(LED1_GPIO,LED1_GPIO_Pin);    
	}
	else if(GPIO_ReadInputDataBit(KEY1_GPIO,KEY1_GPIO_Pin) == Bit_SET)
	{
	    GPIO_SetBits(LED1_GPIO,LED1_GPIO_Pin);    
	}
	/***************����2�Ĳ���********************/
	if(GPIO_ReadInputDataBit(KEY2_GPIO,KEY2_GPIO_Pin) == Bit_RESET)
	{
	    Delay(0xfffff);
		if(GPIO_ReadInputDataBit(KEY2_GPIO,KEY2_GPIO_Pin) == Bit_RESET)
		{
		    if(key_info.Key2_state == true)
			    key_info.Key2_state = false;
			else
				key_info.Key2_state = true;
		}		
	}

	if(key_info.Key2_state == true)
	    GPIO_ResetBits(LED2_GPIO,LED2_GPIO_Pin);
	else 
		GPIO_SetBits(LED2_GPIO,LED2_GPIO_Pin);

    /***************����3�Ĳ���********************/
	if(GPIO_ReadInputDataBit(KEY3_GPIO,KEY3_GPIO_Pin) == Bit_RESET)
	{
	    Delay(0xffff);
		if(GPIO_ReadInputDataBit(KEY3_GPIO,KEY3_GPIO_Pin) == Bit_RESET)
		{
		    if(key_info.Key3_state == true)
			    key_info.Key3_state = false;
			else
				key_info.Key3_state = true;
		}		
	}

	key_info.Counter2 += 0xfff;
	if(key_info.Counter2 > 0x2fffff)
    key_info.Counter2 = 0;

	if(key_info.Key3_state == true)
	{
	    key_info.Counter1 += 1;
		if(key_info.Counter1 > 0x2ff)
		    key_info.Counter1 = 0;
		
		if(key_info.Counter2 > key_info.Counter1 * 0xfff)
		    GPIO_SetBits(LED3_GPIO,LED3_GPIO_Pin);
		else
		    GPIO_ResetBits(LED3_GPIO,LED3_GPIO_Pin);
	}
	else
	    GPIO_SetBits(LED3_GPIO,LED3_GPIO_Pin);
}






