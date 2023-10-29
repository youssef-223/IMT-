#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/**
 * @options:
 *          Normal_mode
 *          PWM_PhaseCorrect_mode
 *          CTC_mode
 *          FastPwm_mode
 */

#define     TimerMode       Normal_mode     

/**
 * @options:
 *          CTC_ToggleOC0_SubMode
 *          CTC_ClearOC0_SubMode
 *          CTC_SetOC0_SubMode
 *          Normal_subMode
 */

#define     CTC_SubMode     CTC_ToggleOC0_SubMode


/**
 * @options:
 *          NoClockSource
 *          NoPreScaling
 *          PreDivBy_8
 *          PreDivBy_64
 *          PreDivBy_256
 *          PreDivBy_1024
 *          EXT_CLK_FALLING
 *          EXT_CLK_RISING
 */
#define     Timer0_PreScaler    PreDivBy_8  


#endif