#include "sys.h"

//目前无初始化系统资源,留待以后写
void sys_init(void)
{
	/* 配置NVIC为优先级组1 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

}
//以下借用江协科技代码

/**
  * @brief  微秒级延时
  * @param  xus 延时时长，范围：0~233015
  * @retval 无
  */
void Delay_us(uint32_t xus)
{
	SysTick->LOAD = 72 * xus;				//设置定时器重装值
	SysTick->VAL = 0x00;					//清空当前计数值
	SysTick->CTRL = 0x00000005;				//设置时钟源为HCLK，启动定时器
	while(!(SysTick->CTRL & 0x00010000));	//等待计数到0
	SysTick->CTRL = 0x00000004;				//关闭定时器
}

/**
  * @brief  毫秒级延时
  * @param  xms 延时时长，范围：0~4294967295
  * @retval 无
  */
void Delay_ms(uint32_t xms)
{
	while(xms--)
	{
		Delay_us(1000);
	}
}
 
/**
  * @brief  秒级延时
  * @param  xs 延时时长，范围：0~4294967295
  * @retval 无
  */
void Delay_s(uint32_t xs)
{
	while(xs--)
	{
		Delay_ms(1000);
	}
} 


//printf重定向至串口1
int fputc(int ch,FILE *p) //函数默认的，在使用 printf 函数时自动调用
{
  USART_SendData(USART1,(u8)ch);
  while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
  return ch;
}

