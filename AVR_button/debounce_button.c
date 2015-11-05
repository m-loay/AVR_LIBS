/*
 * debounce_button.c
 *
 *  Created on: Feb 18, 2014
 *      Author: mody
 */
#include "common.h"
#include"debounce_button.h"

void TO_delay (void)
{
	_delay_ms(DEBOUNCE_TIME);
}

#if SET_BUTTON==1

u8 button_is_pressed_set(u8 U8PinNum)
{

	if (DIO_get_pin(U8PinNum)==HIGH)
	{
		TO_delay();
		if (DIO_get_pin(U8PinNum)==HIGH) return 1;
	}

	return 0;
}

#endif


#if CLR_BUTTON==1
u8 button_is_pressed_clear(u8 U8PinNum)
{
	/* the button is pressed when BUTTON_BIT is clear */
	if (DIO_get_pin(U8PinNum)==LOW)
	{
		TO_delay();
		if (DIO_get_pin(U8PinNum)==LOW) return 1;
	}

	return 0;
}

#endif

