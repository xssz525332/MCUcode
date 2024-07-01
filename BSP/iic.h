#ifndef _iic_h
#define _iic_h

#include "config.h"



/**

	此文件是iic的软件模拟时序

**/

//如果使用报盒库
#if	baohe
	#if	STM32F103ZET6
		//定义scl引脚和sda引脚可自行更改
		#define IIC_SCL    PFout(0) //SCL
		#define IIC_SDA    PFout(1) //SDA	 
		#define READ_SDA   PFin(1)  //输入SDA


		#define	SCL_Port	GPIOF
		#define	SCL_Pin	GPIO_Pin_0

		#define	SDA_Port	GPIOF
		#define	SDA_Pin	GPIO_Pin_1

		//SDA和SCL都在F引脚上，可自行更改
		#define	SCL_RCC	RCC_APB2Periph_GPIOF
		#define SDA_RCC	RCC_APB2Periph_GPIOF
	#endif

#endif



//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(u8 txd);			//IIC发送一个字节
u8 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

#endif

