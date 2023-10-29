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
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"




void EXTI_voidInit(void)
{
    #if EXTI_INT0_ENABLE == EXTI_ENABLE

        /*Enable The INT0 Interrupt*/
        SET_BIT(GICR, GICR_INT0);

        #if EXTI_INT0_SENSE_SIGNAL == EXTI_RISING_EDGE
            /*Set The ISC00 & ISC01 To Sense The Rising Edge*/
            SET_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
        #elif EXTI_INT0_SENSE_SIGNAL == EXTI_FALLING_EDGE
            /*Clear The ISC00 & Set The ISC01 To Sense The Falling Edge*/
            CLR_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
        #elif EXTI_INT0_SENSE_SIGNAL == EXTI_ON_CHANGE 
            /*Set The ISC00 & Clear The ISC01 To Sense The On Chagne*/
            SET_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);
        #elif EXTI_INT0_SENSE_SIGNAL == EXTI_LOW_LEVEL 
            /*Clear The ISC00 & ISC01 To Sense The Low Level*/
            CLR_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);
        #else 
            #error "Error!, EXTI_INT0_SENSE_SIGNAL Configuration Error"
        #endif

    #elif EXTI_INT0_ENABLE == EXTI_DISABLE
        /*Disable The INT0 Interrupt*/
        CLR_BIT(GICR, GICR_INT0);
    #else
        #error "Error!, EXTI_INT0_ENABLE Configuration Error"
    #endif

}


void EXTI_voidInterruptControl(u8 Copy_u8InterruptNum, u8 Copy_u8InterruptState)
{
    switch(Copy_u8InterruptNum)
    {
        case EXTI_INT0:
            switch(Copy_u8InterruptState)
            {
                case EXTI_ENABLE:
                    SET_BIT(GICR, GICR_INT0);
                break;
                
                case EXTI_DISABLE:
                    CLR_BIT(GICR, GICR_INT0);
                break;

                default:
                break;
            }
        break;

        case EXTI_INT1:
        break;

        case EXTI_INT2:
        break;

        default:
        break;
    }
}


void EXTI_voidChangeSenseSignal(u8 Copy_u8InterruptNum, u8 Copy_u8SenseSignal)
{
    switch(Copy_u8InterruptNum)
    {
        case EXTI_INT0:
            switch(Copy_u8SenseSignal)
            {
                case EXTI_RISING_EDGE:
                    SET_BIT(MCUCR, MCUCR_ISC00);
                    SET_BIT(MCUCR, MCUCR_ISC01);
                break;

                case EXTI_FALLING_EDGE:
                    CLR_BIT(MCUCR, MCUCR_ISC00);
                    SET_BIT(MCUCR, MCUCR_ISC01);
                break;

                case EXTI_ON_CHANGE:
                    SET_BIT(MCUCR, MCUCR_ISC00);
                    CLR_BIT(MCUCR, MCUCR_ISC01);
                break;

                case EXTI_LOW_LEVEL:
                    CLR_BIT(MCUCR, MCUCR_ISC00);
                    CLR_BIT(MCUCR, MCUCR_ISC01);
                break;

                default:
                break;
            }
        break;
        
        case EXTI_INT1:
        break;
        
        case EXTI_INT2:
        break;
        
        default:
        break;

    }
}


u8 EXTI_u8GetInterruptFlag(u8 Copy_u8InterruptNum)
{
    u8 Local_u8InterruptFlag;

    switch(Copy_u8InterruptNum)
    {
        case EXTI_INT0:
           Local_u8InterruptFlag = GET_BIT(GIFR,GIFR_INTF0);
        break;

        case EXTI_INT1:
            Local_u8InterruptFlag = GET_BIT(GIFR,GIFR_INTF1);
        break;

        case EXTI_INT2:
            Local_u8InterruptFlag = GET_BIT(GIFR,GIFR_INTF2);
        break;

        default:
        break;
    }
}



static void (*EXTI_voidINT0Function)(void) = NULL;
static void (*EXTI_voidINT1Function)(void) = NULL;
static void (*EXTI_voidINT2Function)(void) = NULL;


/**
 * @brief 
 * 
 */

void EXTI_voidSetCallback(u8 Copy_u8IntNum,void(*ptrToFunc)(void))
{
    switch (Copy_u8IntNum)
    {
    case EXTI_INT0:
        EXTI_voidINT0Function = ptrToFunc;
        break;

    case EXTI_INT1:
        EXTI_voidINT1Function = ptrToFunc;
        break;
    case EXTI_INT2:
        EXTI_voidINT2Function = ptrToFunc;
        break;
    
    default:
        break;
    }
}



/**
 * @brief 
 * 
 */

void _vector_1 (void) __attribute__((signal));
void _vector_1 (void)
{
    if (EXTI_voidSetCallback != NULL)
    {
        EXTI_voidINT0Function();
    }
    else
    {

    }

}
