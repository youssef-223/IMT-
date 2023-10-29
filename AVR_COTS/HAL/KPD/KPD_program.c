
/*Library Inclusion*/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//#include <util/delay.h>

/*Lower Layer Inclusion*/
#include "../../MCAL/DIO/DIO_interface.h"

/*Self Layer Inclusion*/

/*Self File Inclusion*/

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"


static u8 RowArr [4] = {

        KPD_R1_PIN,
        KPD_R2_PIN,
        KPD_R3_PIN,
        KPD_R4_PIN
};

static u8 ColArr [4] = {
    
        KPD_C1_PIN,
        KPD_C2_PIN,
        KPD_C3_PIN,
        KPD_C4_PIN
};

void KPD_voidInit(void)
{

    u8 Local_u8LoopCounter;

    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < KPD_NUMBER_OF_ROWS ; Local_u8LoopCounter++)
    {
        /*Set Rows Pins to be Input Pins*/
        DIO_voidSetPinDirection(KPD_ROWS_PORT,RowArr[Local_u8LoopCounter],INPUT);
        /*Set Rows Pins to be Pulled up Pins*/
       DIO_voidEnablePullUp(KPD_ROWS_PORT,RowArr[Local_u8LoopCounter],PULLUP);



    }


    /*Set Coloumn Pins to be Output High*/



    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < KPD_NUMBER_OF_COL ; Local_u8LoopCounter++)
    {
        /* Set Coloumn Pins to be Output */
        DIO_voidSetPinDirection(KPD_COLOUMNS_PORT,ColArr[Local_u8LoopCounter],OUTPUT);

        /*Set Coloumn Pins to be High*/
        DIO_voidSetPinValue(KPD_COLOUMNS_PORT,ColArr[Local_u8LoopCounter],HIGH);

    }
}



u8 KPD_u8GetPressedKey(void)
{
    u8 Local_u8ButtonsValue [KPD_NUMBER_OF_ROWS][KPD_NUMBER_OF_COL] = KPD_BUTTONS_VAL;
    u8 Local_u8ColCounter;
    u8 Local_u8RowsCounter;
    u8 Local_u8RowValue;
    u8 Local_u8PressedKey = KDP_DEFAULT_VALUE ;

    for(Local_u8ColCounter = 0 ; Local_u8ColCounter < KPD_NUMBER_OF_COL ; Local_u8ColCounter ++ )
    {

        /*Set The Current Coloumn To Be Low */
        DIO_voidSetPinValue(KPD_COLOUMNS_PORT,ColArr[Local_u8ColCounter],LOW);


        /*Read Rows Pins*/
        for(Local_u8RowsCounter = 0 ; Local_u8RowsCounter < KPD_NUMBER_OF_ROWS ; Local_u8RowsCounter ++ )
        {
            
            /*Read The Row Pin*/
            Local_u8RowValue = DIO_u8GetPinValue(KPD_ROWS_PORT,RowArr[Local_u8RowsCounter]);

            /*Local_u8RowValue will be zero if pressed*/
            if(Local_u8RowValue == 0)
            {
                /*Return the pressed key*/
                Local_u8PressedKey = Local_u8ButtonsValue[Local_u8ColCounter][Local_u8RowsCounter];


                /*Polling until the key is released*/
                while (Local_u8RowValue == 0)
                {
                    /*Re- read The Row Value*/
                     Local_u8RowValue = DIO_u8GetPinValue(KPD_ROWS_PORT,RowArr[Local_u8RowsCounter]);
                }
                

                /*Set The Current Coloumn To Be High */
                DIO_voidSetPinValue(KPD_COLOUMNS_PORT,ColArr[Local_u8ColCounter],HIGH); 

                /*Return The Pressed Key*/
                return Local_u8PressedKey;

            } 
        }

        /*Set The Current Coloumn To Be High */
        DIO_voidSetPinValue(KPD_COLOUMNS_PORT,ColArr[Local_u8ColCounter],HIGH);

    }

    return Local_u8PressedKey;
}
