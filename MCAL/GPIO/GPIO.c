#include "STD_Types.h"
#include "BIT_Math.h"
#include "tm4c123gh6pm.h"
#include "GPIO.h"




TenErrorStatus GPIO_pin_init(uint8 u8Port,uint8 u8Pin,uint8 ui8Direction)
{
   TenErrorStatus ErrorStatusReturnVal=E_OK;
   if(u8Pin>7)
   {
      ErrorStatusReturnVal=PIN_OUT_OF_RANGE;
   }
   else if(u8Pin>6&&u8Port==PORTE)
   {
       ErrorStatusReturnVal=PIN_OUT_OF_RANGE;
   }
   else if(u8Pin>5&&u8Port==PORTF)
   {
       ErrorStatusReturnVal=PIN_OUT_OF_RANGE;
   }

  
     if(u8Port==PORTA)
     {
      if(1==ui8Direction)
      {
         SET_BIT(GPIO_PORTA_DIR_R,u8Pin);
      }
      else
      {
          CLR_BIT(GPIO_PORTA_DIR_R,u8Pin);
      }
      SET_BIT(GPIO_PORTA_AFSEL_R,u8Pin);
      SET_BIT(GPIO_PORTA_DEN_R,u8Pin);
     }

   else if(u8Port==PORTB)
     {
      if(1==ui8Direction)
      {
         SET_BIT(GPIO_PORTB_DIR_R,u8Pin);
      }
      else
      {
          CLR_BIT(GPIO_PORTB_DIR_R,u8Pin);
      }
      SET_BIT(GPIO_PORTB_AFSEL_R,u8Pin);
      SET_BIT(GPIO_PORTB_DEN_R,u8Pin);
     } 
   else if(u8Port==PORTC)
     {
      if(1==ui8Direction)
      {
         SET_BIT(GPIO_PORTC_DIR_R,u8Pin);
      }
      else
      {
          CLR_BIT(GPIO_PORTC_DIR_R,u8Pin);
      }
      SET_BIT(GPIO_PORTC_AFSEL_R,u8Pin);
      SET_BIT(GPIO_PORTC_DEN_R,u8Pin);
     } 
   else if(u8Port==PORTD)
     {
      if(1==ui8Direction)
      {
         SET_BIT(GPIO_PORTD_DIR_R,u8Pin);
      }
      else
      {
          CLR_BIT(GPIO_PORTD_DIR_R,u8Pin);
      }
      SET_BIT(GPIO_PORTD_AFSEL_R,u8Pin);
      SET_BIT(GPIO_PORTD_DEN_R,u8Pin);
     } 
   else if(u8Port==PORTE)
     {
      if(1==ui8Direction)
      {
         SET_BIT(GPIO_PORTE_DIR_R,u8Pin);
      }
      else
      {
          CLR_BIT(GPIO_PORTE_DIR_R,u8Pin);
      }
      SET_BIT(GPIO_PORTE_AFSEL_R,u8Pin);
      SET_BIT(GPIO_PORTE_DEN_R,u8Pin);
     }
   else if(u8Port==PORTF)
     {
      if(1==ui8Direction)
      {
         SET_BIT(GPIO_PORTF_DIR_R,u8Pin);
      }
      else
      {
          CLR_BIT(GPIO_PORTF_DIR_R,u8Pin);
      }
      SET_BIT(GPIO_PORTF_AFSEL_R,u8Pin);
      SET_BIT(GPIO_PORTF_DEN_R,u8Pin);
     }
     else
     {
      ErrorStatusReturnVal=PORT_OUT_OF_RANGE;
     }
   return ErrorStatusReturnVal;
}
TenErrorStatus GPIO_port_init(uint8 u8Port)
{
    TenErrorStatus ErrorStatusReturnVal;

    ErrorStatusReturnVal=E_OK;

    if (u8Port > 5  )
    {
        ErrorStatusReturnVal = PORT_OUT_OF_RANGE;
    }
    
    SET_BIT(SYSCTL_RCGCGPIO_R , u8Port);
    return ErrorStatusReturnVal;
}
TenErrorStatus GPIO_pin_write(uint8 u8Port, uint8 u8Pin,uint8 u8Value)
{
  TenErrorStatus ErrorStatusReturnVal;

  ErrorStatusReturnVal=E_OK;
  if( u8Value>1)
  {
    ErrorStatusReturnVal=E_NOK;
  }
  else
  {
    switch(u8Port)
    {
      case PORTA:
      if(1==u8Value)
      {
        SET_BIT(GPIO_PORTA_DATA_R ,u8Pin );
      }
      else
      {
        CLR_BIT(GPIO_PORTA_DATA_R ,u8Pin);
      }
      break;

      case PORTB:
      if(1==u8Value)
      {
        SET_BIT(GPIO_PORTB_DATA_R ,u8Pin );
      }
      else
      {
        CLR_BIT(GPIO_PORTB_DATA_R ,u8Pin);
      }
      break;

      case PORTC:
      if(1==u8Value)
      {
        SET_BIT(GPIO_PORTC_DATA_R ,u8Pin );
      }
      else
      {
        CLR_BIT(GPIO_PORTC_DATA_R ,u8Pin);
      }
      break;

      case PORTD:
      if(1==u8Value)
      {
        SET_BIT(GPIO_PORTD_DATA_R ,u8Pin );
      }
      else
      {
        CLR_BIT(GPIO_PORTD_DATA_R ,u8Pin);
      }
      break;

      case PORTE:
      if(1==u8Value)
      {
        SET_BIT(GPIO_PORTE_DATA_R ,u8Pin );
      }
      else
      {
        CLR_BIT(GPIO_PORTE_DATA_R ,u8Pin);
      }
      break;

      case PORTF:
      if(1==u8Value)
      {
        SET_BIT(GPIO_PORTF_DATA_R ,u8Pin );
      }
      else
      {
        CLR_BIT(GPIO_PORTF_DATA_R ,u8Pin);
      }
      break;

    }
  }
  return  ErrorStatusReturnVal;
}
TenErrorStatus GPIO_pin_toggle(uint8 u8Port, uint8 u8Pin)
{
 TenErrorStatus ErrorStatusReturnVal =E_OK;
  if(u8Port==PORTA)
  {
   TOG_BIT(GPIO_PORTA_DATA_R , u8Pin);
  }
  else if(u8Port==PORTB)
  {
    TOG_BIT(GPIO_PORTB_DATA_R , u8Pin);
  }
  else if(u8Port==PORTC)
  {
    TOG_BIT(GPIO_PORTC_DATA_R , u8Pin);
  }
  else if(u8Port==PORTD)
  {
    TOG_BIT(GPIO_PORTD_DATA_R , u8Pin);
  }
  else if(u8Port==PORTE)
  {
    TOG_BIT(GPIO_PORTE_DATA_R , u8Pin);
  }
  else if(u8Port==PORTF)
  {
    TOG_BIT(GPIO_PORTB_DATA_R , u8Pin);
  }
  else
  {
    ErrorStatusReturnVal=E_NOK;
  }
  return  ErrorStatusReturnVal;
}

