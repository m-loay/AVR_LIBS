/*
 * KEYPAD_Array.h
 *
 *  Created on: Nov 6, 2015
 *      Author: Mohamed
 */

#ifndef KEYPAD_ARRAY_H_
#define KEYPAD_ARRAY_H_

#include "common.h"
#include "KEYPAD_Array_CFG.h"

/**Initialization of Keypad port **/
void keypad_init(void);

/*This function is used to get key pressed in key pad*/
volatile u8 KEY_scan (void);

/**Delay function**/
void TO_delay(void);



#endif /* KEYPAD_ARRAY_H_ */
