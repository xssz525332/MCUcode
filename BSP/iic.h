#ifndef _iic_h
#define _iic_h

#include "config.h"



/**

	���ļ���iic�����ģ��ʱ��

**/

//���ʹ�ñ��п�
#if	baohe
	#if	STM32F103ZET6
		//����scl���ź�sda���ſ����и���
		#define IIC_SCL    PFout(0) //SCL
		#define IIC_SDA    PFout(1) //SDA	 
		#define READ_SDA   PFin(1)  //����SDA


		#define	SCL_Port	GPIOF
		#define	SCL_Pin	GPIO_Pin_0

		#define	SDA_Port	GPIOF
		#define	SDA_Pin	GPIO_Pin_1

		//SDA��SCL����F�����ϣ������и���
		#define	SCL_RCC	RCC_APB2Periph_GPIOF
		#define SDA_RCC	RCC_APB2Periph_GPIOF
	#endif

#endif



//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

#endif

