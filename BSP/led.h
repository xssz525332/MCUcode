#ifndef LED_H

#define	LED_H

#include "config.h"

/**
	
	定义LED使用的引脚定义
	
**/
#if baohe
	//正点原子精英开发板引脚定义
	#if STM32F103ZET6
		#define LED0_Port GPIOB
		#define	LED1_Port	GPIOE
		
		#define	LED0_Pin	GPIO_Pin_5
		#define	LED1_Pin	GPIO_Pin_5
		
		#define LED0_RCC	RCC_APB2Periph_GPIOB
		#define	LED1_RCC	RCC_APB2Periph_GPIOE
		
		#define LED1_READ	GPIO_ReadInputDataBit(LED1_Port,LED1_Pin)
		#define LED0_READ	GPIO_ReadInputDataBit(LED0_Port,LED0_Pin)
	#endif	
#endif






void LED_init(void);
void LED0(uint8_t level);
void LED1(uint8_t level);
void LED_Rollback(uint8_t LED);

#endif

