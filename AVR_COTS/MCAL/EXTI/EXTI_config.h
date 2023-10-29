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
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H


#define     EXTI_INT0_ENABLE        EXTI_ENABLE
#define     EXTI_INT1_ENABLE        EXTI_ENABLE
#define     EXTI_INT2_ENABLE        EXTI_ENABLE

/*
    Options:
    EXTI_RISING_EDGE
    EXTI_FALLING_EDGE
    EXTI_ON_CHANGE
    EXTI_LOW_LEVEL
*/
#define     EXTI_INT0_SENSE_SIGNAL  EXTI_FALLING_EDGE
#define     EXTI_INT1_SENSE_SIGNAL  EXTI_RISING_EDGE
#define     EXTI_INT2_SENSE_SIGNAL  EXTI_RISING_EDGE




#endif



