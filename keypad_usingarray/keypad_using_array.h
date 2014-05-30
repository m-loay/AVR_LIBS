/*
 * keypad_using_array.h
 *
 *  Created on: Feb 18, 2014
 *      Author: mody
 */

#ifndef KEYPAD_USING_ARRAY_H_
#define KEYPAD_USING_ARRAY_H_

#include"keypad_using_array_CFG.h"
#include"debounce_button.h"
#include<util/delay.h>

void keypad_init(void);
unsigned char key_scan();

#endif /* KEYPAD_USING_ARRAY_H_ */
