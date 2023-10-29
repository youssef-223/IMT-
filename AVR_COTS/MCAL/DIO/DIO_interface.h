/*Ai 7aga el user hai7tagha hai include it*/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/******************************************************************************
*****************************   COMMON MACROS   *******************************
******************************************************************************/

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define PIN0    0 
#define PIN1    1 
#define PIN2    2 
#define PIN3    3 
#define PIN4    4 
#define PIN5    5 
#define PIN6    6 
#define PIN7    7 

#define HIGH    1
#define LOW     0

#define INPUT   0
#define OUTPUT  1

#define PULLUP      1
#define PULLDOWN    0

/*****************************************************************************
**************************   FUNCTIONS PROTOTYPE   ***************************
******************************************************************************/

void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Direction);

void DIO_voidEnablePullUp(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullDirection);

void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Value);

void DIO_voidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8Direction);

void DIO_voidSetPortValue(u8 Copy_u8PortName, u8 Copy_u8Value);

void DIO_voidEnablePortPullUp(u8 Copy_u8PortName, u8 Copy_u8PullDirection);

void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName,u8 Copy_u8PortValue);

void DIO_voidSetPortSpecificdirection(u8 Copy_u8PortName,u8 Copy_u8PortDirection);

u8 DIO_u8GetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber);



#endif
