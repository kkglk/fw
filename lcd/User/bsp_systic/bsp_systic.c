#include "bsp_systic.h"

//#ifndef
// void SysTick_Config(void)
// {
//  �ж���װ��ֵ
// if (ticks > SysTick_LOAD_RELOAD_Msk) 
//{
//              return (1);
//}
//	 �趨��װ�ؼĴ���
// SysTick->LOAD  = ticks - 1;  
// 
//�����ж����ȼ�
// NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);
//���õ�ǰ���Ĵ���
// SysTick->VAL = 0;
// ����ϵͳ��ʱ����ʱ��ԴΪ
// SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
//                 SysTick_CTRL_TICKINT_Msk |
//                 SysTick_CTRL_ENABLE_Msk;
// return (0);
// }
//#endif
 
void SysTick_Delay_Us(uint32_t us)
{
  uint32_t i;
  SysTick_Config(72);   //1/72000000Ϊ����ʱ��   *72  =1us
 
 for (i=0; i<us; i++) 
	{
		//����������ֵ��С��0��ʱ��CRTL�Ĵ�����λ16����1
   while ( !((SysTick->CTRL)&(1<<16)) );
  }
	//�ر�SysTick��ʱ��
 SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
 }
void SysTick_Delay_ms(uint32_t ms)
{
  uint32_t i;
  SysTick_Config(72000);  //1/72000000Ϊ����ʱ��   *72000  =1ms
 
 for (i=0; i<ms; i++) 
	{
   while ( !((SysTick->CTRL)&(1<<16)) );
  }
	
 SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
 }
