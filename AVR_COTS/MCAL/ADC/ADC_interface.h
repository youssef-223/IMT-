#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


/******************************************************************************
*****************************   COMMON MACROS   *******************************
******************************************************************************/
#define     LEFT_ADJUST         1
#define     RIGTH_ADJUST        0

#define     ADC_ENABLE          1 
#define     ADC_DISABLE         0



#define     ADC_CHANNEL0    0b00000000
//... complete


/*****************************************************************************
**************************   FUNCTIONS PROTOTYPE   ***************************
******************************************************************************/


void ADC_voidInit(void);

void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus);

u8 ADC_u8StartConversionSynchronous(u8 Copy_u8ChannelNumber);

void ADC_voidStartConversionSynchronous(u8 Copy_u8ChannelNumber, void(*ptrToFunc)(u8 *));



#endif