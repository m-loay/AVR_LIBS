/*
 * Enable_Global_ISR.h
 *
 *  Created on: Nov 27, 2015
 *      Author: Mohamed
 */

#ifndef ENABLE_GLOBAL_ISR_H_
#define ENABLE_GLOBAL_ISR_H_

#include "common.h"
/**  The Global Interrupt Enable bit must be set for the interrupts to be enabled
 * This function enable the global interrupt
 * **/
void Enable_Global_ISR (void);

/**  The Global Interrupt Enable bit must be set for the interrupts to be enabled
 * This function disable the global interrupt
 * **/
void Disable_Global_ISR (void);

#endif /* ENABLE_GLOBAL_ISR_H_ */
