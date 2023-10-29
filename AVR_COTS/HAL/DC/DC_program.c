//#include <util/delay.h>

/*Library Inclusion*/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//#include <util/delay.h>

/*Lower Layer Inclusion*/
#include "../../MCAL/DIO/DIO_interface.h"

/*Self Layer Inclusion*/

/*Self File Inclusion*/

#include "DC_interface.h"
#include "DC_private.h"
#include "DC_config.h"



static void DisableAllTransistors(void)
{

    /*Set pin direction to output*/

    DIO_voidSetPinDirection(MOTOR_PORT,PIN0,OUTPUT);
    DIO_voidSetPinDirection(MOTOR_PORT,PIN1,OUTPUT);

    /*Set all transistors to cut off plan*/

    DIO_voidSetPinValue(MOTOR_PORT,PIN0,LOW);
    DIO_voidSetPinValue(MOTOR_PORT,PIN1,LOW);
    

    
}



void RotateCW(void)
{
    DisableAllTransistors();

    DIO_voidSetPinValue(MOTOR_PORT,PIN1,LOW);
    DIO_voidSetPinValue(MOTOR_PORT,PIN0,HIGH);
    

}


void RotateACW(void)
{
    DisableAllTransistors();

    DIO_voidSetPinValue(MOTOR_PORT,PIN1,HIGH);
    DIO_voidSetPinValue(MOTOR_PORT,PIN0,LOW);
    
}