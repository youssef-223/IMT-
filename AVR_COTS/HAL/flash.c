/*
 * flash.c
 *
 *  Created on: 9 Sep 2023
 *      Author: Youssef
 */
/*Library Inclusion*/
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

/*Lower layer Inclusion*/
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_private.h"

//#include <util/delay.h>
/*Self Files Inclusion*/

void LED_voidFlashingCase1(u8 Copy_u8PortName);
void LED_voidShiftLeftCase2(u8 Copy_u8PortName);
void LED_voidShiftRightCase3(u8 Copy_u8PortName);
void LED_voidConvergingCase4(u8 Copy_u8PortName);
void LED_voidDivergingCase5(u8 Copy_u8PortName);
void LED_voidPingPongCase6(u8 Copy_u8PortName);
void LED_voidincrementingCase7(u8 Copy_u8PortName);
void LED_voidConvergingDivergingCase8(u8 Copy_u8PortName);

u8 incrementing=1;
u8 ping=1;
u8 ToDiverge =0;
u8 ToConverge =0;

void main(void)
{
	while(1)
		{
            DIO_voidSetPortDirection(DIO_PORTB,OUTPUT);
            DIO_voidSetPortDirection(DIO_PORTA,OUTPUT);
            DIO_voidEnablePortPullUp(DIO_PORTB, PULLDOWN);
            u8 myCase = 1;
            switch (myCase)
            {
            case 1:
                LED_voidFlashingCase1(DIO_PORTA) ;
                break;
            case 2:
                LED_voidShiftLeftCase2(DIO_PORTA);
                break;
            case 3:
                LED_voidShiftRightCase3(DIO_PORTA);
                break;
            case 4:
                LED_voidConvergingCase4(DIO_PORTA);

                break;
            case 5:
               LED_voidDivergingCase5(DIO_PORTA);

                break;
            case 6:
               LED_voidPingPongCase6(DIO_PORTA);

                break;
            case 7:
               LED_voidincrementingCase7(DIO_PORTA);

                break;
             case 8:
               LED_voidConvergingDivergingCase8(DIO_PORTA);

                break;
            
            default:
                break;
            }


            myCase++; // Change myCase value to test different cases
                    if (myCase > 8)
                        myCase = 1;

                    _delay_ms(1000); // Add a delay between cases
        }
}

void LED_voidFlashingCase1(u8 Copy_u8PortName)
{
    switch (Copy_u8PortName)
    {
    case  DIO_PORTA:
    	DDRA = 0XFF;
        DIO_voidSetPortValue(DIO_PORTA,HIGH);
         _delay_ms(1000);
        DIO_voidSetPortValue(DIO_PORTA,LOW);
        _delay_ms(1000);
        break;

    case DIO_PORTB:
    	DDRB = 0XFF;
        DIO_voidSetPortValue(DIO_PORTB,HIGH);
        _delay_ms(1000);
        DIO_voidSetPortValue(DIO_PORTB,LOW);
        _delay_ms(1000);        break;

    case DIO_PORTC:
    	DDRC = 0XFF;
        DIO_voidSetPortValue(DIO_PORTC,HIGH);
        _delay_ms(1000);
        DIO_voidSetPortValue(DIO_PORTC,LOW);
        _delay_ms(1000);        break;

    case DIO_PORTD:
    	DDRD = 0XFF;
        DIO_voidSetPortValue(DIO_PORTD,HIGH);
        _delay_ms(1000);
        DIO_voidSetPortValue(DIO_PORTD,LOW);
        _delay_ms(1000);        break;

    default:
        break;
    }
}

