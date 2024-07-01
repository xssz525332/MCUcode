#include "exti.h"

//初始化所用到的EXTI
void extix_init(void)
{
	exti0_init();
//	exti3_init();
//	exti4_init();
}

//初始化EXTI0函数
void exti0_init(void)
{
	//定义NVIC、EXTI、GPIO结构体变量
	NVIC_InitTypeDef NVIC_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	//开启EXTI0用到的时钟
	RCC_APB2PeriphClockCmd(EXTI0_RCC|RCC_APB2Periph_AFIO,ENABLE);
	//赋值GPIO结构体变量
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=EXTI0_Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(EXTIO_Port,&GPIO_InitStruct);//调用函数初始化GPIO相关寄存器
	
	//赋值NVIC结构体变量
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStruct);//调用函数初始化NVIC相关寄存器
	
	
	//赋值EXTI结构体变量
	EXTI_InitStruct.EXTI_Line=EXTI_Line0;
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Rising;
	
	EXTI_Init(&EXTI_InitStruct);//调用函数初始化EXTI相关寄存器
	
	//关联EXTI与对应GPIO
	GPIO_EXTILineConfig(EXTI0_PortSource,GPIO_PinSource0);

}

////初始化EXTI3函数
//void exti3_init(void)
//{
//	//定义NVIC、EXTI、GPIO结构体变量
//	NVIC_InitTypeDef NVIC_InitStruct;
//	EXTI_InitTypeDef EXTI_InitStruct;
//	GPIO_InitTypeDef GPIO_InitStruct;
//	//开启EXTI3用到的时钟
//	RCC_APB2PeriphClockCmd(EXTI3_RCC|RCC_APB2Periph_AFIO,ENABLE);
//	//赋值GPIO结构体变量
//	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStruct.GPIO_Pin=EXTI3_Pin;
//	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(EXTI3_Port,&GPIO_InitStruct);//调用函数初始化GPIO相关寄存器
//	//赋值NVIC结构体变量
//	NVIC_InitStruct.NVIC_IRQChannel=EXTI3_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
//	NVIC_Init(&NVIC_InitStruct);//调用函数初始化NVIC相关寄存器
//	
//	//赋值EXTI结构体变量
//	EXTI_InitStruct.EXTI_Line=EXTI_Line3;
//	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
//	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;
//	
//	EXTI_Init(&EXTI_InitStruct);//调用函数初始化EXTI相关寄存器
//	
//	//关联EXTI与对应GPIO
//	GPIO_EXTILineConfig(EXTI3_PortSource,GPIO_PinSource3);
//}

////初始化EXTI4函数
//void exti4_init(void)
//{
//	//定义NVIC、EXTI、GPIO结构体变量
//	NVIC_InitTypeDef NVIC_InitStruct;
//	EXTI_InitTypeDef EXTI_InitStruct;
//	GPIO_InitTypeDef GPIO_InitStruct;
//	//开启EXTI4用到的时钟
//	RCC_APB2PeriphClockCmd(EXTI4_RCC|RCC_APB2Periph_AFIO,ENABLE);
//	//赋值GPIO结构体变量
//	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStruct.GPIO_Pin=EXTI4_Pin;
//	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(EXTI4_Port,&GPIO_InitStruct);//调用函数初始化GPIO相关寄存器
//	//赋值NVIC结构体变量
//	NVIC_InitStruct.NVIC_IRQChannel=EXTI4_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
//	NVIC_Init(&NVIC_InitStruct);//调用函数初始化NVIC相关寄存器
//	
//	//赋值EXTI结构体变量
//	EXTI_InitStruct.EXTI_Line=EXTI_Line4;
//	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
//	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;
//	
//	EXTI_Init(&EXTI_InitStruct);//调用函数初始化EXTI相关寄存器
//	
//	//关联EXTI与对应GPIO
//	GPIO_EXTILineConfig(EXTI4_PortSource,GPIO_PinSource4);
//}

