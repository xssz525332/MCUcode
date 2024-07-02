#ifndef _exti_h
#define _exti_h

#include "config.h"
#if baohe
	#if STM32F103ZET6
	
		//�ⲿ�ж���ȫ����GPIOE����Ϊ��������Ҫ���и���
		#define KEY0_Port	GPIOE
		#define	KEY0_Pin	GPIO_Pin_4
		#define KEY0_RCC	RCC_APB2Periph_GPIOE
		#define	KEY0_PortSource	GPIO_PortSourceGPIOE
		#define	KEY0_PinSource	GPIO_PinSource4
		#define KEY0_Line	EXTI_Line4
		#define KEY0_IRQn	EXTI4_IRQn
	#endif
#endif

void KEY0_init(void);
void EXTI4_IRQHandler(void);
void extix_init(void);
#endif

