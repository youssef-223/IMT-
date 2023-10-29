/**
 * FILE WHICH IS NOT OBSERVED BY THE USER
 */

/*Library Inclusion*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*Lower layer Inclusion*/

/*Self Files Inclusion*/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


/**
 * DIO_voidSetPinDirection - Set direction to specific pin
 * @Copy_u8PortName : Port Name
 * @Copy_u8PinNumber: Pin Number 
 * @Copy_u8Direction: Direction of the pin to be set
 * 
 * Description: Set direction to specific pin
 * 
 * Return: void 
 */


void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Direction)

{
    switch (Copy_u8PortName)
    {
    case DIO_PORTA:
        switch (Copy_u8Direction)
        {
        case OUTPUT:
            SET_BIT(DDRA,Copy_u8PinNumber);
            break;
        
        case INPUT:
            CLR_BIT(DDRA,Copy_u8PinNumber);
            break;
        }
        break;

     case DIO_PORTB:
        switch (Copy_u8Direction)
        {
        case OUTPUT:
            SET_BIT(DDRB,Copy_u8PinNumber);
            break;
        
        case INPUT:
            CLR_BIT(DDRB,Copy_u8PinNumber);
            break;
        }
        break;
     
     case DIO_PORTC:
        switch (Copy_u8Direction)
        {
        case OUTPUT:
            SET_BIT(DDRC,Copy_u8PinNumber);
            break;
        
        case INPUT:
            CLR_BIT(DDRC,Copy_u8PinNumber);
            break;
        }
        break;
     
     case DIO_PORTD:
        switch (Copy_u8Direction)
        {
        case OUTPUT:
            SET_BIT(DDRD,Copy_u8PinNumber);
            break;
        
        case INPUT:
            CLR_BIT(DDRD,Copy_u8PinNumber);
            break;
        }
        break;
    
    default:
        break;
    }   
}


/**
 * DIO_voidEnablePullUp - control pullup circuit
 * @Copy_u8PortName : Port Name
 * @Copy_u8PinNumber: Pin Number 
 * @Copy_u8PullDirection: Direction of the pull 
 * 
 * Description: control pullup circuit
 * 
 * Return: void 
 */


void DIO_voidEnablePullUp(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullDirection)

{
    switch (Copy_u8PortName)
    {
    case DIO_PORTA:
        switch (Copy_u8PullDirection)
        {
        case OUTPUT:
            SET_BIT(PORTA,Copy_u8PinNumber);
            break;
        
        case INPUT:
            CLR_BIT(PORTA,Copy_u8PinNumber);
            break;
        }
        break;

     case DIO_PORTB:
        switch (Copy_u8PullDirection)
        {
        case OUTPUT:
            SET_BIT(PORTB,Copy_u8PinNumber);
            break;
        
        case INPUT:
            CLR_BIT(PORTB,Copy_u8PinNumber);
            break;
        }
        break;
     
     case DIO_PORTC:
        switch (Copy_u8PullDirection)
        {
        case OUTPUT:
            SET_BIT(PORTC,Copy_u8PinNumber);
            break;
        
        case INPUT:
            CLR_BIT(PORTC,Copy_u8PinNumber);
            break;
        }
        break;
     
     case DIO_PORTD:
        switch (Copy_u8PullDirection)
        {
        case OUTPUT:
            SET_BIT(PORTD,Copy_u8PinNumber);
            break;
        
        case INPUT:
            CLR_BIT(PORTD,Copy_u8PinNumber);
            break;
        }
        break;
    
    default:
        break;
    }   

}

/**
 * DIO_voidSetPinValue - Set Pin Value
 * @Copy_u8PortName : Port Name
 * @Copy_u8PinNumber: Pin Number 
 * @Copy_u8Value: New value of the pin 
 * 
 * Description: Set Pin Value
 * 
 * Return: void 
 */


void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Value)

