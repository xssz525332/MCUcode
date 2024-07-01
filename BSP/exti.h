#ifndef _exti_h
#define _exti_h

#include "config.h"
#if baohe
	#if STM32F103ZET6
	
		//外部中断线全部以GPIOA引脚为例，有需要自行更改
		#define EXTIO_Port	GPIOA
		#define	EXTI0_Pin	GPIO_Pin_0
		#define EXTI0_RCC	RCC_APB2Periph_GPIOA
		#define	EXTI0_PortSource	GPIO_PortSourceGPIOA
		
		#define EXTI1_Port	GPIOA
		#define	EXTI1_Pin	GPIO_Pin_1
		#define EXTI1_RCC	RCC_APB2Periph_GPIOA
		#define	EXTI1_PortSource	GPIO_PortSourceGPIOA
		
		#define EXTI2_Port	GPIOA
		#define	EXTI2_Pin	GPIO_Pin_2
		#define EXTI2_RCC	RCC_APB2Periph_GPIOA
		#define	EXTI2_PortSource	GPIO_PortSourceGPIOA
		
		#define EXTI3_Port	GPIOA
		#define	EXTI3_Pin	GPIO_Pin_3
		#define EXTI3_RCC	RCC_APB2Periph_GPIOA
		#define	EXTI3_PortSource	GPIO_PortSourceGPIOA
		
		#define EXTI4_Port	GPIOA
		#define	EXTI4_Pin	GPIO_Pin_4
		#define EXTI4_RCC	RCC_APB2Periph_GPIOA
		#define	EXTI4_PortSource	GPIO_PortSourceGPIOA
		
	#endif
#endif


void exti0_init(void);
//void exti3_init(void);
//void exti4_init(void);
void extix_init(void);

#endif

