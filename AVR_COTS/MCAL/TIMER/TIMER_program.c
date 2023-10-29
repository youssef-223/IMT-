#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"


void TIMER0_voidInit(void)
{
    /* Select Timer Mode */
    TCCR0 &= Timer0ModeMask;
    TCCR0 |= TimerMode;

    /* Select Timer Submode */
    TCCR0 &= SubModeMask;
    TCCR0 |= CTC_SubMode;

    /* Select Prescaler Division factor */
    TCCR0 &= Timer0_PreScaler;

    /* Set the timer value to 0 by default */
    TCNT0 = 0;
}



void TIMER0_voidSetPreloadValue(u8 Copy_u8Value)
{
    TCNT0 = Copy_u8Value;
}



void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value)
{
    OCR0 = Copy_u8Value;
}

static void (*TIMER0_GlobalPtrToFunc)(void) = NULL;


void TIMER0_voidSetOVFCallBack(void(*ptrToFunc)(void))
{
    TIMER0_GlobalPtrToFunc = ptrToFunc;

}



void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case  :
        /* code */
        break;
    
    default:
        break;
    }
}