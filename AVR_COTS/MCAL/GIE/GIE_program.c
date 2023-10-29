/*Library Inclusion*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*Lower layer Inclusion*/

/*Self Files Inclusion*/
#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"

#include "../DIO/DIO_interface.h"
#include "../DIO/DIO_private.h"
#include "../DIO/DIO_config.h"


/**
 * @GIE_enable -    Set the Global Interupt Enable
 * 
 * Description : Enable the interupt for any prepherial 
 * 
 * Return : void
 * 
 */

void GIE_voidEnable(void)
{
    SET_BIT(SREG,SREG_I_BIT);
}

/**
 * @GIE_disable -    Clear the Global Interupt Enable
 * 
 * Description : Disable the interupt for any prepherial 
 * 
 * Return : void
 * 
 */

void GIE_voidDisable(void)
{
    CLR_BIT(SREG,SREG_I_BIT);
}