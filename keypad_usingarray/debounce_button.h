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
#include"debounce_button_CFG.h"


unsigned char button_is_pressed_set(unsigned char button_pin , unsigned char button_bit);
unsigned char button_is_pressed_clear(unsigned char button_pin , unsigned char button_bit);
#endif /* DEBOUNCE_BUTTON_H_ */
