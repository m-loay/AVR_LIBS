/*
 * main.c
 *
 *  Created on: Nov 5, 2015
 *      Author: Mohamed
 */

#include "common.h"
volatile u16 adc_read;

int main (void)
{

	DIO_init();

	LCD_init();
	LCD_gotoxy(1,1);
	printf("AVR ADC Tutorial");
	LCD_gotoxy(1,2);

	ADC_init();
	ADC_Configure_Reference(VREFERENCE_VALUE);
	ADC_Configure_PRESCALAR(PRESCALAR_VALUE);
	ADC_Enable();
	ADC_start();

	while(1)
	{
		LCD_gotoxy(1,2);
		adc_read=ADC_read_8bits(ADC0);
		printf("%d",adc_read);
		printf ("                  " );
		TO_DELAY(500);
	}

	return(0);

}

