/******************************************************************
**	  ���������壨V1.0��
**	  ϵͳʱ�������ļ�
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
#include <stdio.h>
#include "SystemClock.h"

/********************************************************************************************
*�������ƣ�void RCC_Configuration(void)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵����ϵͳʱ�ӳ�ʼ������
*	       RCC_HSICmd(ENABLE);//ʹ���ڲ����پ��� ;
* 	       RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);//ѡ���ڲ�����ʱ����Ϊϵͳʱ��SYSCLOCK=8MHZ	
*	       RCC_HCLKConfig(RCC_SYSCLK_Div1);       //ѡ��HCLKʱ��ԴΪϵͳʱ��SYYSCLOCK
*  	       RCC_PCLK1Config(RCC_HCLK_Div4);        //APB1ʱ��Ϊ2M 
*  	       RCC_PCLK2Config(RCC_HCLK_Div4);        //APB2ʱ��Ϊ2M
*  	       RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);//ʹ��APB2����GPIOBʱ��
*******************************************************************************************/
void RCC_Configuration(void) 
{
	/* RCC system reset(for debug purpose) */
  	RCC_DeInit();

  	/* Enable HSE */
  	RCC_HSEConfig(RCC_HSE_ON);

  	/* Wait till HSE is ready */
  	while (RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET);

    /* Enable Prefetch Buffer */
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

    /* Flash 2 wait state */
    FLASH_SetLatency(FLASH_Latency_2);
 
    /* HCLK = SYSCLK */
    RCC_HCLKConfig(RCC_SYSCLK_Div1);
  
    /* PCLK2 = HCLK */
    RCC_PCLK2Config(RCC_HCLK_Div1);

    /* PCLK1 = HCLK/2 */
    RCC_PCLK1Config(RCC_HCLK_Div2);

    /* PLLCLK = 8MHz * 9 = 72 MHz */
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);

    /* Enable PLL */ 
    RCC_PLLCmd(ENABLE);

    /* Wait till PLL is ready */
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);

    /* Select PLL as system clock source */
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

    /* Wait till PLL is used as system clock source */
    while(RCC_GetSYSCLKSource() != 0x08);
}

