#ifndef _GPIO_LED_H_
#define _GPIO_LED_H_ 

/*****led1�ӿ�����*****/
#define LED1_RCC_APB2Periph  RCC_APB2Periph_GPIOF
#define LED1_GPIO            GPIOF
#define LED1_GPIO_Pin        GPIO_Pin_6

/*****led2�ӿ�����*****/
#define LED2_RCC_APB2Periph  RCC_APB2Periph_GPIOF
#define LED2_GPIO            GPIOF
#define LED2_GPIO_Pin        GPIO_Pin_7

/*****led3�ӿ�����*****/
#define LED3_RCC_APB2Periph  RCC_APB2Periph_GPIOF
#define LED3_GPIO            GPIOF
#define LED3_GPIO_Pin        GPIO_Pin_8

/*****����USER1�ӿ�����*****/
#define KEY1_RCC_APB2Periph  RCC_APB2Periph_GPIOA
#define KEY1_GPIO            GPIOA
#define KEY1_GPIO_Pin        GPIO_Pin_8

/*****����USER2�ӿ�����*****/
#define KEY2_RCC_APB2Periph  RCC_APB2Periph_GPIOD
#define KEY2_GPIO            GPIOD
#define KEY2_GPIO_Pin        GPIO_Pin_3

/*****����WAKEUP�ӿ�����*****/
#define KEY3_RCC_APB2Periph  RCC_APB2Periph_GPIOA
#define KEY3_GPIO            GPIOA
#define KEY3_GPIO_Pin        GPIO_Pin_0

typedef enum
{
    false=0,
	true
}Bool;

typedef struct
{
    Bool Key1_state;	//����1��״̬���
	Bool Key2_state;	//����2��״̬���
	Bool Key3_state;	//����3��״̬���
	u32  Counter1;      //��ʱ����
	u32  Counter2;      //��ʱ����
}Key_Info;

void GpioLed_Init(void);
void LED_Display(void);
void Key_Init(void);
void Key_Test(void);


#endif
