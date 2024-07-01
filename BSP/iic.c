#include	"iic.h"

//��ʼ��IIC
void IIC_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure={0};
	RCC_APB2PeriphClockCmd(	SCL_RCC|SDA_RCC, ENABLE );	//ʹ��GPIOBʱ��
	
	
	//���ģ��IICʱ�����ⲿ���������������轫��©�����Ϊ�������
	GPIO_InitStructure.GPIO_Pin = SCL_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SCL_Port, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SDA_Port, &GPIO_InitStructure);
	//PB6,PB7 ����ߣ�����״̬
	
	//	GPIO_SetBits(GPIOF,GPIO_Pin_0|GPIO_Pin_1); 
}
/*******************************************************************************
* �� �� ��         : SDA_OUT
* ��������		   : SDA�������	   
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void SDA_OUT(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	//GPIOB9��ʼ������
	GPIO_InitStructure.GPIO_Pin =SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
	GPIO_Init(SDA_Port, &GPIO_InitStructure);//��ʼ��
	
}

/*******************************************************************************
* �� �� ��         : SDA_IN
* ��������		   : SDA��������	   
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void SDA_IN(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	//GPIOB9��ʼ������
	GPIO_InitStructure.GPIO_Pin =SDA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����ģʽ
	GPIO_Init(SDA_Port, &GPIO_InitStructure);//��ʼ��
}


//����IIC��ʼ�ź�
void IIC_Start(void)
{
	SDA_OUT();     //sda�����
	IIC_SDA=1;	  	  
	IIC_SCL=1;
	Delay_us(4);
 	IIC_SDA=0;    //START:when CLK is high,DATA change form high to low 
	Delay_us(4);
	IIC_SCL=0;    //ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//����IICֹͣ�ź�
void IIC_Stop(void)
{
	SDA_OUT();    //sda�����
	IIC_SCL=0;
	IIC_SDA=0;    //STOP:when CLK is high DATA change form low to high
 	Delay_us(4);
	IIC_SCL=1; 
	IIC_SDA=1;    //����I2C���߽����ź�
	Delay_us(4);							   	
}
//�������ݺ󣬵ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ�ܣ�IICֱ���˳�
//        0������Ӧ��ɹ���ʲô������
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      //SDA����Ϊ����  
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
	IIC_SCL=0;    //ʱ�����0 	   
	return 0;  
} 
//����ACKӦ��
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
//������ACKӦ��		    
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
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC_Send_Byte(u8 txd)
{                        
    u8 t;   
	SDA_OUT(); 	    
    IIC_SCL=0;            //����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
			IIC_SDA=(txd&0x80)>>7;
//		if((txd&0x80)>>7)
//			IIC_SDA=1;
//		else
//			IIC_SDA=0;
		txd<<=1; 	  
		Delay_us(2);       //��TEA5767��������ʱ���Ǳ����
		IIC_SCL=1;
		Delay_us(2); 
		IIC_SCL=0;	
		Delay_us(2);
    }	 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();        //SDA����Ϊ����
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
        IIC_NAck();        //����nACK
    else
        IIC_Ack();         //����ACK   
    return receive;
}

