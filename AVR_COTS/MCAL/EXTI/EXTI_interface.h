/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		14 Oct, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  14 Oct, 2023	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/******************************************************************************
*****************************   COMMON MACROS   *******************************
******************************************************************************/

#define     EXTI_RISING_EDGE        0
#define     EXTI_FALLING_EDGE       1
#define     EXTI_ON_CHANGE          2
#define     EXTI_LOW_LEVEL          3

#define     EXTI_INT0               0
#define     EXTI_INT1               1
#define     EXTI_INT2               2

#define     EXTI_ENABLE             1
#define     EXTI_DISABLE            0


/*****************************************************************************
**************************   FUNCTIONS PROTOTYPE   ***************************
******************************************************************************/

void EXTI_voidInit(void);

void EXTI_voidInterruptControl(u8 Copy_u8InterruptNum, u8 Copy_u8InterruptState);

void EXTI_voidChangeSenseSignal(u8 Copy_u8InterruptNum, u8 Copy_u8SenseSignal);

u8 EXTI_u8GetInterruptFlag(u8 Copy_u8InterruptNum);

void EXTI_voidSetCallback(u8 Copy_u8IntNum,void(*ptrToFunc)(void));



#endif
