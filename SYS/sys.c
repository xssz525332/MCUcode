#include "sys.h"

//Ŀǰ�޳�ʼ��ϵͳ��Դ,�����Ժ�д
void sys_init(void)
{
	/* ����NVICΪ���ȼ���1 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

}
//���½��ý�Э�Ƽ�����

/**
  * @brief  ΢�뼶��ʱ
  * @param  xus ��ʱʱ������Χ��0~233015
  * @retval ��
  */
void Delay_us(uint32_t xus)
{
	SysTick->LOAD = 72 * xus;				//���ö�ʱ����װֵ
	SysTick->VAL = 0x00;					//��յ�ǰ����ֵ
	SysTick->CTRL = 0x00000005;				//����ʱ��ԴΪHCLK��������ʱ��
	while(!(SysTick->CTRL & 0x00010000));	//�ȴ�������0
	SysTick->CTRL = 0x00000004;				//�رն�ʱ��
}

/**
  * @brief  ���뼶��ʱ
  * @param  xms ��ʱʱ������Χ��0~4294967295
  * @retval ��
  */
void Delay_ms(uint32_t xms)
{
	while(xms--)
	{
		Delay_us(1000);
	}
}
 
/**
  * @brief  �뼶��ʱ
  * @param  xs ��ʱʱ������Χ��0~4294967295
  * @retval ��
  */
void Delay_s(uint32_t xs)
{
	while(xs--)
	{
		Delay_ms(1000);
	}
} 


//printf�ض���������1
int fputc(int ch,FILE *p) //����Ĭ�ϵģ���ʹ�� printf ����ʱ�Զ�����
{
  USART_SendData(USART1,(u8)ch);
  while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
  return ch;
}

