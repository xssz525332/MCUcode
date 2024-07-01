#include	"iic.h"

//初始化IIC
void IIC_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure={0};
	RCC_APB2PeriphClockCmd(	SCL_RCC|SDA_RCC, ENABLE );	//使能GPIOB时钟
	
	
	//软件模拟IIC时由于外部无上拉电阻所以需将开漏输出改为推挽输出
	GPIO_InitStructure.GPIO_Pin = SCL_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SCL_Port, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SDA_Port, &GPIO_InitStructure);
	//PB6,PB7 输出高，空闲状态
	
	//	GPIO_SetBits(GPIOF,GPIO_Pin_0|GPIO_Pin_1); 
}
/*******************************************************************************
* 函 数 名         : SDA_OUT
* 函数功能		   : SDA输出配置	   
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void SDA_OUT(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	//GPIOB9初始化设置
	GPIO_InitStructure.GPIO_Pin =SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//普通输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
	GPIO_Init(SDA_Port, &GPIO_InitStructure);//初始化
	
}

/*******************************************************************************
* 函 数 名         : SDA_IN
* 函数功能		   : SDA输入配置	   
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void SDA_IN(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	//GPIOB9初始化设置
	GPIO_InitStructure.GPIO_Pin =SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//输入模式
	GPIO_Init(SDA_Port, &GPIO_InitStructure);//初始化
}


//产生IIC起始信号
void IIC_Start(void)
{
	SDA_OUT();     //sda线输出
	IIC_SDA=1;	  	  
	IIC_SCL=1;
	Delay_us(4);
 	IIC_SDA=0;    //START:when CLK is high,DATA change form high to low 
	Delay_us(4);
	IIC_SCL=0;    //钳住I2C总线，准备发送或接收数据 
}	  
//产生IIC停止信号
void IIC_Stop(void)
{
	SDA_OUT();    //sda线输出
	IIC_SCL=0;
	IIC_SDA=0;    //STOP:when CLK is high DATA change form low to high
 	Delay_us(4);
	IIC_SCL=1; 
	IIC_SDA=1;    //发送I2C总线结束信号
	Delay_us(4);							   	
}
//发送数据后，等待应答信号到来
//返回值：1，接收应答失败，IIC直接退出
//        0，接收应答成功，什么都不做
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      //SDA设置为输入  
	IIC_SDA=1;Delay_us(1);	   
	IIC_SCL=1;Delay_us(1);	 
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL=0;    //时钟输出0 	   
	return 0;  
} 
//产生ACK应答
void IIC_Ack(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=0;
	Delay_us(2);
	IIC_SCL=1;
	Delay_us(2);
	IIC_SCL=0;
}
//不产生ACK应答		    
void IIC_NAck(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=1;
	Delay_us(2);
	IIC_SCL=1;
	Delay_us(2);
	IIC_SCL=0;
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC_Send_Byte(u8 txd)
{                        
    u8 t;   
	SDA_OUT(); 	    
    IIC_SCL=0;            //拉低时钟开始数据传输
    for(t=0;t<8;t++)
    {              
			IIC_SDA=(txd&0x80)>>7;
//		if((txd&0x80)>>7)
//			IIC_SDA=1;
//		else
//			IIC_SDA=0;
		txd<<=1; 	  
		Delay_us(2);       //对TEA5767这三个延时都是必须的
		IIC_SCL=1;
		Delay_us(2); 
		IIC_SCL=0;	
		Delay_us(2);
    }	 
} 	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();        //SDA设置为输入
  for(i=0;i<8;i++)
	{
    IIC_SCL=0; 
    Delay_us(2);
		IIC_SCL=1;
    receive<<=1;
    if(READ_SDA)
		{
			receive++;  
		}	 
		Delay_us(1); 
   }					 
    if (!ack)
        IIC_NAck();        //发送nACK
    else
        IIC_Ack();         //发送ACK   
    return receive;
}

