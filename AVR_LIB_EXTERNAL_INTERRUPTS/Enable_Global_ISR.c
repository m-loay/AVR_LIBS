/*
 * Enable_Global_ISR.c
 *
 *  Created on: Nov 27, 2015
 *      Author: Mohamed
 */
#include "Enable_Global_ISR.h"

/**  The Global Interrupt Enable bit must be set for the interrupts to be enabled
 * This function enable the global interrupt
 * **/
void Enable_Global_ISR (void)
{
	SET_BIT(SREG,7);
}

/**  The Global Interrupt Enable bit must be set for the interrupts to be enabled
 * This function disable the global interrupt
 * **/
void Disable_Global_ISR (void)
{
	CLEAR_BIT(SREG,7);
}


