#include "led.h"
/**************************************************************************
函数功能：LED接口初始化
入口参数：无 
返回  值：无
**************************************************************************/
void LED_Init(void)
{
	RCC->APB2ENR|=1<<2; //使能 PORTA 时钟  
	GPIOA->CRH&=0XFFF0FFFF;
	GPIOA->CRH|=0X00030000;//PA12 推挽输出
	GPIOA->ODR|=1<<12; //PA12 输出高
	
	GPIOA->CRH&=0XFFFF0FFF;
	GPIOA->CRH|=0X00003000;//PA11 推挽输出
	GPIOA->ODR|=1<<11; //PA11 输出高
	
	RCC->APB2ENR|=1<<4; //使能 PORTC 时钟  
	GPIOC->CRH&=0XFF0FFFFF;
	GPIOC->CRH|=0X00300000;//PC13 推挽输出
	GPIOC->ODR|=1<<13; //PC13 输出高
}

