#ifndef LED_H

#define	LED_H

#include "config.h"

/**
	
	����LEDʹ�õ����Ŷ���
	
**/
#if baohe
	//����ԭ�Ӿ�Ӣ���������Ŷ���
	#if STM32F103ZET6
		#define LED0_Port GPIOB
		#define	LED1_Port	GPIOE
		
		#define	LED0_Pin	GPIO_Pin_5
		#define	LED1_Pin	GPIO_Pin_5
		
		#define LED0_RCC	RCC_APB2Periph_GPIOB
		#define	LED1_RCC	RCC_APB2Periph_GPIOE
	#endif	
#endif






void LED_init(void);
void LED0(uint8_t level);
void LED1(uint8_t level);

#endif

