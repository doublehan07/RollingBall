# RollingBall
## Introduction
RollingBall is a 10cm ball which will tonggle led status between lights on and off when collides with other objects. The gif demo is shown below.

![](/Intro/1.gif)


Things get more interesting when the number of balls increases.

![](/Intro/2.gif)

![](/Intro/3.gif)

## Solution details
These basic modules are demanded.
- 1 * Gashapon Shell(White)
- 2 * Li-polymer Battery
- 1 * RollingBall Mainboard

![](/Intro/3.jpg)


On each side, there include:
- 8 * 0805 led
- 2 * 5mm led

![](/Intro/2.jpg)


***stm32f103c8t6*** is the main controller. 

A inertial measurement unit(imu) ***mpu6050*** will update ball's motion status(i.e. 3 axis of acceleration values).

For charging purpose, the ***tp4054*** is selected.

![](/Intro/3.jpg)

