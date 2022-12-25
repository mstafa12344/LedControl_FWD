#ifndef GPIO_H
#define GPIO_H
#include "STD_Types.h"

/* ports */

#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3
#define PORTE    4
#define PORTF    5

/*interupt condition*/
#define EDGE_SENSITIVE   0
#define LEVEL_SENSITIVE  1

#define SINGLE_EDGE      0
#define DOULE_EDGE       1

#define RISING_EDGE      0
#define FALLING_EDGE     1


/*OUTPUT CURRENT*/
#define _2mA     0
#define _4mA     1
#define _8mA     2

/*PULL RESISTOR*/
#define PULLUP   0
#define PULLDOWN 1

typedef enum
{
   E_OK,
   E_NOK,
   PIN_OUT_OF_RANGE,
   PORT_OUT_OF_RANGE,
   WORING_DIRCTION,
   NULL_PTR

}TenErrorStatus;

/*FUNCTIONS*/
TenErrorStatus GPIO_pin_init(uint8 u8Port,uint8 u8Pin,uint8 ui8Direction);
TenErrorStatus GPIO_port_init(uint8 u8Port);
TenErrorStatus GPIO_pin_write(uint8 u8Port, uint8 u8Pin,uint8 u8Value);
TenErrorStatus GPIO_pin_toggle(uint8 u8Port, uint8 u8Pin);
TenErrorStatus GPIO_pin_read(uint8 u8Port, uint8 u8Pin,uint8 *PtrResult);
TenErrorStatus GPIO_pin_EN_interrupt(uint8 pinNum ,uint8 portnum, uint8 edge_state , uint8 singl_doubleEdge , uint8 riz_fall_edge);
#endif