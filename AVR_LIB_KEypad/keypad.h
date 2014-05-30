/*
 * keypad.h
 *
 *  Created on: Dec 27, 2013
 *      Author: mody
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>
#include "keypad_CFG.h"
#include "LCD_4bit.h"


void keypad_init(void);
unsigned char get_key (void);


#endif /* KEYPAD_H_ */
