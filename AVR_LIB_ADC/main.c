/*
 * ADC_interrupt.c
 *
 * Created: 5/16/2013 8:13:01 PM
 *  Author: mohamed
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>       // needed for uint8_t
#include <stdlib.h>
#include "ADC.h"
#include "LCD_4bit.h"
volatile int adc_data;

int main(void)
{
	sei ();
	lcd_init();
	lcd_gotoxy(1,1);
	printf("AVR ADC Tutorial");
	intit_adc();
	lcd_gotoxy(1,2);

	while(1)
	{
		lcd_gotoxy(1,2);
		printf("%d",adc_data);
		printf ("                  " );
		_delay_ms(200);
	}
	return 0;
}

ISR (ADC_vect)
{
	adc_data=read_adc8(0);
}
