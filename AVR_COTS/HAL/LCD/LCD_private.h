#ifndef LED_PRIVATE_H
#define LED_PRIVATE_H

#define FUNCTION_SET_CMD      0x38  
#define DISPLAY_ON_OFF_CMD    0x0F  
#define DISPLAY_CLR_CMD       0x01  

static void voidSendCommand(u8 Copy_u8Command);

#endif