{
    switch (Copy_u8PortName)
    {
    case DIO_PORTA:
        switch (Copy_u8Value)
        {
        case HIGH:
            SET_BIT(PORTA,Copy_u8PinNumber);
            break;

        case LOW:
            CLR_BIT(PORTA,Copy_u8PinNumber);
            break;
        
        }
        break;
    
    case DIO_PORTB:
        switch (Copy_u8Value)
        {
        case HIGH:
            SET_BIT(PORTB,Copy_u8PinNumber);
            break;

        case LOW:
            CLR_BIT(PORTB,Copy_u8PinNumber);
            break;
        
        }
        break;

    case DIO_PORTC:
        switch (Copy_u8Value)
        {
        case HIGH:
            SET_BIT(PORTC,Copy_u8PinNumber);
            break;

        case LOW:
            CLR_BIT(PORTC,Copy_u8PinNumber);
            break;
        
        }
        break;

    case DIO_PORTD:
        switch (Copy_u8Value)
        {
        case HIGH:
            SET_BIT(PORTD,Copy_u8PinNumber);
            break;

        case LOW:
            CLR_BIT(PORTD,Copy_u8PinNumber);
            break;
        
        }
        break;
    
    }
}

/**
 * DIO_voidSetPortDirection - Set direction to specific port
 * @Copy_u8PortName : Port Name
 * @Copy_u8Direction: Direction of the pin to be set
 * 
 * Description: Set direction to specific port
 * 
 * Return: void 
 */

