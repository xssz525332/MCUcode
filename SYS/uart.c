#include "uart.h"

void uart_init(void)
{
	//����1��ʼ�����������������������󣬺ʹ���1��ͬ�����ڴ˺�������
	uart1_init(115200);
	
}


void uart1_init(uint32_t baud)
{
	//����gpio��ʼ���ṹ�塢�жϿ������ṹ��ʹ��ڽṹ��
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStructure;
	//����usart1ʱ�Ӻ����gpioʱ��
	RCC_APB2PeriphClockCmd(Uart1_Rcc|RCC_APB2Periph_USART1,ENABLE);
	//��ʼ��gpio_tx�ṹ���������ͨ��GPIO_Init��������ؼĴ�����ֵ
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=Uart1_Tx_Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Uart1_Tx_Port,&GPIO_InitStruct);
	//��ʼ��gpio_rx�ṹ���������ͨ��GPIO_Init��������ؼĴ�����ֵ
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=Uart1_Rx_Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Uart1_Rx_Port,&GPIO_InitStruct);
	//��ʼ��usart1�ṹ���������ͨ��USART_Init��������ؼĴ�����ֵ
	USART_InitStruct.USART_BaudRate=baud;
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStruct.USART_Parity=USART_Parity_No;
	USART_InitStruct.USART_StopBits=USART_StopBits_1;
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruct);
	
	/* Ƕ�������жϿ�������ѡ�� */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	/* ����USARTΪ�ж�Դ */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	/* �������ȼ�Ϊ1 */
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	/* �����ȼ�Ϊ1 */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	/* ʹ���ж� */
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	/* ��ʼ������NVIC */
	NVIC_Init(&NVIC_InitStructure);

	//����usart1RXNE(����)�ж�
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	//ʹ�ܴ���1����
	USART_Cmd(USART1,ENABLE);
}
