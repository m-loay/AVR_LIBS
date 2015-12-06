/*
 * debounce_button.h
 *
 *  Created on: Feb 18, 2014
 *      Author: mody
 */

#ifndef DEBOUNCE_BUTTON_H_
#define DEBOUNCE_BUTTON_H_
#include <avr/io.h>
#include <util/delay.h>

#define SET_BUTTON	    1
#define CLR_BUTTON	    1
#define DEBOUNCE_TIME	500

u8 button_is_pressed_set(u8 U8PinNum);
u8 button_is_pressed_clear(u8 U8PinNum);
void TO_delay (void);

#endif /* DEBOUNCE_BUTTON_H_ */
