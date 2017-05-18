#include "sys.h"

u8 delay_50,delay_flag;//,Bi_zhang=0;          //默认情况下，不开启避障功能，长按用户按键2s以上可以进入避障模式
int main(void)
{ 
	Stm32_Clock_Init(9);            //=====系统时钟设置
	delay_init(72);                 //=====延时初始化
	//JTAG_Set(JTAG_SWD_DISABLE);     //=====关闭JTAG接口
	JTAG_Set(SWD_ENABLE);           //=====打开SWD接口 可以利用主板的SWD接口调试
	LED_Init();                     //=====初始化与 LED 连接的硬件接口
	uart_init(72,115200);           //=====初始化串口1
	IIC_Init();                     //=====模拟IIC初始化
	
  MPU6050_initialize();           //=====MPU6050初始化	
  DMP_Init();                     //=====初始化DMP     
	
	PAout(8) = 0;
	PAout(11) = 0;
	PAout(12) = 0;
	PAout(15) = 0;
	
	EXTI_Init();                    //=====MPU6050 5ms定时中断初始化
	delay_ms(500);
	PCout(13)= 1;
	
	while(1)
	{     
			  delay_flag=1;	
				delay_50=0;
				while(delay_flag);	     //通过MPU6050的INT中断实现的50ms精准延时				
	} 
}
