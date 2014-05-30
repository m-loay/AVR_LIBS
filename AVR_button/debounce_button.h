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
#define DEBOUNCE_TIME	25

unsigned char button_is_pressed_set(unsigned char button_pin , unsigned char button_bit);
unsigned char button_is_pressed_clear(unsigned char button_pin , unsigned char button_bit);
void TO_delay (void);

#endif /* DEBOUNCE_BUTTON_H_ */
