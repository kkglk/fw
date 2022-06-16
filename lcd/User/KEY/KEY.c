#include"KEY.h"

void KEY_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;//定义一个结构体
	GPIO_InitTypeDef GPIO_InitStructcc;//定义一个结构体2
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//开启相关的GPIO时钟
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0; //要控制的管脚
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING; //设置引脚模式，通用推挽输出
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);  //调用库函数初始化GPIO
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//开启相关的GPIO时钟
	
	GPIO_InitStructcc.GPIO_Pin=GPIO_Pin_13; //要控制的管脚
	GPIO_InitStructcc.GPIO_Mode=GPIO_Mode_IN_FLOATING; //设置引脚模式，通用推挽输出
	
	GPIO_Init(GPIOC,&GPIO_InitStructcc);  //调用库函数初始化GPIO
}
