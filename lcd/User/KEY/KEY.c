#include"KEY.h"

void KEY_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;//����һ���ṹ��
	GPIO_InitTypeDef GPIO_InitStructcc;//����һ���ṹ��2
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//������ص�GPIOʱ��
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0; //Ҫ���ƵĹܽ�
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING; //��������ģʽ��ͨ���������
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);  //���ÿ⺯����ʼ��GPIO
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//������ص�GPIOʱ��
	
	GPIO_InitStructcc.GPIO_Pin=GPIO_Pin_13; //Ҫ���ƵĹܽ�
	GPIO_InitStructcc.GPIO_Mode=GPIO_Mode_IN_FLOATING; //��������ģʽ��ͨ���������
	
	GPIO_Init(GPIOC,&GPIO_InitStructcc);  //���ÿ⺯����ʼ��GPIO
}
