#include "exti.h"

//��ʼ�����õ���EXTI
void extix_init(void)
{
	KEY0_init();
}

//��ʼ��EXTI4����
void KEY0_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	
	RCC_APB2PeriphClockCmd(KEY0_RCC|RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=KEY0_Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(KEY0_Port,&GPIO_InitStruct);

	/* �����ж�Դ������1 */
	NVIC_InitStructure.NVIC_IRQChannel = KEY0_IRQn;
	/* ������ռ���ȼ���1 */
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	/* ���������ȼ���1 */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	/* ʹ���ж�ͨ�� */
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructure);
	
	
	EXTI_InitStruct.EXTI_Line = KEY0_Line;

	/* EXTIΪ�ж�ģʽ */
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	/* �������ж� */
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	/* ʹ���ж� */
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	
	GPIO_EXTILineConfig(KEY0_PortSource,KEY0_PinSource);
}

void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(KEY0_Line))
	{
		LED_Rollback(0);
	}
	
	EXTI_ClearITPendingBit(KEY0_Line);
}


