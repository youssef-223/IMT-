#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

void TIMER0_voidInit(void);

void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);

void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value);

void TIMER0_voidSetOVFCallBack(void(*ptrToFunc)(void));

void TIMER0_voidSetOCFCallBack(void(*ptrToFunc)(void));

void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode);

void TIMER0_voidDisbleInterrupt(u8 Copy_u8Mode);

void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32Time);


#endif