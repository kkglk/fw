#include"LED.h"

void LED_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;//����һ���ṹ��
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//������ص�GPIOʱ��
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5; //Ҫ���ƵĹܽ�
	//GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1; 
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP; //��������ģʽ��ͨ���������
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz; //������������
	
	GPIO_Init(GPIOB,&GPIO_InitStruct);  //���ÿ⺯����ʼ��GPIO
	
	//GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5); //����״̬ʱע��
}
