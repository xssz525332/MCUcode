#include "exti.h"

//初始化所用到的EXTI
void extix_init(void)
{
	KEY0_init();
}

//初始化EXTI4函数
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

	/* 配置中断源：按键1 */
	NVIC_InitStructure.NVIC_IRQChannel = KEY0_IRQn;
	/* 配置抢占优先级：1 */
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	/* 配置子优先级：1 */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	/* 使能中断通道 */
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructure);
	
	
	EXTI_InitStruct.EXTI_Line = KEY0_Line;

	/* EXTI为中断模式 */
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	/* 上升沿中断 */
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	/* 使能中断 */
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


