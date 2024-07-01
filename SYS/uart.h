#ifndef _uart_h
#define _uart_h

#include "config.h"

#if	baohe
	#if STM32F103ZET6
		#define Uart1_Rx_Port		GPIOA
		#define Uart1_Tx_Port 	GPIOA
		#define	Uart1_Rx_Pin		GPIO_Pin_10
		#define	Uart1_Tx_Pin		GPIO_Pin_9
		#define	Uart1_Rcc				RCC_APB2Periph_GPIOA
	#endif
#endif


void uart1_init(uint32_t baud);
void uart_init(void);


#endif
