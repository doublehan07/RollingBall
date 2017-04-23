/*
	@Copyright Han ZHANG(haldak) | All rights reserved.
	@Last Modified Time Apr.23, 2017
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sROLLINGBALL_H
#define __sROLLINGBALL_H

/* Includes ------------------------------------------------------------------*/
#include "sys.h"

/* Exported types ------------------------------------------------------------*/
typedef struct
{
	double x;
	double y;
	double z;
}Gyro;

typedef struct
{
	double x;
	double y;
	double z;
}Accel;

/* Exported constants --------------------------------------------------------*/
extern Gyro gyroNow, gyro_1;
extern Accel accelNow, accel_1;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __sROLLINGBALL_H */
