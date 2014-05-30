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
#include "ADC_10bit.h"
#include "LCD_4bit.h"
int adc_data;
char value [4];

int main(void)
{
	sei ();
	lcd_init();
	lcd_gotoxy(1,1);
	intiat_adc();

	while(1)
	{
		dtostrf((double)adc_data,3,0,value);
		lcd_gotoxy(1,1);
		lcd_string_print(value);
		lcd_string_print (" " );
		_delay_ms(200);
	}
	return 0;
}

ISR (ADC_vect)
{
	 adc_data=read_adc10(0);

}
