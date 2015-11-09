/*
 * External_ISR.h
 *
 *  Created on: Nov 9, 2015
 *      Author: Mohamed
 */

#ifndef EXTERNAL_ISR_H_
#define EXTERNAL_ISR_H_

#include "common.h"
#include "External_ISR_CFG.h"

/* *  These macros assigns an integer value for each INT interrupt */
#define INTRRUPT_0 						0
#define INTRRUPT_1 						1
#define INTRRUPT_2 						2

/*  These macros assigns an integer value for each INT sense configuration */
#define LOW_LEVEL						0
#define	ANY_LOGICAL_CHANGE				1
#define	RISING_EDGE						2
#define	FALLING_EDGE					3

/*This function is used to configure the interrupt number and its mode
 * The first argument takes the interrupt number INTRRUPT_0,INTRRUPT_1,INTRRUPT_2
 * The second arguments takes the mode LOW_LEVEL ,ANY_LOGICAL_CHANGE,
 * The third arguments is about input mode HIGH_IMPEDENCE , PULLUP
 * FALLING_EDGE, RISING_EDGE
 * IMPORTANT INT2 Modes only FALLING_EDGE or RISING_EDGE
 * */
void Configure_Interrupt(u8 INT_Number , u8 INT_Mode,u8 Input_Mode);

/*This function is used to Enables the interrupt
 * The argument takes the interrupt number INTRRUPT_0,INTRRUPT_1,INTRRUPT_2
 * */
void Enable_Interrupt (u8 INT_Number );

/*This function is used to Disable the interrupt
 * The argument takes the interrupt number INTRRUPT_0,INTRRUPT_1,INTRRUPT_2
 * */
void Disable_Interrupt (u8 INT_Number );

/**  The Global Interrupt Enable bit must be set for the interrupts to be enabled
 * This function enable the global interrupt
 * **/
void Enable_Global_ISR (void);

/**  The Global Interrupt Enable bit must be set for the interrupts to be enabled
 * This function disable the global interrupt
 * **/
void Disable_Global_ISR (void);
#endif /* EXTERNAL_ISR_H_ */
