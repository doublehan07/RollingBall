#include "sys.h"

u8 delay_50,delay_flag;//,Bi_zhang=0;          //Ĭ������£����������Ϲ��ܣ������û�����2s���Ͽ��Խ������ģʽ
int main(void)
{ 
	Stm32_Clock_Init(9);            //=====ϵͳʱ������
	delay_init(72);                 //=====��ʱ��ʼ��
	//JTAG_Set(JTAG_SWD_DISABLE);     //=====�ر�JTAG�ӿ�
	JTAG_Set(SWD_ENABLE);           //=====��SWD�ӿ� �������������SWD�ӿڵ���
	LED_Init();                     //=====��ʼ���� LED ���ӵ�Ӳ���ӿ�
//	uart_init(72,115200);           //=====��ʼ������1
	IIC_Init();                     //=====ģ��IIC��ʼ��
	
  MPU6050_initialize();           //=====MPU6050��ʼ��	
  DMP_Init();                     //=====��ʼ��DMP     
	
	PAout(8) = 0;
	PAout(11) = 0;
	PAout(12) = 0;
	PAout(15) = 0;
	
	EXTI_Init();                    //=====MPU6050 5ms��ʱ�жϳ�ʼ��
	delay_ms(500);
//	PCout(13)= 1;
	
	while(1)
	{     
			  delay_flag=1;	
				delay_50=0;
				while(delay_flag);	     //ͨ��MPU6050��INT�ж�ʵ�ֵ�50ms��׼��ʱ				
	} 
}
