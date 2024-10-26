/******************************************************************
**	  ���������壨V1.0��
**	  �ж������ļ�
**
**	  ��    ̳��bbs.openmcu.com
**	  ��    ����www.openmcu.com
**	  ��    �䣺support@openmcu.com
**
**    ��    ����V1.0
**	  ��    �ߣ�FXL
**	  �������:	2012.7.25
********************************************************************/
#include "stm32f10x.h"
#include <stdio.h>
#include "Nvic.h"
#include "TimTest.h"

/********************************************************************************************
*�������ƣ�void NVIC_Configuration(void)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵�����жϲ�������
*******************************************************************************************/
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

#ifdef  VECT_TAB_RAM
  /* Set the Vector Table base location at 0x20000000 */
  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
#else  /* VECT_TAB_FLASH  */
  /* Set the Vector Table base location at 0x08000000 */
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
#endif

  /* ʹ��TIM�ж� */
  if(TIM == TIM1)
      NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;
  else if(TIM == TIM2)
	  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;

  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);
}
