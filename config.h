#ifndef Config_h
#define Config_h

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
#endif


#endif

