#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"



void ADC_voidInit(void)
{
    
    /* Select the prescaler = 64 */
    ADCSRA &= PRES_SEL_MASK;
    ADCSRA |= ADC_PRESCALER;

    /* Select Reference Voltage */

    ADMUX &= REF_SEL_BIT_MASK;
    ADMUX |= ADC_REF;

    #if ADC_LEFT_RIGHT_ADJUST == LEFT
            /* Left Adjust */
            SET_BIT(ADMUX,ADMUX_ADLAR);

    #elif ADC_LEFT_RIGHT_ADJUST == RIGHT
            /* Right Adjust */
            CLR_BIT(ADMUX,ADMUX_ADLAR);

    #endif


    #if ADC_ENABLE == ENABLE
            /* Enable ADC */
            SET_BIT(ADCSRA,ADCSRA_ADEN);

    #elif ADC_ENABLE == DISABLE
            /* Disable ADC */
            CLR_BIT(ADCSRA,ADCSRA_ADEN);

    #endif



}

u8 ADC_u8StartConversionSynchronous(u8 Copy_u8ChannelNumber)
{
    /* Select Channel */
    ADMUX &= CHANNEL_SELECTION_MASK;
    ADMUX |= Copy_u8ChannelNumber;
    
    /* Trigger ADC to start the conversion */
    SET_BIT(ADCSRA, ADCSRA_ADSC);

    /* Polling (busy wait) till the ADC ends the conversion (Flag is raised) */
    while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);

    /* Clear The Flag */
    SET_BIT(ADCSRA, ADCSRA_ADIF);

    /* Return The Digital Value */
    return (ADCH);
}


u16 ADC_u16StartConversionSynchronous(u8 Copy_u8ChannelNumber)
{
    /* Select Channel */
    ADMUX &= CHANNEL_SELECTION_MASK;
    ADMUX |= Copy_u8ChannelNumber;

    /* Right Adjust */
    CLR_BIT(ADMUX,ADMUX_ADLAR);

    u16 *ptrToDigitalOutput = &ADCL;

    /* Trigger ADC to start the conversion */
    SET_BIT(ADCSRA, ADCSRA_ADSC);

    /* Polling (busy wait) till the ADC ends the conversion (Flag is raised) */
    while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);

    /* Clear The Flag */
    SET_BIT(ADCSRA, ADCSRA_ADIF);

    /* Return The Digital Value */
    return (ADCH);
}


/**
 * a function to return u16 
 * 
 * right adjust
 * 
 * u16 *ptr = &ADCL;
 * 
 */


/**
 * @brief 
 * 
 * @param Copy_u8ChannelNumber 
 * @param ptrToFunc 
 */

void ADC_voidStartConversionAsynchronous(u8 Copy_u8ChannelNumber, void(*ptrToFunc)(u8 *))
{

    ADC_ptrToFunc = ptrToFunc;

    /* Select Channel */
    ADMUX &= CHANNEL_SELECTION_MASK;
    ADMUX |= Copy_u8ChannelNumber;

    /* Enable The PIE */
    SET_BIT(ADCSRA,ADCSRA_ADIE);

    /* Trigger ADC to start the conversion */
    SET_BIT(ADCSRA, ADCSRA_ADSC);




}

void (* ADC_ptrToFunc)(u8 *) = NULL;
u8 ADC_u8Reslut = 0;

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
    ADC_u8Reslut = ADCH;

    if (ADC_ptrToFunc != NULL)
    {
        ADC_ptrToFunc(&ADC_u8Reslut);
    }
    else
    {
        //Do Nothing
    }
}