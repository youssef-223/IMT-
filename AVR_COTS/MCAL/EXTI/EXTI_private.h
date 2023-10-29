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
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define     MCUCR           *((volatile u8 *)0x55)
#define     MCUCR_ISC00     0           
#define     MCUCR_ISC01     1           
#define     MCUCR_ISC10     2           
#define     MCUCR_ISC11     3

#define     MCUCSR          *((volatile u8 *)0x54)
#define     MCUCSR_ISC2     6

#define     GICR            *((volatile u8 *)0x5B)
#define     GICR_INT2       5
#define     GICR_INT0       6
#define     GICR_INT1       7

#define     GIFR            *((volatile u8 *)0x5A)
#define     GIFR_INTF2       5
#define     GIFR_INTF0       6
#define     GIFR_INTF1       7

#endif