/*
 * ADC_10bit.h
 *
 *  Created on: Dec 28, 2013
 *      Author: mody
 */

#ifndef ADC_10BIT_H_
#define ADC_10BIT_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ADC_10bit_CFG.h"


void intiat_adc ();
uint16_t read_adc10(uint8_t adc_channel);

#endif /* ADC_8BIT_H_ */