TenErrorStatus GPIO_pin_read(uint8 u8Port, uint8 u8Pin,uint8 *PtrResult)
{
  TenErrorStatus ErrorStatusReturnVal=E_OK;
  if(PtrResult ==NULL)
  {
    ErrorStatusReturnVal = NULL_PTR;
  }
  else
      {
      if(u8Port==PORTA)
      {
        *PtrResult = GET_BIT(GPIO_PORTA_DATA_R , u8Pin);
      }
      else if(u8Port==PORTB)
      {
        *PtrResult = GET_BIT(GPIO_PORTB_DATA_R , u8Pin);
      }
      else if(u8Port==PORTC)
      {
        *PtrResult = GET_BIT(GPIO_PORTC_DATA_R , u8Pin);
      }
      else if(u8Port==PORTD)
      {
        *PtrResult = GET_BIT(GPIO_PORTD_DATA_R , u8Pin);
      }
      else if(u8Port==PORTE)
      {
        *PtrResult = GET_BIT(GPIO_PORTE_DATA_R , u8Pin);
      }
      else if(u8Port==PORTF)
      {
        *PtrResult = GET_BIT(GPIO_PORTB_DATA_R , u8Pin);
      }
    }
  return ErrorStatusReturnVal;
}

TenErrorStatus GPIO_pin_EN_interrupt(uint8 pinNum ,uint8 portnum, uint8 edge_state , uint8 singl_doubleEdge , uint8 riz_fall_edge)
{
  switch(portnum)
  {
    case PORTA:
    if(edge_state==EDGE_SENSITIVE)
      {CLR_BIT(GPIO_PORTA_IS_R , pinNum);} else SET_BIT(GPIO_PORTA_IS_R , pinNum);

    if(singl_doubleEdge==DOULE_EDGE) 
      {SET_BIT(GPIO_PORTA_IBE_R , pinNum);} else CLR_BIT(GPIO_PORTA_IBE_R , pinNum);

    if(riz_fall_edge==RISING_EDGE)
      {SET_BIT(GPIO_PORTB_IEV_R , pinNum);} else CLR_BIT(GPIO_PORTA_IEV_R , pinNum);

      CLR_BIT(GPIO_PORTA_ICR_R , pinNum); //delete icr
      SET_BIT(GPIO_PORTA_IM_R , pinNum) ;  //unmasked
    break;

    case PORTB:
    if(edge_state==EDGE_SENSITIVE)
      {CLR_BIT(GPIO_PORTA_IS_R , pinNum);} else SET_BIT(GPIO_PORTA_IS_R , pinNum);

    if(singl_doubleEdge==DOULE_EDGE) 
      {SET_BIT(GPIO_PORTA_IBE_R , pinNum);} else CLR_BIT(GPIO_PORTA_IBE_R , pinNum);

    if(riz_fall_edge==RISING_EDGE)
      {SET_BIT(GPIO_PORTB_IEV_R , pinNum);} else CLR_BIT(GPIO_PORTA_IEV_R , pinNum);

      CLR_BIT(GPIO_PORTA_ICR_R , pinNum); //delete icr
      SET_BIT(GPIO_PORTA_IM_R , pinNum);  //unmasked
    break;

    case PORTC:
    if(edge_state==EDGE_SENSITIVE)
      {CLR_BIT(GPIO_PORTA_IS_R , pinNum);} else SET_BIT(GPIO_PORTA_IS_R , pinNum);

    if(singl_doubleEdge==DOULE_EDGE) 
      {SET_BIT(GPIO_PORTA_IBE_R , pinNum);} else CLR_BIT(GPIO_PORTA_IBE_R , pinNum);

    if(riz_fall_edge==RISING_EDGE)
      {SET_BIT(GPIO_PORTB_IEV_R , pinNum);} else CLR_BIT(GPIO_PORTA_IEV_R , pinNum);

      CLR_BIT(GPIO_PORTA_ICR_R , pinNum); //delete icr
      SET_BIT(GPIO_PORTA_IM_R , pinNum);  //unmasked
    break;

    case PORTD:
    if(edge_state==EDGE_SENSITIVE)
      {CLR_BIT(GPIO_PORTA_IS_R , pinNum);} else SET_BIT(GPIO_PORTA_IS_R , pinNum);

    if(singl_doubleEdge==DOULE_EDGE) 
      {SET_BIT(GPIO_PORTA_IBE_R , pinNum);} else CLR_BIT(GPIO_PORTA_IBE_R , pinNum);

    if(riz_fall_edge==RISING_EDGE)
      {SET_BIT(GPIO_PORTB_IEV_R , pinNum);} else CLR_BIT(GPIO_PORTA_IEV_R , pinNum);

      CLR_BIT(GPIO_PORTA_ICR_R , pinNum); //delete icr
      SET_BIT(GPIO_PORTA_IM_R , pinNum);  //unmasked
    break; 

    case PORTE:
    if(edge_state==EDGE_SENSITIVE)
      {CLR_BIT(GPIO_PORTA_IS_R , pinNum);} else SET_BIT(GPIO_PORTA_IS_R , pinNum);

    if(singl_doubleEdge==DOULE_EDGE) 
      {SET_BIT(GPIO_PORTA_IBE_R , pinNum);} else CLR_BIT(GPIO_PORTA_IBE_R , pinNum);

    if(riz_fall_edge==RISING_EDGE)
      {SET_BIT(GPIO_PORTB_IEV_R , pinNum);} else CLR_BIT(GPIO_PORTA_IEV_R , pinNum);

      CLR_BIT(GPIO_PORTA_ICR_R , pinNum); //delete icr
      SET_BIT(GPIO_PORTA_IM_R , pinNum);  //unmasked
    break; 

    case PORTF:
    if(edge_state==EDGE_SENSITIVE)
      {CLR_BIT(GPIO_PORTA_IS_R , pinNum);} else SET_BIT(GPIO_PORTA_IS_R , pinNum);

    if(singl_doubleEdge==DOULE_EDGE) 
      {SET_BIT(GPIO_PORTA_IBE_R , pinNum);} else CLR_BIT(GPIO_PORTA_IBE_R , pinNum);

    if(riz_fall_edge==RISING_EDGE)
      {SET_BIT(GPIO_PORTB_IEV_R , pinNum);} else CLR_BIT(GPIO_PORTA_IEV_R , pinNum);

      CLR_BIT(GPIO_PORTA_ICR_R , pinNum); //delete icr
      SET_BIT(GPIO_PORTA_IM_R , pinNum);  //unmasked
    break; 
  }
}