void DIO_voidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8Direction)
{
    switch (Copy_u8PortName)
    {
    case DIO_PORTA:
        switch (Copy_u8Direction)
        {
        case OUTPUT:
            DDRA=0XFF;
            break;

        case INPUT:
            DDRA=0X00;
            break;
        
        default:
            break;
        }
        break;

    case DIO_PORTB:
        switch (Copy_u8Direction)
        {
        case OUTPUT:
            DDRB=0XFF;
            break;

        case INPUT:
            DDRB=0X00;
            break;
        
        default:
            break;
        }
        break;

    case DIO_PORTC:
        switch (Copy_u8Direction)
        {
        case OUTPUT:
            DDRC=0XFF;
            break;

        case INPUT:
            DDRC=0X00;
            break;
        
        default:
            break;
        }
        break;

    case DIO_PORTD:
        switch (Copy_u8Direction)
        {
        case OUTPUT:
            DDRD=0XFF;
            break;

        case INPUT:
            DDRD=0X00;
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}

/**
 * DIO_voidSetPortValue - Set port Value
 * @Copy_u8PortName : Port Name
 * @Copy_u8Value: New value of the pin 
 * Description: Set port Value
 * 
 * Return: void 
 */

void DIO_voidSetPortValue(u8 Copy_u8PortName, u8 Copy_u8Value)
{
    switch (Copy_u8PortName)
    {
    case DIO_PORTA:
        switch (Copy_u8Value)
        {
        case HIGH:
            PORTA=0XFF;
            break;

        case LOW:
            PORTA=0X00;
            break;
        
        default:
            break;
        }
        break;

     case DIO_PORTB:
        switch (Copy_u8Value)
        {
        case HIGH:
            PORTB=0XFF;
            break;

        case LOW:
            PORTB=0X00;
            break;
        
        default:
            break;
        }
        break;

    case DIO_PORTC:
        switch (Copy_u8Value)
        {
        case HIGH:
            PORTC=0XFF;
            break;

        case LOW:
            PORTC=0X00;
            break;
        
        default:
            break;
        }
        break;

    case DIO_PORTD:
        switch (Copy_u8Value)
        {
        case HIGH:
            PORTD=0XFF;
            break;

        case LOW:
            PORTD=0X00;
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}

/**
 * DIO_voidEnablePortPullUp - control pullup circuit
 * @Copy_u8PortName : Port Name
 * @Copy_u8PullDirection: Direction of the pull
 * 
 * Description: control pullup circuit
 * 
 * Return: void 
 */

void DIO_voidEnablePortPullUp(u8 Copy_u8PortName, u8 Copy_u8PullDirection)
{
    
    switch (Copy_u8PortName)
    {
    case DIO_PORTA:
        switch (Copy_u8PullDirection)
        {
        case OUTPUT:
            PORTA=0XFF;
            break;

        case INPUT:
            PORTA=0X00;
            break;
        
        default:
            break;
        }
        break;

     case DIO_PORTB:
        switch (Copy_u8PullDirection)
        {
        case OUTPUT:
            PORTB=0XFF;
            break;

        case INPUT:
            PORTB=0X00;
            break;
        
        default:
            break;
        }
        break;

    case DIO_PORTC:
        switch (Copy_u8PullDirection)
        {
        case OUTPUT:
            PORTC=0XFF;
            break;

        case INPUT:
            PORTC=0X00;
            break;
        
        default:
            break;
        }
        break;

    case DIO_PORTD:
        switch (Copy_u8PullDirection)
        {
        case OUTPUT:
            PORTD=0XFF;
            break;

        case INPUT:
            PORTD=0X00;
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}


/**
 * SetPortSpecificValue - assign a value to the port
 * @Copy_u8PortName : Port Name
 * @Copy_u8PortValue: port specific value
 * 
 * Description: assign specific pins in the port with high and low values
 * 
 * Return: void 
 */


void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName,u8 Copy_u8PortValue)
{
    switch (Copy_u8PortName)
    {
    case DIO_PORTA:
        PORTA = Copy_u8PortValue;
        break;

    case DIO_PORTB:
        PORTB = Copy_u8PortValue;
        break;

    case DIO_PORTC:
        PORTC = Copy_u8PortValue;
        break;

    case DIO_PORTD:
        PORTD = Copy_u8PortValue;
        break;
    
    default:
        break;
    }
}


/**
 * SetPortSpecificdirection - assign a value to the port
 * @Copy_u8PortName : Port Name
 * @Copy_u8PortDirection: port specific direction
 * 
 * Description: assign specific pins in the port to be input or output
 * 
 * Return: void 
 */

void DIO_voidSetPortSpecificdirection(u8 Copy_u8PortName,u8 Copy_u8PortDirection)
{
    switch (Copy_u8PortName)
    {
    case DIO_PORTA:
        DDRA = Copy_u8PortDirection;
        break;

    case DIO_PORTB:
        DDRB = Copy_u8PortDirection;
        break;

    case DIO_PORTC:
        DDRC = Copy_u8PortDirection;
        break;

    case DIO_PORTD:
        DDRD = Copy_u8PortDirection;    
        break;
    
    default:
        break;
    }
}
    

/**
 * DIO_u8GetPinValue - assign a value to the port
 * @Copy_u8PortName : Port Name
 * @Copy_u8PinNumber: The Pin Required to be returned
 * 
 * Description: Get The value of the pin set to High
 * 
 * Return: The pin to be Read
 */

u8 DIO_u8GetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{
	u8 Local_u8PinVal;
	switch(Copy_u8PortName)
    {
        case DIO_PORTA:
           Local_u8PinVal= GET_BIT(PINA,Copy_u8PinNumber); //<<<<<<<<<<<<<<<<<<<<< 
        break;
        
        case DIO_PORTB:
           Local_u8PinVal= GET_BIT(PINB,Copy_u8PinNumber); //<<<<<<<<<<<<<<<<<<<<<
        break;

        case DIO_PORTC:
			Local_u8PinVal= GET_BIT(PINC,Copy_u8PinNumber); //<<<<<<<<<<<<<<<<<<<<<
        break;

        case DIO_PORTD:
		   Local_u8PinVal= GET_BIT(PIND,Copy_u8PinNumber); //<<<<<<<<<<<<<<<<<<<<<
        break;

        default:
        break;
    }
	return Local_u8PinVal;

}