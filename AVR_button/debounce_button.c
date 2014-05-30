/*
 * debounce_button.c
 *
 *  Created on: Feb 18, 2014
 *      Author: mody
 */

#include"debounce_button.h"

void TO_delay (void)
{
	_delay_ms(DEBOUNCE_TIME);
}

#if SET_BUTTON==1
unsigned char button_is_pressed_set(unsigned char button_pin  , unsigned char button_bit)
{

	if ((button_pin & (1<<button_bit))>0)
	{
		TO_delay();
		if ((button_pin & (1<<button_bit))>0) return 1;
	}

	return 0;
}

#endif


#if CLR_BUTTON==1
unsigned char button_is_pressed_clear(unsigned char button_pin , unsigned char button_bit)
{
	/* the button is pressed when BUTTON_BIT is clear */
	if ((button_pin & (1<<button_bit))==0)
	{
		TO_delay();
		if ((button_pin & (1<<button_bit))==0) return 1;
	}

	return 0;
}

#endif

