#include "uart.h"

void uart_init(void)
{
	//串口1初始化函数，若有其他串口需求，和串口1相同，都在此函数调用
	uart1_init(115200);
	
}


void uart1_init(uint32_t baud)
{
	//定义gpio初始化结构体、中断控制器结构体和串口结构体
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStructure;
	//开启usart1时钟和相关gpio时钟
	RCC_APB2PeriphClockCmd(Uart1_Rcc|RCC_APB2Periph_USART1,ENABLE);
	//初始化gpio_tx结构体变量，并通过GPIO_Init函数对相关寄存器赋值
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=Uart1_Tx_Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Uart1_Tx_Port,&GPIO_InitStruct);
	//初始化gpio_rx结构体变量，并通过GPIO_Init函数对相关寄存器赋值
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=Uart1_Rx_Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Uart1_Rx_Port,&GPIO_InitStruct);
	//初始化usart1结构体变量，并通过USART_Init函数对相关寄存器赋值
	USART_InitStruct.USART_BaudRate=baud;
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStruct.USART_Parity=USART_Parity_No;
	USART_InitStruct.USART_StopBits=USART_StopBits_1;
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruct);
	
	/* 嵌套向量中断控制器组选择 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	/* 配置USART为中断源 */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	/* 抢断优先级为1 */
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	/* 子优先级为1 */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	/* 使能中断 */
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	/* 初始化配置NVIC */
	NVIC_Init(&NVIC_InitStructure);

	//开启usart1RXNE(接收)中断
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	//使能串口1外设
	USART_Cmd(USART1,ENABLE);
}
