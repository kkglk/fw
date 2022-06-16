#include"LED.h"

void LED_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;//定义一个结构体
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//开启相关的GPIO时钟
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5; //要控制的管脚
	//GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1; 
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP; //设置引脚模式，通用推挽输出
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz; //设置引脚速率
	
	GPIO_Init(GPIOB,&GPIO_InitStruct);  //调用库函数初始化GPIO
	
	//GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5); //保存状态时注释
}
