#include "led.h"

void LED_init(void)
{
	//初始化gpio结构体变量
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(LED0_RCC|LED1_RCC,ENABLE);
	
	//给LED0的gpio结构体变量赋值并通过GPIO_Init()库函数初始化gpio寄存器
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin=LED0_Pin;
	GPIO_Init(LED0_Port,&GPIO_InitStruct);
	
	//给LED1的gpio结构体变量赋值并通过GPIO_Init()库函数初始化gpio寄存器
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin=LED1_Pin;
	GPIO_Init(LED1_Port,&GPIO_InitStruct);
	
	//将LED0与LED1引脚默认配置为高电平
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

