#include "control.h"	
#include "RollingBall.h"

int EXTI9_5_IRQHandler(void) 
{
	static u8 state = 0, lock = 0, lockStateTiming = 0;
	static u16 counter = 0;
	
	if(PBin(5)==0)		
	{   
		EXTI->PR=1<<5;                                                      //清除LINE5上的中断标志位   
		if(delay_flag==1)
		{
			if(++delay_50==10)	 delay_50=0,delay_flag=0;                    //给主函数提供50ms的精准延时
		}
		Read_DMP();                                               //===更新姿态	      

		if(counter < 600) counter++;
		else state = 1;
		if(state)
		{	
				static double diffX, diffY, diffZ;
				
				lockStateTiming++;
				if(lockStateTiming >= 10)
				{
					lockStateTiming = 0;
					lock = 0;
				}
			
				diffX = accelNow.x - accel_1.x;
				diffY = accelNow.y - accel_1.y;
				diffZ = accelNow.z - accel_1.z;
				diffX = diffX>0 ? diffX : -diffX;
				diffY = diffY>0 ? diffY : -diffY;
				diffZ = diffZ>0 ? diffZ : -diffZ;
				
				if((diffX > 10 || diffY > 10 || diffZ > 10) && !lock)
				{
					PAout(8) = ~PAout(8);
					PAout(11) = ~PAout(11);
					PAout(12) = ~PAout(12);
					PAout(15) = ~PAout(15);
					
					lock = 1;
					lockStateTiming = 0;
				}
			
		}		
	}       	
	return 0;	  
} 
