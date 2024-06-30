#include "led.h"

void LED_init(void)
{
	//��ʼ��gpio�ṹ�����
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(LED0_RCC|LED1_RCC,ENABLE);
	
	//��LED0��gpio�ṹ�������ֵ��ͨ��GPIO_Init()�⺯����ʼ��gpio�Ĵ���
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin=LED0_Pin;
	GPIO_Init(LED0_Port,&GPIO_InitStruct);
	
	//��LED1��gpio�ṹ�������ֵ��ͨ��GPIO_Init()�⺯����ʼ��gpio�Ĵ���
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin=LED1_Pin;
	GPIO_Init(LED1_Port,&GPIO_InitStruct);
	
	//��LED0��LED1����Ĭ������Ϊ�ߵ�ƽ
	GPIO_SetBits(LED0_Port,LED0_Pin);
	GPIO_SetBits(LED1_Port,LED1_Pin);
}

void LED0(uint8_t level)
{
	GPIO_WriteBit(LED0_Port,LED0_Pin,(BitAction)level);
}

void LED1(uint8_t level)
{
	GPIO_WriteBit(LED1_Port,LED1_Pin,(BitAction)level);
}

