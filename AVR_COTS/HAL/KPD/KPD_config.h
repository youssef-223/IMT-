#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H


#define     KPD_ROWS_PORT           DIO_PORTC

#define KPD_R1_PIN      PIN0
#define KPD_R2_PIN      PIN1
#define KPD_R3_PIN      PIN2
#define KPD_R4_PIN      PIN3



#define     KPD_COLOUMNS_PORT       DIO_PORTC

#define KPD_C1_PIN      PIN4
#define KPD_C2_PIN      PIN5
#define KPD_C3_PIN      PIN6
#define KPD_C4_PIN      PIN7


#define KPD_NUMBER_OF_ROWS      4
#define KPD_NUMBER_OF_COL       4

#define KPD_BUTTONS_VAL         {\
                                {'1','2','3','4'},\
                                {'5','6','7','8'},\
                                {'9','0','+','-'},\
                                {'*','/','C','='}\
                                }


#define     KDP_DEFAULT_VALUE       255

#endif