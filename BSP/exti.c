#include "exti.h"

//��ʼ�����õ���EXTI
void extix_init(void)
{
	exti0_init();
//	exti3_init();
//	exti4_init();
}

//��ʼ��EXTI0����
void exti0_init(void)
{
	//����NVIC��EXTI��GPIO�ṹ�����
	NVIC_InitTypeDef NVIC_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	//����EXTI0�õ���ʱ��
	RCC_APB2PeriphClockCmd(EXTI0_RCC|RCC_APB2Periph_AFIO,ENABLE);
	//��ֵGPIO�ṹ�����
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=EXTI0_Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(EXTIO_Port,&GPIO_InitStruct);//���ú�����ʼ��GPIO��ؼĴ���
	
	//��ֵNVIC�ṹ�����
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStruct);//���ú�����ʼ��NVIC��ؼĴ���
	
	
	//��ֵEXTI�ṹ�����
	EXTI_InitStruct.EXTI_Line=EXTI_Line0;
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Rising;
	
	EXTI_Init(&EXTI_InitStruct);//���ú�����ʼ��EXTI��ؼĴ���
	
	//����EXTI���ӦGPIO
	GPIO_EXTILineConfig(EXTI0_PortSource,GPIO_PinSource0);

}

////��ʼ��EXTI3����
//void exti3_init(void)
//{
//	//����NVIC��EXTI��GPIO�ṹ�����
//	NVIC_InitTypeDef NVIC_InitStruct;
//	EXTI_InitTypeDef EXTI_InitStruct;
//	GPIO_InitTypeDef GPIO_InitStruct;
//	//����EXTI3�õ���ʱ��
//	RCC_APB2PeriphClockCmd(EXTI3_RCC|RCC_APB2Periph_AFIO,ENABLE);
//	//��ֵGPIO�ṹ�����
//	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStruct.GPIO_Pin=EXTI3_Pin;
//	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(EXTI3_Port,&GPIO_InitStruct);//���ú�����ʼ��GPIO��ؼĴ���
//	//��ֵNVIC�ṹ�����
//	NVIC_InitStruct.NVIC_IRQChannel=EXTI3_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
//	NVIC_Init(&NVIC_InitStruct);//���ú�����ʼ��NVIC��ؼĴ���
//	
//	//��ֵEXTI�ṹ�����
//	EXTI_InitStruct.EXTI_Line=EXTI_Line3;
//	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
//	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;
//	
//	EXTI_Init(&EXTI_InitStruct);//���ú�����ʼ��EXTI��ؼĴ���
//	
//	//����EXTI���ӦGPIO
//	GPIO_EXTILineConfig(EXTI3_PortSource,GPIO_PinSource3);
//}

////��ʼ��EXTI4����
//void exti4_init(void)
//{
//	//����NVIC��EXTI��GPIO�ṹ�����
//	NVIC_InitTypeDef NVIC_InitStruct;
//	EXTI_InitTypeDef EXTI_InitStruct;
//	GPIO_InitTypeDef GPIO_InitStruct;
//	//����EXTI4�õ���ʱ��
//	RCC_APB2PeriphClockCmd(EXTI4_RCC|RCC_APB2Periph_AFIO,ENABLE);
//	//��ֵGPIO�ṹ�����
//	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStruct.GPIO_Pin=EXTI4_Pin;
//	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(EXTI4_Port,&GPIO_InitStruct);//���ú�����ʼ��GPIO��ؼĴ���
//	//��ֵNVIC�ṹ�����
//	NVIC_InitStruct.NVIC_IRQChannel=EXTI4_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
//	NVIC_Init(&NVIC_InitStruct);//���ú�����ʼ��NVIC��ؼĴ���
//	
//	//��ֵEXTI�ṹ�����
//	EXTI_InitStruct.EXTI_Line=EXTI_Line4;
//	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
//	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;
//	
//	EXTI_Init(&EXTI_InitStruct);//���ú�����ʼ��EXTI��ؼĴ���
//	
//	//����EXTI���ӦGPIO
//	GPIO_EXTILineConfig(EXTI4_PortSource,GPIO_PinSource4);
//}