void LED_voidShiftLeftCase2(u8 Copy_u8PortName)
{
    u8 i;
    switch (Copy_u8PortName)
    {
        case DIO_PORTA:
        for(i=0;i<=8;i++)
        {
            SET_BIT(PORTA,PIN0 << i);
            _delay_ms(250);
            if(i == 8)
            {
                i=0;
            }
        }
    	
        break;

        case DIO_PORTB:
        for(i=0;i<=8;i++)
        {
            SET_BIT(PORTB,PIN0 << i);
            _delay_ms(250);
            if(i == 8)
            {
                i=0;
            }
        }

    	break;

        case DIO_PORTC:
    	for(i=0;i<=8;i++)
        {
            SET_BIT(PORTC,PIN0 << i);
            _delay_ms(250);
            if(i==8)
            {
                i=0;
            }
        }
        break;

        case DIO_PORTD:
    	for(i=0;i<=8;i++)
        {
            SET_BIT(PORTD,PIN0 << i);
            _delay_ms(250);
            if(i==8)
            {
                i=0;
            }
        }
        break;

        default:
        break;
    }
    
}

void LED_voidShiftRightCase3(u8 Copy_u8PortName)
{
    u8 i;
    switch (Copy_u8PortName)
    {
        case DIO_PORTA:
        for(i=0;i<=8;i++)
        {
            SET_BIT(PORTA,PIN0 >> i);
            _delay_ms(250);
            if(i==8)
            {
                i=0;
            }
        }
    	
        break;

        case DIO_PORTB:
        for(i=0;i<=8;i++)
        {
            SET_BIT(PORTB,PIN0 >> i);
            _delay_ms(250);
            if(i==8)
            {
                i=0;
            }
        }

    	break;

        case DIO_PORTC:
    	for(i=0;i<=8;i++)
        {
            SET_BIT(PORTC,PIN0 >> i);
            _delay_ms(250);
            if(i=8)
            {
                i=0;
            }
        }
        break;

        case DIO_PORTD:
    	for(i=0;i<=8;i++)
        {
            SET_BIT(PORTD,PIN0 >> i);
            _delay_ms(250);
            if(i==8)
            {
                i=0;
            }
        }
        break;

        default:
        break;
    }
    
}

void LED_voidConvergingCase4(u8 Copy_u8PortName)
{
    u8 i;
    u8 a = 0b10000000; // Initialize 'a' and 'b' here
    u8 b = 0b00000001;

    for (i = 0; i < 4; i++)
    {
        DIO_voidSetPortValue(Copy_u8PortName, a + b);
        _delay_ms(300);
        a = a >> 1;
        b = b << 1;
    }

    if ((a == 0b00010000) && (b == 0b00001000))
    {
        ToDiverge = 1;
    }
}

void LED_voidDivergingCase5(u8 Copy_u8PortName)
{
    u8 i;
    u8 a = 0b00010000; // Initialize 'a' and 'b' here
    u8 b = 0b00001000;

    for (i = 0; i < 4; i++)
    {
        DIO_voidSetPortValue(Copy_u8PortName, a + b);
        _delay_ms(300);
        a = a << 1;
        b = b >> 1;
    }

    if ((a == 0b10000000) && (b == 0b00000001))
    {
        ToConverge = 1;
    }
}


void LED_voidPingPongCase6(u8 Copy_u8PortName)
{
    if(ping == 1)
    {
        SetPortSpecificValue(Copy_u8PortName,~ping);       //0000 0001
        ping<<1;   //0000 0010
    }
    else if (ping == 128)
    {
        SetPortSpecificValue(Copy_u8PortName,~ping);       //1000 0000
        ping>>1;   //0100 0000
    }
    
}

void LED_voidincrementingCase7(u8 Copy_u8PortName)
{
    if(incrementing!=128)
    {   
        SetPortSpecificValue(Copy_u8PortName,~incrementing);       //0000 0001
        incrementing<<1;   //0000 0010
    }
    else
    {
        incrementing=1;
    }
    _delay_ms(300);
}

void LED_voidConvergingDivergingCase8(u8 Copy_u8PortName)
{
    if(ToConverge==1)
    {
        LED_voidConvergingCase4(Copy_u8PortName);
    }
    else if(ToDiverge==1)
    {
        LED_voidDivergingCase5(Copy_u8PortName);
    }

}














