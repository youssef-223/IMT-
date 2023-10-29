#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H



#define     Timer0ModeMask                      0b10110111

#define     Normal_mode                        0b00000000
#define     PWM_PhaseCorrect_mode              0b01000000
#define     CTC_mode                           0b00001000
#define     FastPwm_mode                       0b01001000




#define     SubModeMask                        0b11001111

#define     Normal_subMode                     0b00000000

#define     CTC_ToggleOC0_SubMode              0b00010000
#define     CTC_ClearOC0_SubMode               0b00100000       //Clear OC0 on Compare Match, Set OC0 at Top  
#define     CTC_SetOC0_SubMode                 0b00110000       //Set OC0 on Compare Match, Clear OC0 at Top  
#define     PWM_ClearOC0_SubMode               0b00100000       //Clear OC0 on Compare Match when Upcounting, Set OC0 on Compare Match while Downcounting
#define     PWM_SetOC0_SubMode                 0b00110000       //Set OC0 on Compare Match when Upcounting, Clear OC0 on Compare Match while Downcounting




#define     Timer0_PreScaler                   0b11111000

#define     NoClockSource                      0b00000000
#define     NoPreScaling                       0b00000001 
#define     PreDivBy_8                         0b00000010 
#define     PreDivBy_64                        0b00000011 
#define     PreDivBy_256                       0b00000100 
#define     PreDivBy_1024                      0b00000101 
#define     EXT_CLK_FALLING                    0b00000110     // External CLK on T0 pin
#define     EXT_CLK_RISING                     0b00000111     // External CLK on T0 pin




/*************************** TIMER 0 ************************/

#define     TCCR0               *((volatile u8 *)0x35)  
#define     TIMER_CS00           0
#define     TIMER_CS01           1
#define     TIMER_CS02           2
#define     TIMER_WGM01          3
#define     TIMER_COM00          4
#define     TIMER_COM01          5   
#define     TIMER_WGM00          6
#define     TIMER_FOC0           7



#define     TCNT0               *((volatile u8 *)0x52)  

#define     OCR0                *((volatile u8 *)0x5C)  

#define     TIMSK               *((volatile u8 *)0x59)  
#define     TIMSK_TOIE0         0
#define     TIMSK_OCIE0         1
#define     TIMSK_TOIE1         2
#define     TIMSK_OCIE1B        3
#define     TIMSK_OCIE1A        4
#define     TIMSK_TICIE1        5
#define     TIMSK_TOIE2         6
#define     TIMSK_OCIE2         7


#define     TIFR                *((volatile u8 *)0x58)    
#define     TIFR_TOV0           0
#define     TIFR_OCF0           1    
#define     TIFR_TOV1           2
#define     TIFR_OCF1B          3
#define     TIFR_OCF1A          4
#define     TIFR_ICF1           5
#define     TIFR_TOV2           6
#define     TIFR_OCF2           7  

#define     CTC_Interrupt       0 
#define     OVF_Interrupt       1




#endif