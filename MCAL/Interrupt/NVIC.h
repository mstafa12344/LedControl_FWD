#ifndef NVIC_H
#define NVIC_H
#include "../../LIBRARIES/STD_TYPES.h"

/*vectors*/

#define NVIC_GPIO_PORT_A             16
#define NVIC_GPIO_PORT_B             17
#define NVIC_GPIO_PORT_C             18
#define NVIC_GPIO_PORT_D             19
#define NVIC_GPIO_PORT_E             20
#define NVIC_GPIO_PORT_F             46



void  NVIC_Init(const uint8 vectorNum) ;

#endif