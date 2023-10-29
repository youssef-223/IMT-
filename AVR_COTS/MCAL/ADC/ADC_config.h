#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


/**
 * @options:
 *          PRE_DIV_BY_2  
 *          PRE_DIV_BY_4  
 *          PRE_DIV_BY_8  
 *          PRE_DIV_BY_16 
 *          PRE_DIV_BY_32 
 *          PRE_DIV_BY_64 
 *          PRE_DIV_BY_128
 */
#define ADC_PRESCALER           PRE_DIV_BY_64

/**
 * @options:
 *          AVCC
 *          AREF
 *          INTERNAL_2v56
 */
#define ADC_REF                 AVCC

/**
 * @options:
 *          RIGHT
 *          LEFT        
 */
#define ADC_LEFT_RIGHT_ADJUST         RIGHT
/**
 * @options:
 *          ENABLE
 *          DISABLE          
 */
#define ADC_ENABLE      ENABLE

#endif