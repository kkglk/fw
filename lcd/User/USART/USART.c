#include "USART.h"

void USART_NVIC()
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	
	NVIC_Init(&NVIC_InitStruct);
}

void USART_GPIO(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	//nvic
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);
}

void USART_Config(void)
{
	USART_InitTypeDef USART_InitStruct;
	
	USART_GPIO();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	USART_InitStruct.USART_BaudRate=9600;
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	USART_InitStruct.USART_StopBits=USART_StopBits_1;
	USART_InitStruct.USART_Parity=USART_Parity_No;
	USART_InitStruct.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
	USART_InitStruct.USART_HardwareFlowControl=DISABLE;
	
	USART_Init(USART1,&USART_InitStruct);
	
	USART_NVIC();
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	USART_Cmd(USART1,ENABLE);
}

//重定向c库函数printf到串口，重定向后可使用printf函数
int fputc(int ch,FILE *f)
{
	//发送一个字节数据到串口
	USART_SendData(USART1, (uint8_t) ch);
	
	//等待发送完毕
	while (USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	
	return (ch);
}
