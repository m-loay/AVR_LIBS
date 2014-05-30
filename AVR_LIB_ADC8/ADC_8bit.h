/*
 * ADC_8bit.h
 *
 *  Created on: Dec 28, 2013
 *      Author: mody
 */

#ifndef ADC_8BIT_H_
#define ADC_8BIT_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ADC_8bit_CFG.h"


void intiat_adc ();
uint8_t read_adc8 (uint8_t adc_channel);

#endif /* ADC_8BIT_H_ */
