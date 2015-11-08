/*
 * SEVEN_segments.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Mohamed
 */

#ifndef SEVEN_SEGMENTS_H_
#define SEVEN_SEGMENTS_H_

#include "common.h"
#include "SEVEN_segments_CFG.h"

/**  This function is used to initialize the micro to use 7-segments
 * The function can be edited in SEVEN_segments_CFG.h
 * **/
void SEVEN_SEGMENTS_init (void);

/**  This functions is used to write on the 7-segments**/
void SEVEN_SEGMENTS_write(u32 number);

/**To get the number of digits **/
u8 number_of_digits(u32 number);

/**To get an U8 into array**/
u8 *toArray(u32 number , u8 digits_number);

#endif /* SEVEN_SEGMENTS_H_ */
