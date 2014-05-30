/*
 * ADC.c
 *
 * Created: 5/16/2013 6:58:54 PM
 *  Author: mohamed
 */ 

#include "ADC_10bit.h"

void intiat_adc ()
{
	/*set the ADC PORT as an output*/
	ADC_PORT_DDR=0x00;
	/* Select Vref=AVcc*/
	ADMUX |= (1<<REFS0);
	/*set prescaller to 128 and enable ADC*/
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN));
	/*Enabling ADIE for interrupt*/
	ADCSRA |=(1<<ADIE);
	/*Start the first conversion*/
	ADCSRA|=(1<<ADSC);
}


uint16_t read_adc10(uint8_t adc_channel)
{
	//select ADC channel with safety mask
	ADMUX = (ADMUX & 0xF0) | (adc_channel & 0x0F);
	//single conversion mode
	ADCSRA |= (1<<ADSC);
	//return ADC value
	return ADC;
}

