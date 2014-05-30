/*
 * debounce_button.c
 *
 *  Created on: Feb 18, 2014
 *      Author: mody
 */

#include"debounce_button.h"

#if SET_BUTTON==1
unsigned char button_is_pressed_set(unsigned char button_pin , unsigned char button_bit)
{

	if (bit_is_set(button_pin,button_bit))
	{
		_delay_ms(DEBOUNCE_TIME);
		if (bit_is_set(button_pin, button_bit)) return 1;
	}

	return 0;
}

#endif


#if CLR_BUTTON==1
unsigned char button_is_pressed_clear(unsigned char button_pin , unsigned char button_bit)
{
	/* the button is pressed when BUTTON_BIT is clear */
	if (bit_is_clear(button_pin,button_bit))
	{
		_delay_ms(DEBOUNCE_TIME);
		if (bit_is_clear(button_pin, button_bit)) return 1;
	}

	return 0;
}

#endif

