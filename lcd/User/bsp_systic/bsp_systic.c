#include "bsp_systic.h"

//#ifndef
// void SysTick_Config(void)
// {
//  判断重装载值
// if (ticks > SysTick_LOAD_RELOAD_Msk) 
//{
//              return (1);
//}
//	 设定重装载寄存器
// SysTick->LOAD  = ticks - 1;  
// 
//设置中断优先级
// NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);
//设置当前数寄存器
// SysTick->VAL = 0;
// 设置系统定时器的时钟源为
// SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
//                 SysTick_CTRL_TICKINT_Msk |
//                 SysTick_CTRL_ENABLE_Msk;
// return (0);
// }
//#endif
 
void SysTick_Delay_Us(uint32_t us)
{
  uint32_t i;
  SysTick_Config(72);   //1/72000000为晶振时间   *72  =1us
 
 for (i=0; i<us; i++) 
	{
		//当计数器的值减小到0的时候，CRTL寄存器的位16会置1
   while ( !((SysTick->CTRL)&(1<<16)) );
  }
	//关闭SysTick定时器
 SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
 }
void SysTick_Delay_ms(uint32_t ms)
{
  uint32_t i;
  SysTick_Config(72000);  //1/72000000为晶振时间   *72000  =1ms
 
 for (i=0; i<ms; i++) 
	{
   while ( !((SysTick->CTRL)&(1<<16)) );
  }
	
 SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
 }
