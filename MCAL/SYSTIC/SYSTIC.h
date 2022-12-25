#ifndef SYSTIC_H
#define SYSTIC_H

#include "../../LIBRARIES/STD_TYPES.h"
#include "../../LIBRARIES/BIT_MATH.h"
#include "../../LIBRARIES/tm4c123gh6pm.h"

void SYSTIC_voidInit(void);
void SYSTICK_delay_m(uint32 delayVal , pf CALL_BACK);
void SYSTICK_delay_ms(uint32 delayNms );

#endif