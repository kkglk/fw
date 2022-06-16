#include "stm32f10x.h"
#include "LED.h"
#include "KEY.h"
#include "USART.h"
#include "bsp_dht11.h"
#include "bsp_systic.h"
#include "bsp_ili9341_lcd.h"
#include "fonts.h"
#include "stdio.h"
#include "bsp_dht11.h"
#include "bsp_systic.h"
DHT11_Data_TypeDef DHT11_Data;
void LCD_Test(void);
void LCD_Test1(void);
void LCD_Test2(void);
void LCD_Test3(void);
void LCD_Test4(void);
void Delay(uint32_t i)
{
	for(;i!=0;i--);
}
int main()
{
	//LED_Config();
	//初始化USART
	USART_Config();
  ILI9341_Init();
	DHT11_Init();
	
  while(1)
	{
		LCD_Test();
		//LCD_Test1();
		//LCD_Test2();
		//LCD_Test3();
		//LCD_Test4();
	}
   
}
//lcd温度显示初始化
void LCD_Test(void)
{
	LCD_SetFont(&Font16x24);//字号
	LCD_SetColors(RED,BLACK);//字体颜色 背景颜色
	
	ILI9341_Clear(0,0,240,320);//清屏
	
	//Delay(0xFFFFFF);
			if(DHT11_Read_TempAndHumidity(&DHT11_Data) == SUCCESS)
			{char str[100];
				
				
				printf("湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n", DHT11_Data.humi_int, DHT11_Data.humi_deci, DHT11_Data.temp_int, DHT11_Data.temp_deci);
				sprintf(str, "HUM: %d.%d%%RH  ", DHT11_Data.humi_int, DHT11_Data.humi_deci);
				ILI9341_DispStringLine_EN(LINE(1),str);
				sprintf(str, "TEMP: %d.%dCEL ", DHT11_Data.temp_int, DHT11_Data.temp_deci);
				ILI9341_DispStringLine_EN(LINE(3),str);
			}
			else
			printf("Read DHT11 ERROR!\r\n");
			  
//				ILI9341_DispString_EN(200,250,"2");
		if(DHT11_Data.humi_int >= 65)
        ILI9341_DispString_EN(200,250,"sd");
			 // ILI9341_DispStringLine_EN(LINE(4),"error");
//			else if(DHT11_Data.humi_int < 65)
//			{
//			ILI9341_DispString_EN(200,250,"");
//			}
//			else
//			ILI9341_Clear(200,250,240,320);//清屏
//			
		SysTick_Delay_ms(2000);
}
//lcd基本显示
void LCD_Test1(void)
{
	LCD_SetFont(&Font16x24);//字号
	LCD_SetColors(RED,BLACK);//字体颜色 背景颜色
	
	ILI9341_Clear(0,0,240,320);//清屏
	
	ILI9341_DispStringLine_EN(LINE(0),"hello world");
	ILI9341_DispStringLine_EN(LINE(1),"use for lcd by ili9341");
	//Delay(0xFFFFFF);
	SysTick_Delay_ms(100);
}

//显示变量
void LCD_Test2(void)
{
	static uint8_t testCNT = 0;
	char dispBuff[100];
	testCNT++;
	
	LCD_SetFont(&Font16x24);
	LCD_SetColors(BLUE,BLACK);
	ILI9341_Clear(0,0,240,320);
	
	//将变量转换为字符串
	sprintf(dispBuff,"Cout : %d",testCNT);
	LCD_ClearLine(LINE(4)); //清除单行文字
	
	ILI9341_DispStringLine_EN(LINE(4),dispBuff);
	Delay(0xFFFFFF);
}
//画图
void LCD_Test3(void)
{
	LCD_ClearLine(LINE(4)); //清除单行文字
	LCD_SetColors(BLUE,BLACK);
	ILI9341_Clear(0,0,240,320);
	
	ILI9341_DispStringLine_EN(LINE(4),"Hello:cir");
	
	LCD_SetTextColor(RED);
	ILI9341_DrawCircle(100,200,20,0);
	
	LCD_SetTextColor(BLUE);
	ILI9341_DrawCircle(220,200,20,0);
	
	Delay(0xFFFFFFff);
	
	ILI9341_Clear(0,16*8,LCD_X_LENGTH,LCD_Y_LENGTH-16*8);
}
//画线
void LCD_Test4(void)
{
	LCD_ClearLine(LINE(4)); //清除单行文字
	LCD_SetColors(BLUE,BLACK);
	ILI9341_Clear(0,0,240,320);
	
	ILI9341_DispStringLine_EN(LINE(4),"Hello:line");
	
	LCD_SetTextColor(RED);
	ILI9341_DrawLine(100,200,210,300);
	
	LCD_SetTextColor(BLUE);
	ILI9341_DrawLine(220,200,20,0);
	
	Delay(0xFFFFFF);
	
	ILI9341_Clear(0,16*8,LCD_X_LENGTH,LCD_Y_LENGTH-16*8);
}

