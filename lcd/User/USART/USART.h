#ifndef __USART__H
#define __USART__H

#include "stm32f10x.h"
#include "stdio.h"

void USART_NVIC(void);
void USART_GPIO(void);
void USART_Config(void);
int fputc(int ch,FILE *f);
#endif

