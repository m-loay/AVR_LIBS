/*
 * LCD_CFG_H_
 *
 *  Created on: Dec 20, 2013
 *      Author: mody
 */

#ifndef CFG_LCD_H_
#define CFG_LCD_H_

#include "common.h"
#define bit4_cont_mode_Enable 	0
#define bit4_mixed_mode_Enable  1


#if bit4_cont_mode_Enable==1
//Defs of the ports
#define LCD_DATA_PORT				PORT0_OUTPUT_VALUE
#define LCD_DATA_DIRECTION			PORT0_DIR
#define RS_DATA_PIN					PIN0
#define EN_DATA_PIN					PIN1
#endif


//Mixed Pins
#if bit4_mixed_mode_Enable==1

#define RS_DATA_PIN					PIN14
#define EN_DATA_PIN					PIN15
#define D4_DATA_PIN					PIN4
#define D5_DATA_PIN					PIN5
#define D6_DATA_PIN					PIN6
#define D7_DATA_PIN					PIN7

#endif


#endif /* LCD_CFG_H_ */
