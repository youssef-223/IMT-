#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

/******************************************************************************
**************************   FUNCTIONS PROTOTYPE   ***************************
******************************************************************************/

void LCD_voidInit(void);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSendString(u8 * Ref_pu8String);
void LCD_voidGoToXY (u8 Copy_u8XPosition, u8 Copy_u8YPosition);
void LCD_voidSendNumber(u32 Copy_u32Number);
void LCD_voidClearDisplay(void);
void LCD_voidSendCustomCharacter(u8 * Ref_pu8CharacterArray,u8 Copy_u8PatternNumber,u8 Copy_u8XPosition,u8 Copy_u8YPosition);
#endif