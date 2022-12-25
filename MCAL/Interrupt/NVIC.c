#include "NVIC.h"
#include "../../LIBRARIES/BIT_Math.h"
#include "../../LIBRARIES/STD_TYPES.h"
#include "../../LIBRARIES/tm4c123gh6pm.h"
void  NVIC_Init( uint8 vectorNum) 
{
    uint8 registerNumber;
    uint8 bitNumber;
    
    __enable_irq();

     registerNumber = (vectorNum - 16) / 32;
     bitNumber = (vectorNum- 16) % 32;

    if(registerNumber==0)
    {
        SET_BIT(NVIC_EN0_R, bitNumber);
    }
    else if(registerNumber==1)
    {
        SET_BIT(NVIC_EN1_R, bitNumber);
    }
    else if(registerNumber==2)
    {
        SET_BIT(NVIC_EN2_R, bitNumber);
    }
    else if(registerNumber==3)
    {
        
		SET_BIT(NVIC_EN3_R, bitNumber);
    }
}