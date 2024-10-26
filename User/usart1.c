/*-------------------------------------------------*/
/*            ��γ����STM32ϵ�п�����              */
/*-------------------------------------------------*/
/*                                                 */
/*             ʵ�ִ���1���ܵ�Դ�ļ�               */
/*                                                 */
/*-------------------------------------------------*/

#include "stm32f10x.h"  //������Ҫ��ͷ�ļ�
#include "usart1.h"     //������Ҫ��ͷ�ļ�


volatile unsigned char USART1_States = 0;


volatile unsigned char USART1_RX_Tim = 0;

volatile unsigned char USART1_RXD[USART1_RXD_SIZE];
volatile unsigned short USART1_RXD_Index;


/*-------------------------------------------------*/
/*����������ʼ������1���͹���                      */
/*��  ����bound��������                            */
/*����ֵ����                                       */
/*-------------------------------------------------*/
void USART1_Init(unsigned int bound)
{  	 	
    GPIO_InitTypeDef GPIO_InitStructure;     //����һ������GPIO���ܵı���
	USART_InitTypeDef USART_InitStructure;   //����һ�����ô��ڹ��ܵı���

	NVIC_InitTypeDef NVIC_InitStructure;     //���ʹ�ܽ��չ��ܣ�����һ�������жϵı���



	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�����ж��������飺��2�� �������ȼ���0 1 2 3 �����ȼ���0 1 2 3

      
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);  //ʹ�ܴ���1ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);   //ʹ��GPIOAʱ��
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;              //׼������PA9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //IO����50M
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	       //����������������ڴ���1�ķ���
    GPIO_Init(GPIOA, &GPIO_InitStructure);                 //����PA9
   
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;             //׼������PA10 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //�������룬���ڴ���1�Ľ���
    GPIO_Init(GPIOA, &GPIO_InitStructure);                 //����PA10
	
	USART_InitStructure.USART_BaudRate = bound;                                    //����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;                    //8������λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;                         //1��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;                            //����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;	               //�շ�ģʽ
  
  USART_Init(USART1, &USART_InitStructure);                                      //���ô���1	




	USART_ClearFlag(USART1, USART_FLAG_RXNE);	            //������ձ�־λ
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);          //���������ж�
	
	
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;       //���ô���1�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0; //��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//�ж�ͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	                        //���ô���1�ж�
 

	USART_Cmd(USART1, ENABLE);                              //ʹ�ܴ���1
}



void Send_Hex(unsigned char *Data,unsigned short Length)
{
	
	unsigned short i;
	
	
	for(i=0;i<Length;i++)
	{
		/* Place your implementation of fputc here */
		/* e.g. write a character to the USART */
		USART_SendData(USART1, *Data++);
		/* Loop until the end of transmission */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
		{}
	}
		
}



//������һ���Ǳ�д���������ݣ���Ƭ��������ģ���ͨ���Ǵ���ͨ�ţ����Ͷ�Ӧ������Ϳ��Կ���ģ�鲥������



//���淢�͵�����ǹ̶��ģ����Ƕ��ڵ��������������Ǳ仯�����Ծ�Ҫ����У���
void DoSum(unsigned char *Str,unsigned char len)//У��λ����
{
	unsigned int xorsum = 0;
	unsigned char i;

	for(i=1;i<len;i++)
	{
		xorsum = xorsum + Str[i];
	}
	xorsum = 0 - xorsum;
	*(Str+i)     = (unsigned char)(xorsum >> 8);
	*(Str+i+1)   = (unsigned char)(xorsum & 0x00ff);
}
void Music_Vol(unsigned char Vol)
{
	unsigned char Table[10];
	Table[0] = 0x7E;
	Table[1] = 0xFF;
	Table[2] = 0x06;

	Table[3] = 0x06; //ָ��
	Table[4] = 0x00;
	Table[5] = 0x00;
	Table[6] = Vol;//����
	DoSum(Table,7);//����У����	
	Table[9] = 0xEF;//������
	
	Send_Hex(Table,10);//����ָ������
}


void Music_DOWN(void)	   //��һ������
{
	unsigned char Table[10];   //����һ������
	Table[0]= 0x7E;
	Table[1]= 0xFF;
	Table[2]= 0x06;
	Table[3]= 0x01;
	Table[4]= 0x00;
	Table[5]= 0x00;
	Table[6]= 0x00;
	Table[7]= 0xFE;
	Table[8]= 0xFA;
	Table[9]= 0xEF;	   //�����ֵ������

	Send_Hex(Table,10);	 //�Ӹ����ͺ���
}
void Music_UP(void)	    //��һ��
{
	unsigned char Table[10];
	Table[0]= 0x7E;
	Table[1]= 0xFF;
	Table[2]= 0x06;
	Table[3]= 0x02;
	Table[4]= 0x00;
	Table[5]= 0x00;
	Table[6]= 0x00;
	Table[7]= 0xFE;
	Table[8]= 0xF9;
	Table[9]= 0xEF;

	Send_Hex(Table,10);
}


void Music_STOP(void)   //ֹͣ��������
{
	unsigned char Table[10];
	Table[0]= 0x7E;
	Table[1]= 0xFF;
	Table[2]= 0x06;
	Table[3]= 0x0E;
	Table[4]= 0x00;
	Table[5]= 0x00;
	Table[6]= 0x00;
	Table[7]= 0xFE;
	Table[8]= 0xED;
	Table[9]= 0xEF;

	Send_Hex(Table,10);
}
void Music_Play(void)	//��ʼ��������
{
	unsigned char Table[10];
	Table[0]= 0x7E;
	Table[1]= 0xFF;
	Table[2]= 0x06;
	Table[3]= 0x0D;
	Table[4]= 0x00;
	Table[5]= 0x00;
	Table[6]= 0x00;
	Table[7]= 0xFE;
	Table[8]= 0xEE;
	Table[9]= 0xEF;

	Send_Hex(Table,10);
}


void USART1_IRQHandler(void)
{
	unsigned char a;
	if(USART_GetFlagStatus(USART1,USART_FLAG_TC))  //����������
	{
		USART_ClearFlag(USART1,USART_FLAG_TC); //���������ɱ�־
		
		
		
		
	}	
	else if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE))//���������ж�
	{       
		  USART_ClearFlag(USART1,USART_FLAG_RXNE);  //������������жϱ�־
		
			 a = USART_ReceiveData(USART1);	  //��������
		
		   USART1_RX_Tim = USART1_RX_TIM_CONST;
		
			if(USART1_States &(1 << USART1_RXD_END))
			{
				//��һ֡����û�д����꣬������������
			}
			else
			{
				
				USART1_RXD[USART1_RXD_Index++ % USART1_RXD_SIZE] = a;
			}	
		}
		else
		{
			 USART_ClearFlag(USART1,USART_FLAG_RXNE); //��ս�������ж�
						
			 USART_ClearFlag(USART1,USART_FLAG_TC);	  //��շ�������ж�
			
			 if (USART_GetFlagStatus(USART1, USART_FLAG_ORE) != RESET)  //���ڽ��� ���
			 {
				 USART_ClearFlag(USART1,USART_FLAG_ORE);
	 
			 }	

	  }
						
			
}









