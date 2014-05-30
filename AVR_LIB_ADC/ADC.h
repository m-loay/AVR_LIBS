/*
 * ADC.h
 *
 * Created: 5/16/2013 7:01:58 PM
 *  Author: mohamed
 */ 


#ifndef ADC_H_
#define ADC_H_
#include"ADC_CFG.h"
void intit_adc ();

#if ADC_10bit_Enable==1
uint16_t read_adc10 (uint8_t adc_channel);
#endif

#if ADC_8bit_Enable==1
uint8_t read_adc8 (uint8_t adc_channel);
#endif


#endif /* ADC_H_ */
