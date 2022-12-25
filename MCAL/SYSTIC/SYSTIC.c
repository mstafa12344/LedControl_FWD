#include "SYSTIC.h"
pf SYSTIC_CALLBACK;              // pointer to function
static uint32 counter;
void  sysTick_Handler(void) ;
void SYSTIC_voidInit(void)
{
       
	__enable_irq();              //Global interrupt enable

     NVIC_ST_CTRL_R    = 0      ; //FIRST DISABLE THE TIMER
     NVIC_ST_RELOAD_R  = 16000-1; //NUMBER OF COUNTS
     NVIC_ST_CURRENT_R = 0      ; //TO CLEAR FLAG COUNTER FLAG
     NVIC_ST_CTRL_R    = 6      ; //,CLOCK SOURCE,INT_ENABLE 
}

void SYSTICK_delay_m(uint32 delayVal , pf CALL_BACK)
{
  counter = delayVal;
  SYSTIC_CALLBACK = CALL_BACK;
  SET_BIT(NVIC_ST_CTRL_R ,0);
}

void SYSTICK_delay_ms (uint32 delayNms )
{

    counter = delayNms;

    NVIC_ST_CURRENT_R = 1;
    /*enable timer*/
    NVIC_ST_CTRL_R = 7 ; 

    while (counter!=0);

    
}

void sysTick_Handler(void) 
{
     counter--;
     if(counter==0)
     {
          CLR_BIT( NVIC_ST_CTRL_R,0);
          
        if (SYSTIC_CALLBACK!= NULL)
        {
            SYSTIC_CALLBACK();
            SYSTIC_CALLBACK= NULL;
        }
     }
}