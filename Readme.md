# RollingBall
RollingBall is a 10cm ball which will tonggle led status between lighting on & off when collides with other objects.

## Introduction
Any difference of acceleration in 50ms larger than 15 times scaler will account for a blink event. Then all leds will tonggle lighting status.

![](/Intro/1.gif)


Things get more interesting when the number of balls increases.

![](/Intro/2.gif)


## Important Project files
1. [PDF](/Boards/RollingBallMainBoard/RollingBallMainBoard.pdf) project files

2. [Gerber](/Boards/RollingBallMainBoard/Project_Outputs_for_RollingBallMainBoard.zip) files (zip file)

3. Pin Assignment

|Pin	|	Function		|
|-------|-------------------------------|
|PA8	|	LED array 1		|
|PA11	|	LED array 2		|
|PA12	|	LED array 3		|
|PA15	|	LED array 4		|
|PC13	|	Debug LED		|
|PB8	|	SCL(Software Simulated)	|
|PB9	|	SDA(Software Simulated)	|
|PB5	|	EXTI9_5(MPU6050_INT)	|
|PA9	|	USART1_TX		|
|PA10	|	USART1_RX		|
|PA13	|	SWDIO			|
|PA14	|	SWCLK			|


## Solution details
These basic modules are demanded.
- 1 * Gashapon Shell(White)
- 2 * Li-polymer Battery
- 1 * RollingBall Mainboard

![](/Intro/3.jpg)


On each side, there includes:
- 8 * 0805 led
- 2 * 5mm led

![](/Intro/2.jpg)


***stm32f103c8t6*** is the main controller. 

A inertial measurement unit(imu) ***mpu6050*** will update ball's motion status(i.e. 3 axis of acceleration values).

For charging purpose, the ***tp4054*** is selected.

![](/Intro/3.jpg)

