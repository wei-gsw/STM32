/*-------------------------------------------------*/
/*            ��γ����STM32ϵ�п�����              */
/*-------------------------------------------------*/
/*                                                 */
/*             ʵ�ִ���1���ܵ�ͷ�ļ�               */
/*                                                 */
/*-------------------------------------------------*/

#ifndef __USART1_H
#define __USART1_H

#include "stdio.h"      //������Ҫ��ͷ�ļ�
#include "stdarg.h"		//������Ҫ��ͷ�ļ� 
#include "string.h"     //������Ҫ��ͷ�ļ�
#include "TimTest.h"



extern volatile unsigned char USART1_RX_Tim;
#define USART1_RX_TIM_CONST  3

extern volatile unsigned char USART1_States;

#define USART1_RXD_END        0






#define USART1_RXD_SIZE       512

extern volatile unsigned char USART1_RXD[USART1_RXD_SIZE];
extern volatile unsigned short USART1_RXD_Index;





#define  USART1_TXD_SIZE     16

extern volatile unsigned char const USART1_TXD[USART1_TXD_SIZE];
extern volatile unsigned char USART1_TXD_Index;





void USART1_Init(unsigned int);     //����1 ��ʼ������
void USART1_Send_Data(unsigned char *Data,unsigned short Length);


void USART1_Processing(void);

void Music_DOWN(void);
void Music_UP(void);
void DoSum(unsigned char *Str,unsigned char len);
void Music_Vol(unsigned char Vol);
void Music_STOP(void);
void Music_Play(void);


#endif


