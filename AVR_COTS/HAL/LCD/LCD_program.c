

/*Library Inclusion*/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//#include <util/delay.h>

/*Lower Layer Inclusion*/
#include "../../MCAL/DIO/DIO_INTERFACE.h"

/*Self Layer Inclusion*/

/*Self File Inclusion*/

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{
    /*Set Data Pins To Be Output Pins*/
    DIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);

    /*Set Control Pins To Be Output Pins*/
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT);     // Enable PIN
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);     // Read/Write PIN
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);     // Register Select PIN

    /*8-BIT Intialization*/

    /*1)Power On (No Code Needed)*/

    /*2)Wait For More Than 30 ms*/
    _delay_ms(40);

    /*3)Send Function Set Command (Since, RS=0. Therefore Command. Since, RW=0. Therefore Write)*/
    voidSendCommand(FUNCTION_SET_CMD);


    /*4)Wait for more than 39 Micro Sec*/
    /*No Need For Delay Because It Is Already Delayed In The Send Command*/

    /*5)Send Display ON/OFF Control*/
    voidSendCommand(DISPLAY_ON_OFF_CMD);

    /*6) Send Display Clear Command*/
    voidSendCommand(DISPLAY_CLR_CMD);
}

void LCD_voidSendData (u8 Copy_u8Data)
{
   /*Set RS Pin To Be Low, RS = 0 -> Command, 1 -> Data*/
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
    /*Set RW Pin To Be Low, RW = 0 -> Write, 1 -> Read*/
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
    /*Set The Data Port To Be The Command*/
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Data);

    /*Send The Enable Pulse On The Enable Pin*/
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

static void voidSendCommand (u8 Copy_u8Command)
{
    /*Set RS Pin To Be Low, RS = 0 -> Command, 1 -> Data*/
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
    /*Set RW Pin To Be Low, RW = 0 -> Write, 1 -> Read*/
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
    /*Set The Data Port To Be The Command*/
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Command);

    /*Send The Enable Pulse On The Enable Pin*/
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

void LCD_voidGoToXY (u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
    u8 Local_u8Address = 0;
    if(Copy_u8XPosition == 0)
    {
        Local_u8Address = Copy_u8YPosition;
    }
    else if(Copy_u8XPosition == 1)
    {
        Local_u8Address = Copy_u8YPosition + 0x40;
    }
    else 
    {
        // Error
        return;
    }
    SET_BIT(Local_u8Address, 7);
    voidSendCommand(Local_u8Address);
}

void LCD_voidSendString(u8 * Ref_pu8String)
{
    u8 Local_u8LoopCounter = 0;
    while(Ref_pu8String[Local_u8LoopCounter] != '\0')
    {
        LCD_voidSendData(Ref_pu8String[Local_u8LoopCounter]);
        Local_u8LoopCounter++;
    }
}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
    s8 Local_s8LoopCounter = 0;
    u8 Local_u8SplittedDigits[10] = {0};
    if(Copy_u32Number == 0)
    {
        LCD_voidSendData('0');
        return;
    }
    while(Copy_u32Number != 0)
    {
        
        Local_u8SplittedDigits[Local_s8LoopCounter] = Copy_u32Number % 10;
        Copy_u32Number /= 10;
        Local_s8LoopCounter++;
    }
    Local_s8LoopCounter--;
    while(Local_s8LoopCounter >= 0)
    {
        LCD_voidSendData(Local_u8SplittedDigits[Local_s8LoopCounter] + '0');
        Local_s8LoopCounter--;
    }

}

void LCD_voidClearDisplay(void)
{
    voidSendCommand(DISPLAY_CLR_CMD);
}

void LCD_voidSendCustomCharacter(   u8 * Ref_pu8CharacterArray,u8 Copy_u8PatternNumber,u8 Copy_u8XPosition,u8 Copy_u8YPosition)
{
    u8 Local_u8LoopCounter = 0;
    u8 Local_u8CGRAMAddress = 0;
    Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
    SET_BIT(Local_u8CGRAMAddress, 6);
    voidSendCommand(Local_u8CGRAMAddress);
    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
    {
        LCD_voidSendData(Ref_pu8CharacterArray[Local_u8LoopCounter]);
    }

    LCD_voidGoToXY(Copy_u8XPosition, Copy_u8YPosition);
    LCD_voidSendData(Copy_u8PatternNumber);
}