#ifndef Config_h
#define Config_h


/**
test

**/ 
 
#include "stm32f10x.h"
#include "stdio.h"
#include "string.h"

/**

	����ʹ�ñ��п�

**/
#define baohe 1


/**

	����ʹ�õ�оƬ�ͺ�

**/
#ifdef	STM32F10X_HD
	#define	STM32F103ZET6 1
	//#define STM32F103C8T6
#endif







/**

	�궨�����õı����ļ�

**/
#if baohe
	#include "sys.h"
	#include "led.h"
	#include "iic.h"
	#include "at24c02.h"
	#include "uart.h"
	#include "exti.h"
#endif


#endif

